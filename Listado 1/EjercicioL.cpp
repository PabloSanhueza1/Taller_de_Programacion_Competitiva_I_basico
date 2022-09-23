#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class RecipeFraction
{
public:
    double getFraction(vector<string>, vector<string>);
};

double RecipeFraction::getFraction(vector<string> recipe, vector<string> ingredients)
{
    double f = 0;
    double total = 0;
    int flag = 0;
    string aux;

    vector<int> v;
    string r_recipe[recipe.size()];

    for (int i = 0; i < recipe.size(); i++)
    {
        stringstream linea(recipe[i]);
        int auxInt;
        while (linea >> auxInt)
        {
            v.push_back(auxInt);
        }
        total += v[i];
    }

    for (int i = 0; i < recipe.size(); ++i)
    {
        if (recipe[i][1] != '0')
        {
            for (int j = 0; j < recipe[i].size(); ++j)
            {
                if (recipe[i][j + 2] >= 'A' && recipe[i][j + 2] <= 'Z')
                {

                    r_recipe[i].push_back(recipe[i][j + 2]);
                }
                if (r_recipe[i].size() == (recipe[i].size() - 2))
                    break;
            }
        }
        else
        {
            for (int j = 0; j < recipe[i].size(); ++j)
            {
                if (recipe[i][j + 3] >= 'A' && recipe[i][j + 3] <= 'Z')
                {
                    r_recipe[i].push_back(recipe[i][j + 3]);
                }
                if (r_recipe[i].size() == (recipe[i].size() - 3))
                    break;
            }
        }
    }

    // calcular suma de cada ingrediente
    for (int i = 0; i < ingredients.size(); i++)
    {
        for (int j = 0; j < recipe.size(); j++)
        {
            if (ingredients[i] != "" && r_recipe[j] == ingredients[i])
            {
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
                cout << "f: " << f << endl;
            }
        }
    }
    return f / total;
}
/*
int main()
{
    vector<string> a = {"2 GRAPES",
                        "1 APPLES",
                        "3 STRAWBERRIES"};
    vector<string> b = {"APPLES"};
    RecipeFraction v;

    double r = v.getFraction(a, b);
    cout << r << endl;

    return 0;
}*/