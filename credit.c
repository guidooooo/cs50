#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long credit_card_number;
    do{
        credit_card_number = get_long("Number: \n");
    }while(credit_card_number<0);

    long num = 1;
    int count = 0;
    long credit_card_prefix = 0;
    for(long x =10; num>0; x = x*10)
    {
        num = credit_card_number / x;

        count +=1;

        if(num <100 && credit_card_prefix == 0)
        {
            credit_card_prefix = num;
        }

        // checking if the number is too long
        if(count == 17 )
        {
            num = 0;
        }
    }

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
