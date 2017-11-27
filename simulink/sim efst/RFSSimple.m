function [ Y ] = RFSSimple( S,Fin,Fs )
%Calculates the average of 1 or more triplettes
%  Detailed explanation goes here

% Samples Store
persistent X; %array of samples
persistent LY;
persistent Lm;

% Initialize
[r,c]=size(X);
if (~((r==1) & (c==3)))
    X=zeros(1,3);
    LY=0;
    Lm=0;
end
%Shift
X(2:3)=X(1:2); %do the shift

X(1)=S;
    %Calculations
n=X(1)+X(3);
d=2*X(2);
band=floor(2*Fin/(Fs));

if ( (d==0) | (abs(n)>abs(d)) )
    Y(1)=LY;
    Y(2)=Lm*0.7;
else
    a=acos(n/d)/pi;
    
    Y(1)=Fin-(band + (1/2) + ((-1)^band) * (a - (1/2)) )*(Fs/2);
    %w=abs(X(2+i));
    %w=(X(2+i)^2)*(0+a*(1-a));
    Y(2)=(X(2)^2);
    %Y(2)=abs(X(2));
    
    LY=Y(1);
    Lm=Y(2);
end




