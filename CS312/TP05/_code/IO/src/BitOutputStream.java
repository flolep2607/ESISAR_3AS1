package IO;

import java.io.OutputStream;
import java.io.IOException;


/**
 * Bit Output stream
 * @author O. Carton
 * @version 1.2 modified by LG
 */



class BitOutputStream {
    OutputStream os; // The stream where the bytes are read
    int buffer = 0;  // Buffer for the bits or -1 if ended (an int contains 8 bits)
    int length; // current number of accurate bits in buffer
    
    BitOutputStream(OutputStream os) {
	buffer = 0;
	length = 0;
	this.os = os;
    }
    /**
     * Write a bit into the stream from an integer value.
     * The bit is 0 is this value is 0 and it is 1 otherwise
     * @param bit the bit
     */
    void write(int bit) 
	throws IOException {
	// TODO: some shifts and bit logic might be useful.
    }
    /**
     * Write a bit into the stream from a boolean value.  
     * The bit is 0 if this value is true and it is 1 otherwise.
     * @param bit the bit 
     */
    void write(boolean bit)
 	throws IOException {
	// TODO : use previous function to implement this one.
    }
    void close()
 	throws IOException {
	// Output remaining bits in the buffer, then close the stream
    }
}
