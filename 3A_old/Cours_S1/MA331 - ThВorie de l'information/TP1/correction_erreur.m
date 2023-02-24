%% correction d'erreur

function [vecteur_sortie] = correction_erreur(vecteur_entree)

H = [0,1,1,1,1,0,0;
     1,0,1,1,0,1,0;
     1,1,0,1,0,0,1];


S=vecteur_entree*H';
S = arrayfun(@(x) mod(x,2),S);

k = find(ismember(H',S,'rows'),1); % 


if not(isempty(k))
    vecteur_entree(k)= 1 - vecteur_entree(k);
end

vecteur_sortie = vecteur_entree(1:4);

end