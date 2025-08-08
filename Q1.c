#include<stdio.h>
#include<stdlib.h>

//functions to len string, concat string, string comparison, insert, delete substring
int strlen(char *s){
    int len;
    while(*s++!='\0'){
        len++;}
    return len;
}

void strconcat(char *a, char *b){
    char *p; int i;
p=a;
while(*p!='\0'){
    p++;
}

while(*b!='\0'){
    *p=*b;
    b++; p++;
}
*p='\0';
}

void strequal(char *a, char *b){
    int i=0;
    while(a[i]==b[i] && (a[i]!='\0'&& b[i]!='\0')){
        i++;
    }
    i=0;
    if(a[i]==b[i]){
        printf("strings are identical \n");
    }
    else
        printf("different strings \n");
}

void insertsub(char *s, char *sub, int pos){
    int len1=0, len2=0,i=0;
    char *p=s;
    char *ps=sub;
    while(*p++!='\0'){
        len1++;}
    while(*ps++!='\0'){
        len2++;}
    while(i<len2){
        for(int j=len1; j>=pos;j--){
            s[j]=s[j-1];
        }
        s[pos-1]=sub[i];
        len1++; pos++; i++;}
    s[len1]='\0';

}


int delsub(char *s, char *sub) {
    int len1 = 0, len2 = 0, pos = -1;
    int flag;

    // Calculate lengths of s and sub
    while (s[len1] != '\0') len1++;
    while (sub[len2] != '\0') len2++;

    // Find first occurrence of sub in s
    for (int i = 0; i <= len1 - len2; i++) {
        flag = 1;
        for (int j = 0; j < len2; j++) {
            if (s[i + j] != sub[j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Substring not found\n");
        return 0;
    }

    // Correctly shift characters and null terminator
    int new_len = len1 - len2;
    for (int i = pos; i <= new_len; i++) {
        s[i] = s[i + len2];
    }

    // The previous loop already places the null terminator correctly, but
    // we can explicitly set it for clarity and robustness.
    // s[new_len] = '\0';

    return 1; // success
}
void main(){
    char a[30], b1[40], b2[20], c1[20], c2[20], d[20], sub1[20], e[20], sub2[20];
    int pos;
    printf("enter string to get length \n");
    gets(a);
    printf("length of string is %d ", strlen(a));


printf("\nenter 2 strings to concatenate: \n");
    gets(b1);
    gets(b2);
    strconcat(b1,b2);
    printf("concatenated strings:");
    puts(b1);


strequal("hridini", "hridini");
strequal("hridini", "Hridini");
printf("enter main, substring, insert pos: ");
gets(d);
gets(sub1);
scanf("%d", &pos);
 insertsub(d, sub1, pos);
 puts(d);

 printf("enter main, substring");
fgets(e, sizeof(e), stdin);
fgets;(sub2, sizeof(sub2), stdin);
 delsub(e, sub2);
 puts(e);
 }



