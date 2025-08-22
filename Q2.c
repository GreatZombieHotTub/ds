#include<stdio.h>
#include<stdlib.h>

struct student{ //store name, roll no, grade
    char name[30];
    int roll;
    char grade[2];
};

void read(struct student s[], int n){
 printf("enter student data: \n");
 for(int i=0; i<n; i++){
        printf("enter name, roll no. and grade: ");\
        scanf("%s", s[i].name);
        scanf("%d", &s[i].roll);
        scanf("%s", s[i].grade);

 }}

void display(struct student s[], int n){
    printf("student data: ");
    for(int i=0; i<n; i++){
        printf("name: %s \t", s[i].name);
        printf("roll no. %d \t", s[i].roll);
        printf("grade:  %s \n", s[i].grade);
    }
}

void sort(struct student s[],int n)
{int i,j,ps; struct student t;
for(i=0;i<n-1;i++)
{ps=i;
for(j=i+1;j<n;j++)
if(s[ps].roll>s[j].roll)
{ps=j;
}
t=s[ps];
s[ps]=s[i];
s[i]=t; } }

void main(){
    struct student s[20];
    int n;
    printf("enter no. of students: ");
    scanf("%d", &n);
    read(s,n);
    printf("after sorting: \n");
    sort(s,n);
    display(s,n);


}
