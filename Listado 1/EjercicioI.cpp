#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TVRemoteText
{
public:
    int numPresses(string);
};

int TVRemoteText::numPresses(string text)
{
    vector<string> grid =
        {
            "ABCDEFG",
            "HIJKLMN",
            "OPQRSTU",
            "VWXYZ12",
            "3456789",
            "0$.,-!?",
            ":/+()*@",
            "&%#=<> "};

    int moves = 0;
    int row = 0;
    int col = 0;

    for (int k = 0; k < text.size(); k++)
    {
        int flag = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == text[k])
                {
                    moves += abs(row - i) + abs(col - j);
                    row = i;
                    col = j;
                    flag = 1;
                    moves++; // select
                    break;
                }
            }
            if (flag)
            break;
        }
    }
    moves++; // enter
    return moves;
}
/*
int main()
{
    string a = {

        "2B+-2B,THAT=? 3177 $H4K5P3R3"};

    TVRemoteText v;

    int r = v.numPresses(a);
    cout << "resultado: " << r << endl;

    return 0;
}*/