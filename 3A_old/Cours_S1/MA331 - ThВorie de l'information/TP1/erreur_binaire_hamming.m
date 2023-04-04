
function [taux_erreur_bianire] = erreur_binaire_hamming(NB_TESTS,n,p0,f)

c=0;
for k = 1:NB_TESTS

    vecteur_entree = source(n,p0);
    vecteur_sortie = decodage(canal(codage(vecteur_entree),f));

    for i = 1:n
        if  vecteur_sortie(i) ~= vecteur_entree(i)
            c=c+1;
        end
    end

end

taux_erreur_bianire = c/(n*NB_TESTS);

end