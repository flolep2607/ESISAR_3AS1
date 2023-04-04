package FSMIO;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;


public class FSMIO<T1, T2> {
    private List<State> states;
    private TransitionFunction<T1, T2> tf;
    private State currentState;	
    private State initialState;
	
    // Constructors
    public FSMIO(List<State> states, State init) {
	this.states = states;
	this.tf = new TransitionFunction<T1, T2>();
	this.currentState = this.initialState = init;
    }
	
    public FSMIO(State init){
	this.currentState = this.initialState = init;
	this.states = new ArrayList<State>();
	this.states.add(init);
	this.tf = new TransitionFunction<T1, T2>();
    }
	
    // Adding states & transitions
    public boolean addState(State s){		
	boolean done = false;
	if(!this.states.contains(s)){
	    this.states.add(s);
	    done = true;
	}
	return done;
    }
	
    public void addTransition(State orig, T1 input, T2 output, State dest){
	if(this.states.contains(orig) && this.states.contains(dest) && getTransition(orig, input) == null){
	    this.tf.addTransition(orig, input, dest, output);
	}
    }
	
    // Executing
    // Reseting to initial state
    public void reset(){
	this.currentState = this.initialState;
    }
    
    // Firing a transition
    public T2 doTransition(T1 input){		
	Transition<T1, T2> nt = getTransition(currentState, input); 
	if(nt != null){
	    this.currentState = nt.getDest();
	    return(nt.getTag().getOutput());
	}
	return null;
    }
	
    public State getCurrentState(){
	return this.currentState;
    }
	
    // toString
    public String toString(){
	return this.tf.toString();
    }
	
    // Inspection methods
    // Get a transition from a state
    private Transition<T1, T2> getTransition(State orig, T1 input){
	return this.tf.getTransition(orig,  input);
    }
	
}
