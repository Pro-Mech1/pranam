#include<stdio.h>
#include<string.h>

int main() {
    char pattern[50], dna_sequence[100];
    int dna_length, pattern_length;
    int count=0;  

    printf("Enter DNA sequence: ");
    scanf("%s", dna_sequence);  
    printf("Enter pattern to search: ");
    scanf("%s", pattern);  

    dna_length = strlen(dna_sequence);
    pattern_length = strlen(pattern);

    for (int i = 0; i <= dna_length - pattern_length; i++) {
        if (strncmp(&dna_sequence[i], pattern, pattern_length) == 0) {
            count++;
        }
    }
    printf("Pattern found %d time(s) in the DNA sequence.\n", count);
    return 0;
}
