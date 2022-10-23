// REALIZADO POR MI

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t, n;
    vector<int> a;
    vector<string> salida;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int aux;
            cin >> aux;
            a.push_back(aux);
        }

        for (int k = a.size() - 1; k > 0; k--)
        {
            sort(a.begin(), a.end());
            if (abs(a[k] - a[k - 1]) <= 1)
            {
                a.pop_back();
                // cout<<"size: "<<a.size()<<endl;
                // for (int j = 0; j < a.size(); j++)
                //{
                //	cout<<a[j]<<" ";
                // }
            }
        }
        if (a.size() == 1)
        {
            salida.push_back("YES");
        }
        else
            salida.push_back("NO");
        a = {};
    }

    for (int i = 0; i < salida.size(); i++)
    {
        cout << salida[i] << endl;
    }

    return 0;
}