#include <iostream>
#include <math.h>
#include <string>
using namespace std;


bool is_number_palindrome(long number)
{
    string number_s = to_string(number);
    for (int i = 0; i < floor(number_s.size()/2); i++)
    {
        if(number_s[i] != number_s[number_s.size()-1 - i])
            return false;
    }
    
    return true;
}

int main()
{
    long result=0;
    for (int x = 999; x >= 100; x--)
    {
        for (int y = 999; y >= 100; y--)
        {
            if(is_number_palindrome(x*y))
            {
                if(result < x*y)
                    result = x*y;
                
            }
        }
    }
    
    cout<<"Vysledek: "<<result<<endl;
}