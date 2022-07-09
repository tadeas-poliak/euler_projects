#include <iostream>


using namespace std;


int get_sum_of_Fibonacci_sequence_that_are_divided(int divider, long max)
{
    int result=0;

    //Predchozi cislo Fibonacciho posloupnosti
    int last_number = 1;

    // i = Aktualni cislo Fibonacciho posloupnosti 
    for (int i = 1; i <= max;)
    {
        int prev_last_num = last_number;
        last_number = i;
        i+=prev_last_num;

        if(i % divider == 0)
            result += i;
        
    }
    return result;
}

int main()
{
    cout<<"Vysledek:"<<get_sum_of_Fibonacci_sequence_that_are_divided(2,4000000)<<endl;
}