#include <stdio.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int rollNumber;
    char name[NAME_LENGTH];
    float mark;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent(void) {
    Student student;

    if (studentCount >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }

    printf("Enter roll number: ");
    if (scanf("%d", &student.rollNumber) != 1) {
        printf("Invalid roll number.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == student.rollNumber) {
            printf("This roll number already exists.\n");
            return;
        }
    }

    printf("Enter student name: ");
    if (scanf(" %49[^\n]", student.name) != 1) {
        printf("Invalid name.\n");
        return;
    }

    printf("Enter mark (0-100): ");
    if (scanf("%f", &student.mark) != 1 ||
        student.mark < 0 || student.mark > 100) {
        printf("Invalid mark. Enter a value from 0 to 100.\n");
        return;
    }

    students[studentCount++] = student;
    printf("Student added successfully!\n");
}

void viewStudents(void) {
    if (studentCount == 0) {
        printf("No student records available.\n");
        return;
    }

    printf("\n%-12s %-25s %s\n", "Roll Number", "Name", "Mark");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-12d %-25s %.2f\n",
               students[i].rollNumber, students[i].name, students[i].mark);
    }
}

void searchStudent(void) {
    int rollNumber;
    printf("Enter roll number to search: ");
    if (scanf("%d", &rollNumber) != 1) {
        printf("Invalid roll number.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Name: %s\n", students[i].name);
            printf("Mark: %.2f\n", students[i].mark);
            return;
        }
    }
    printf("Student not found.\n");
}

void showAverage(void) {
    if (studentCount == 0) {
        printf("No marks available to calculate an average.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < studentCount; i++) {
        total += students[i].mark;
    }
    printf("Class average: %.2f\n", total / studentCount);
}

int main(void) {
    int choice;

    while (1) {
        printf("\n=== Student Grade Manager ===\n");
        printf("1. Add student\n");
        printf("2. View all students\n");
        printf("3. Search by roll number\n");
        printf("4. Show class average\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a number.\n");
            return 1;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: showAverage(); break;
            case 5: printf("Goodbye!\n"); return 0;
            default: printf("Invalid option. Try again.\n");
        }
    }
}
