#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 4)
    {
        //initializes and assigns arrays to variables.
        float first = atof(argv[1]);
        float second = atof(argv[3]);
        //initializes all variables used in switch.
        float plus, min, mult, divis;
        //initializes variable which controls for length of inputted operator.
        char h = strlen(argv[2]);
        if (h == 1)
        {
            //states exctly what to do for each inputted operator in third array.
            switch (argv[2][0])
            {
                case '+':
                {
                    plus = first + second;
                    printf("%f\n", plus);
                    break;
                    return 0;
                }
                case '-':
                {
                    min = first - second;
                    printf("%f\n", min);
                    break;
                    return 0;
                }
                case 'x':
                {
                    mult = first * second;
                    printf("%f\n", mult);
                    break;
                    return 0;
                }
                case '/':
                {
                    divis = first / (second);
                    printf("%f\n", divis);
                    break;
                    return 0;
                }
                case '%':
                {
                    //modulo replacement
                    int mod = first / second;
                    float a = mod * second;
                    float b = first - a;
                    printf("%f\n", b);
                    break;
                    return 0;
                }
                //controls for specific operators.
                default:
                {
                    return 1;
                }
            }
        }
        //controls for length of array.
        else
        {
            return 1;
        }
    }
    //tells user exactly which format is needed to run code.
    else if (argc == 1 || argc > 4)
    {
        printf("User: ./calc <(int i) (operator) (int i2)\n");
        return 1;
    }
}
