/*1. Store and retrieve the name of the students and obtained marks in c programming in 1st semester using structure.*/

/*#include <stdio.h>
struct student
{
    char name[20];
    float marks;
};
int main()
{
    int n, i;
    printf("Enter how many records do you want to store : ");
    scanf("%d", &n);
    struct student s[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter name : ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter obtained marks in C :");
        scanf("%f", &s[i].marks);
    }
    for (i = 0; i < n; i++)
    {
        printf("%s\n", s[i].name);
        printf("%f\n", s[i].marks);
    }
    return 0;
}*/

/*
Write a program to read name, rollno, address, and phone number of each student in your class using structure. Store the information in file so that you can recover the information later. While recovering the information from the file sort the information alphabetically according to the name.
*/
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int roll;
    char address[100];
    double phone;
};


void sortByName(struct student s[], int n) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(s[i].name, s[j].name) > 0) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    struct student s[100];

    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar(); 

    
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0'; 

        printf("Roll No: ");
        scanf("%d", &s[i].roll);
        getchar();

        printf("Address: ");
        fgets(s[i].address, sizeof(s[i].address), stdin);
        s[i].address[strcspn(s[i].address, "\n")] = '\0';

        printf("Phone: ");
        scanf("%lf", &s[i].phone);
        getchar();

       
        fprintf(file, "%s\n%d\n%s\n%.0lf\n", s[i].name, s[i].roll, s[i].address, s[i].phone);
    }

    fclose(file);

    
    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error reading file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fgets(s[i].name, sizeof(s[i].name), file);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';

        fscanf(file, "%d\n", &s[i].roll);

        fgets(s[i].address, sizeof(s[i].address), file);
        s[i].address[strcspn(s[i].address, "\n")] = '\0';

        fscanf(file, "%lf\n", &s[i].phone);
    }

    fclose(file);

    
    sortByName(s, n);

    printf("\n--- Sorted Student Records ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nName: %s\nRoll: %d\nAddress: %s\nPhone: %.0lf\n", s[i].name, s[i].roll, s[i].address, s[i].phone);
    }

    return 0;
}*/

/*Write a program to find the position of the character 'C' in the sentence "idea without execution is worthless" using pointer and string.*/

/*#include <stdio.h>

int main() {
    char str[] = "idea without execution is worthless";
    char *ptr = str;
    char ch = 'c';
    int position = 0;
    int found = 0;

    while (*ptr != '\0') {
        position++;
        if (*ptr == ch) {
            found = 1;
            break;
        }
        ptr++;
    }

    if (found)
        printf("Character '%c' found at position %d.\n", ch, position);
    else
        printf("Character '%c' not found in the string.\n", ch);

    return 0;
}*/


/*Write a program to find the average expenditure of a company for each month of each year, each year and average over the range of years specified. Use arrays to construct a table, display the table of expenditure and find the sum and average.*/

#include <stdio.h>

#define MAX_YEARS 10
#define MONTHS 12

int main() {
    int years, i, j;
    float expenditure[MAX_YEARS][MONTHS];
    float yearlySum[MAX_YEARS] = {0};
    float yearlyAvg[MAX_YEARS] = {0};
    float totalSum = 0, totalAvg = 0;

    printf("Enter number of years (max %d): ", MAX_YEARS);
    scanf("%d", &years);

    
    for (i = 0; i < years; i++) {
        printf("\nEnter expenditure for Year %d:\n", i + 1);
        for (j = 0; j < MONTHS; j++) {
            printf("  Month %d: ", j + 1);
            scanf("%f", &expenditure[i][j]);
        }
    }

    
    printf("\n--- Expenditure Table ---\n");
    printf("Year\t");
    for (j = 0; j < MONTHS; j++)
        printf("M%d\t", j + 1);
    printf("Total\t\tAverage\n");

  
    for (i = 0; i < years; i++) {
        printf("%d\t", i + 1);
        for (j = 0; j < MONTHS; j++) {
            printf("%.2f\t", expenditure[i][j]);
            yearlySum[i] += expenditure[i][j];
        }
        yearlyAvg[i] = yearlySum[i] / MONTHS;
        totalSum += yearlySum[i];
        printf("%.2f\t%.2f\n", yearlySum[i], yearlyAvg[i]);
    }

    
    totalAvg = totalSum / (years * MONTHS);
    printf("\nTotal Expenditure over %d years: %.2f", years, totalSum);
    printf("\nOverall Average Expenditure: %.2f\n", totalAvg);

    return 0;
}



