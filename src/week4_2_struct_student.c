/*
 * week4_2_struct_student.c
 * Author: Anna Anaastasija Jansone
 * Student ID: 241ADC002
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and grade.
 *   Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h>

// TODO: Define struct Student with fields: name (char[]), id (int), grade (float)
// Example:
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    struct Student s1;
    struct Student s2;
    strcpy(&s1.name, "John"), s1.id = 420, s1.grade = 2;
    strcpy(&s2, "Stephany"), s2.id = 9/11, s2.grade = 52; 

    printf("Student 1 information:\nname: %1s\nid: %2d\ngrade: %3.2f\n\n", &s1.name, s1.id, s1.grade);
    printf("Student 2 information:\nname: %1s\nid: %2d\ngrade: %3.2f\n", &s2.name, s2.id, s2.grade);
    return 0;
}
