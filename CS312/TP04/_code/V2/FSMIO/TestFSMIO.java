package FSMIO;

import java.util.*;
import java.lang.*;

public class TestFSMIO {

	public static void main(String argv[]) {
		State s1, s2, s3, s4;
		s1 = new State("s1");
		s2 = new State("s2");
		s3 = new State("s3");
		s4 = new State("s4");

		ArrayList<State> states = new ArrayList<State>();
		states.add(s1);
		states.add(s2);
		states.add(s3);
		states.add(s4);

		FSMIO<String, Integer> fsm = new FSMIO<String, Integer>(states, s1);

		// remarquez que l'ordre des arguments n'est pas le même que la V1. Pourquoi ?
		fsm.addTransition(s1, "a", 0, s2);
		fsm.addTransition(s1, "b", 0, s3);
		fsm.addTransition(s2, "a", 0, s3);
		fsm.addTransition(s2, "b", 1, s2);
		fsm.addTransition(s3, "a", 0, s4);
		fsm.addTransition(s3, "b", 0, s3);
		fsm.addTransition(s4, "a", 1, s2);
		fsm.addTransition(s4, "b", 1, s3);

		System.out.println("Premier automate :");
		System.out.println(fsm);

		// TODO : Play with this automata, and add another one.

		State s21, s22, s23, s24, s25, s26, s27, s28, s29;
		s21 = new State("s21");
		s22 = new State("s22");
		s23 = new State("s23");
		s24 = new State("s24");
		s25 = new State("s25");
		s26 = new State("s26");
		s27 = new State("s27");
		s28 = new State("s28");
		s29 = new State("s29");

		ArrayList<State> states2 = new ArrayList<State>();
		states2.add(s21);
		states2.add(s22);
		states2.add(s23);
		states2.add(s24);
		states2.add(s25);
		states2.add(s26);
		states2.add(s27);
		states2.add(s28);
		states2.add(s29);
		FSMIO<Integer, Integer> fsm2 = new FSMIO<Integer, Integer>(states2, s21);

		fsm2.addTransition(s21, 0, 0, s22);
		fsm2.addTransition(s21, 1, 0, s26);
		fsm2.addTransition(s22, 0, 0, s23);
		fsm2.addTransition(s22, 1, 0, s21);
		fsm2.addTransition(s23, 0, 0, s24);
		fsm2.addTransition(s23, 1, 0, s21);
		fsm2.addTransition(s24, 0, 1, s25);
		fsm2.addTransition(s24, 1, 0, s21);

		fsm2.addTransition(s26, 1, 0, s27);
		fsm2.addTransition(s26, 0, 0, s21);
		fsm2.addTransition(s27, 1, 0, s28);
		fsm2.addTransition(s27, 0, 0, s21);
		fsm2.addTransition(s28, 1, 1, s29);
		fsm2.addTransition(s28, 0, 0, s21);

		System.out.println("Deuxième automate :");
		System.out.println(fsm2);
	}
}
