#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct Vektor2
{
       public:
              int x,y;
              Vektor2(int x,int y)
              {
                 this->x = x;
                 this->y = y;    
              }
              float get_size()
              {
                     return sqrt(x*x + y*y);
              }
};

struct Vektor3
{
       public:
              int x,y,z;
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


bool is_right_angle_triangle(float a, float b, float c)
{
       return sqrt(a*a + b*b) == c;
}

//Vrati strany pravouhleho trojuhelniku, ktere maji soucet 'perimeter'
vector<Vektor3> get_possible_sides_of_perimeter(int perimeter)
{
       vector<Vektor3> output;
       int count = 0;
       vector<int> found_a;
       //strana a
       for (int a = 1; a < perimeter; a++)
       {
              //strana b
              for (int b = a; b < perimeter; b++)
              {
                     //strana c = obvod - a - b
                    if(is_right_angle_triangle(a,b,perimeter-a-b))
                    {
                            output.push_back(Vektor3(a,b,perimeter-a-b));
                    }
              }
       }
       return output;
}

int main()
{
       int max_solutions = 0;
       int result = 0;
      for (int p = 1; p <= 1000; p++)
      {
              cout<<p<<endl;
              vector<Vektor3> out = get_possible_sides_of_perimeter(p);
              for (int i = 0; i < out.size(); i++)
              {
                     cout<<"\t"<<out[i].x<<", "<<out[i].y<<", "<<out[i].z<<endl;
              }
              cout<<"\t"<<out.size()<<endl;
              if(max_solutions < out.size())
              {
                     max_solutions = out.size();
                     result = p;
              }
      }
      cout<<"Vysledek: "<<result;
}