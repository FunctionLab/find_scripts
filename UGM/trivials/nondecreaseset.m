function k=nondecreaseset(a)

n=1;
temp=a(n);
k(1)=1;
i=2;
while n<length(a)
    n=n+1;
    if(a(n)>temp)
        k(i)=n;
        i=i+1;
         temp=a(n);
    end;

end;