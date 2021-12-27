#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
bool check_valid_key(string s);

int main(int argc, string argv[])
{
    if (argc != 2 || !check_valid_key(argv[1]))
    {
        printf("Usage:./caesar key\n");
        return 1;
    }
   int key = atoi(argv[1]);// atoi transform from ('a'atoi => askii) to a int (ato'i' => int)string "13" to a number 13
   
   string plaintext = get_string("plaintext: ");
   printf("ciphertext: ");
   
   for (int i = 0, n = strlen(plaintext); i < n; i++)
   {
       char c = plaintext[i];
       if (isalpha(c))
       {
           char m = 'A';
           if ( islower(c))
           m = 'a';
           printf("%c", (c - m + key) % 26 + m);
       }
       else 
       
           printf("%c", c);
       }
       printf("\n");
   
}
   
   bool check_valid_key(string s)
   {
       for (int i = 0, n = strlen(s); i < n; i++)
       if (!isdigit(s[i]))
       return false;
       
       return true;
   }

