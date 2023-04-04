
function [Out] = tri_insertion(L)

n = length(L);

for j = 2:n
    
    x = L(j);
    i = j-1;
    while(i>0 && L(i) > x)
        
        L(i+1) = L(i);
        i=i-1;
        
    end
    
    L(i+1)=x;
    
end

Out = L;

end