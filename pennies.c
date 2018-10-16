
/**
 * pennies.c
 *
 * CS50 AP
 * Old Friends
 *
 * Calculates how many pennies a user would get if their change
 * doubles each day using command line information
 */

#include <cs50.h>
#include <math.h>
#include <stdio.h>

// defined constants
#define MAX_DAYS 31
#define MIN_DAYS 28

int main(int argc, string argv[])
{
    if (argc == 3)
    {
        for (int i = 1; i < argc; i++)
        {
            int days = atoi(argv[1]);
            if (days < MIN_DAYS || days > MAX_DAYS)
            {
                printf("Enter the correct days in a month, try again!\n");
                return 1;
            }
            // get a number of pennies in [0, inf)
            int pennies = atoi(argv[2]);
            if (pennies < 0)
            {
                printf("You cannot start out with negative pennies, try again!\n");
                return 1;
            }
            // relatively few pennies required to get out of bounds of int
            long long total = pennies;
            // add double the amount of pennies of the previous day each day
            for (int k = 1; k < days; k++)
            {
                total += pennies * pow(2, k);
            }
            double vertotal = (((double) total) * 0.01);
            // output the total as dollars and cents only
            printf("$%.2f\n", vertotal);
            return 0;
        }
    }
    if (argc > 3 || argc == 2)
    {
        printf("Code works only if the input is days then pennies, no more nor less integers, try again!\n");
        return 1;
    }
    else if (argc == 1)
    {
        printf("User: ./pennies <int i>\n");
        return 1;
    }
}
