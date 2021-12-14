#include<stdio.h>
struct student
{
    int roll;
    char name[20];
    float cgpa;
}stud[10];

int main()
{
    int i,n;
    float max;
    printf("Enter the number of students\' info you want to accept \n");
    scanf("%d",&n);
    printf("Enter details for %d Students: ",n);
    for(i=0;i<n;i++)
    {
        printf("Student roll: ");
        scanf("%d",&stud[i].roll);
        printf("Name           : ");
        scanf("%s",stud[i].name);
        printf("CGPA         : ");
        scanf("\n %f",&stud[i].cgpa);
    }
    max=stud[0].cgpa;
    for(i=0;i<n;i++)
    {
        if(stud[i].cgpa>max)
        max=stud[i].cgpa;
    }
    printf("Highest CGPA student details: \n");
    printf("ROLLNO    NAME  CGPA\n");
    for(i=0;i<n;i++)
    {
        if(stud[i].cgpa==max)
        printf("\n %d\t%s\t%f",stud[i].roll,stud[i].name,stud[i].cgpa);
    }
    return 0;
}