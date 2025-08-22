#include<stdio.h>
#include<stdlib.h>

//accept dynamically allocated array. make function to return smallest element
int small(int *p,int n){
 int small=*(p);
 for(int i=1;i<n;i++){
    if(*(p+i)<small){
        small=*(p+i);}}
 return small; }

int main() {
int *a, n;

printf("enter number of elements: ");
scanf("%d",&n);

a=(int *)malloc(n*sizeof(int));
if(a==NULL){
    printf("memory not allocated!");
    return 1;
}
int *p=a;
printf("enter elements:");
for(int i=0; i<n; i++){
    scanf("%d", a+i);
}

printf("smallest element= %d",small(a,n));
free(a);
return 0;}
