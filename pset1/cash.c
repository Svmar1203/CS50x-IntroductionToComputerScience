#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) 
{
    float dollar;// use float, can handle dollars and cents, number might have a decimal
    do
    {
        dollar = get_float("Enter your change: ");//prompt the user how much change is owed in dollars
    }
    while (dollar <= 0);// check is value is non negative
    
    int cents = round(dollar * 100); // convert the number of dollars in to cents ant round cents to nearest penny
    int coints = 0;
    
    while (cents >= 25)
    {
        cents -= 25;// cents = cents - 25;
        coints++;
    }
    while (cents >= 10)
    {
        cents -= 10;
        coints++;
    }
    while (cents >= 5)
    {
        cents -= 5;
        coints++;
    }
    while (cents >= 1)
    {
        cents -= 1;
        coints++;
    }
    printf("%i\n", coints);// Print out that number of coins to the screen
}