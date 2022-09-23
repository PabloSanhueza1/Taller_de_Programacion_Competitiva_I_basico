#include <iostream>
#include <vector>
#include <string>

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
    int cont1 = 0;
    int cont = 0;

    if (lettersGuessed.size() == 0 && possibleAnswers.size() == 1)
    {
        return possibleAnswers[0];
    }
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
                if ((possibleAnswers[i].find(lettersGuessed[j]) <= possibleAnswers[i].size() && revealed.find(lettersGuessed[j]) > revealed.size()))
                {
                    discard.push_back(i);
                    break;
                }
            }
        }

        string auxString1 = "";

        for (int i = 0; i < revealed.size(); i++)
        {
            if (auxString1.find(revealed[i]) > auxString1.size() && revealed[i] != '_')
            {
                auxString1 += revealed[i];
            }
        }

        cout << "letrita: " << auxString1 << endl;

        for (int i = 0; i < possibleAnswers.size(); i++)
        {
            cont1 = 0;
            cont = 0;
            for (int j = 0; j < possibleAnswers[i].size(); j++)
            {
                for (int k = 0; k < auxString1.size(); k++)
                {
                    if (possibleAnswers[i][j] == auxString1[k])
                        cont1++;
                }
            }

            for (int k = 0; k < possibleAnswers[i].size(); k++)
            {
                if (possibleAnswers[i][k] == revealed[k])
                {
                    cont++;
                }
            }

            cout << possibleAnswers[i] << "  "
                 << "  " << cont1 << "  " << cont << endl;

            int aux = 0;

            for (int k = 0; k < discard.size(); k++)
            {
                if (discard[k] == i)
                {
                    aux = 1;
                    break;
                }
            }

            for (int k = 0; k < index.size(); k++)
            {
                if (possibleAnswers[i][index[k]] != revealed[index[k]])
                {
                    aux = 1;
                    break;
                }
            }

            if (cont == cont1 && aux == 0)
            {
                no_discard.push_back(i);
            }
            cont = 0;
            cont1 = 0;
        }

        if (no_discard.size() == 1)
            return possibleAnswers[no_discard[0]];
        else
            return "";
    }
}
/*
int main()
{
    string a = "grzn";
    string b = "_r_ng_";
    vector<string> c = {"banana", "cherry", "potato"};

    HangmanSolver v;
    string r = v.guess(a, b, c);

    cout << r << endl;

    return 0;
} *//*
  int main()
  {
      string a = "xalv";
      string b = "_a___a";
      vector<string> c = {"camera", "lambda", "saliva", "aaaaa", "rwanda", "canada"}, "camara"};

      HangmanSolver v;
      string r = v.guess(a, b, c);

      cout << r << endl;

      return 0;
  }*/