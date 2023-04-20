import java.util.*;
import java.lang.*;

public class TestFSMIOString {

	public static void main(String[] args) {

		if (args.length != 1) {
			System.out.println("nom du fichier svp");
			System.exit(1);
		}

		String nomFichier = args[0];
		FSMIOString fsm = new FSMIOString(nomFichier);

	}
}