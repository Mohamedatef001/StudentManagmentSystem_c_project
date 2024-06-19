#ifndef STATMENTS_H_INCLUDED
#define STATMENTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;
typedef int int32;
typedef enum { false, true } bool;

struct student
{
    char first_name[10];
    char last_name[10];
    int id;
    float gpa;
    int num_of_courses;
};

void SDB_APP(struct student students[], int32 *i);
uint8 SDB_GetUsedSize(struct student students[], int32 *i);
bool SDB_AddEntry(struct student students[], int32 *i);
void SDB_DeletEntry (struct student students[], int32 *i);
bool SDB_ReadEntry (struct student students[], int32 *i);
void SDB_DeletEntry (struct student students[], int32 *i);
bool SDB_ReadEntry_By_First_Name (struct student students[], int32 *i);
void SDB_ReadEntry_By_Number_Of_Courses(struct student students[], int32 *i);
void SDB_UpdateData(struct student students[], int32 *i);


void SDB_UpdateData(struct student students[], int32 *i)
{
    printf("Enter the student iD you want to update : ");
    int z;
    scanf(" %d", &z);
    for (int a = 0; a < *i; a++)
    {
        if (students[a].id == z)
        {
            while (1)
            {
                printf("\n\nChoose what you want to update : ");
                printf("\n-> (1) First Name\n");
                printf("-> (2) last Name\n");
                printf("-> (3) iD\n");
                printf("-> (4) GPA\n");
                printf("-> (5) Number of courses taken\n");
                printf("-> (0) Done\n");
                printf("\n=> the option : ");
                int c;
                scanf(" %d", &c);
                if (c == 1)
                {
                    printf("Enter the new First Name : ");
                    scanf(" %s", students[a].first_name);
                }
                if (c == 2)
                {
                    printf("Enter the new Last Name : ");
                    scanf(" %s", students[a].last_name);
                }
                if (c == 3)
                {
                    printf("Enter the new iD : ");
                    int v;
                    scanf(" %d", &v);
                    for (int n = 0; n < *i; n++)
                    {
                        if (students[n].id == v)
                        {
                            printf("Error !!! Already existing iD !! enter a different iD => ");
                            scanf(" %d", &v);
                        }
                    }
                    students[a].id = v;
                }
                if (c == 4)
                {
                    printf("Enter the new GPA : ");
                    scanf(" %.2f", &students[a].gpa);
                }
                if (c == 5)
                {
                    printf("Enter the new number of registered courses : ");
                    scanf(" %d", &students[a].num_of_courses);
                }
                if (c == 0)
                {
                    break;
                }
            }
        }
    }
}

void SDB_ReadEntry_By_Number_Of_Courses(struct student students[], int32 *i)
{
    printf("Enter the number of courses taken : ");
    int b;
    scanf("%d", &b);
    printf("Please wait");
    fflush(stdout);

    for (int j = 0; j < 5; j++)
    {
        printf(".");
        fflush(stdout);
        Sleep(1);
    }
    printf("\n\n");
    for (int a = 0; a < *i; a++)
    {
        if (students[a].num_of_courses == b)
        {
            printf("Student (%d) : \n", a);
            printf("=> First Name : %s\n", students[a].first_name);
            printf("=> Last Name : %s\n", students[a].last_name);
            printf("=> iD : %d\n", students[a].id);
            printf("=> GPA : %.2f\n", students[a].gpa);
            printf("=> Number of Courses Taken : %d\n\n", students[a].num_of_courses);
        }
    }
}

bool SDB_ReadEntry_By_First_Name (struct student students[], int32 *i)
{
    printf("Enter the First Name : ");
            char b[10];
            scanf("%s", b);
            printf("Please wait");
            fflush(stdout);

            for (int j = 0; j < 5; j++)
            {
                printf(".");
                fflush(stdout);
                Sleep(1);
            }
            printf("\n\n");
            for (int a = 0; a < *i; a++)
            {
                if (strcmp(students[a].first_name, b) == 0)
                {
                    printf("Student (%d) : \n", a);
                    printf("=> First Name : %s\n", students[a].first_name);
                    printf("=> Last Name : %s\n", students[a].last_name);
                    printf("=> iD : %d\n", students[a].id);
                    printf("=> GPA : %.2f\n", students[a].gpa);
                    printf("=> Number of Courses Taken : %d\n\n", students[a].num_of_courses);
                    break;
                }
            }
}

void SDB_DeletEntry (struct student students[], int32 *i)
{
    printf("Enter the student iD you want to delete : ");
            int z;
            scanf(" %d", &z);
            printf("Please wait");
            fflush(stdout);

            for (int j = 0; j < 5; j++)
            {
                printf(".");
                fflush(stdout);
                Sleep(1);
            }
            printf("\n\n");
            for (int j = 0; j < *i; j++)
            {
                if (students[j].id == z)
                {
                    for (int k = j; k < (*i) - 1; k++)
                    {
                        students[k] = students[k + 1];
                    }
                    (*i)--;
                    break;
                }
            }
            printf("the student data is deleted successfully !\n\n");
}


bool SDB_ReadEntry  (struct student students[], int32 *i)
{
    printf("Enter the iD number : ");
                int z;
                scanf("%d", &z);
                printf("Please wait");
                fflush(stdout);

                for (int j = 0; j < 5; j++)
                {
                    printf(".");
                    fflush(stdout);
                    Sleep(1);
                }
                printf("\n\n");
                for (int a = 0; a < *i; a++)
                {
                    if (students[a].id == z)
                    {
                        printf("the data of student with iD %d : \n\n", z);
                        printf("=> First Name : %s\n", students[a].first_name);
                        printf("=> Last Name : %s\n", students[a].last_name);
                        printf("=> iD : %d\n", students[a].id);
                        printf("=> GPA : %.2f\n", students[a].gpa);
                        printf("=> Number of Courses Taken : %d\n\n", students[a].num_of_courses);
                        break;
                    }
                }
                return 1;
}
uint8 SDB_GetUsedSize(struct student students[], int32 *i)
{
    if (students[0].id != 0 || students[0].first_name[0] != '\0')
    {
        return *i;
    }
    else
    {
        return 0;
    }
}

bool SDB_AddEntry(struct student students[], int32 *i)
{
    printf("\nEnter the student's First Name : ");
    scanf(" %s", students[*i].first_name);
    printf("Enter the student's Last Name : ");
    scanf(" %s", students[*i].last_name);
    printf("Enter the student's ID : ");
    scanf(" %d", &students[*i].id);
    printf("Enter the student's GPA : ");
    scanf(" %f", &students[*i].gpa);
    printf("Enter the registered number of courses : ");
    scanf(" %d", &students[*i].num_of_courses);
    printf("\n\n Thank you for the registration\n");
    printf("the student data is added successfully\n\n");
    (*i)++;
    return true;
}

void SDB_APP(struct student students[], int32* i)
{
    while (1)
    {
        printf("\t\t Class Management System\n\n");
        printf("\t\t Welcome to the System\n\n");
        printf("Please Choose an option :\n\n");
        printf("=> (1) Add the student details.\n");
        printf("=> (2) Find the student details by ID number.\n");
        printf("=> (3) Find the student details by first name.\n");
        printf("=> (4) Find the student details by number of courses taken.\n");
        printf("=> (5) Get the total students number.\n");
        printf("=> (6) Delete the student details.\n");
        printf("=> (7) Update the student details.\n");
        printf("=> (8) Exit the program.\n\n");
        printf("=>  Option : ");
        int x;
        scanf(" %d", &x);

        switch (x)
        {
        case 1:
            SDB_AddEntry(students, i); // To add entry
            break;
        case 2:
            SDB_ReadEntry(students, i);
            break;
        case 3:
            SDB_ReadEntry_By_First_Name (students, i);
            break;
        case 4:
            SDB_ReadEntry_By_Number_Of_Courses(students, i);
            break;
        case 5:
            printf("\nThe total number of students: %d\n\n", SDB_GetUsedSize(students, i)); // To get used size in database
            break;
        case 6:
            SDB_DeletEntry(students, i); // To delete student data
            break;
        case 7:
            SDB_UpdateData(students, i);
            break;
        case 8:
            exit(0); // To exit
        }

        printf("\nDo you want to continue? [1] => Yes - [0] => No   Ans : ");
        int y;
        scanf(" %d", &y);
        if (y == 0)
        {
            break;
        }else if(y == 1)
        {
            system("cls"); 
        }
    }
}

#endif
