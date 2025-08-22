#include<stdio.h>
int main(){
int a[100],i, n, key, found, ll, ul;
printf("enter number of elements");
scanf("%d", &n);
printf("enter array elements");
for(i=0; i<n;i++){
    scanf("%d",&a[i]);
}
//ONLY FOR A SORTED LIST
printf("enter element to find:");
scanf("%d",&key);
found=0;
ll=0; ul=n-1;
int mid=0;
while(ll<ul && ll>=0){
    mid=(ll+ul)/2;
    if(key<=a[mid]) ul=mid;
    else ll=mid;
    if(key==a[mid]){
    printf("element found at position %d", mid+1);
    break;}

}

}
