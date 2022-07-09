#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;



int string_to_number(string in)
{
       int output=0;
       for (int i = 0; i < in.size(); i++)
              output += ((int)in[i]-(int)'0') * pow(10,in.size()-1-i);
       
       return output;
}


vector<vector<int>> make_grid(string numbers_input)
{
       vector<vector<int>> output;
       //Radek
       vector<int> row;
       string number = "";

       for (int i = 0; i < numbers_input.size(); i++)
       {
              //Vyporadani s nulami
              if(i < numbers_input.size()-1)
                     if(numbers_input[i] == '0' && numbers_input[i+1] == '0')
                            continue;  
              
              //pridani cisla do radku (cisla jsou oddeleny mezerou)
              if(numbers_input[i] == ' ')
              {
                     row.push_back(string_to_number(number));
                     number = "";
                     continue;
              }
              //pridani radku
              if(numbers_input[i] == '\n')
              {
                     output.push_back(row);
                     number = "";
                     row.clear();
                     continue;
              }
              number += numbers_input[i];
       }
       return output;
}



int get_greatest_product_of_n_adjacent_numbers(vector<vector<int>> grid,int n)
{
       int result=0;
       //radek
       for (int y = 0; y < grid.size(); y++)
       {
              //sloupec
              for (int x = 0; x < grid[y].size(); x++)
              {    
                     //------- SVISLE ---------
                     //kontrola cisel doprava
                     int product=1;
                     for (int i = 1; i <= n; i++)
                     {
                            //kontrola, zda jsme nepresahi rozmery gridu
                            if(x+i >= grid[y].size())
                                   break;
                            product *= grid[y][x+i];         
                     }
                     if(product > result)
                            result = product;
                     
                     //kontrola cisel doleva
                     product=1;
                     for (int i = 1; i <= n; i++)
                     {
                            //kontrola, zda jsme nepresahi rozmery gridu
                            if(x-i < 0)
                                   break;
                            product *= grid[y][x-i];         
                     }
                     if(product > result)
                            result = product;

                     //kontrola cisel nahoru
                     product=1;
                     for (int i = 1; i <= n; i++)
                     {
                            //kontrola, zda jsme nepresahi rozmery gridu
                            if(y-i < 0)
                                   break;
                            product *= grid[y-i][x];         
                     }
                     if(product > result)
                            result = product;

                     //kontrola cisel dolu
                     product=1;
                     for (int i = 1; i <= n; i++)
                     {
                            //kontrola, zda jsme nepresahi rozmery gridu
                            if(y+i >= grid.size())
                                   break;
                            product *= grid[y+i][x];         
                     }
                     if(product > result)
                            result = product;

                     // --------------  DIAGONALNE -------------
                     //kontrola cisel diagonalne doleva nahoru
                     product=1;
                     for (int i = 1; i <= n; i++)
                     {
                            //kontrola, zda jsme nepresahi rozmery gridu
                            if(y-i < 0 || x-i < 0)
                                   break;
                            product *= grid[y-i][x-i];         
                     }
                     if(product > result)
                            result = product;
                     
                     //kontrola cisel diagonalne nahoru doprava
                     product=1;
                     for (int i = 1; i <= n; i++)
                     {
                            //kontrola, zda jsme nepresahi rozmery gridu
                            if(y-i < 0 || x+i >= grid[y].size())
                                   break;
                            product *= grid[y-i][x+i];         
                     }
                     if(product > result)
                            result = product;

                     //kontrola cisel diagonalne dolu doleva
                     product=1;
                     for (int i = 1; i <= n; i++)
                     {
                            //kontrola, zda jsme nepresahi rozmery gridu
                            if(x+i < 0 || y+i >= grid.size())
                                   break;
                            product *= grid[y+i][x-i];         
                     }
                     if(product > result)
                            result = product;

                     //kontrola cisel diagonalne dolu doprava 
                     product=1;
                     for (int i = 1; i <= n; i++)
                     {
                            //kontrola, zda jsme nepresahi rozmery gridu
                              if(x+i >= grid[y].size() || y+i >= grid.size())
                                   break;
                            product *= grid[y+i][x+i];         
                     }
                     if(product > result)
                            result = product;
              }
       }
       return result;
       
}

int main()
{
       fstream input_file("input.txt");
       string line,input;

       while ( getline(input_file,line) )
              input += line + '\n';


       vector<vector<int>> grid = make_grid(input);
       int result = get_greatest_product_of_n_adjacent_numbers(grid,4);
       

       cout<<"Vysledek: "<<result<<endl;
}