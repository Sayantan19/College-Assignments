#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter the line of text: ");
    scanf("%s",s);
    int length = strlen(s);
    int count = 0;
    int arr[length];
    char dum[length];
    for(int i=0;i<length;i++)
    {
        char c = s[i];
        printf("Character: %c\n",c);
        printf("Enter the numeric code you want for this character (Press -1 if you have already done the same for the present character\n");
        int code;
        scanf("%d",&code);
        if(code!=-1)
        {
            arr[count] = code;  //this takes in the numeric code for the letter
            dum[count] = s[i];  //this takes in the letter to which the code is assigned to
            count++;            //counter to count the length of the above 2 arrays
        }
    }
    printf("Encryted code is\n");
    int check[length];
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<count;j++)
        {
            if(s[i]==dum[j])
            {
                check[i] = arr[j];
                printf("%d",arr[j]);
            }
        }
    }
    printf("\n");
    printf("This is for checking whether it can be decrypted correctly\n");
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<count;j++)
        {
            if(check[i]==arr[j])
            {
                printf("%c",dum[j]);
            }
        }
    }
    printf("\n");
    return 0;
}