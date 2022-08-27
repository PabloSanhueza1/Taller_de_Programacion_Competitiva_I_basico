#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

class RecipeFraction
{
public:
    double getFraction(vector<string>, vector<string>);
};
//test
double RecipeFraction::getFraction(vector<string> recipe, vector<string> ingredients)
{
    double f = 0.e-9;
    double total = 0.e-9;
    string aux;

    // calcular total
    for (int i = 0; i < recipe.size(); i++)
    {
        aux = "";
        for (int j = 0; j < recipe[i].size(); j++)
        {
            if (recipe[i][j] >= '0' && recipe[i][j] <= '9')
            {
                aux.push_back(recipe[i][j]);
            }
        }
        if (aux.size() == 2)
        {
            total += 10;
        }
        else
        {
            total += aux[0] - 48;
        }
    }

    // calcular total
    /*
    for (int i = 0; i < recipe.size(); i++)
    {
        for (int j = 0; j < recipe[i].size(); j++)
        {
            if (recipe[i][j] == '1')
            {
                if (recipe[i][j + 1] == '0')
                {
                    total += 10;
                    break;
                }
                else
                {
                    total += 1;
                    break;
                }
            }

            else
            {
                if (recipe[i][j] >= '0' && recipe[i][j] <= '9')
                {
                    total += recipe[i][j] - 48;
                    break;
                }
            }
        }
    }*/

    // calcular la fraccion * total
    for (int i = 0; i < ingredients.size(); i++)
    {
        for (int j = 0; j < recipe.size(); j++)
        {
            cout << f << " " << total << endl;

            cout << ingredients[i] << " " << total << endl;

            if (ingredients[i] != "" && recipe[j].find(ingredients[i]) <= recipe[j].size())
            { /*
                 for (int k = 0; k < recipe[j].size(); k++)
                 {
                     if (recipe[j][k] == '1')
                     {
                         if (recipe[j][k + 1] == '0')
                         {
                             f += 10;
                             break;
                         }
                         else
                         {
                             f += 1;
                             break;
                         }
                     }

                     else
                     {
                         if (recipe[j][k] >= '0' && recipe[j][k] <= '9')
                         {
                             f += recipe[j][k] - 48;
                             break;
                         }
                     }
                 }*/

                aux = "";
                for (int k = 0; k < recipe[i].size(); k++)
                {
                    if (recipe[j][k] >= '0' && recipe[j][k] <= '9')
                    {
                        aux.push_back(recipe[j][k]);
                    }
                }
                if (aux.size() == 2)
                {
                    f += 10;
                }
                else
                {
                    f += aux[0] - 48;
                }
            }
        }
    }
    int aux2 = setprecision(3);
     return f / total;
}

int main()
{
    vector<string> a = {"                        2 GRAPES",
                        " 1 0        APPLES",
                        "3       STRAWBERRIES"};
    vector<string> b = {"GRAPES", ""};
    RecipeFraction v;

    double r = v.getFraction(a, b);
    cout << r << endl;

    return 0;
}