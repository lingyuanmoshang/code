#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    char c;
    scanf("%d %c",&n,&c);
    int m=(n/2.0+0.5);
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            printf("%c",c);
        }
        puts("");
    }
    return 0;
}
