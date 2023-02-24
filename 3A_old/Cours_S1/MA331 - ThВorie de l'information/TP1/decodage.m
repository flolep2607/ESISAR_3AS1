%% decodage


function [vecteur_sortie] = decodage(vecteur_entree)

H = [0,1,1,1,1,0,0;
     1,0,1,1,0,1,0;
     1,1,0,1,0,0,1];

n = length(vecteur_entree);

m=zeros(1,4);
r=zeros(1,7);
vecteur_sortie=[];

for i = 1:7:n
    r = vecteur_entree(i:i+6);
    
    m = correction_erreur(r);
    
    vecteur_sortie = [ vecteur_sortie m ];

end

end