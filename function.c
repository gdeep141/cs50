/*this program caluclates the minimum amount of
coins needed to make change
*/

#include<stdio.h>
#include<cs50.h>

int decrement(int coin);

//global as used in main and decrement
int counter = 0;
float change;

int main(void)
{
    //prompts user for positive amount of change
    do
    {
        printf("How much change is owed? ");
        change = GetFloat();
    }
    while (change < 0);
    
    //converts dollars to cents
    change = change * 100;
    
    decrement(25);
    decrement(10);
    decrement(5);
    decrement(1);
    
    printf("%d \n", counter);
}

//adds 1 to counter for each coin used
int decrement(int coin)
{
    while (change >=  coin)
    {
        change = change - coin;
        counter++;
    }
    return change;
    return counter;
}