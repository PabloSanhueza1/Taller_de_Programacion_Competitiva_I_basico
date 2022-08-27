#include <iostream>
#include <vector>
#include <string>

using namespace std;

class EllysTimeMachine
{
public:
    string getTime(string);
};

string EllysTimeMachine::getTime(string time)
{
    string hora = "";

    if (time[3] == '0')
    {
        if (time[4] == '5')
        {
            hora.push_back('0');
            hora.push_back('1');
        }
        else
        {
            hora.push_back('1');
            hora.push_back('2');
        }
    }
    else
    {
        int m1 = time[3] - 48;
        int m2 = time[4] - 48;

        if (m2 != 0)
        {
            m1 *= 10;
            m1 += m2;
        }
        else
        {
            m1 *= 10;
        }

        m1 /= 5;

        if (m1 < 10)
        {
            hora.push_back('0');
            hora.push_back(m1 + 48);
        }
        else
        {
            hora.push_back('1');
            if (m1 == 10)
                hora.push_back('0');
            else if (m1 == 11)
                hora.push_back('1');
        }
    }

    hora.push_back(':');

    if (time[0] == '1' && time[1] == '2')
    {
        hora.push_back('0');
        hora.push_back('0');
    }
    else
    {
        int m1 = time[0] - 48;
        int m2 = time[1] - 48;

        if (m1 == 0)
        {
            m1 = m2;
        }
        else
        {
            m1 *= 10;
            m1 += m2;
        }

        m1 *= 5;
        hora.push_back(m1 / 10 + 48);
        hora.push_back((m1 - 10 * (m1 / 10)) + 48);
    }
    return hora;
}

int main()
{
    string a = "01:00";
    EllysTimeMachine v;

    string r = v.getTime(a);
    cout << r << endl;

    return 0;
}