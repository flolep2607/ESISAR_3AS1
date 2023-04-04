1:
	gcc 1.c -o 1.o
	./1.o 'ls -l' 'grep rwx'

2:
	gcc 2/server.c -o server.o
	gcc 2/client.c -o client.o
	./server.o &
	./client.o "hello world"
	./client.o ":)" "yeah"
