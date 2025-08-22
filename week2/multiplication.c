#include<stdio.h>
#include<stdlib.h>

void multiply(int **a,int **b,int **c, int m, int n, int q){
    for(int i=0;i<m;i++){
        for(int j=0; j<q; j++){
            *(*(c+i)+j)=0;
            for(int k=0; k<n;k++){
                *(*(c+i)+j)+=*(*(a+i)+k)**(*(b+k)+j);
            }
        }
    }
}


int main() {
int **a, **b, **c, m, n, p, q;
int i,j;

printf("enter array1 dimensions ");
scanf("%d",&m);
scanf("%d",&n);
a=(int **)malloc(m*sizeof(int *));
for(i=0; i<m; i++){
    *(a+i)=(int *)malloc(n*sizeof(int));}

printf("enter elements:");
for(i=0; i<m; i++){
    for(j=0; j<n; j++){
        scanf("%d", (*(a+i)+j));
    }
}


printf("enter array2 dimensions ");
scanf("%d",&p);
scanf("%d",&q);
b=(int **)malloc(p*sizeof(int *));
for(i=0; i<p; i++){
    *(b+i)=(int *)malloc(q*sizeof(int));}

printf("enter elements:");
for(i=0; i<p; i++){
    for(j=0; j<q; j++){
        scanf("%d", (*(b+i)+j));
    }
}
if(n==p){
c=(int **)malloc(m*sizeof(int *));
for(i=0; i<m; i++){
    *(c+i)=(int *)malloc(q*sizeof(int));}
multiply(a,b,c,m,n,q);
for(i=0; i<m; i++){
    for(j=0; j<q; j++){
        printf("%d ", *(*(c+i)+j));
    }
    printf("\n");
}
}
else{
    printf("multiplication not possible");
}
return 0;}
