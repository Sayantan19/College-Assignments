This is a program which allows the user to enter a few Nucleotide sequences and generates a phylogenetic tree based on the sequences.

The way this program functions is pretty simple. It takes the organism's name and its genetic sequence from the user, stores it in a structure datatype called "data".

A function calculates the ratio between the number of nucleotide differences between 2 genetic sequences 
and the number of nucleotides in the sequence with the larger number of nucleotides. This value is then fed into a 2D matrix, where each index represents the difference ratio of the respective organism (i.e., the value at [1,2] will represent the difference ratio between the 2nd and the 3rd organism entered by the user). Note that the 1st organism entered by the user is the root organism, i.e. the parent organism which started the evolutionary process.

Another function checks the smallest value of the difference ratio in the first row, and then updates the matrix by reducing the table accordingly. This finds out the immediate successor to the parent organism, as the successor has to have the highest similarity in the nucleotide sequences w.r.t. the parent organism. The value is then used to determine the organism number and places the same in the final phylogenetic tree.

The 2 functions are called recursively untill the last organism is placed in the tree.

Once the tree is formed, We print the name of the organism corresponding to the number stored in the tree nodes in a Pre Order (Root->Left->Right) format.

NOTE: The program has been tested for long data sequences. If you wish to test them, you can find a list of pre-baked sequences at "Nucleotide.txt" file.

ANY VALUABLE FEEDBACK AND SUGGESTIONS FOR MAKING THE PROGRAM MORE EFFICIENT WOULD BE APPRECIATED.