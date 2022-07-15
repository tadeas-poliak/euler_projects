#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct Vektor2
{
       public:
              long x,y;
              Vektor2()
              {}
              Vektor2(long x,long y)
              {
                     this->x = x;
                     this->y = y;
              }
              bool equals(Vektor2 B)
              {
                     return x == B.x && y == B.y;
              }

};


long get_possible_ways_in_grid_from_A_to_B(Vektor2 grid_size,Vektor2 A,Vektor2 B)
{
       long numx = 0;
       long numy = 0;
       if(A.equals(B))
              return 1;
       if(A.x + 1 <= grid_size.x)
              numx += get_possible_ways_in_grid_from_A_to_B(grid_size,Vektor2(A.x+1,A.y),B);
       if(A.y + 1 <= grid_size.y)
              numy += get_possible_ways_in_grid_from_A_to_B(grid_size,Vektor2(A.x,A.y+1),B);
       return numx + numy;
}

int main()
{
       long result = get_possible_ways_in_grid_from_A_to_B(Vektor2(20,20),Vektor2(0,0),Vektor2(20,20));
       
       cout<<"Vysledek: "<<result<<endl;
}