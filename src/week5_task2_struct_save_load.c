// week5_task2_struct_save_load.c
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming
// TODO: Complete function implementations and file handling logic.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student.txt";

    printf("Saving student to file...\n");
    save_student(s1, filename);

    printf("Loading studdent from flie...\n");
    Student loaded = load_student(filename);

    printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age, loaded.gpa);

    return 0;
}

void save_student(Student s, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%s %d %.2f\n", s.name, s.age, s.gpa);

    fclose(fp);
}

Student load_student(const char *filename) {
    Student s;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    if (fscanf(fp, "%49s %d %f", s.name, &s.age, &s.gpa) != 3) {
        fprintf(stderr, "Error: Invalid file format.\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    return s;
}
