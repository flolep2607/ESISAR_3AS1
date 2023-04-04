clear all
close all
clc

n = -7:1:7;
Nfft = 2000;
ff=0:1/Nfft:1-1/Nfft;

htc = 1/2*sinc((1/2)*n);
HTCf=fft(htc,Nfft);

h_ham=htc.*hamming(15).';
Hf_ham = fft(h_ham,Nfft);

h= [ 1 1 0 0 1 1];
fid=[0 0.25 0.25 0.75 0.75 1];

figure
subplot(2,1,1)
plot(ff,abs(HTCf),'linewidth',2)
hold on 
plot(fid,h,'linewidth',2)
plot(ff,abs(Hf_ham),'--g')
legend('rectangular','ideal','Hamming')

xlabel('f/Fe')
subplot(2,1,2)
plot(ff,unwrap(angle(HTCf)))
xlabel('f/Fe')

figure
subplot(2,1,1)
plot(ff,20*log10(abs(HTCf)),'linewidth',2)
hold on 
plot(ff,20*log10(abs(Hf_ham)),'--g')
legend('rectangular','Hamming')

xlabel('f/Fe')
subplot(2,1,2)
plot(ff,unwrap(angle(HTCf)))
xlabel('f/Fe')