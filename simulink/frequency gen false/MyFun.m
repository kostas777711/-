function [ Y ] = MyFun( x )
%UNTITLED1 Summary of this function goes here
%  Detailed explanation goes here
persistent S;

[r,c]=size(S);
if (~((r==1) & (c==3)))
    S=zeros(1,3);
end
S(1)=S(2);
S(2)=S(3);
S(3)=x;


a=S(1)+S(3);
p=2*S(2);
if p==0 
    Y=0;
else
    r=a/p;
    if r>1 
        Y=0;
    else
        Y=acos(r);
    end
end



