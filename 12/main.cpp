#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

unsigned int get_nth_triangular_number(unsigned int n)
{
    return n * ((1 + n) / 2);
}

bool is_a_prime_number(unsigned int num)
{
    if (num == 2 || num == 1)
        return true;
    if (num <= 0)
        return false;

    for (int i = ceil((float)(sqrt(num))); i > 1; i--)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
struct factor
{
public:
    unsigned int count;
    unsigned int number;
    factor(unsigned int count, unsigned int number)
    {
        this->count = count;
        this->number = number;
    }
};

bool is_between_factors(unsigned int value, std::vector<factor> factors)
{
    for (int i = 0; i < factors.size(); i++)
    {
        if (factors[i].number == value)
            return true;
    }
    return false;
}

unsigned int get_index_in_factors(unsigned int value, std::vector<factor> factors)
{
    for (int i = 0; i < factors.size(); i++)
    {
        if (factors[i].number == value)
            return i;
    }
}

unsigned int get_number_of_factors(unsigned int num)
{
    if (num == 1)
        return 1;
    std::vector<factor> factors;
    for (int i = 2; i <= ceil((float)num / 2); i++)
    {
        if (is_a_prime_number(num))
        {
            if (is_between_factors(num, factors))
                factors[get_index_in_factors(num, factors)].count += 1;
            else
                factors.push_back(factor(1, num));
            
            break;
        }
        if ((is_a_prime_number(i) && num % i == 0))
        {
            if (is_between_factors(i, factors))
                factors[get_index_in_factors(i, factors)].count += 1;
            else
                factors.push_back(factor(1, i));
            
            num /= i;
            i = 1;
        }
    }
    unsigned int result = 1;
    if (factors.size() == 0)
        return 2;

    for (int i = 0; i < factors.size(); i++)
        result *= (factors[i].count + 1);
    
    return result;
}

int main()
{
    unsigned int result = 0;

    for (int i = 1; ; i++)
    {
        if(get_number_of_factors(get_nth_triangular_number(i)) > 500)
        {
            result = get_nth_triangular_number(i);
            break;
        }
    }
    std::cout<<"Vysledek: "<<result<<std::endl;
}