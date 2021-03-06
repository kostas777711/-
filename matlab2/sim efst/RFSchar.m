function [ Y ] = RFSchar( S,Fin,Fs,Gain )
%Calculates the average of 1 or more triplettes
%  Detailed explanation goes here

% Samples Store
persistent X;
persistent Acc;
persistent Accx;
% Initialize
[r,c]=size(X);
if (~((r==1) & (c==3)))
    X=zeros(1,3);
    Acc=0;
    Accx=0;
end
%Shift
X(2:3)=X(1:2);

X(1)=S;
%Calculations
n=X(1)+X(3);
d=2*X(2);
band=floor(2*Fin/(Fs));

if ( (d==0) | (abs(n)>abs(d)) )
    Fc=Fin;
    w=0;
else
    a=acos(n/d)/pi;
    Fc=(band + (1/2) + ((-1)^band)*( (a) - (1/2) ))*(Fs/2);
    %w=abs(X(2));
    %w=(X(2)^2)*(0+a*(1-a));
    w=(X(2)^2);%*((X(1)^2)+(X(3)^2));
end
erx=(Fin-Fc)*w*Gain;
Acc=Acc+erx;
Accx=Accx+Acc+1*erx;
if Accx<(band+0.01)*Fs/2
    Accx=(band+0.01)*Fs/2;
end
if Accx>(band+0.99)*Fs/2
    Accx=(band+0.99)*Fs/2;
end

Y=erx;




