#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class StrangeComparator
{
public:
    vector<string> compareString(vector<string>, vector<string>);
};

vector<string> StrangeComparator::compareString(vector<string> a, vector<string> b)
{
    vector<string> r;
    int dif = 0;

    for (int i = 0; i < a.size(); i++)
    {

        if (a[i].size() == 0 && b[i].size() == 0)
            r.push_back("Yes");
        else if (a[i].size() == b[i].size())
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                if (a[i][j] != b[i][j])
                {
                    dif++;
                    if (dif > 1)
                    {
                        r.push_back("No");
                        break;
                    }
                }
                if ((j == a[i].size() - 1))
                    r.push_back("Yes");
            }
            dif = 0;
        }
        else
            r.push_back("No");
    }

    return r;
}

/*
int main()
{
    vector<string> a = {"", "abc", "bde", "ahsdjka"};
    vector<string> b = {"", "qbp", "fde", "ahsdjka"};
    StrangeComparator v;
    vector<string> r = v.compareString(a,b);
    for(int i=0;i<a.size();i++)
    {
        cout<<r[i]<<endl;
    }

    return 0;
}
*/