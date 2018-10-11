/**
 * helpers.c
 *
 * CS50 AP
 * Find
 *
 * Helper functions.
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
#include <string.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (value < 1)
    {
        return false;
    }
    // TODO: implement a searching algorithm
    int x;
    for (x = 0; x < n; x++)
    {
        //middle of array if n is even
        int halfeven = n / 2;
        //middle of array if n is odd
        int halfodd = (n - 1) / 2;
        //if n is nonpositive, then stop
        if (n < 1)
        {
            return false;
        }
        //if len is even, check right and left
        if (n % 2 == 0)
        {
            int i;
            //check if needle is in middle of array
            if (values[halfeven] == value)
            {
                return true;
            }
            //checking if needle is to the left of middle of array
            for (i = halfeven; i >= 0; i--)
            {
                if (values[i] == value)
                {
                    return true;
                }
            }
            //checking if needle is to the right of middle of array
            for (i = halfeven; i <= n; i++)
            {
                if (values[i] == value)
                {
                    return true;
                }
            }
            //if none of the above, then stop
            return false;
        }
        //if len is odd, check right and left
        else
        {
            int k;
            //check if needle is in middle of array
            if (values[halfodd] == value)
            {
                return true;
            }
            //checking if needle is to the right of middle of array
            for (k = halfodd; k <= n; k++)//fix
            {
                if (values[k] == value)
                {
                    return true;
                }
            }
            ////checking if needle is to the left of middle of array
            for (k = halfodd; k >= 0; k--)
            {
                if (values[k] == value)
                {
                    return true;
                }
            }
            //if none of the above, then stop
            return false;
        }
    }
    //if none of the above, then stop
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    //Sorts array of n values using insertion sort.
    //declares integers.
    int x, k, move;
    for (x = 1; x < n; x++)
    {
        //assign int i to int k.
        k = x;
        //assigns the value at i to int move.
        move = values[x];
        //while int k is more than 0 and value at k - 1 is more than value of value at i,
        //then assign value of k - 1 to the k array and subtract one from int k.
        while (k > 0 && values[k - 1] > move)
        {
            values[k] = values[k - 1];
            k--;
        }
        //end of swap, value of array i is assigned to the k array.
        values[k] = move;
    }
}
