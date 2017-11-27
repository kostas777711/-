function [ Y ] = RFS02( S,Fin,Fs,Gain )
%Calculates the average of 1 or more triplettes
%  Detailed explanation goes here

% Samples Store
persistent X;
persistent Acc;
persistent Accx;
% Initialize
[r,c]=size(X);
if (~((r==1) & (c==13)))
    X=zeros(1,13);
    Acc=zeros(1,3);
end
%Shift
X(2:13)=X(1:12);

X(1)=S;
erx=0;
for i=0:2
    %Calculations
    n=X(1)+X(3+2*i);
    d=2*X(2+i);
    band=floor(2*Acc(1)*(i+1)/(Fs));

    if ( (d==0) | (abs(n)>abs(d)) )
        Fc=Fin;
        w=0;
        a=0;
    else
        a=acos(n/d)/pi;
        
        Fc=(band + (1/2) + ((-1)^band)*( (a) - (1/2) ))*(Fs/(2*(i+1)));
        %w=abs(X(2+i));
        w=(X(2+i)^2)*(0+a*(1-a));
        %w=(X(2+i)^2);
    end
    tEr(i+1)=(Fin-Fc)*w*Gain;
    erx=erx+tEr(i+1);
    [i,Fc,band,a,w,erx];
end
Acc(1)=Acc(1)+erx;
%Acc(2)=Acc(2)+Acc(1)+1*erx;
tY=Acc(1);
band=floor(2*Fin*(1)/(Fs));

if tY<(band+0.01)*Fs/2
     tY=(band+0.01)*Fs/2;
end
if tY>(band+0.99)*Fs/2
     tY=(band+0.99)*Fs/2;
end

Y=tY;




