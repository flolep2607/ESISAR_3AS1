package FSMIO;

public class SimpleFSMIO {
    private SimpleTransitionFunction t;
    private String initialState;
    private String currentState;
    private String states[];
    private char inputs[];

    // Yes, these methods would need a bit more documentation.
    public SimpleFSMIO(String states[], String initialState, char inputs[]) {
	this.t = new SimpleTransitionFunction(states, inputs);
	this.states = states;
	this.inputs = inputs;
	this.currentState = this.initialState = initialState;
    }
    
    public void addTransition(String fromState, char inputVal, String destState, int output){

	boolean fromStateValid = false;
	boolean destStateValid = false;
	boolean inputValid = false;
	
	for(int ie = 0; ie < this.states.length && (!fromStateValid || !destStateValid); ie++){
	    if(fromState.equals(this.states[ie])) fromStateValid = true;
	    if(destState.equals(this.states[ie])) destStateValid = true;
	}
		
	for(int i = 0; i < this.inputs.length && !inputValid; i++){
	    inputValid = (inputVal == this.inputs[i]);
	}
		
	if (fromStateValid && destStateValid && inputValid){
	    t.addTransition(fromState, inputVal, destState, output);
	}
    }
	
    public int doTransition(char val){

	// TODO : 
	// no code just implement getNextState and getOutput	
	int output = getOutput(this.currentState, val);
	this.currentState = getNextState(this.currentState, val);
	return output;
    }

    
    public void reset(){
	this.currentState = this.initialState;
    }
	
    public String getCurrentState(){
	return this.currentState;
    }
	
    public String getNextState(String s, char e){

	// TODO : MODIFY THIS METHOD (V1.Q1)
	// Add an exception handler around the call
	// to the "transition" getNextState
	// This is a call to the SimpleTra
	return(this.t.getNextState(s, e));
	
    }

	
    public int getOutput(String s, char e){
	// TODO : MODIFY THIS METHOD (V1.Q1)
	

	return(this.t.getOutput(s, e));
	
    }


}
