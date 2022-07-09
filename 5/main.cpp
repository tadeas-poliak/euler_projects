#include <iostream>
#include <math.h>
#include <string>
using namespace std;


int get_smallest_number_dividable_by_numbers(int from,int to)
{
    bool founded = false;
    int number=from;
    while (!founded)
    {
        for (int i = from; i <= to; i++)
        {
            if(number % i != 0)
                break;
            if(i == to && number % i == 0)
                return number;
            
        }
        number++;   
    }
    return 0;   
}

int main()
{
    long result=0;
    
    cout<<"Vysledek: "<<get_smallest_number_dividable_by_numbers(1,20)<<endl;
}