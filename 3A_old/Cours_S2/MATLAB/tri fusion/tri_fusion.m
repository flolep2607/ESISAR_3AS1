
function [Out] = tri_fusion(a)

n = length(a);

if n <= 1
  Out = a;
else
  Out = merge( tri_fusion( a(1 : floor(n/2)) ), tri_fusion( a(floor(n/2+1) : n) ) );
end

