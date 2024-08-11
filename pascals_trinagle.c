#include<stdio.h>
int main(){
    int n,i,j;
    printf("enter the value of n:");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        for ( j = i; j <=n ; j++)
        {
            printf(" ");
        }
        int count=1;
        for ( j = 0; j <= i; j++)
        {
            printf("%d ",count);
            count=count*(i-j)/(j+1);
        }
        printf("\n");
        
    }
    
}