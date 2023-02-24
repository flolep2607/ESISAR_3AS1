package BLOOM;

import java.nio.ByteBuffer;
import java.nio.channels.SeekableByteChannel;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.BitSet;

public class Bloom_Filter {
	
	int m; // taille en bits du filtre de Bloom 
	int k; // nombre de fois qu'il faut hacher
	BitSet bloomFilter;
	
	public Bloom_Filter(int m, int k, String file) {
		this.m = m;
		this.k = k;
		this.bloomFilter = new BitSet(m);
		construct(file);
	}
	
	private void construct(String file) {
		try {
			long start = System.currentTimeMillis();
			SeekableByteChannel sbc = Files.newByteChannel(Paths.get(file), StandardOpenOption.READ);
			
			int count =0;// Lecture des 50 000 premiers octets du fichier
			ByteBuffer buf = ByteBuffer.allocate(50000);
			
			int ret = sbc.read(buf);
			while(ret>0) {// Conversion des 50_0000 octets en 1000 chaine de caractères
				for (int i = 0; i < 1000; i++) {
					String str = new String(buf.array(),i*50,50);// Suppression des espaces en fin de chaine
					str = str.trim();// Affichage de la chaine de caractères sur la console
					for(int j=0; j<this.k; j++) {
						bloomFilter.set(hash(str, j));
					}
					// System.out.println(str);
					count++;

				}
				// Lecture des 50_000 octets suivants
				buf.clear();
				ret = sbc.read(buf);
			}
			System.out.println("Nombre d'URL dans le fichier = "+count);
			System.out.println("Elapsed Time="+(System.currentTimeMillis()-start)/1000+"s");
			// Fermeture du fichier
			sbc.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private int hash(String value, int numFonction) {
		int h1 = h1(value);
		int h2 = h2(value);
		
		int h = ( (h1 + numFonction * h2) % m);
		h = (h+m) % m;
		
		return h;
	}
	
	private static int h1(String value) {
		char val[] = value.toCharArray();
		
		int h = 0;
		for(int i = 0; i < val.length; i++) {
			h = 31 * h + val[i];
		}
		return h;
	}
	
	private static int h2(String value) {
		char val[] = value.toCharArray();
		
		int h = 0;
		for(int i = 0; i < val.length; i++) {
			h = 57 * (h <<2) + val[i];
		}
		return h;
	}
	
	public boolean contain(String url) {
		int hit=0;
		for(int j=0; j<this.k; j++) {
			if (bloomFilter.get(hash(url, j)))
				hit++;
		}
		return (hit==this.k);
	}
}






