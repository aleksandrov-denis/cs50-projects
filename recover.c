#include <stdio.h>
#include <stdint.h>
#include <cs50.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    char *data = argv[1];
    char file[7];
    //initializing buffer for block of 512 bytes
    BYTE buff[512];
    //bool value for whether a JPEG header is present
    bool present = false;
    //integer for .jpg number
    int num = 1;
    //initializes read file and its pointer
    FILE *inptr = fopen(data, "r");
    //initializes outfile pointer
    FILE *outptr;
    //if file does not open properly, close program and report to user
    if (inptr == NULL)
    {
        printf("Failed to open %s\n", data);
        return 2;
    }
    //while program is reading from card.raw properly, proceed
    while (fread(buff, 512, 1, inptr) == 1)
    {
        //cheching whether first four bytes indicate JPEG header
        if (buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0)
        {
            if (present == true)
            {
                fclose(outptr);
                //name JPEG
                sprintf(file, "%03i.jpg", num);
                //iterate to next JPEG
                num++;
                outptr = fopen(file, "w");
                fwrite(buff, 512, 1, outptr);
            }
            //if begining of JPEG not present, run again
            else
            {
                sprintf(file, "%03i.jpg", 0);
                present = true;
                outptr = fopen(file, "w");
                fwrite(buff, 512, 1, outptr);
            }
        }
        //read again
        else if (present == true)
        {
            fwrite(buff, 512, 1, outptr);
        }
    }
    //all done!
    return 0;

}
