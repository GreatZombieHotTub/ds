#include <stdio.h>
#include <string.h>

// structure definition
struct Student {
    char name[50];
    int roll_no;
    float marks;
};

// function to read student details
void read_students(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %s", (s + i)->name);  // pointer notation
        printf("Roll No: ");
        scanf("%d", &(s + i)->roll_no);
        printf("Marks: ");
        scanf("%f", &(s + i)->marks);
    }
}

// function to display student details
void display_students(struct Student *s, int n) {
    printf("\n--- Student Details ---\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll No: %d, Marks: %.2f\n", 
               (s + i)->name, (s + i)->roll_no, (s + i)->marks);
    }
}

// function to find student with highest marks
void find_topper(struct Student *s, int n) {
    int top_index = 0;
    for (int i = 1; i < n; i++) {
        if ((s + i)->marks > (s + top_index)->marks) {
            top_index = i;
        }
    }
    printf("\n--- Topper ---\n");
    printf("Name: %s, Roll No: %d, Marks: %.2f\n", 
           (s + top_index)->name, (s + top_index)->roll_no, (s + top_index)->marks);
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];      // array of structures
    struct Student *ptr = s;  // pointer variable pointing to array

    // pass pointer instead of &s
    read_students(ptr, n);
    display_students(ptr, n);
    find_topper(ptr, n);

    return 0;
}
