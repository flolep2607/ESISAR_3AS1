package MAIN;

import java.nio.ByteBuffer;
import java.nio.channels.SeekableByteChannel;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

import BLOOM.Bloom_Filter;

public class MAIN {
	
	public static void main(String[] args) {
		System.out.println("--- Start Main ---");
		
		/*
		Bloom_Filter F = new Bloom_Filter(200_000_000, 11, "infected-urls.txt");
		
		
		System.out.println("\n--- Test faux positifs ---");
		testContain(F,"valides-urls.txt");
		*/
		
		etudeVariations();
		
		
	}
	
	private static int testContain(Bloom_Filter filtre, String file) {
		System.out.println("Testing every url in "+file);
		int hit = 0;
		try {
			long start = System.currentTimeMillis();
			SeekableByteChannel sbc = Files.newByteChannel(Paths.get(file), StandardOpenOption.READ);
			
			int count =0;// Lecture des 50 000 premiers octets du fichier
			ByteBuffer buf = ByteBuffer.allocate(50_000);
			
			int ret = sbc.read(buf);
			while(ret>0) {// Conversion des 50_0000 octets en 1000 chaine de caractères
				for (int i = 0; i < 1000; i++) {
					String str = new String(buf.array(),i*50,50);// Suppression des espaces en fin de chaine
					str = str.trim();// Affichage de la chaine de caractères sur la console
					
					if (filtre.contain(str)) {
						//System.out.println("Hit on "+str);
						hit++;
					}
					
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
		System.out.println("Nombre de Faux Positifs = "+hit);
		return hit;
	}
	
	private static void etudeVariations() {
		int[] tableau= new int[21];
		Bloom_Filter F;
		for(int k=1; k<=20; k++) {
			
			F = new Bloom_Filter(200_000_000, k, "infected-urls.txt");
			tableau[k] = testContain(F, "valides-urls.txt");
			System.out.println("K:"+k+"Faux positifs: "+tableau[k]);
		}
		
		for(int k=1; k<=20; k++) {
			System.out.println("K:"+k+"Faux positifs: "+tableau[k]);
			System.out.println("Pourcentage: "+(tableau[k]/200_000_000)*100);
		}
		
	}
	
	
}