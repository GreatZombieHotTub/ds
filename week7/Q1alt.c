//this code is correct
#include <stdio.h>
#include <stdlib.h>

int main(){
char s[100];
char stack[100];
int top=-1;
char c;

printf("enter string: ");
scanf("%s",s);
while(s[len]!='\0'){
    len++;
}

for(int i=0; i<len; i++){
    c=s[i];
    if((c=='(') || (c=='{') (c=='[')){
        if(i==len-1) {printf("stack overflow"); break;}
        else stack[top++]c;
       }
    else {
        if(top==-1) {printf("stack undeflow"); break;}
        else if(((c==')')&& stack[top]=='(') || ((c=='}')&& (c=='}')) || ((c==']')&&(c=='[')) top-=1;
        else{
            printf("unbalanced");
            break;
        }
}
}

return 0; }
