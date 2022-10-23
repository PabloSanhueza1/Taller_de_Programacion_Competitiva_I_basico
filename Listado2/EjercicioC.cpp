// REALIZADO CON AYUDA

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t > 0)
    {
        cin >> n;
        vector<int> a;
        vector<int> b;

        // ingreso de datos de a y b
        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            a.push_back(aux);
        }
        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            b.push_back(aux);
        }

        int mna = *min_element(a.begin(), a.end());
        int mnb = *min_element(b.begin(), b.end());

        long long mov = 0; // para obtener mejor precision
        for (int i = 0; i < n; i++)
        {
            /*
                se analiza la cantidad de movimientos por "columna".

                Se calcula la diferencia de cada fila con el minimo, estos son los movimientos.

                Cuando en una columna se puede "optimizar" la cantidad de movimientos
                se tiene que el maximo de (a-mna) y el maximo de (b-mnb) son iguales,
                por lo que el contador "mov" se aumenta en su minima cantidad de movimientos posibles.

                (Hablamos de "optimizar" cuando los movimientos aumentan considerando la disminucion de 2 elementos
                de las columnas al mismo tiempo, acorde a lo planteado en el problema)

                Ejemplo de "optimizacion":  se tiene 3 3 6      mov = 0
                                                     2 2 3

                   (paso intermedio)           luego 3 3 5      mov = 1, note que fila 1 columna 3 y fila 2 columna 3
                                                     2 2 2               disminuyeron al mismo tiempo, pues mov aumento solo en 1

                   (paso terminado)       finalmente 3 3 3      mov = 3, mov aumenta en 2 por (5 - 3)
                                                     2 2 2
            */
            mov += max(a[i] - mna, b[i] - mnb);
        }
        /*
            inmediatamente se necesita imprimir la cantidad de movimientos
            necesarios antes de continuar con los siguientes valores de entrada,
            reiniciando el contador en su declaracion.
        */
        cout << mov << endl;
        t--;
    }
    return 0;
}