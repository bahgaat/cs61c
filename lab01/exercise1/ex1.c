#include <string.h>
#include "ex1.h"

/* Returns the number of times LETTER appears in STR.
There are two different ways to iterate through a string.
1st way hint: strlen() may be useful
2nd way hint: all strings end in a null terminator */
int num_occurrences(char *str, char letter) {
    int occurence = 0;
    for (int i = 0; i < strlen(str); i ++) {
      char c = str[i];
      if (c == letter) {
        occurence += 1;
      }
    }
    return occurence;
}

/* Populates DNA_SEQ with the number of times each nucleotide appears.
Each sequence will end with a NULL terminator and will have up to 20 nucleotides.
All letters will be upper case. */
void compute_nucleotide_occurrences(DNA_sequence *dna_seq) {
    int A = num_occurrences(dna_seq -> sequence, 'A');
    int C = num_occurrences(dna_seq -> sequence, 'C');
    int G = num_occurrences(dna_seq -> sequence, 'G');
    int T = num_occurrences(dna_seq -> sequence, 'T');
    dna_seq -> A_count = A;
    dna_seq -> C_count = C;
    dna_seq -> G_count = G;
    dna_seq -> T_count = T;
    return;
}
