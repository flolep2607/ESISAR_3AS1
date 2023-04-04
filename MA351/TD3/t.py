import requests
import time
from requests_toolbelt.multipart.encoder import MultipartEncoder

file_url = 'http://commondatastorage.googleapis.com/gtv-videos-bucket/sample/BigBuckBunny.mp4'
target = 'http://up.hydrax.net/cec7534b591d2f4641a5d23dcbb8d602'


class PinocchioFile:
    def __init__(self, url):
        self.req = requests.get(url, stream=True)
        length = self.req.headers.get('content-length')
        self.total_length = length
        self.len = None if length is None else int(length)
        self._raw = self.req.raw
        self.i=0
        self.start=time.time()
    def read(self, chunk_size):
        chunk = self._raw.read(chunk_size) or b''
        self.len -= len(chunk)
        if not chunk:
            self.len = 0
        self.i+=1
        if self.i%100==0:
            print(f"time spent: {time.time()-self.start} | total length: {self.total_length} | remaining length: {self.len}")
        return chunk


multipart_data = MultipartEncoder([
    ('file',('video.mp4',PinocchioFile(file_url),'video/mp4'))
])
# ,None, encoding='utf-8')

# Create headers
headers = {
    'Content-Type': multipart_data.content_type
}

response = requests.post(
    target,
    data=multipart_data,
    headers=headers,
)
