/**
 * helpers.c
 *
 * CS50 AP
 * Sort Race
 *
 * Helper functions for the sort race
 */
#include <stdio.h>
#include <cs50.h>
#include "helpers.h"
//typedef enum bool{false,true} bool;

void printarray(int values[], int n);

void swapints(int *a, int *b);


//Returns true if str is a valid flag (-a, -b, -r, or -s), false otherwise.

bool check_flag(char *str)
{
    if (str[0] == '-' && (str[1] == 'a' || str[1] == 'b' || str[1] == 'r' || str[1] == 's'))
    {
        return true;
    }
    return false;
}


//Sorts array of n values using bubble sort.

void bubble(int values[], int n)
{
    //declares integer.
    int i;
    for (i = 0; i < n; i++)
    {
        for (i = 1; i < n; i++)
        {
            //if previous value is larger than present value, use swap function.
            if (values[i - 1] > values[i])
            swapints(&values[i], &values[i - 1]);
        }
    }
    return;
}


//Sorts array of n values using selection sort.

void selection(int values[], int n)
{
    //declares integers.
    int i, k, min;
    for (i = 0; i < n - 1; i++)
    {
        //stores iterating value into int min to be able to use it as a swap variable.
        min = i;
        for (k = i + 1; k < n; k++)
        {
            //assign the # of the array of next value to the # of the current, if current value is larger.
            if (values[k] < values[min])
            min = k;
        }
        //if next value != current value, use swap function.
        if (min != i)
        swapints(&values[min], &values[i]);
    }
    return;
}


//Sorts array of n values using insertion sort.

void insertion(int values[], int n)
{
    //declares integers.
    int i, k, move;
    for (i = 1; i < n; i++)
    {
        //assign int i to int k.
        k = i;
        //assigns the value at i to int move.
        move = values[i];
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
    return;
}

//Print array function

void printarray(int values[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i ", values[i]);
    }
    printf("\n");
}

//takes location of int a, location of int b and swaps there values. Returns nothing
//locations in memory.
void swapints(int *a, int *b)
{
    int swap;
    swap = *a;
    *a = *b;
    *b = swap;
}
