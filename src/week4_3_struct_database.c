/*
 * week4_3_struct_database.c
 * Author: Anna Anaastasija Jansone
 * Student ID: 241ADC002
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    students = malloc(sizeof(struct Student) * n);

    for(int i = 0; i < n; ++i)
    {
        printf("Please, enter Student %d, name\n", i + 1);
        scanf("%s", &students[i].name);
        printf("Please, enter Student %d, id\n", i + 1);
        scanf("%d", &students[i].id);
        printf("Please, enter Student %d, grade\n", i + 1);
        scanf("%f", &students[i].grade);
        printf("\n");
    }

    for(int i = 0; i < n; ++i)
    {
        printf("Student %1d information:\nname: %2s\nid: %3d\ngrade: %4.2f\n\n",
            i + 1, &students[i].name, students[i].id, students[i].grade);
    }

    struct Student* topStudent = students;
    float sum = 0;
    float average = 0;
    for(int i = 0; i < n; ++i)
    {
        sum += students[i].grade;
        if(topStudent->grade < students[i].grade)
            topStudent = &students[i]; 
    }
    average = (double)sum/(double)n;
    printf("Average grade: %f\n\n", average);
    printf("Best student information:\nname: %1s\nid: %2d\ngrade: %3.2f\n\n",
            &topStudent->name, topStudent->id, topStudent->grade);
    free(students);
    // Optional: Compute average grade or find top student

    // TODO: Free allocated memory

    return 0;
}
