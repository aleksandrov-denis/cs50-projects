#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>     

int main(int argc, string argv[])
{
    //ensures that key is written in command line
    if (argc == 2)
    {
        //garantees that key text doesn't have a number in it
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Something went wrong, try again!\n");
                return 1;
            }
        }
        //asking for plaintext
        string plain = get_string("plaintext: ");
        //prints "ciphertext: " to output each follow up letter after equation is run
        printf("ciphertext: ");
        for (int k = 0, l = strlen(plain); k < l; k++)
        {
            //takes length of argv and uses it as mod for which argv[1] string to focus on
            int n = strlen(argv[1]);
            int t = k % n;
            //assigns the chars after run code to key
            int key = argv[1][t];
            //lowercase letters in ascii table
            if (key < 123 && key > 96)
            {
                key = ((key - 97) % 26);
            }
            //uppercase letters in ascii table
            else if (key < 91 && key > 64)
            {
                key = ((key - 65) % 26);
            }
            else
            {
                return 1;
            }
            //assigns the string cipher to the lengths of string plain
            char cipher[strlen(plain)];
            //for loop that moves through encripting each concecutive letter
            int conv;
            //lowercase letters in ascii table
            if (plain[k] < 123 && plain[k] > 96)
            {
                //adds key # to ascii value of plaintext letter, subtracts ascii value of 'a' so that mod of 26
                //is that same value and adds ascii value of 'a' to output the ascii value of the encripted letter
                conv = (((plain[k] + key) - 97) % 26) + 97;
            }
            //uppercase letters in ascii table
            if (plain[k] < 91 && plain[k] > 64)
            {
                //adds key # to ascii value of plaintext letter, subtracts ascii value of 'A' so that mod of 26
                //is that same value and adds ascii value of 'A' to output the ascii value of the encripted letter
                conv = (((plain[k] + key) - 65) % 26) + 65;
            }
            if (plain[k] > 90 && plain[k] < 95)
            {
                conv = plain[k];
            }
            if (plain[k] < 65 || plain[k] > 122)
            {
                conv = plain[k];
            }
            //assigns every encripted letter to the corresponding place in string cipher
            cipher[k] = conv;
            //prints the encripted letter concecutively
            printf("%c", cipher[k]);
        }
        //breaks text
        printf("\n");
        return 0;
    }
    //ensures that command line string has a length none other than 2
    if (argc != 2)
    {
        printf("Something went wrong, try again!\n");
        return 1;
    }
}
