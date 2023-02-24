%% Source

function [vecteur_sortie] = source(n,p0)

vecteur_sortie = zeros(1,n);

for i = 1:n
    x = rand;
    if x <= p0
        x = 0;
    else 
        x = 1;
    end
    vecteur_sortie(i)=x;
end

end
