GHDL = ghdl
WORK= --workdir=work
GHDLFLAGS= --ieee=synopsys 
test: compteur_16 compteur_16_tb
	$(GHDL) -r $(WORK) compteur_16_tb --vcd=compteur_16_tb.vcd

# Binary depends on the object file
%: %.o
	$(GHDL) -e $(GHDLFLAGS) $(WORK) $@

# Object file depends on source
%.o: %.vhd
	$(GHDL) -a $(GHDLFLAGS) $(WORK) $<

clean:
	echo "Cleaning up..."
	cd work
	rm -f *.o *_tb compteur16 work*.cf e*.lst
	cd ..