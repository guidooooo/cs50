#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // getting credit number until is a valid format
    long credit_card_number;
    do{
        credit_card_number = get_long("Number: \n");
    }while(credit_card_number<0);

    // initializing variables
    long num = 1;
    int count = 0;
    long credit_card_prefix = 0;

    // getting digit quantity and prefix
    // the idea is to divide the credit card number
    // 10 by 10 until the result is equal to 0
    for(long x =10; num>0; x = x*10)
    {
        num = credit_card_number / x;

        count +=1;

        // if the rest is less than 100,
        // it means that we get the first two digit
        // so I save it as the credit card prefix
        if(num <100 && credit_card_prefix == 0)
        {
            credit_card_prefix = num;
        }

        // checking if the number is too long
        // if digit number is greater than 16,
        // I skip the process
        if(count == 17 )
        {
            num = 0;
        }
    }

    // Checking credit card brand
    if(count == 15 && (credit_card_prefix  == 34 || credit_card_prefix ==37))
    {
        printf("AMEX\n");
    }else if((count == 13 || count == 16) && (credit_card_prefix/10) == 4 )
    {
        printf("VISA\n");
    }else if((count == 16) && (credit_card_prefix >= 51 && credit_card_prefix<=55))
    {
        printf("MASTER\n");

    }else{
        printf("INVALID\n");
    }

}
