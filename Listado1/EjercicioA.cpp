#include <iostream>
#include <vector>

using namespace std;
class Chooser
{
public:
    int numSets(vector<int>, vector<int>, vector<int>);
};
int Chooser::numSets(vector<int> easy, vector<int> middle, vector<int> hard)
{
    // int tame = 3, tamm = 3, tamd = 3, comb;
    /*
        for (int i = 0; i < easy.size(); i++)
        {
            if (easy[i] == 0) tame--;
        }
        for (int i = 0; i < middle.size(); i++)
        {
            if (middle[i] == 0) tamm--;
        }
        for (int i = 0; i < hard.size(); i++)
        {
            if (hard[i] == 0) tamd--;
        }
    */
    int comb = 0;

    for (int i = 0; i < easy.size(); i++)
    {
        for (int j = 0; j < middle.size(); j++)
        {
            for (int k = 0; k < hard.size(); k++)
            {

                if (easy[i] + middle[j] + hard[k] >= 60 && easy[i] + middle[j] + hard[k] <= 75)
                {
                    comb++;
                }
            }
        }
    }
    return comb;
}