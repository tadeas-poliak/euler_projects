#include <iostream>
#include <math.h>
#include <vector>
using namespace std;



struct Vektor3
{
       public:
              int x=0,y=0,z=0;
              Vektor3()
              {

              }
              Vektor3(int x,int y,int z)
              {
                 this->x = x;
                 this->y = y;
                 this->z = z;    
              }
              float get_size()
              {
                     return sqrt(x*x + y*y + z*z);
              }
};

bool are_numbers_pythagorean_tripltes(int a, int b, int c)
{
    return a*a + b*b == c*c && a < b < c;
}

Vektor3 get_pythagorean_tripltes_with_perimeter(int perimeter)
{
       Vektor3 output= Vektor3(0,0,0);

       for (int a = 1; a < perimeter; a++)
       {
              for (int b = a+1; b < perimeter; b++)
              {
                    int c = sqrt(a*a + b*b);
                    if(are_numbers_pythagorean_tripltes(a,b,c) && a + b + c==perimeter)
                    {
                            output=(Vektor3(a,b,c));
                    }
              }
       }
       return output;
}


int main()
{
    Vektor3 out = get_pythagorean_tripltes_with_perimeter(1000);
    cout<<"Vysledek: "<<out.x*out.y*out.z<<endl;
}