// REALIZADO CON AYUDA

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;
    stack<char> st;

    for (int i = 0; i < input.size(); i++)
    {
        if (st.size() == 0)
            st.push(input[i]);
        else
        {
            // basicamente, todo lo que se hace es hallar pares de signos iguales
            // esto provoca que puedan desenredarse sin problemas
            // cuando estos pares son hallados se eliminan para seguir leyendo
            if (st.top() == input[i])
                st.pop();
            else
                st.push(input[i]);
        }
    }
    // si "st" se encuentra vacio, todos los cables son desenredados
    if (st.size() == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}