#include<stdio.h>
int main(){
printf("this works");
//BUBBLE SORT, accept an array from user and sort it
int a[100],i,j, n, temp;
printf("enter number of elements");
scanf("%d", &n);
printf("enter array elements");
for(i=0; i<n;i++){
    scanf("%d",&a[i]);
}

//now sorting in ascending
for(i=0; i<n-1; i++){
    for(j=0; j<n-i-1; j++){
        if(a[j]>a[j+1]){
            temp=a[j+1];
            a[j+1]=a[j];
            a[j]=temp;
        }
    }
}

for(i=0; i<n;i++){
    printf("%d ",a[i]);
}
}
