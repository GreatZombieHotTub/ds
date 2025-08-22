#include<stdio.h>
int main(){
int a[100],i,j, n, small, id;
printf("enter number of elements");
scanf("%d", &n);
printf("enter array elements");
for(i=0; i<n;i++){
    scanf("%d",&a[i]);
}
//now sorting in ascending}
for(i=0; i<n-1; i++){
    small=a[i];
    id=i;
    for(j=i; j<n ;j++){
     if(a[j]<a[id]){
        small=a[j];
        id=j;
     }}
     a[id]=a[i];
     a[i]=small;
}
for(i=0; i<n;i++){
    printf("%d ",a[i]);
}
}
