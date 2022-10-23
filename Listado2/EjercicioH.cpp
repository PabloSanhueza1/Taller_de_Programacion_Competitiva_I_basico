// REALIZADO CON AYUDA

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int len = 0;
    stack<int> st;
    string cables;
    int d[1000006];
    // el array "d" se rellena completamente de "-1"
    memset(d, -1, sizeof(d));
    // ingreso de datos
    cin >> cables;

    int maxi = 0, cnt = 1;

    for (int i = 0; i < cables.length(); i++)
    {
        // claramente todas las secuencias validas empiezan con "("
        if (st.empty() || cables[i] == '(')
        {
            st.push(i);
            continue;
        }
        // se accede a lo que se encuentra encima del stack
        // note esto corresponde a los "i's" del for
        int pos = st.top();

        // dado que el stack no debe estar vacio
        // ni se encuentra un "(", se tiene un ")"
        // por lo que, de inmediato, se busca su pareja
        if (cables[pos] == '(')
        {
            if (d[pos - 1] != -1)
                d[i] = d[pos - 1];
            else
                d[i] = pos;
            // len corresponde al largo del sub string
            len = i - d[i] + 1;

            if (len == maxi)
            {
                // dada la condicion, si esto llega a pasar
                // estamos en presencia de otro grupo bien formado
                // en caso contrario se seguiria teniendo solamente
                /// uno de estos grupos
                cnt++;
            }
            else if (len > maxi)
            {
                maxi = len;
                cnt = 1;
            }
        }

        // se elimina del stack el primer elemento
        // correspondiente a la cima de la pila
        // esto puesto que ya se analizo su "pareja"
        st.pop();
    }
    cout << maxi << " " << cnt << endl;
    return 0;
}