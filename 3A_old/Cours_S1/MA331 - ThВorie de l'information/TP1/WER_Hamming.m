function [WER] = WER_Hamming(NB_TESTS,p0,f)

err = 0;
for k = 1:NB_TESTS
	
    vecteur_entree = source(4,p0);
    vecteur_sortie = decodage(canal(codage(vecteur_entree),f));
	%on utilise codage car on veut qu'il y ait 7 bits dans le mot décodé

  if  not(isequal(vecteur_sortie, vecteur_entree))
    err = err + 1;
	end

end

WER = err/NB_TESTS;

end