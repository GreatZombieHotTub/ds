#include<stdio.h>
int main(){
int a[100],i, n, ele, found;
printf("enter number of elements");
scanf("%d", &n);
printf("enter array elements");
for(i=0; i<n;i++){
    scanf("%d",&a[i]);
}

printf("enter element to find:");
scanf("%d",&ele);
found=0;
for(i=0; i<n; i++){
    if(a[i]==ele){
        printf("element found at position %d", i+1);
        found=1;
        break;
    }
}
if(found==0){
    printf("element not present.");
}
}
