#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WallRepair
{
public:
    int bricksRequired(vector<string>);
};

int WallRepair::bricksRequired(vector<string> wallRows)
{
    int flag_x = 0;
    int cont_dot = 0;
    int it = 0;

    if (wallRows.size() == 1)
        return 0;
    else
    {
        for (int i = 0; i < wallRows.size(); i++)
            cout << wallRows[i] << endl;

        for (int i = 0; i < wallRows[0].size(); i++)
        {
            for (int j = 0; j < wallRows.size(); j++)
            {
                if (flag_x == 0 && wallRows[j][i] == 'X')
                {
                    flag_x = 1;
                }

                if (flag_x != 0 && wallRows[j][i] == '.')
                {
                    wallRows[j][i] = '#';
                    cont_dot++;
                }
                it++;
            }

            flag_x = 0;

            if (it == wallRows[0].size() * wallRows[0].size())
                break;
        }
    }
    cout << endl;
    for (int i = 0; i < wallRows.size(); i++)
        cout << wallRows[i] << endl;
    return cont_dot;
}
/*
int main()
{
    vector<string> a =
        {
            ".........X............",
            "......X..X..X..X......",
            "X.......X..X.........X",
            "....XXXXX..X.XXXXX...X",
            ".....X..X..X.........X",
            "...X....X..X.........X",
            ".X...XX..X..X..X......",
            ".....X...X...XX......X"};

    WallRepair v;

    int r = v.bricksRequired(a);
    cout << r << endl;
    return 0;
}*/