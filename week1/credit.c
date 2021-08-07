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
    int first_checksum_sum = 0;
    int second_checksum_sum = 0;
    int extra_num=0;

    // getting digit quantity and prefix
    // the idea is to divide the credit card number
    // 10 by 10 until the result is equal to 0
    for(long x =10; num>0; x = x*10)
    {
        num = credit_card_number / x;

        //calculating check_sum
        // if it is the first iteration i save the first and the second digit
        if(count == 0){
            second_checksum_sum += credit_card_number%10;
            first_checksum_sum += (num%10)*2;
        }else
        {
            // if it is not the first iteration,
            // and the iteration is not even,
            // i calculate the second sum
            if(count%2 != 0){
                second_checksum_sum += num%10;
            }else{
                // if the iteration is even,
                // i calculate the first sum multiplying by 2
                extra_num = (num%10)*2;
                // if the result is greater than 10,
                // i split the digit before summarize
                if (extra_num>9)
                {
                    first_checksum_sum += ((int) extra_num%10 + (int) extra_num/10);
                }else{
                    first_checksum_sum += (int) extra_num ;
                }
            }
        }

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

    int check_sum = (int )(first_checksum_sum + second_checksum_sum) %10;

    if (check_sum != 0){
        printf("INVALID\n");
    }else{
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

}
