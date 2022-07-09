#include <iostream>
#include <cctype>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int get_alphabetical_position(char character)
{
    return (int)tolower(character) - (int)'a'+1;
}

int get_t(int n)
{
    return (n*(n+1))/2;
}

int get_sum_of_chars(string chars)
{
    int output=0;
    for (int i = 0; i < chars.size(); i++)
    {
        output+=(int)get_alphabetical_position(chars[i]);
    }

    return output;
}


bool is_number_tringular_number(int t)
{
    for (int i = 1; i <= t; i++)
    {
        if(get_t(i) == t)
            return true;
    }
    return false;
}

int main()
{
    std::vector<string> vektor;
    std::ifstream slova("slova.txt");
    std::string slovo;
    int i = 0;
    while (getline(slova,slovo));
    slova.close();
    string s;
    for (int i = 0; i < slovo.size(); i++)
    {
            if(slovo[i] == ',')
            {
                vektor.push_back(s);
                s.clear();
                continue;
            }
             if(slovo[i] != '\"' && slovo[i] != ' ')
             {
                s.push_back(slovo[i]);
             }
    }
    
    int num_of_tri=0;
    for (int i = 0; i < vektor.size(); i++)
    {
        if(is_number_tringular_number(get_sum_of_chars(vektor[i])))
            num_of_tri++;
    }
    cout<<"Result: "<<num_of_tri<<endl;    
}