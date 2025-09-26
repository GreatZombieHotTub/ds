//this code is corrrect

#include <stdio.h>
#include <stdlib.h>

int main(){
char s[100];
char stack[100];
int top=-1, len=0;
char c;

printf("enter string: ");
scanf("%s",s);
while(s[len]!='\0'){
    len++;
}
for(int i=0; i<len; i++){
    c=s[i];
    if(top==-1){
        stack[top++]=c;
    }
    else if(stack[top]==c) top-=1;
    else if(top>=99)printf("stack overflow");
    else stack[top++]=c;
}

if(top==-1){
    printf("its a palindrome");
}
else printf("not a palindrome");

return 0;

https://github.com/Abhijeet-Chandra/DS-Lab
