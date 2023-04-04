%% canal

function [vecteur_sortie] = canal(vecteur_entree,f)

n = length(vecteur_entree);
vecteur_sortie = zeros(1,n);

for i = 1:n
    x = rand;
    if x <= f
        %modifie
        vecteur_sortie(i)= 1 - vecteur_entree(i);
    else
        vecteur_sortie(i)=vecteur_entree(i);
    end
end

end