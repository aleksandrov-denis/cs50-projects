#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int A, B, C, D;
    int pennies, nickles, dimes, quarters, b, c, d, Change, T;
    double change;
    //Statements.
    printf("Hello there! How much change do I owe you?: ");
    change = get_double();
    while (change < 0)
    {
        printf("Declared change must be a positive number, please try again: ");
        change = get_double();
    }
    pennies = 1;
    nickles = 5;
    dimes = 10;
    quarters = 25;
    //Solve for ideal change.
    Change = change * 100;
    A = Change / quarters;
    b = Change % quarters;
    B = b / dimes;
    c = b % dimes;
    C = c / nickles;
    d = c % nickles;
    D = d / pennies;
    T = A + B + C + D;
    //Output.
    printf("%d\n", T);
    return 0;
}
