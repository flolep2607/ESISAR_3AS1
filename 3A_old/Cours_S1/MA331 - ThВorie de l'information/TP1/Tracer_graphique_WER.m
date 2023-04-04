%% plot

NB_POINTS=100;
pmax=0.5;

pp = 0:pmax/(NB_POINTS-1):pmax;

NB_TESTS = 1000;
p0 = 0.5;


Proba_hamming = zeros(1,NB_POINTS);
Proba_non_codee = zeros(1,NB_POINTS);

for i = 1:NB_POINTS
    Proba_hamming(i) = WER_Hamming(NB_TESTS,p0,pp(i));
    Proba_non_codee(i) = WER(NB_TESTS,p0,pp(i));
end

figure(1)
plot(pp,Proba_hamming,'-b','linewidth',2) %affichage de x1 en fonction de t. La courbe en bleue continue d'épaisseur 3
hold on % affichage de plusieurs courbes
plot(pp,Proba_non_codee,'--r','linewidth',2)
xlabel("probabilité d'erreur canal (f)",'fontsize',14) %label sur l'axe x avec une police de 14
ylabel('WER','fontsize',14)    % idem sur l'axe y
set(gca,'fontsize',14) % police des axes en 14
set(gcf,'color','white') %couleur de la fenêtre en blanc