#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    int dogit, sum = 0, i, product;
    long long x;
    printf("ISBN: "); //asking for ISBN number.
    x = get_long_long();
    i = 10; //Sifting out seperate numbers.
    while (x > 0)
    {
        dogit = x % 10;
        sum = sum + (dogit * (i--)); //calculates the sum of all of the seperate digits, in ISBN format.
        x = x / 10;
    }
    //specifies remainder variable, when sum is divided by 11. Specific characteristic of valid ISBN numbers.
    product = sum % 11;
    if (product != 0)
    {
        printf("NO\n");
    }
    if (product == 0)
    {
        printf("YES\n");
    }
    return 0;
}
