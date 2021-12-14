/*Paper of size A0 has dimensions 1189 mm x 841 mm. Each 
subsequent size A(n) is defined as A(n-1) cut in half parallel to its 
shorter sides. Thus paper of size A1 would have dimensions 841 
mm x 594 mm. Write a program to calculate and print paper sizes 
A0, A1, A2, … A8.*/

#include<stdio.h>
#include<conio.h>
int main()
{
    int la0,ba0,la1,ba1,la2,ba2,la3,ba3,la4,ba4,la5,ba5,la6,ba6,la7,ba7,la8,ba8;
    la0=1189;
    ba0=841;
    la1=ba0;
    ba1=la0/2;
    la2=ba1;
    ba2=la1/2;
    la3=ba2;
    ba3=la2/2;
    la4=ba3;
    ba4=la3/2;
    la5=ba4;
    ba5=la4/2;
    la6=ba5;
    ba6=la5/2;
    la7=ba6;
    ba7=la6/2;
    la8=ba7;
    ba8=la7/2;
    printf(" the dimensions of A0 paper are %d %d \n",la0,ba0);
    printf(" the dimensions of A1 paper are %d %d \n",la1,ba1);
    printf(" the dimensions of A2 paper are %d %d \n",la2,ba2);
    printf(" the dimensions of A3 paper are %d %d \n",la3,ba3);
    printf(" the dimensions of A4 paper are %d %d \n",la4,ba4);
    printf(" the dimensions of A5 paper are %d %d \n",la5,ba5);
    printf(" the dimensions of A6 paper are %d %d \n",la6,ba6);
    printf(" the dimensions of A7 paper are %d %d \n",la7,ba7);
    printf(" the dimensions of A8 paper are %d %d \n",la8,ba8);
    return 0;
}