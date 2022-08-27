#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Yllion
{
public:
    string getPower(string, string);
};

string Yllion::getPower(string a, string b)
{
    string r = "";
    int a1;



    /*
    if (a.size() == 3 && b.size() == 3)
    {
        if ((a == "one" && b == "ten") || (a == "ten" && b == "one"))
            return "ten";
        else if (a == "one" && b == "one")
            return "one";
        else
            return "one hundred";
    }
    else
    {
        if ((a[0] == 'o' && b[0] == 't') || (a[0] == 't' && b[0] == 'o'))
            r.push_back("ten");
        else if (a[0] == 'o' && b[0] == 'o')
            r.push_back("one");
        return r;
    }*/
}

int main()
{
    string a = "ten";
    string b = "ten";
    Yllion v;

    string r = v.getPower(a, b);
    cout << r << endl;

    return 0;
}