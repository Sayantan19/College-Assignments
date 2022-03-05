#include<bits/stdc++.h>
using namespace std;

void Template(string s)
{
    int len = s.length();
    string RNA = "";
    for(int i=0;i<len;i++)
    {
        char c = s[i];
        switch(c)
        {
            case 'A':   RNA = RNA + 'U';
                        break;
            case 'T':   RNA = RNA + 'A';
                        break;
            case 'G':   RNA = RNA + 'C';
                        break;
            case 'C':   RNA = RNA + 'G';
                        break;
            
        }
    }
    cout<<"The required RNA strand is: "<<RNA;
}

void Coding(string s)
{
    int len = s.length();
    string RNA = "";
    for(int i=0;i<len;i++)
    {
        char c = s[i];
        if(c=='T')
            RNA = RNA + 'U';
        else
            RNA = RNA + c;
    }
    cout<<"The required RNA strand is: "<<RNA;
}

int main()
{
    int a;
    string code;
    cout<<"Enter whether the DNA sequence you want to transcribe belongs to the template or coding strand[1 for template, 2 for coding";
    cin>>a;
    cout<<"Enter the Genetic Sequence";
    cin>>code;
    switch (a)
    {
    case 1:
        Template(code);
        break;
    case 2:
        Coding(code);
        break;
    default:
        cout<<"You entered the wrong choice!";
    }
}