#include <stdio.h>
#include <cs50.h>

void print_level(int);

int main(void)
{
    int level_num;
    do
    {
        level_num = get_int("Insert how much levels you would like\n");

    }
    while(level_num<1 || level_num>8);

    print_level(level_num);

}

void print_left_level(int, int);
void print_right_level(int);

void print_level(int n)
{
    for(int x = 0; x<n ; x++)
    {
        print_left_level(n,x);
        printf("  ");
        print_right_level(x);
        printf("\n");
    }
}

void print_left_level(int n, int x)
{
    for(int y = n; y>x+1; y--)
    {
        printf(" ");
    }
    for(int y = 0; y<=x; y++)
    {
        printf("#");
    }
}

void print_right_level(int x)
{
    for(int y = 0; y<=x; y++)
    {
        printf("#");
    }
}
