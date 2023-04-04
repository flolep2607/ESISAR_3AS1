%% correction d'erreur

function [vecteur_sortie] = correction_erreur(vecteur_entree)

H = [0,1,1,1,1,0,0;
     1,0,1,1,0,1,0;
     1,1,0,1,0,0,1];


S = vecteur_entree*H';
% arrayfun applique la fonction modulo 2 à tout les éléments du vecteur S
S = arrayfun(@(x) mod(x,2),S);

% is member renvoie un vecteur de taille 7 avec chaque élément égale à 1 si S = la ième colone de H' et 0 sinon
% ensuite find renvoie le numéro de ligne à laquelle il y a un 1.
% graçe à cela, on obtient k le numéro du bit à corriger 
k = find(ismember(H',S,'rows'),1);  


if not(isempty(k))
    vecteur_entree(k)= 1 - vecteur_entree(k);
end

% le vecteur à renvoyer est composé des 4 premiers bit du message corrigé.
vecteur_sortie = vecteur_entree(1:4);

end