"source";
%m = [0,0,0,0];
%c = [0,0,0,0,0,0,0];
%d = [0,0,0,0];

nombre_bit = 10;
p0 = 0.5;
f = 0.1;

s = source(nombre_bit,p0);
s

c = codage(s);


t = canal(c,f);


d = decodage(t);
d

