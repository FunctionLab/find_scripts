function b=nondecreaseset(a)

n=length(a);
b=a;
b(n)=a(n);
i=n-1;
while i>=1
    if(a(i)>b(i+1))
        b(i)=a(i);
        
    else
        b(i)=b(i+1);
    end
i=i-1;
end