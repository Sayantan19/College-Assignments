#include<stdio.h>
struct student
{
    int roll;
    char name[20];
    float marksinPhysics;
    float marksinChemistry;
    float marksinMathematics;
    float total;
}stud[100];                         //We are assuming that there are a 100 students max in the class

int main()
{
    int i,n;
    printf("Enter the number of students\' info you want to accept \n");
    scanf("%d",&n);
    printf("Enter details for %d Students: ",n);
    for(i=0;i<n;i++)
    {
        printf("Student roll: ");
        scanf("%d",&stud[i].roll);
        printf("Name: ");
        scanf("%*c%[^\n]",stud[i].name);
        printf("Marks in Physics: ");
        scanf("\n %f",&stud[i].marksinPhysics);
        printf("Marks in Chemistry: ");
        scanf("\n %f",&stud[i].marksinChemistry);
        printf("Marks in Mathematics: ");
        scanf("\n %f",&stud[i].marksinMathematics);
        stud[i].total = stud[i].marksinPhysics+stud[i].marksinChemistry+stud[i].marksinMathematics;
    }
    for (int i = 0; i < n; i++)
    {
        // char s[100];
        float t = 0;
        int r=0;
        for (int j = 0; j < n - 1; j++)
        {
            if (stud[j].total < stud[j + 1].total)
            {
                struct student t = stud[j];
                stud[j] = stud[j + 1];
                stud[j + 1] = t;
            }
        }
    }
    printf("List of students in descending order\n");
    for(int i=0;i<n;i++)
    {
        printf("%f\t",stud[i].total);
        printf("%s\n",stud[i].name);
    }
    return 0;
}