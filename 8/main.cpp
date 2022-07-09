#include <iostream>
#include <fstream>
#include <string>
using namespace std;



long get_largest_product_of_adjacent_digit(int num_of_adjacent_mubers,string numbers)
{
    long result = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        if(i + num_of_adjacent_mubers >= numbers.size())
            return result;

        long number = 1;
        for (int k = 0; k < num_of_adjacent_mubers; k++)
            number *= ((int)(numbers[i+k])-(int)'0');
        
        if(number > result)
            result = number;
    }
    return result;
}


int main()
{   
    string input="";

    fstream input_file("input.txt");
    string line;

    while ( getline(input_file,line) )
        input += line;
    
    cout<<input<<endl;
    cout<<"Vysledek: "<<  get_largest_product_of_adjacent_digit(13,input)<<endl;
}