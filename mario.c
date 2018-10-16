#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    int height;
    printf("Height: ");
    height = get_int();
    while (0 > height || height > 23)
    {
        printf("Height: ");
        height = get_int();
    }
    for (int i = 1; i <= height; i++) // increments through rows
    {
        for (int j = height - i; j > 0; j--) // increments through spaces in a row
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++) //increments through # in row
        {
            printf("#");
        }
        printf("\n");
        // make new line
    }
    return 0;
}
