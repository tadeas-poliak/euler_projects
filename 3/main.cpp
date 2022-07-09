#include <iostream>
#include <math.h>
using namespace std;


bool is_prime_number(long number)
{
    float check = sqrt((float)number);
    for (int i = ceil(check); i > 1; i--)
        if(number % i == 0)
            return false;
    
    return true;
}

long get_largest_prime_factor(long number)
{
    for (long i = ceil(sqrt(number)); i > 0; i--)
    {
        if(number % i == 0 && is_prime_number(i))
            return i;
    }
    return 0;   
}

int main()
{
    cout<<"Vysledek:"<<get_largest_prime_factor(600851475143)<<endl;
}