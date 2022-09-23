#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double m(vector<double> a, vector<double> b)
{
    double r = 0;
    int iguales = 0;
    int minA = *min_element(a.begin(), a.end());
    int minB = *min_element(b.begin(), b.end());

    while (iguales == 0)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] > minA && b[i] > minB)
            {
                if (a[i] / 2 > minA && b[i] / 2 > minB)
                {
                    r += a[i] - (int)a[i] / 2;
                    a[i] = (int)a[i] / 2;
                    b[i] = (int)b[i] / 2;
                }
                else
                {
                    a[i]--;
                    b[i]--;
                    r++;
                }
            }

            else if (a[i] / 2 > minA)
            {
                r += a[i] - (int)a[i] / 2;
                a[i] = (int)a[i] / 2;
            }
            else
            {
                a[i]--;
                r++;
            }

            else if (b[i] / 2 > minB)
            {
                r += b[i] - (int)b[i] / 2;
                b[i] = (int)b[i] / 2;
            }
            else
            {
                b[i]--;
                r++;
            }

            int cont = 0;

            for (int j = 0; j < a.size() - 1; j++)
            {
                if (a[j] == a[j + 1] && b[j] == b[j + 1])
                {
                    cont++;
                    if (cont == a.size() - 1)
                    {
                        iguales++;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (iguales == 1)
                break;
        }
    }
    return r;
}

int main()
{
    int t, n;
    cin >> t;
    vector<double> r;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<double> a;
        vector<double> b;
        for (int j = 0; j < n; j++)
        {
            double aux;
            cin >> aux;
            a.push_back(aux);
        }
        for (int j = 0; j < n; j++)
        {
            double aux;
            cin >> aux;
            b.push_back(aux);
        }
        r.push_back(m(a, b));
    }
    for (int i = 0; i < r.size(); i++)
    {
        cout.precision(10);
        cout << r[i] << endl;
    }
    return 0;
}