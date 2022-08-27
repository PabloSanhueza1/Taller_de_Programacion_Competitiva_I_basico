#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class HangmanSolver
{
public:
    string guess(string, string, vector<string>);
};

string HangmanSolver::guess(string lettersGuessed, string revealed, vector<string> possibleAnswers)
{
    vector<int> index;
    vector<int> no_discard;
    vector<int> discard;

    int cont = 0;

    if (lettersGuessed.size() == 0 && possibleAnswers.size() == 1)
        return possibleAnswers[0];
    else
    {
        for (int i = 0; i < revealed.size(); i++)
        {
            if (revealed[i] != '_')
            {
                index.push_back(i);
            }
        }

        for (int i = 0; i < possibleAnswers.size(); i++)
        {
            for (int j = 0; j < lettersGuessed.size(); j++)
            {
                // cout << "Buscar " << lettersGuessed[j] << " en " << possibleAnswers[i] << " Y ademas " << lettersGuessed[j] << " en " << revealed<< endl;
                if ((possibleAnswers[i].find(lettersGuessed[j]) <= possibleAnswers[i].size() && revealed.find(lettersGuessed[j]) > revealed.size()) || possibleAnswers[i].size() < revealed.size() || possibleAnswers[i].size() > revealed.size())
                {
                    discard.push_back(i);
                    break;
                }
            }
        }

        for (int i = 0; i < possibleAnswers.size(); i++)
        {

            for (int k = 0; k < index.size(); k++)
            {
                if (possibleAnswers[i][index[k]] == revealed[index[k]])
                {
                    cont++;
                }
            }
            int aux = 0;
            for (int k = 0; k < discard.size(); k++)
            {
                if (discard[k] == i)
                {
                    aux = 1;
                    break;
                }
            }

            if (cont == index.size() && aux == 0)
            {
                no_discard.push_back(i);
            }

            cont = 0;
        }
        if (no_discard.size() == 1)
            return possibleAnswers[no_discard[0]];
        else
            return "";
    }
    return "";
}

int main()
{
    string a = "hos";
    string b = "___";
    vector<string> c = {"lakas",
                        "holassas",
                        "pel"
                        };

    HangmanSolver v;
    string r = v.guess(a, b, c);

    cout << r << endl;

    return 0;
}
