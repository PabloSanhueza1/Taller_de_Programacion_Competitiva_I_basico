// REALIZADO POR MI

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int f, c;
    string indice_fila;
    string indice_columna;

    cin >> f >> c;
    char input[f][c];

    // ingreso de datos
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> input[i][j];
        }
    }

    // revisar fila a fila
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (input[i][j] == 'S')
            {
                // marca la ubicacion (indice) de la S
                indice_fila.push_back(i + 48);
                break;
            }
        }
    }

    // revisar columna a columna
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < f; i++)
        {
            if (input[i][j] == 'S')
            {
                // marca la ubicacion (indice) de la S
                indice_columna.push_back(j + 48);
                break;
            }
        }
    }
    cout  << endl;

    int output = 0;

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (indice_fila.find(i + 48) > indice_fila.length() || indice_columna.find(j + 48) > indice_columna.length())
            {
                output++;
            }
        }
    }

    cout << output << endl;
    return 0;
}