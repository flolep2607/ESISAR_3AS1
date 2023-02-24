%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%                       EXAMEN DE TP MA 361
%  Duree : 1h30
%  Sans documents, sans calculatrice, sans accès internet
%
% Nom :
%
% Prenom : 
%
% Consignes : 
%       - le script matlab ou octave doit être enregistre sous le format : Nom.m
%       - repondre directement dans le script avec des commentaires 
%       - Commenter chaque ligne de votre script exemple :
%             a = 10 ; % a : frequence du signal x(t)
%       - affichage : les courbes doivent être lisibles avec une legende si
%       plusieurs courbes sur un même graphique
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Fonction utiles (utilisez l'aide pour en savoir plus):
%
% find(A==ii) : trouver l'indice d'un element ii dans un vecteur A
% plot : affichage 2D
% zeros : vecteur de 0
% ones : vecteur de 1
% max : maximum d'un vecteur
% log : logarithme neperien (ln)
% log10 : ln base 10
% sum : somme 
% spectrogram (Matlab) / specgram (Octave) : calcul et affiche le sprectrogramme
% blackman : fenêtre de ponderation de blackman
% rectwin : fenêtre de ponderation rectangle
% hamming : fenêtre de ponderation de hamming
% sinc : sinus cardinal
% filter : applique le filter à un signal
% selection d'une partie d'un vecteur : a(ii:jj)
%
% exemple de figure avec subplot: 
% figure(ii)
% subplot(2,1,1)
% plot(A,B,'-b','linewidth',3)
% xlabel('frequence (Hz)','fontsize',14)
% ylabel('Y(f)','fontsize',14)
% set(gca,'fontsize',14)
% subplot(2,1,2)
% plot(A,C,'-r','linewidth',3)
% xlabel('frequence (Hz)','fontsize',14)
% ylabel('Z(f)','fontsize',14)
% set(gca,'fontsize',14)
% set(gcf,'color','white')

%%
clear all
close all 
clc
%
%% Etude d'un signal 

% 1. Creez et affichez un signal z(t) representant une cosinusoïde 
% de frequence 10 kHz  de duree 1 millisecondes. Vous prendrez une
% frequence d'echantillonnage de 10 fois la limite de Shannon




% 2. calculez l'energie du signal z(t)



% 3. calculez la puissance du signal z(t)



% 4. a. tracez le module du spectre de z(t) sur 1000 points grâce à la
% technique de prolongement par des zeros.







%    b. Quel est l'interêt de cette technique?






%   c. la frequence du signal obtenue grâce au spectre est-elle correcte?

 

%% modulation d'amplitude 

%5. Nous allons à present moduler le signal z(t) par un signal cosinusoidal
% p(t) de frequence 25 kHz.
% le signal module est egal à : m(t) = p(t) x z(t) avec x la multiplication
% tracer le signal m(t)






%6. a. tracez le module du spectre de m(t) sur 1000 points en utilisant un
%prolongement par des zeros





% b. Justifiez les frequences contenues dans le spectre.




%7. Nous allons à present demodule le signal m(t). Pour cela il faut
%d'abord multiplie le signal m(t) par la porteuse p(t). Nous appelerons ce
%signal zm(t).

% a. tracez le spectre de zm(t). 





% b. Quelle operation est necessaire pour obtenir z(t)?


%% filtre passe-bas 

% 8. En utilisant la methode de la fenêtre (decrite dans le cours), 
% determinez theoriquement la reponse impulsionnelle h(n) d’un filtre 
% RIF passe-bas ideal de frequence de coupure 15kHz. Le nombre de coefficients est fixe à 51 
% La frequence d'echantillonnage est celle de la question 1. La fenêtre de ponderation est un fenêtre rectangle.
%
% Affichez la reponse impulsionnelle en fonction du temps puis le module en dB et
% la phase de la fonction de transfert en fonction de la frequence.




%9. Appliquez le filtre au signal zm(t). 

% a. Tracez le signal et le module du spectre du signal en sortie du filtre. 




% b. Lafrequence du signal est-elle coherente avec ce que vous attendiez?




% c. Expliquez le phenomène qui apparait au debut du signal temporel entre t= 0 et t = 0.1 ms.


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Bonus %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%10. Refaite le filtre de la question 9 en utilisant une fenêtre de
% hamming. Affichez le module de la fonction de transfert du filtre en
% fonction de la frequence.







