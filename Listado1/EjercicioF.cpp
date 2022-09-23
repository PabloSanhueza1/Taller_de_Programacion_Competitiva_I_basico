#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class WordFindPuzzle
{
public:
    int solveWordFindPuzzle(vector<string>, vector<string>);
};

int WordFindPuzzle::solveWordFindPuzzle(vector<string> words, vector<string> board)
{
    int r = 0;
    int flag = 0;
    string auxString = "";

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            // encontrar horizontal
            if (board[j].find(words[i]) <= board[j].size())
            {
                flag++;
            }
            else
            {
                for (int k = 0; k < words[i].size() / 2; k++)
                {
                    swap(words[i][k], words[i][words[i].size() - k - 1]);
                }
                if (board[j].find(words[i]) <= board[j].size())
                {
                    flag++;
                    break;
                }
                else
                {
                    for (int k = 0; k < words[i].size() / 2; k++)
                    {
                        swap(words[i][k], words[i][words[i].size() - k - 1]);
                    }
                }
            }
        }

        // encontrar vertical
        if (flag != 0 && words[i].size() <= board.size())
        {
            for (int a = 0; a < board[0].size(); a++)
            {
                for (int j = 0; j < board.size(); j++)
                {
                    auxString.push_back(board[j][a]);
                }
                if (auxString.find(words[i]) <= board.size())
                {
                    r++;
                    break;
                }
                else
                {
                    for (int k = 0; k < words[i].size() / 2; k++)
                    {
                        swap(words[i][k], words[i][words[i].size() - k - 1]);
                    }
                    if (auxString.find(words[i]) <= board.size())
                    {
                        r++;
                        break;
                    }
                }
                auxString = "";
            }
        }
        auxString = "";
        flag = 0;
    }
    return r;
}
/*
int main()
{
    vector<string> a =
        {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "no", "o", "p", "q", "r", "s"};

    vector<string>
        b = {
            "ab",
            "bb",
            "cb",
            "db",
            "eb",
            "fb",
            "gb",
            "hb",
            "ib",
            "jb",
            "kb",
            "lb",
            "mb",
            "no",
            "ob",
            "pb",
            "qb",
            "rb",
            "sb"};
    WordFindPuzzle v;
    // test para string.find(string)

    // vector<string> aaa = {"", "bob"};
    // vector<string> bbb = {"alex", ""};
    // cout << bbb[1].find(aaa[0]) << endl;
    // if (bbb[1].find(aaa[0]) <= bbb.size()) cout << "encontrado" << endl;
    int r = v.solveWordFindPuzzle(a, b);
    cout << a.size() << endl;
    cout << b.size() << endl;
    cout << r << endl;

    return 0;
}
*/