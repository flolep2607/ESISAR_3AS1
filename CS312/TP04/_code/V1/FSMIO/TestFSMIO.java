package FSMIO;
import java.util.*;
import java.lang.*;

public class TestFSMIO {

	public static void main(String argv[]){

	    String stateNames[] = new String[3];
	    char inputs[] = new char[2];
	    stateNames[0] = "s1";
	    stateNames[1] = "s2";
	    stateNames[2] = "s3";
	    inputs[0] = 'a';
	    inputs[1] = 'b';

	    SimpleFSMIO sfsm = new SimpleFSMIO(stateNames, "s1", inputs);
	    sfsm.addTransition("s1", 'a', "s1", 0);
	    sfsm.addTransition("s1", 'b', "s3", 0);
	    sfsm.addTransition("s2", 'a', "s1", 0);
	    sfsm.addTransition("s2", 'b', "s2", 1);
	    sfsm.addTransition ("s3", 'a', "s2", 1);
	    sfsm.addTransition("s3", 'b', "s3", 1);

	    // TODO (V1.Q2) test your functions...
	    // Uncomment to test your first methods.
	    //System.out.println(sfsm.getNextState("s1", 'a'));
	    //System.out.println(sfsm.getOutput("s3", 'b')); 

	    sfsm.reset();
	    // TODO (V1.Q3) : play string "abbaabbaaa"!
	    
	}
}
