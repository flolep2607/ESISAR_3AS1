
function [taux_erreur_bianire] = erreur_binaire(n,p0,f)

c=0;
% Boucle for pour répéter l'expérience 100 fois
for k = 1:100

    vecteur_entree = source(n,p0);
    vecteur_sortie = canal(vecteur_entree,f);

    for i = 1:n
        if  vecteur_sortie(i) ~= vecteur_entree(i)
% On compte le nombre de bits corrompus
            c=c+1;
        end
    end

end
% Puis on finis par faire la moyenne pour obtenir une probabilité (d'erreur bit)
taux_erreur_bianire = c/(n*100);

end