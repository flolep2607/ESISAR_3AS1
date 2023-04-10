package FSMIO;

public class SimpleTransitionFunction {
	private String stateNames[];
	private char inputs[];
	private String nextState[][];
	private int output[][];

	public SimpleTransitionFunction(String stateNames[], char inputs[]) {
		this.stateNames = stateNames;
		this.inputs = inputs;

		// TODO (V1.Q2) : 1 - allocate the 2 remaining attributes
		nextState = new String[stateNames.length][inputs.length];
		output = new int[stateNames.length][inputs.length];

		// TODO (V1.Q2) 2- initialize nextState/output with empty string or -1 value (4
		// lines)
		//
		// To debug, you can uncomment the following line
		System.out.println("transition table of size " + stateNames.length + " x" + inputs.length);
	}

	// Cherche l'index d'un état donné par sa chaîne.
	private int getStateIndex(String etat) throws Exception {
		int i = 0;
		while (i < this.stateNames.length
				&& !this.stateNames[i].equals(etat))
			i++;
		if (i == this.stateNames.length)
			throw new Exception("Etat inexistant");
		return i;
	}

	// identiquement...b
	private int getInputIndex(char input) throws Exception {
		int i = 0;
		while (i < this.inputs.length && this.inputs[i] != input)
			i++;
		if (i == this.inputs.length)
			throw new Exception("Input inexistant");
		return i;
	}

	public void addTransition(String fromStateName, char input, String nomEtatDest, int output) {
		// TODO : get indexes, add in tables (V1.Q2)
		try {
			int i = getStateIndex(fromStateName);
			int j = getInputIndex(input);
			nextState[i][j] = nomEtatDest;
			this.output[i][j] = output;
		} catch (Exception e) {
			System.out.println("Erreur : " + e.getMessage());
		}
	}

	public String getNextState(String fromStateName, char input) throws Exception {
		// TODO: implement (V1.Q2) (with exceptions)
		int i = getStateIndex(fromStateName);
		int j = getInputIndex(input);
		return nextState[i][j];
	}

	public int getOutput(String fromStateName, char input) throws Exception {
		// TODO: implement (V1.Q2)
		int i = getStateIndex(fromStateName);
		int j = getInputIndex(input);
		return output[i][j];
	}
}
