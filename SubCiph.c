/*
    Project 1 - Substitution Cipher
    Travis Henderson & Jared Currie
    CIS 241 02
    SubCiph.c
*/

// Includes
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int decrypt = 0; // 1 if the user is decrypting
    char ch;         // Character being encrypted / decrypted
    FILE *fin, *fout;

    if (argc != 5)
    {
        printf("Missing one or more arguments, or there are too many arguments!\n");
        printf("Usage: cipher inputFile key outputFile e/d");
        exit(1);
    }

    int keyLength = strlen(argv[2]) + 1;

    // Key arrays
    char alphabet[27] = "zyxwvutsrqponmlkjihgfedcba";    // Holds the backwards alphabet
    char fwdAlphabet[27] = "abcdefghijklmnopqrstuvwxyz"; // For decryption, holds the forward alphabet
    char input[keyLength];                               // Holds the user input
    strncpy(input, argv[2], keyLength);                  // Copy the input from argv[2]
    char key[27];                                        // Array that will hold the key

    // Convert input key to lowercase
    int inNum = 0;
    for (; inNum < strlen(input); inNum++)
    {
        input[inNum] = tolower(input[inNum]);
    }

    // Copy input into start of key array
    strcpy(key, input);
    int i = strlen(key);

    // Search through the alphabet array and remove any letter that's in the key
    int keySearch = 0;
    for (; keySearch < strlen(input); keySearch++)
    {
        int letter = 0;
        for (; letter < strlen(alphabet); letter++)
        {
            if (alphabet[letter] == input[keySearch])
            {
                alphabet[letter] = '-';
            }
        }
    }

    printf("Alphabet->  %s\n", alphabet);

    int a = 0;
    while (strlen(key) != 26)
    {
        if (alphabet[a] != '-')
        {
            key[i] = alphabet[a];
            i++, a++;
        }
        else
        {
            a++;
        }
    }

    // Debugging, print key
    printf("Key->       %s\n", key);

    // Check for if the user would like to decrypt
    if (strcmp(argv[4], "d") == 0)
    {
        printf("Decrypting...\n");
        decrypt = 1;
    }
    else
    {
        printf("Encrypting...\n");
    }

    // Open file stream
    fin = fopen(argv[1], "r");
    fout = fopen(argv[3], "w");

    printf("\n%s -> %s", argv[1], argv[3]);

    if (fin == NULL || fout == NULL)
    {
        printf(" ERROR\n");
        printf("File could not be opened!\n\n");
        exit(1);
    }
    // index to save where letter is in loop
    int num;

    while (fscanf(fin, "%c", &ch) != EOF)
    {
        // If the character is a letter A-Z or a-z
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            if (decrypt)
            {
                // DECRYPTOR HERE
                // Variable fwdAlphabet contains the normal alphabet
                int l = 0;
                while (tolower(ch) != key[l])
                {
                    l++;
                }
                if (isupper(ch))
                {
                    ch = fwdAlphabet[l];
                    fprintf(fout, "%c", toupper(ch));
                }
                else
                {
                    ch = fwdAlphabet[l];
                    fprintf(fout, "%c", ch);
                }
            }
            else
            {
                if (isupper(ch))
                {
                    fprintf(fout, "%c", toupper(key[ch - 'A']));
                }
                else
                {
                    fprintf(fout, "%c", key[ch - 'a']);
                }
            }
        }
        else
        { // If the character is NOT a letter, print to file
            fprintf(fout, "%c", ch);
        }
    }

    printf(" SUCCESS\n\n");

    // Close filestream and end program
    fclose(fin);
    fclose(fout);

    return 1;
}
