// package Exo1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.lang.Math;

// mdp à chercher : 17441945

public class Exo1 {

    /*
     * 
     * 
     * 
     * Alice 8FC92036B2963C604DC38B2DDB305148
Bob 367F3AC1129CC92DCBB8C4B9EA4EE55A
Clara 38251B4C8C210841C60CDE0B7E4C7A87
     */

    public String hash(String str) throws NoSuchAlgorithmException { 
        MessageDigest digest = MessageDigest.getInstance("MD5");
        // String str = "12345678";
        byte[] hash = digest.digest(str.getBytes());
        // Affichage
        StringBuilder sb = new StringBuilder();
        for (byte b : hash) {
            sb.append(String.format("%02X", b));
        }
        // System.out.println(sb.toString());
        return sb.toString();
    }

    public String Int2String(int i) {
        String str = String.format("%08d", i);
        // System.out.println("str=" + str); // Affiche str=00000123
        return str;
    }

    public void String2Bytes(String s) {
        // String s = "404142434445464748494A4B4C4D4E4F";
        // Conversion de s en un tableau de byte, le premier byte est 0x40 , le deuxième
        // 0x41 , et ainsi de suite
        int len = s.length();
        byte[] data = new byte[len / 2];
        for (int i = 0; i < len; i += 2) {
            data[i / 2] = (byte) ((Character.digit(s.charAt(i), 16) << 4) + Character.digit(s.charAt(i + 1), 16));
        }
        // Affichage de data
        for (int i = 0; i < data.length; i++) {
            System.out.println("data[" + i + "]=" + data[i]);
        }
    }

    public void bruteForce() {
        for (int i = /*00000000*/ 17441945; i < 17441950/*99999999*/; i++) {
            String TMPstr = this.Int2String(i);
            String Hashed = "";
            try {
                Hashed = this.hash(TMPstr);
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
            System.out.println("Hashed=" + Hashed);
            if (Hashed == "38251B4C8C210841C60CDE0B7E4C7A87") {
                System.out.println("Found ! " + TMPstr);
                return;
            }
        }
    }

    public static void main(String[] args) throws NoSuchAlgorithmException {
        Exo1 exo1 = new Exo1();
        // exo1.hash("17441945");
        // exo1.Int2String(123);
        // exo1.String2Bytes("404142434445464748494A4B4C4D4E4F");
        exo1.bruteForce();
    }
}