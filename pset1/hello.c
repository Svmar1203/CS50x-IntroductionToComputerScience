#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    string name = get_string("What's your name?\n");// promt from user get Name
    printf("Hello, %s\n", name);// output to screen answer
}