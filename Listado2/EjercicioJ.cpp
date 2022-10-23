// REALIZADO CON AYUDA

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 1;
    cin >> t;
    for (int aux = 0; aux < t; aux++)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<int> output(n);
        vector<int> unos;
        vector<int> ceros;
        int cont = 0; // corresponde a la i-esima sub secuencia

        /*
            Dado que los numeros no pueden ser desplazados, se cuentan, en orden, las subsecuencias validas,
            donde se les asocia un contador.
            Leyendo caracter a caracter el string de entrada, se tiene que:
            Si se encuentra un "0", primero se verifica si es que el vector "unos" contiene elementos,
                - de no ser asi, el contador de subsecuencia se incrementa y se almacena en el vector de "ceros",
                puesto que se hallo un "0" en lo que corresponde la primera subsecuencia. Ademas, el valor del contador
                se imprime por pantalla.
            A su vez, el vector "unos" almacena sus valores de manera analoga a "ceros", por lo tanto:
                + Si es que "unos" no es vacio, ese ultimo valor contenido en "unos" correspondiente al contador de su subsecuencia,
                se pasa a "ceros" (puesto que seguimos analizando el caso de encontrar un "0"), y ademas se imprime por pantalla.

            De esta forma, sucesivamente se lee toda la cadena de entrada, y note que siempre que se encuentre una
            sub secuencia diferente el contador aumenta, puesto que si o si "unos" o "ceros" estaria vacia (dado las condiciones
            para se llamada "subsecuencia", correspondiente a la adyacencia de estos digitos, "1" y "0").
        */

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (unos.size() == 0)
                {
                    cont++;
                    ceros.push_back(cont);
                    output[i] = cont;
                }
                else
                {
                    int last = unos.back(); // referencia al ultimo elemento del vector "unos"
                    unos.pop_back();
                    ceros.push_back(last);
                    output[i] = last;
                }
            }

            else
            {
                if (ceros.size() == 0)
                {
                    cont++;
                    unos.push_back(cont);
                    output[i] = cont;
                }
                else
                {
                    int last = ceros.back();
                    ceros.pop_back();
                    unos.push_back(last);
                    output[i] = last;
                }
            }
        }

        cout << cont << endl; // el numero de sub sencuencias siempre corresponde al de la n-esima subsecuencia, con n sub secuencias (el minomo) en total
        for (int i = 0; i < output.size(); i++)
            cout << output[i] << " ";
        cout << endl;
    }
    return 0;
}