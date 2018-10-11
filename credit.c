#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long long num = 0;
    num = get_long_long("Number:");
    int sum = 0;
    int length = log10(num) + 1;
    long long numI = num;
    //for use in two different places of text
    if ((length != 13) && (length != 15) && (length != 16))
        //checks the length of the number given
    {
        printf("INVALID\n");
        return 0;
    }
    for (int i = 0; i < length; i++)
        //using Luhn's Algorithm to calculate the sum

    {
        int digit = num % 10;
        //finding and isloating a specific digit
        num = num / 10;
        if ( i % 2 == 1)
            //takes every other digit starting from the second right most, the even number of digits within total
        {
            int IIdigit = (digit * 2);
            //states to multiply evens by two
            if (IIdigit < 10)
                //keep in mind if 2(digit) is larger or smaller than 10, bc you add up the digits of the products
            {
                sum = sum + IIdigit;
                //if less
            }
            else
            {
                sum = sum + IIdigit - 9;
                //if more than sum of digits, its sum of 2(digit) - 9.
            }
        }
        else
        {
            sum = sum + digit;
            //for odd digit placements
        }
    }
    if (0 != sum % 10)
        //mod10 check
    {
        printf("INVALID sum=%d length=%d\n", sum, length);
        return 0;
    }
    long long front = pow(10.0, (length - 2));
    //to leave the front two digits
    int digitf = numI / front;
    if ( digitf == 34 || digitf == 37)
    {
        printf("AMEX\n");
    }
    else if (  50 < digitf && digitf < 56  )
    {
        printf("MASTERCARD\n");
    }
    else if (digitf >= 40 && digitf < 50)
    {
        printf("VISA\n");
    }
}
