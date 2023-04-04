function [WER] = WER(NB_TESTS,p0,f)

err = 0;
for k = 1:NB_TESTS
	
    vecteur_entree = source(4,p0);
    vecteur_sortie = canal(vecteur_entree,f);

  if  not(isequal(vecteur_sortie, vecteur_entree))
    err = err + 1;
	end

end

WER = err/NB_TESTS;

end