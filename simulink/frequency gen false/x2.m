function [ y0 ] = x2( x )
%X2 Summary of this function goes here
%  Detailed explanation goes here
persistent S;

[r,c]=size(S);
if (~((r==1) & (c==3)))
    S=zeros(1,3);
end
S(1)=S(2);
S(2)=S(3);
S(3)=x;

y0=S(2);

