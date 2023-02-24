%% codage

function [vecteur_sortie] = codage(vecteur_entree)

% Matrice du code de Hamming(7,4)
G=[1,0,0,0,0,1,1;
   0,1,0,0,1,0,1;
   0,0,1,0,1,1,0;
   0,0,0,1,1,1,1];

n = length(vecteur_entree);
n2 = n+mod(4-mod(n,4),4);%rajoute 1,2,ou 3 bits pour être multiple de 4

% V2 = vecteur_entree étendu à n bits (par concaténation de (n2-n) zéros)
V2 = [vecteur_entree zeros(1,mod(n,4))];
vecteur_sortie = zeros(1,(n2/4)*7);

j=0;
m=zeros(1,4);
c=zeros(1,7);
    
for i = 1:4:n2
% On découpe le vecteur_entree en paquets de 4 bits
    m=[V2(i),V2(i+1),V2(i+2),V2(i+3)];
    c=m*G;
    for k = 1:7
        vecteur_sortie(j+k)=mod(c(k),2);
    end
    j=j+7;
end

end