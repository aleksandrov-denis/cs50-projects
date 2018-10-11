#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    float C;
    double F;
    //statements
    printf("C: ");
    C = get_float();
    //computeforF
    F = ((C * 9) / 5) + 32;
    printf("F: %.1f\n", F);
    return 0;
}
