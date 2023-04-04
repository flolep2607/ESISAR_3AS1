GHDL = ghdl
WORK= --workdir=work
GHDLFLAGS= --ieee=synopsys 
FILE=compteur_16
test: $(FILE) $(FILE)_tb
	$(GHDL) -r $(WORK) $(FILE)_tb --vcd=compteur_16_tb.vcd

# Binary depends on the object file
%: %.o
	$(GHDL) -e $(GHDLFLAGS) $(WORK) $@

# Object file depends on source
%.o: %.vhd
	$(GHDL) -a $(GHDLFLAGS) $(WORK) $<

clean:
	echo "Cleaning up..."
	cd work
	rm -f *.o *_tb $(FILE) work*.cf e*.lst
	cd ..
