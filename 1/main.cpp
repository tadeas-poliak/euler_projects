#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


int get_sum_of_multiplies(int multiplyA,int multiplyB,int max)
{
    int result=0;
    for (int i = 0; i < max; i++)
    {
        if(i % multiplyA == 0 || i % multiplyB == 0)
            result += i;
    }
    return result;
}

int main()
{
    cout<<"Vysledek:"<<get_sum_of_multiplies(3,5,1000)<<endl;
}