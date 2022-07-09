#include <iostream>
#include <math.h>
#include <string>
using namespace std;


long get_sum_of_square_of_number(int from, int to)
{
    long result = 0;
    for (int i = from; i <= to; i++)
        result += i*i;
    
    return result;
}

long get_square_of_sum_of_numbers(int from, int to)
{
    int a1 = from;
    int an = to;
    int n = an - a1 + 1;
    return pow(n/2*(a1+an),2);
}


int main()
{
    long result= get_square_of_sum_of_numbers(1,100) - get_sum_of_square_of_number(1,100);

    cout<<"Vysledek: "<<result<<endl;
}