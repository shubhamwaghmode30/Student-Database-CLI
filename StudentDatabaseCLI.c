// Building Student DataBase With Structures (Added Search by Grade and No. of Students scored the smilar Grade. )

#include <stdio.h>
#include <string.h>

struct Std 
{
    int ID;             
    char Name[100];      
    float Marks[10];   
    float P;            
    char Grade[10];      
    float Sum;          
};

int main()         
{
    struct Std S[100]; 
    int i, j, n, m;
    char searchName[100]; 
  
    // Flag to check if student is found
    int found = 0;       
    // Counter for students with Grade 
    int CountA = 0;       
    int CountB = 0;     
    int CountC = 0;    \
    int CountD = 0;       
    char Grade[10];       

    // Input number of students
    printf("Enter the number of Students: ");
    scanf("%d", &n);

    // Input student data
    for (i = 0; i < n; i++)
    {
        printf("\nStudent %d:\n", (i + 1));

        printf("ID: ");
        scanf("%d", &S[i].ID);

        printf("Name: ");
        scanf(" %[^\n]", S[i].Name);  // Reads full name including spaces

        printf("How many Subjects: ");
        scanf("%d", &m);

        S[i].Sum = 0;
        for (j = 0; j < m; j++)
        {
            printf("Subject %d: ", (j + 1));
            scanf("%f", &S[i].Marks[j]);
            S[i].Sum += S[i].Marks[j];
        }

        S[i].P = S[i].Sum / m;  

        // Determine grade and count
        if (S[i].P >= 80 && S[i].P <= 100)
        {
            CountA++;                                                   
            strcpy(S[i].Grade, "A");
        }
        else if (S[i].P >= 60 && S[i].P < 80)
        { 
            CountB++;
            strcpy(S[i].Grade, "B");
        }
        else if (S[i].P >= 40 && S[i].P < 60)
        {
            CountC++;
            strcpy(S[i].Grade, "C");
        }
        else if (S[i].P >= 0 && S[i].P < 40)
        {
            CountD++;
            strcpy(S[i].Grade, "D");
        }
        else
        {
            strcpy(S[i].Grade, "Invalid");
        }
    }

    // Display all Students' Primary Data.
    printf("\n\nStudent Grading System\n");
    printf("+------+-------------------+------------+-------+\n");
    printf("| Roll | Name              | Percentage | Grade |\n");
    printf("+------+-------------------+------------+-------+\n");

    for (i = 0; i < n; i++)
    {
        printf("| %-4d | %-17s | %-10.2f | %-5s |\n", S[i].ID, S[i].Name, S[i].P, S[i].Grade);
        printf("+------+-------------------+------------+-------+\n");
    }

    // Search for a specific Student's Data.
    printf("\nDo you want any specific Student's data?\nEnter the name: ");
    scanf(" %[^\n]", searchName);

    for (i = 0; i < n; i++)
    {
        if (strcmp(S[i].Name, searchName) == 0)
        {
            printf("\nStudent Details for %s\n", searchName);
            printf("+------+-------------------+------------+-------+\n");
            printf("| Roll | Name              | Percentage | Grade |\n");
            printf("+------+-------------------+------------+-------+\n");
            printf("| %-4d | %-17s | %-10.2f | %-5s |\n", S[i].ID, S[i].Name, S[i].P, S[i].Grade);
            printf("+------+-------------------+------------+-------+\n");
            
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent with name '%s' not found.\n", searchName);
    }
    
    // Input the grade to search by Grade.
    printf("\nEnter the Grade to search for (A, B, C, D): ");
    scanf("%s", Grade);

    // Print the header for the grade-based Student list.
    printf("\nStudents with Grade %s:\n", Grade);
    printf("+------+-------------------+------------+-------+\n");
    printf("| Roll | Name              | Percentage | Grade |\n");
    printf("+------+-------------------+------------+-------+\n");

    // Flag to check if any Students with the specified grade were found
    found = 0;

    // Loop through the Students to find and display those with the specified grade
    for (i = 0; i < n; i++)
    {
        if (strcmp(Grade, S[i].Grade) == 0)
        {
            printf("| %-4d | %-17s | %-10.2f | %-5s |\n", S[i].ID, S[i].Name, S[i].P, S[i].Grade);
            printf("+------+-------------------+------------+-------+\n");
            found = 1;
        }
    }

    if (!found)
    {
        printf("\nNo Students secured %s Grade.\n", Grade);
    }
    else
    {
        // Print the count of Students with the specific Grade.
        if (strcmp(Grade, "A") == 0) printf("Total Students with Grade A: %d\n", CountA);
        if (strcmp(Grade, "B") == 0) printf("Total Students with Grade B: %d\n", CountB);
        if (strcmp(Grade, "C") == 0) printf("Total Students with Grade C: %d\n", CountC);
        if (strcmp(Grade, "D") == 0) printf("Total Students with Grade D: %d\n", CountD);
    }

    return 0;
}
