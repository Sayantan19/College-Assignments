#include<stdio.h>
#include<string.h>
#include<stdlib.h>

float Nucleotide_Difference_Calculator(char * sequence1,char * sequence2)
{
    int l1,l2;
    int s=0; 
    l1 = strlen(sequence1); 
    l2 = strlen(sequence2); 
    if(l1>l2)
    {
        for(int i=0;i<l2;i++)
            if(sequence1[i]!=sequence2[i])
                s++;
        s = s+(l1-l2);
    }
    else
    {
        for(int i=0;i<l1;i++)
            if(sequence1[i]!=sequence2[i])
                s++;
        s = s+(l2-l1);
    }
    return (s/(float)strlen(sequence1));
}

int main()
{
    char * sequence1 = "ATATAAATATGGGAAAGAGAATGGGGAAATTTCTACCAGTCTTCATCTCTGAGAGCAAACTTCTCTGCATCTCTTTCTCTCTTCTCTGGGCCTCCCCCAGCTCATCATGGCTCTCTGGATCCGATCACTGCCTCTTCTGGCTCTCCTTGTCTTTTCTGGCCCTGGAACCAGCTATGCAGCTGCCAACCAGCACCTCTGTGGCTCCCACTTGGTGGAGGCTCTCTACCTGGTGTGTGGAGAGCGTGGCTTCTTCTACTCCCCCAAAGCCCGACGGGATGTCGAGCAGCCCCTAGTGAGCAGTCCCTTGCGTGGCGAGGCAGGAGTGCTGCCTTTCCAGCAGGAGGAATACGAGAAAGTCAAGCGAGGGATTGTTGAGCAATGCTGCCATAACACGTGTTCCCTCTACCAACTGGAGAACTACTGCAACTAGCCAAGAAGCCGGAAGCGGGCACAGACATACACTTACTCTATCGCACCTTCAAAGCATTTGAATAAACCTTGTTGGTCTACTGGAAGACTTGTGCC";

    char * sequence2 = "CACCCCGACACGGCCGGCAAACAGGTCGCCATGGCCCTCTGGATGCGCCTCCTGCCCCTGCTGGCCCTGCTGGCCCTCTGGGCGCCCGCGCCCACCCGAGCCTTCGTTAACCAGCACCTGTGTGGCTCCCACCTGGTAGAGGCTCTGTACCTGGTGTGCGGGGAGCGCGGCTTCTTCTACACGCCTAAGGCCCGCCGGGAGGTGGAGGACCTGCAGGTGAGGGACGTGGAGCTGGCCGGGGCGCCTGGCGAGGGCGGCCTGCAGCCCCTGGCCCTGGAGGGGGCCCTGCAGAAGCGAGGCATCGTGGAGCAGTGCTGCACCAGCATCTGCTCCCTCTACCAGCTGGAGAATTACTGCAACTAGGGGCGCGGGGGGCAGGACGTGGCAGCACCTGCTGCAGGTCACGGTGGCCGCAAGCCTTCGGCTCTCTGCACCCCAAGTGATTCAATAAACCCTCTGAATG";

    float diff = Nucleotide_Difference_Calculator(sequence1,sequence2);
    printf("%f",diff);
}