%% Rendement et Limite de Shannon

NB_TESTS = 400;
TAILLE_SOURCE = 4;
p0 = 0.5;
f = 0.05;

Rendement_Hamming = 4/7;
C = 1 + f*log2(f) + (1-f)*log2(1-f) ;

ber = erreur_binaire_hamming(NB_TESTS,TAILLE_SOURCE,p0,f)


NB_POINTS=50;
pmax=0.2;
pp = 0:pmax/(NB_POINTS-1):pmax;

Limite_Shanon = zeros(1,NB_POINTS);
for i = 1:NB_POINTS
    Limite_Shanon(i) = C / ( 1 + pp(i)*log2(pp(i)) + (1-pp(i))*log2(1-pp(i)) ) ;
end

figure(1)
plot(Rendement_Hamming,ber,'+b','linewidth',5) %affichage de x1 en fonction de t. La courbe en bleue continue d'épaisseur 3
hold() % affichage de plusieurs courbes
plot(Limite_Shanon,pp,'-r','linewidth',2)
xlim([0,2])
ylim([0,0.2])
set(gca,'Yscale','log')
xlabel("Rendement",'fontsize',14) %label sur l'axe x avec une police de 14
ylabel("Probabilité d'erreur bit ",'fontsize',14)    % idem sur l'axe y
set(gca,'fontsize',14) % police des axes en 14
set(gcf,'color','white') %couleur de la fenêtre en blanc