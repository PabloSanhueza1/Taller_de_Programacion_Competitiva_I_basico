// REALIZADO POR MI

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;

    cin >> n;
    int pilas[n];
    vector<int> suma;
    int aux = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> pilas[i];
        aux += pilas[i];
        suma.push_back(aux);
    }

    cin >> q;
    int jugosos;
    for (int i = 0; i < q; i++)
    {
        cin >> jugosos;
        cout << lower_bound(suma.begin(), suma.end(), jugosos) - suma.begin() + 1 << endl;
    }
    return 0;
}