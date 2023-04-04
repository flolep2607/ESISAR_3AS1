package FSMIO;
import java.util.*;
import java.lang.*;

public class TestFSMIO {

    public static void main(String argv[]){
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

	System.out.println(fsm);

	
	// TODO : Play with this automata, and add another one.
    }
}
