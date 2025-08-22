#include<stdio.h>
#include<stdlib.h>

//sort using selection sort algorithm, use pointers, display sorted array

int selsort(int *arr, int start,int n){
if(start>=n-1){
    return 1;}
int i,j;
int *p=arr;
int small= *(p+start);
for(i=start+1; i<n; i++){
    if(small> *(p+i)){
    small=*(p+i);
    j=i;}
}
if(*(p+start)!=small){
*(p+j)=*(p+start);
*(p+start)=small;
selsort(p, start+1,n);}}



int main() {
int *a, n,i;

printf("enter number of elements: ");
scanf("%d",&n);

a=(int *)malloc(n*sizeof(int));
if(a==NULL){
    printf("memory not allocated!");
    return 1;
}
printf("enter elements:");
for(i=0; i<n; i++){
    scanf("%d", (a+i));
}
selsort(a, 0, n);
for(i=0;i<n; i++){
    printf("%d ", *(a+i));
}
free(a);
return 0;}
