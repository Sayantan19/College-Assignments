#include<stdio.h>
#include<stdlib.h>
struct Employee
{
    int Empno,bs;
    float daval,hraval,da,hra;
    char name[100],dept[100];
    float gs;
}e[50];

int main()
{
    FILE *fp1,*fp2;
    fp1 = fopen("I_P.txt","wb");
    fp2 = fopen("O_P.txt","wb");
    int n,c;
    float max=0;
    printf("Enter the number of employees: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the Employee number: ");
        scanf("%d",&e[i].Empno);
        printf("Enter the Employee Name: ");
        scanf("%*c%[^\n]",e[i].name);
        printf("Enter the Employee Department: ");
        scanf("%*c%[^\n]",e[i].dept);
        printf("Enter the Employee Basic Salary: ");
        scanf("%d",&e[i].bs);
        printf("Enter the Employee DA: ");
        scanf("%f",&e[i].da);
        printf("Enter the Employee HRA: ");
        scanf("%f",&e[i].hra);
        e[i].daval = ((e[i].da/100.0)*e[i].bs);
        e[i].hraval = ((e[i].hra/100.0)*e[i].bs);
        e[i].gs = e[i].bs*(1.0+((e[i].daval+e[i].hraval)/100));
        if(max<e[i].gs)
        {
            max = e[i].gs;
            c=i;
        }
        fwrite(&e[i],sizeof(e[i]),1,fp1);
    }
    fclose(fp1);
    fwrite(&e[c],sizeof(e[c]),1,fp2);
    fclose(fp2);
    fp1 = fopen("I_P.txt","rb");
    fp2 = fopen("O_P.txt","rb");
    printf("The details of all the employees are: \n");
    for(int i=0;i<n;i++)
        while(fread(&e[i],sizeof(e[i]),1,fp1)==1)
        printf("Emp. no.%d\nName: %s\nDept.: %s\nBasic Salary: %d\nDA: %f\nHRA: %f\nGross Salary: %f\n",e[i].Empno,e[i].name,e[i].dept,e[i].bs,e[i].daval,e[i].hraval,e[i].gs);
    printf("The details of the employee with the highest gross salary\n");
        while(fread(&e[c],sizeof(e[c]),1,fp2)==1)
        printf("Emp. no.%d\nName: %s\nDept.: %s\nBasic Salary: %d\nDA: %f\nHRA: %f\nGross Salary: %f\n",e[c].Empno,e[c].name,e[c].dept,e[c].bs,e[c].daval,e[c].hraval,e[c].gs);
    fclose(fp1);
    fclose(fp2);
    return 0;
}