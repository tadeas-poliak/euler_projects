#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


bool is_prime_number(long number)
{

       if(number == 1)
              return false;

       if(number == 2)
              return true;   
       float check = sqrt((float)number);

       for (int i = ceil(check); i > 1; i--)
              if(number % i == 0)
              return false;
       
       return true;
}

int main()
{
       long result = 0;  
       for (long i = 2; i  < 2000000; i++)
       {
              if(is_prime_number(i))
                     result += i;
       }
       cout<<"Vysledek: "<<result<<endl;
}