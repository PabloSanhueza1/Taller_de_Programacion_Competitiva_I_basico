// REALIZADO CON AYUDA

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    int t;
    cin >> t;

    // para analizar todos los t casos de prueba
    for (int j = 0; j < t; j++)
    {
        // posicion del agujero y cantidad de ratones
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < k; i++)
        {
            int aux;
            cin >> aux;
            v.push_back(aux);
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        //"total" es la cantidad de ratones que se salvan, se inicializa en el total (abajo la explicacion)
        //"sum" es una variable auxiliar
        int total = k, sum = 0;

        for (int i = 0; i < k; i++)
        {
            /*
                Dado que n-1 es la ultima posicion donde pueden estar los ratones (antes de entrar al agujero),
                y ademas, considerando que los ratones que estan mas lejanos del agujero
                son los mas propensos a ser atacados, estos son los primeros que deben moverse.

                Con esto, se tiene que, cuando la suma de las posiciones de los ratones mas lejanos
                del agujero es mayor a n-1, esto en un x numero de ratones, entonces el total de
                ratones que se salvan es x.

                Evidentemente, si nunca se satisface la condicion, todos se salvan.
            */

            sum += n - v[i];
            if (n - 1 < sum)
            {
                total = i;
                break;
            }
        }
        cout << total << endl;

        //el vector se limpia para realizar el siguiente test
        v.clear();
    }
    return 0;
}