
NB_TEST = 20;
WIDTH = 50;
INCR = 100;
N = 0;

x = 1:WIDTH;
x= x.*INCR;
y1 = [];
y2 = [];

for k = 1:WIDTH

    N = N + INCR;

    time1 = 0;
    time2 = 0;
    for i = 1:NB_TEST

        Liste1 = randi([10 50],1,N);
        Liste2 = Liste1;

     tic
        Tri = tri_insertion(Liste1);
     time1 = time1 + toc;
     
     tic
        Tri = tri_fusion(Liste2);
     time2 = time2 + toc;
    end
    
    y1(k) = time1/NB_TEST;
    y2(k) = time2/NB_TEST;

k
end

figure(1)
plot(x,y1,'-b','linewidth',2) %affichage de x1 en fonction de t. La courbe en bleue continue d'épaisseur 3
hold on % affichage de plusieurs courbes
plot(x,y2,'--r','linewidth',2)
legend('Tri insertion','Tri fusion')
xlabel("Longueur data set (nb élem)",'fontsize',14) %label sur l'axe x avec une police de 14
ylabel("Temps d'execution (s)",'fontsize',14)    % idem sur l'axe y
set(gca,'fontsize',14) % police des axes en 14
set(gcf,'color','white') %couleur de la fenêtre en blanc