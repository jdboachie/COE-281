#include <stdio.h>

char grade(int score);

int main()
{
    int numStudents;
    int total = 0;
    int average = 0;
    printf("How many students are in the class? ");
    scanf("%d", &numStudents);

    int marks[10];
    for (int i = 0; i < numStudents; i++)
    {
        printf("Enter the mark for student %d: ", i + 1);
        scanf("%d", &marks[i]);
        total += marks[i];
    }

    // Printing out the marks for each student
    for (int i = 0; i < numStudents; i++)
    {
        printf("The mark for student %d is %d\n", i + 1, marks[i]);
    }

    // Calculating the average
    average = total / numStudents;
    printf("The average mark for the class is %d\n", average);

    // Sorting the array marks in ascending order
    for (int i = 0; i < numStudents; i++)
    {
        for (int j = i + 1; j < numStudents; j++)
        {
            if (marks[i] > marks[j])
            {
                int temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }

    // Printing out the array
    for (int i = 0; i < numStudents; i++)
    {
        printf("%d ", marks[i]);
    }

    // MULTI DIMENSIONAL ARRAYS

    float studentResults[7][2] = {
        {3, 57.45},
        {2, 69.29},
        {2, 71.32},
        {4, 65.05},
        {3, 75.67},
        {3, 48.65},
        {1, 88.21}
    };

    // Printing out the array
    printf("\nCREDIT\t|SCORE\t|GRADE\t|\n");
    printf("\t|\t|\t|\n");
    for(int i=0; i<7; ++i){
        for(int j=0; j<2; ++j){
            printf("%.2f \t|", studentResults[i][j]);
            if(j%2 == 1){ 
                printf("%c \t|", grade(studentResults[i][j]));
                printf("\n\t|\t|\t|");
            }
        }
        printf("\n");
    }

    // Calculate CWA
    float weightedsum = 0.0;
    float totalcredits = 0.0;
    for(int i=0; i<7; ++i)
    {
        weightedsum = weightedsum + (studentResults[i][0] * studentResults[i][1]);
        totalcredits += studentResults[i][0];
    };
    float cwa = weightedsum/totalcredits;
    printf("\ncwa = %.2f\n", cwa);

}

char grade(const int score)
{
    if (score >= 70)
    {
        return 'A';
    }
    else if (score >= 60)
    {
        return 'B';
    }
    else if (score >= 50)
    {
        return 'C';
    }
    else if (score >= 40)
    {
        return 'D';
    }
    else if (score < 40)
    {
        return 'F';
    }
    else
    {
        printf("Invalid score!");
        return 'X';
    }
}