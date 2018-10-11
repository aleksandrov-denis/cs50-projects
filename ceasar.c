# cs50-projects
//Copied from what I completed of the cs50 course in school.

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //ensures that key is written in command line
    if (argc == 2)
    {
        //assigns the variable after run code to key
        int key = atoi(argv[1]);
        //ensures that key isn't negative
        if (key < 0)
        {
            return 1;
        }
        //asking for plaingtext
        string plain = get_string("plaintext: ");
        //assigns the string cipher to the lengths of string plain
        char cipher[strlen(plain)];
        //prints "ciphertext: " to output each follow up letter after equation is run
        printf("ciphertext: ");
        //for loop that moves through encripting each concecutive letter
        for (int i = 0, n = strlen(plain); i < n; i++)
        {
            int conv;
            //lowercase letters in ascii table
            if (plain[i] < 123 && plain[i] > 96)
            {
                //adds key # to ascii value of plaintext letter, subtracts ascii value of 'a' so that mod of 26
                //is that same value and adds ascii value of 'a' to output the ascii value of the encripted letter
                conv = (((plain[i] + key) - 97) % 26) + 97;
            }
            //uppercase letters in ascii table
            if (plain[i] < 91 && plain[i] > 64)
            {
                //adds key # to ascii value of plaintext letter, subtracts ascii value of 'A' so that mod of 26
                //is that same value and adds ascii value of 'A' to output the ascii value of the encripted letter
                conv = (((plain[i] + key) - 65) % 26) + 65;
            }
            //assigns every encripted letter to the corresponding place in string cipher
            cipher[i] = conv;
            //prints the encripted letter concecutively
            printf("%c", cipher[i]);
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
