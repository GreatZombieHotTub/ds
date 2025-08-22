#include<stdio.h>
int main(){
//INSERTION SORT, accept an array from user and sort it
int a[100],i,j, n, temp;
printf("enter number of elements");
scanf("%d", &n);
printf("enter array elements");
for(i=0; i<n;i++){
    scanf("%d",&a[i]);
}
temp=0;
for(i=1; i<n;i++){
    temp=a[i];
    j=i-1;
    while((j>=0) && (a[j]>temp)){
        a[j+1]=a[j];
        j=j-1;}
    a[j+1]=temp;}

for(i=0; i<n;i++){
    printf("%d ",a[i]);
}
}
