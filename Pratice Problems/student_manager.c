#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[50];
    int age;
    char gender[10];
    int classNumber;
    struct Student *next;
} Student;

Student *head = NULL;

// Function to add a student
void addStudent(int id, const char *name, int age, const char *gender, int classNumber) {
    Student *s = malloc(sizeof(Student));
    s->id = id;
    strcpy(s->name, name);
    s->age = age;
    strcpy(s->gender, gender);
    s->classNumber = classNumber;
    s->next = head;
    head = s;
    printf("Student %s added successfully.\n", name);
}

// Function to delete a student by ID
void deleteStudent(int id) {
    Student *prev = NULL, *cur = head;
    while (cur && cur->id != id) {
        prev = cur;
        cur = cur->next;
    }
    if (!cur) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    if (prev) prev->next = cur->next;
    else head = cur->next;

    free(cur);
    printf("Student with ID %d deleted.\n", id);
}

// Function to search a student by ID
void searchStudent(int id) {
    Student *cur = head;
    while (cur) {
        if (cur->id == id) {
            printf("Student Found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nGender: %s\nClass: %d\n",
                   cur->id, cur->name, cur->age, cur->gender, cur->classNumber);
            return;
        }
        cur = cur->next;
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to display students by class
void displayByClass(int classNum) {
    Student *cur = head;
    int count = 0;
    printf("Students in Class %d:\n", classNum);
    while (cur) {
        if (cur->classNumber == classNum) {
            printf("ID: %d | Name: %s | Age: %d | Gender: %s\n",
                   cur->id, cur->name, cur->age, cur->gender);
            count++;
        }
        cur = cur->next;
    }
    if (count == 0) printf("No students found in Class %d.\n", classNum);
}

int main() {

    addStudent(101, "Alice", 14, "Female", 10);
    addStudent(102, "Bob", 15, "Male", 10);
    addStudent(103, "Charlie", 13, "Male", 9);
    addStudent(104, "Daisy", 14, "Female", 10);

    printf("\nSearching for ID 102 \n");
    searchStudent(102);

    printf("\n Deleting ID 103 \n");
    deleteStudent(103);

    printf("\n Display Class 10 \n");
    displayByClass(10);

    printf("\n Display Class 9 \n");
    displayByClass(9);

    return 0;
}