//
//  main.c
//  Secure Coding - BufferOverflow1
//



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void usage(char *arg)
{
    char buf[100]; // creating an array of chars with 100 bytes
    //strcpy(buf, arg); // (Dest, Src).strcpy is used to copy an array of bytes that are terminated by a NULL byte (a C string) from one address (the second parameter) to another address (the first parameter). Usually, it is used to copy a string from one memory location to a totally different memory location
    strncpy(buf, arg, 99);//coping the string up to 99 charecter (buffsize-1)
    buf[99]='\0';// setting the last charecter to be a NULL char.
    /*For a "safer strcpy()", you are better off using strncat() like so:
    
    if (dest_size > 0)
    {
        dest[0] = '\0';
        strncat(dest, source, dest_size - 1);
    }
    That will always nul-terminate the result, and won't copy more than necessary.*/
    if (strcmp(buf, "--help") == 0 ||
        strcmp(buf, "-h") == 0)
    {
        printf("\nUsage: overflow [--help]\n\n");
        printf(" --help (-h) : Displays this Message.\n\n");
    }
    else
    {
        printf("\nUnknown Option: \"%s\"\n\n", buf);
    }
}

int main (int argc, char **argv)
{
    
    if (argc == 2)
    {
        usage(argv[1]);
    }
    else
    {
        printf("\nThis program prints this line.\n\n");
    }
    
    return 0;
    
}
