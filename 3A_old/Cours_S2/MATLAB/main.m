
NB_TEST = 10;
WIDTH = 50;
INCR = 1000;
N = 0;

x = 1:WIDTH;
x= x.*INCR;
y = [];

for k = 1:WIDTH

    N = N + INCR;

    time = 0;
    for i = 1:NB_TEST

        Liste = randi([10 50],1,N);

     tic
        Tri = tri_insertion(Liste);
     time = time + toc;
    end
    
    y(k) = time/NB_TEST;

k
end

figure(1)
plot(x,y,'-b','linewidth',2) %affichage de x1 en fonction de t. La courbe en bleue continue d'épaisseur 3
xlabel("Longueur data set (nb élem)",'fontsize',14) %label sur l'axe x avec une police de 14
ylabel("Temps d'execution (s)",'fontsize',14)    % idem sur l'axe y
set(gca,'fontsize',14) % police des axes en 14
set(gcf,'color','white') %couleur de la fenêtre en blanc