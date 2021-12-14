#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    float l1, l2, g1, g2;
    printf(" Enter the Latitude and longitude of place 1 \n");
    scanf("%f %f", &l1, &g1);
    printf(" Enter the Latitude and longitude of place 2 \n");
    scanf("%f %f",&l2,&g2);
    float distance;
    distance = 3963 * acos((sin(l1)*sin(l2)) + (cos(l1)*cos(l2)) * cos(g2-g1));
    printf(" The distance between the 2 places are %f nautical miles \n", distance);
    return 0;
}