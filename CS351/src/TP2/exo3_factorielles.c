#include <stdio.h>

int factorielle(int n)
{
    int result=1;
    for(int i=1;i<=n;i++){
        result*=i;
    }
    return result;
}
int factoriellebis(int m)
{
    int result=1;
    int index=1;
    while(result<=m){
        index++;
        result*=index;
    }
    return index;
}

int main()
{
    int n;
    printf("n!:");
    scanf("%d",&n);
    printf("%d\n", factorielle(n));
    printf("%d\n", factoriellebis(factorielle(n)));
    return 0;
}
