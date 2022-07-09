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


int nth_prime_number(int n)
{
    int number = 2;
    for (int number_of_primes = 1;;)
    {
  
        
        if(is_prime_number(number))
        {
            number_of_primes++;
            if(number_of_primes >= n)
                return number;
        }
        number++;
    }
    return 0;
}

int main()
{
    
    
    cout<<"Vysledek: "<<nth_prime_number(10001)<<endl;
}