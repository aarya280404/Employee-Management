// C program for the above approach

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include<conio.h>
// In the start coordinates
// will be 0, 0

COORD cord = {0, 0};

// function to set the
// coordinates

void gotoxy(int x, int y)
{
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}

FILE *fp, *ft;
// Function to add the records

// Structure of the employee
struct emp
{
    char name[50];
    int age;
    int id;

    struct date
    {
        int day;
        int month;
        int year;
    } date_of_joining;
    char dept[50];
};

struct emp e;

// size of the structure
long int size = sizeof(e);
void addrecord1()
{
    system("cls");
    fseek(fp, 0, SEEK_END);
    char another = 'y';
    while (another == 'y')
    {
        printf("\nEnter Name : ");
        scanf("%s", e.name);

        printf("\nEnter Age : ");
        scanf("%d", &e.age);

        printf("\nEnter EMP-ID : ");
        scanf("%d", &e.id);

        printf("\nEnter Date in (dd mm yyyy)format : ");
        scanf("%d %d %d",
              &e.date_of_joining.day, &e.date_of_joining.month, &e.date_of_joining.year);

        printf("\nEnter the department : ");
        scanf("%s", e.dept);

        fwrite(&e, size, 1, fp);
        printf("\nWant to add another"
               " record (Y/N) : ");

        fflush(stdin);
        scanf("%c", &another);
    }
}

// Function to delete the records

void deleterecord1()
{
    system("cls");
    char empname[50];
    char another = 'y';
    while (another == 'y')
    {
        printf("\nEnter employee "
               "name to delete : ");
        scanf("%s", empname);
        ft = fopen("temp1.txt", "wb");
        rewind(fp);
        while (fread(&e, size,
                     1, fp) == 1)
        {
            if (strcmp(e.name,
                       empname) != 0)
                fwrite(&e, size, 1, ft);
        }
        fclose(fp);
        fclose(ft);
        remove("demo.txt");
        rename("temp1.txt", "demo.txt");
        fp = fopen("demo.txt", "rb+");
        printf("\nWant to delete another"
               " record (Y/N) :");
        fflush(stdin);
        another = getche();
    }
}

// Function to display the record

void displayrecord1()
{
    system("cls");

    // sets pointer to start
    // of the file

    rewind(fp);

    printf("\n========================="
           "==================================================="
           "======");

    printf("\nNAME\t\tAGE\t\tID\t\t"
           "DOJ\t\tDEPARTMENT\n",
           e.name, e.age, e.id,
           e.date_of_joining, e.dept);

    printf("==========================="
           "==================================================="
           "====\n");

    while (fread(&e, size, 1, fp) == 1)

        printf("\n%s\t\t%d\t\t%d\t\t%d-%d-%d\t\t%s", e.name, e.age, e.id,
               e.date_of_joining.day, e.date_of_joining.month, e.date_of_joining.year, e.dept);

    printf("\n\n\n\t");
    system("pause");
}

// Function to modify the record

void modifyrecord1()
{
    system("cls");
    char empname[50];
    char another = 'y';
    while (another == 'y')
    {
        printf("\nEnter employee name"
               " to modify : ");
        scanf("%s", empname);
        rewind(fp);

        // While File is open

        while (fread(&e, size, 1, fp) == 1)
        {
            // Compare the employee name
            // with ename

            if (strcmp(e.name, empname) == 0)
            {
                printf("\nEnter Name : ");
                scanf("%s", e.name);

                printf("\nEnter Age : ");
                scanf("%d", &e.age);

                printf("\nEnter EMP-ID : ");
                scanf("%d", &e.id);

                printf("\nEnter Date in (dd mm yyyy)format : ");
                scanf("%d %d %d",
                      &e.date_of_joining.day, &e.date_of_joining.month, &e.date_of_joining.year);

                printf("\nEnter the department : ");
                scanf("%s", e.dept);

                fseek(fp, -size, SEEK_CUR);
                fwrite(&e, size, 1, fp);
                break;
            }
        }

        // Ask for modifying another record

        printf("\nWant to modify another"
               " record (Y/N) :");
        fflush(stdin);
        scanf("%c", &another);
    }
}

// Structure of the employee

struct emp2
{
    char name[50];
    int base;
    int tax;
    int bonus;
    float salary;
};
struct emp2 a;

// size of the structure

long int size2 = sizeof(a);

FILE *fp, *ft;

// Function to add the records

void addrecord2()
{
    system("cls");
    fseek(fp, 0, SEEK_END);
    char another = 'y';
    while (another == 'y')
    {
        printf("\nEnter Name : ");
        scanf("%s", a.name);

        printf("\nEnter Base Salary : ");
        scanf("%d", &a.base);

        printf("\nEnter Tax Percent : ");
        scanf("%d", &a.tax);

        printf("\nEnter Bonus : ");
        scanf("%d", &a.bonus);

        int c = a.base - (a.base * (a.tax / 100.0));
        a.salary = c + (a.bonus);
        fwrite(&a, size, 1, fp);
        printf("\nWant to add another"
               " record (Y/N) : ");
        fflush(stdin);
        scanf("%c", &another);
    }
}

// Function to delete the records

void deleterecord2()
{
    system("cls");
    char empname[50];
    char another = 'y';
    while (another == 'y')
    {
        printf("\nEnter employee "
               "name to delete : ");
        scanf("%s", empname);

        ft = fopen("temp.txt", "wb");
        rewind(fp);
        while (fread(&a, size,
                     1, fp) == 1)
        {
            if (strcmp(a.name,
                       empname) != 0)
                fwrite(&a, size, 1, ft);
        }
        fclose(fp);
        fclose(ft);
        remove("data.txt");
        rename("temp.txt", "data.txt");
        fp = fopen("data.txt", "rb+");
        printf("\nWant to delete another"
               " record (Y/N) :");
        fflush(stdin);
        another = getche();
    }
}

// Function to display the record

void displayrecord2()
{
    system("cls");

    // sets pointer to start
    // of the file

    rewind(fp);
    a.salary = (a.base - ((a.tax / 100) * a.base)) + a.bonus;

    printf("\n========================="
           "==========================="
           "=========");

    printf("\nNAME\t\tBASE SALARY\tTAX\tBonus"
           "\tIn-Hand Salary\n",
           a.name, a.base,
           a.tax, a.bonus, a.salary);

    printf("==========================="
           "==========================="
           "=======\n");

    while (fread(&a, size, 1, fp) == 1)
        printf("\n%s\t\t%d\t\t%d\t%d\t%.2f",
               a.name, a.base, a.tax, a.bonus, a.salary);
    printf("\n\n\n\t");
    system("pause");
}

// Function to modify the record

void modifyrecord2()
{
    system("cls");
    char empname[50];
    char another = 'y';
    while (another == 'y')
    {
        printf("\nEnter employee name"
               " to modify : ");
        scanf("%s", empname);
        rewind(fp);

        // While File isopen

        while (fread(&a, size, 1, fp) == 1)
        {
            // Compare the employee name
            // with ename

            if (strcmp(a.name, empname) == 0)
            {
                printf("\nEnter new name:");
                scanf("%s", a.name);

                printf("\nEnter new salary :");
                scanf("%d", &a.base);

                printf("\nEnter new tax :");
                scanf("%f", &a.tax);

                printf("\nEnter new bonus :");
                scanf("%d", &a.bonus);

                a.salary = (a.base - ((a.tax / 100) * a.base)) + a.bonus;
                fseek(fp, -size, SEEK_CUR);
                fwrite(&a, size, 1, fp);
                break;
            }
        }

        // Ask for modifying another record

        printf("\nWant to modify another"
               " record (Y/N) :");
        fflush(stdin);
        scanf("%c", &another);
    }
}

// Structure of the employee

struct emp3
{
    char name[50];
    int day;
    char month[20];
    int year;
    int no_of_days;
    int end_of_leave;
    int id;
};
struct emp3 b;

// size of the structure

long int size3 = sizeof(b);

FILE *fp, *ft;

// Function to add the records

void addleave3()
{
    system("cls");
    fseek(fp, 0, SEEK_END);
    char another = 'y';

    while (another == 'y')
    {
        printf("\nEnter Name : ");
        scanf("%s", b.name);

        printf("\nEnter date of leave : ");
        scanf("%d", &b.day);

        printf("\nEnter month of leave : ");
        scanf("%s", b.month);

        printf("\nyear of leave : ");
        scanf("%d", &b.year);

        printf("\nEnter no. of days of leave : ");
        scanf("%d", &b.no_of_days);

        printf("\nLast date of leave : ");
        scanf("%d", &b.end_of_leave);

        fwrite(&b, size, 1, fp);

        printf("\nWant to add another"
               " record (Y/N) : ");
        fflush(stdin);

        scanf("%c", &another);
    }
}

// Function to delete the records

void deleteleave3()
{
    system("cls");
    char empname[50];
    char another = 'y';
    while (another == 'y')
    {
        printf("\nEnter employee "
               "name to cancel applied leave : ");
        scanf("%s", empname);

        ft = fopen("temp1.txt", "wb");
        rewind(fp);

        while (fread(&b, size,
                     1, fp) == 1)
        {
            if (strcmp(b.name,
                       empname) != 0)
                fwrite(&b, size, 1, ft);
        }

        fclose(fp);
        fclose(ft);
        remove("data1.txt");
        rename("temp1.txt", "data1.txt");
        fp = fopen("data1.txt", "rb+");
        printf("\nWant to delete another"
               " record (Y/N) :");
        fflush(stdin);
        another = getche();
    }
}

// Function to display the record

void displayleave3()
{
    system("cls");

    // sets pointer to start
    // of the file

    rewind(fp);

    printf("\n========================="
           "==========================="
           "========================================");

    printf("\nNAME\t\tDOL\t\tMONTH\t\tYEAR\t\tNO OF DAYS\tEND OF LEAVE"
           "\n",
           b.name, b.day, b.month, b.year, b.no_of_days, b.end_of_leave);

    printf("==========================="
           "==========================="
           "========================================\n");

    while (fread(&b, size, 1, fp) == 1)
        printf("\n%s\t\t%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t",
               b.name, b.day, b.month, b.year, b.no_of_days, b.end_of_leave);
    printf("\n\n\n\t");
    system("pause");
}

// Function to modify the record

void modifyleave3()
{
    system("cls");
    char empname[50];
    char another = 'y';
    while (another == 'y')
    {
        printf("\nEnter employee name"
               " to modify : ");
        scanf("%s", empname);

        rewind(fp);

        // While File is open

        while (fread(&b, size, 1, fp) == 1)
        {
            // Compare the employee name
            // with ename

            if (strcmp(b.name, empname) == 0)
            {
                printf("\nEnter new date:");
                scanf("%d", b.day);

                printf("\nEnter new duration :");
                scanf("%d", &b.no_of_days);

                printf("\nEnter new last date of leave :");
                scanf("%d", &b.end_of_leave);

                fseek(fp, -size, SEEK_CUR);
                fwrite(&b, size, 1, fp);
                break;
            }
        }

        // Ask for modifying another record

        printf("\nWant to modify another"
               " record (Y/N) :");
        fflush(stdin);
        scanf("%c", &another);
    }
}

void fun1()
{
    // Driver code

    int choice;

    // opening the file

    fp = fopen("demo.txt", "rb+");

    // showing error if file is
    // unable to open.

    if (fp == NULL)
    {
        fp = fopen("demo.txt", "wb+");
        if (fp == NULL)
        {
            printf("\nCannot open file...");
            exit(1);
        }
    }
    system("cls");
    system("Color 3F");

	printf("\n\n\n\n\t\t\t\t_____________"
		"_____________________________"
		"_____________");

        printf("\n\t\t\t\t_____________"
        "_____________________________"
        "_____________");

        printf("\n\t\t\t\t====================="
		"\t\t============="
		"===========");

	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~\t"
		"\t\t~~~~~~~~~~~~~"
		"~~~");

        printf("\n\t\t\t\t************"
		"\t\t\t\t    *********"
		"***");

	printf("\n\t\t\t\t|||>>>>>>>>>"
		"     EMPLOYEE PROFILE SYSTEM    <<<<<"
		"<<<<|||\t");

	printf("\n\t\t\t\t************"
		"\t\t\t\t    *********"
		"***");

	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~\t"
		"\t\t~~~~~~~~~~~~~"
		"~~~");

	 printf("\n\t\t\t\t====================="
		"\t\t============="
		"===========");

        printf("\n\t\t\t\t_____________"
		"_____________________________"
		"_____________");

        printf("\n\t\t\t\t_____________"
        "_____________________________"
        "_____________");

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t"
		"Developer : Ayush Talan\n\t\t\t\t\t\t\t\t\t\t\t    Aarya Singh\n\t\t\t\t\t\t\t\t\t\t\t    Akshat Singhal\n\t\t\t\t\t\t\t\t\t\t\t    Manan"
		"\n\n\t\t\t\t");
    system("pause");

    while (1)
    {
        // Clearing console and asking the
        // user for input

        system("cls");
        gotoxy(30, 10);

        printf("\n1. ADD RECORD\n");
        gotoxy(30, 12);

        printf("\n2. DELETE RECORD\n");
        gotoxy(30, 14);

        printf("\n3. DISPLAY RECORDS\n");
        gotoxy(30, 16);

        printf("\n4. MODIFY RECORD\n");
        gotoxy(30, 18);

        printf("\n5. EXIT\n");
        gotoxy(30, 20);

        printf("\nENTER YOUR CHOICE...\n");
        fflush(stdin);
        scanf("%d", &choice);

        // Switch Case

        switch (choice)
        {
        case 1:
            // Add the records

            addrecord1();
            break;
        case 2:
            // Delete the records

            deleterecord1();
            break;
        case 3:
            // Display the records
            displayrecord1();
            break;

        case 4:
            // Modify the records
            modifyrecord1();
            break;

        case 5:
            fclose(fp);
            return;
            break;

        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
}

void fun2()
{
    // Driver code

    int choice;
    // opening the file

    fp = fopen("data.txt", "rb+");

    // showing error if file is
    // unable to open.

    if (fp == NULL)
    {
        fp = fopen("data.txt", "wb+");
        if (fp == NULL)
        {
            printf("\nCannot open file...");
            exit(1);
        }
    }
    system("cls");
    system("Color 5F");
	printf("\n\n\n\n\t\t\t\t_____________"
		"_____________________________"
		"_____________");

        printf("\n\t\t\t\t_____________"
        "_____________________________"
        "_____________");

        printf("\n\t\t\t\t====================="
		"\t\t============="
		"===========");

	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~\t"
		"\t\t~~~~~~~~~~~~~"
		"~~~");

        printf("\n\t\t\t\t************"
		"\t\t\t\t    *********"
		"***");

	printf("\n\t\t\t\t|||>>>>>>>>>>"
		"     EMPLOYEE SALARY SYSTEM    <<<<<<"
		"<<<|||\t");

	printf("\n\t\t\t\t************"
		"\t\t\t\t    *********"
		"***");

	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~\t"
		"\t\t~~~~~~~~~~~~~"
		"~~~");

	 printf("\n\t\t\t\t====================="
		"\t\t============="
		"===========");

        printf("\n\t\t\t\t_____________"
		"_____________________________"
		"_____________");

        printf("\n\t\t\t\t_____________"
        "_____________________________"
        "_____________");

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t"
		"Developer : Ayush Talan\n\t\t\t\t\t\t\t\t\t\t\t    Aarya Singh\n\t\t\t\t\t\t\t\t\t\t\t    Akshat Singhal\n\t\t\t\t\t\t\t\t\t\t\t    Manan"
		"\n\n\t\t\t\t");
    system("pause");
    while (1)
    {

        // Clearing console and asking the
        // user for input

        system("cls");
        gotoxy(30, 10);

        printf("\n1. ADD RECORD\n");
        gotoxy(30, 12);

        printf("\n2. DELETE RECORD\n");
        gotoxy(30, 14);

        printf("\n3. DISPLAY RECORDS\n");
        gotoxy(30, 16);

        printf("\n4. MODIFY RECORD\n");
        gotoxy(30, 18);

        printf("\n5. EXIT\n");
        gotoxy(30, 20);

        printf("\nENTER YOUR CHOICE...\n");
        fflush(stdin);
        scanf("%d", &choice);

        // Switch Case

        switch (choice)
        {
        case 1:
            // Add the records
            addrecord2();
            break;

        case 2:
            // Delete the records
            deleterecord2();
            break;

        case 3:
            // Display the records
            displayrecord2();
            break;

        case 4:
            // Modify the records
            modifyrecord2();
            break;

        case 5:
            fclose(fp);
            return;
            break;

        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
  
}

void fun3()
{
    // Driver code
    int choice;

    // opening the file
    fp = fopen("data1.txt", "rb+");

    // showing error if file is
    // unable to open.

    if (fp == NULL)
    {
        fp = fopen("data1.txt", "wb+");
        if (fp == NULL)
        {
            printf("\nCannot open file...");
            exit(1);
        }
    }
    system("cls");
    system("Color 4F");

	printf("\n\n\n\n\t\t\t\t_____________"
		"_____________________________"
		"_____________");

        printf("\n\t\t\t\t_____________"
        "_____________________________"
        "_____________");

        printf("\n\t\t\t\t====================="
		"\t\t============="
		"===========");

	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~\t"
		"\t\t~~~~~~~~~~~~~"
		"~~~");
        printf("\n\t\t\t\t************"
		"\t\t\t\t    *********"
		"***");

	printf("\n\t\t\t\t|||>>>>>>>>>"
		"    LEAVE MANAGEMENT SYSTEM   <<<<<"
		"<<<<<<|||\t");

	printf("\n\t\t\t\t************"
		"\t\t\t\t    *********"
		"***");

	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~\t"
		"\t\t~~~~~~~~~~~~~"
		"~~~");

	 printf("\n\t\t\t\t====================="
		"\t\t============="
		"===========");

        printf("\n\t\t\t\t_____________"
		"_____________________________"
		"_____________");

        printf("\n\t\t\t\t_____________"
        "_____________________________"
        "_____________");

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t"
		"Developer : Ayush Talan\n\t\t\t\t\t\t\t\t\t\t\t    Aarya Singh\n\t\t\t\t\t\t\t\t\t\t\t    Akshat Singhal\n\t\t\t\t\t\t\t\t\t\t\t    Manan"
		"\n\n\t\t\t\t");

    system("pause");
    do{
        // Clearing console and asking the
        // user for input

        system("cls");
        gotoxy(30, 10);

        printf("\n1. ADD LEAVE\n");
        gotoxy(30, 12);

        printf("\n2. DELETE LEAVE\n");
        gotoxy(30, 14);

        printf("\n3. DISPLAY LEAVE\n");
        gotoxy(30, 16);

        printf("\n4. MODIFY LEAVE\n");
        gotoxy(30, 18);

        printf("\n0. EXIT\n");
        gotoxy(30, 20);

        printf("\nENTER YOUR CHOICE...\n");
        fflush(stdin);
        scanf("%d", &choice);

        // Switch Case

        switch (choice)
        {

        case 1:
            // Add the records
            addleave3();
            break;

        case 2:
            // Delete the records
            deleteleave3();
            break;

        case 3:
            // Display the records
            displayleave3();
            break;

        case 4:
            // Modify the records
            modifyleave3();
            break;
        }
    }while(choice);
    fclose(fp);
    return;
}

int main()
{
    int choice;
    system("Color 2F");

        printf("\n\n\n\n\t\t\t\t_____________"
		"_____________________________"
		"_____________");

        printf("\n\t\t\t\t_____________"
        "_____________________________"
        "_____________");

        printf("\n\t\t\t\t====================="
		"\t\t============="
		"===========");

	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~\t"
		"\t\t~~~~~~~~~~~~~"
		"~~~");

        printf("\n\t\t\t\t************"
		"\t\t\t\t    *********"
		"***");

	printf("\n\t\t\t\t|||>>>>>"
		"    WELCOME TO EMPLOYEE RECORD SYSTEM\t<<<<"
		"<|||\t");

	printf("\n\t\t\t\t************"
		"\t\t\t\t    *********"
		"***");

	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~\t"
		"\t\t~~~~~~~~~~~~~"
		"~~~");

	 printf("\n\t\t\t\t====================="
		"\t\t============="
		"===========");

        printf("\n\t\t\t\t_____________"
		"_____________________________"
		"_____________");

        printf("\n\t\t\t\t_____________"
        "_____________________________"
        "_____________");

	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t"
		"Developer : Ayush Talan\n\t\t\t\t\t\t\t\t\t\t\t    Aarya Singh\n\t\t\t\t\t\t\t\t\t\t\t    Akshat Singhal\n\t\t\t\t\t\t\t\t\t\t\t    Manan"
		"\n\n\t\t\t\t");

    system("pause");
    char ch;
    do{
        system("cls");

        system("Color 3F");
        gotoxy(30,10);

        printf("1. ENTER EMPLOYEE PROFILE SYSTEM");
        gotoxy(30,12);

        printf("2. ENTER EMPLOYEE SALARY SYSTEM");
        gotoxy(30,14);

        printf("3. ENTER EMPLOYEE LEAVE SYSTEM");
        gotoxy(30,16);

        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            fun1();
            break;

        case 2:
            fun2();
            break;

        case 3:
            fun3();
            break;

        }

        getchar();
        printf("Do you want to enter into any other system (Y/N)\n");

        //scanf("%c",&ch);
        ch=getchar();
    }

    while(ch=='Y' || ch=='y');

    system("cls");
    system("Color 7F");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t Thank You!\n"
            "\t\t\t\t\t\t Happy Programming\n");
    return 0;
}
