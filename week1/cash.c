#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){

    float dollars = 0;
    int total_coins = 0;
    do{
        dollars = get_float("How much change is owed? \n");
    }while(dollars<0);


    dollars = dollars - (int)dollars;
    printf("%f\n", dollars);
    int cents = round(dollars * 100);

    total_coins += (cents / 25);
    cents -= (cents / 25)*25;
    total_coins += (cents / 10);
    cents -= (cents / 10)*10;
    total_coins += (cents / 5);
    cents -= (cents / 5)*5;
    total_coins += (cents / 1);
    cents -= (cents / 1)*1;
    printf("%i\n", total_coins);

}
