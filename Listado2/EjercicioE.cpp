// REALIZADO CON AYUDA

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    int n;
    vector<int> a;
    // entrada de datos
    cin >> n;
    for (i = 0; i < n; i++)
    {
        int aux;
        cin >> aux;
        a.push_back(aux);
    }

    // al menos hay un segmento continuo valido
    int cnt = 1;
    // vector auxiliar
    vector<int> v;

    for (i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            // se agregan a "v" la cantidad de repeticiones
            // de un mismo elemento, dado su respectivo orden de aparicion
            // ejemplo: 221122 -> v = {2,1,2}
            v.push_back(cnt);
            cnt = 1;
        }
        else
            cnt++;
    }

    v.push_back(cnt);

    int r = 0;
    if (v.size() > 1)
    {
        /*
            dado que para tener un segmento valido se necesita
            que tanto "1" como "2" tengan igual cantidad de apariciones
            se designa el output segun el minimo entre pares del vector v
            luego, la longitud maxima se obtiene gracias al max()
            que lee todas las lontigudes obtenidas
        */
        for (i = 0; i < v.size() - 1; i++)
            r = max(r, min(v[i], v[i + 1]));
    }

    cout << (r * 2) << endl;

    return 0;
}