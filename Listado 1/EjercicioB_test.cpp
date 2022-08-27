#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int dulces[12];

    for (int i = 0; i < 12; i++)
    {
        cin >> dulces[i];
    }


    int aux;
    for (int i = 0; i < 12 - 1; i++)
    {
        for (int j = i + 1; j < 12; j++)
        {
            if (dulces[i] > dulces[j])
            {
                aux = dulces[i];
                dulces[i] = dulces[j];
                dulces[j] = aux;
            }
        }
    }
    int min=dulces[0];
    int max=dulces[11];

    if(min == max) cout<<min<<endl;
    else
    {
        int res;
        for(int i=0;i<2*12;i++)
        {
            dulces[11]-=dulces[0];
            
            for (int i = 0; i < 12 - 1; i++)
            {
                for (int j = i + 1; j < 12; j++)
                {
                    if (dulces[i] > dulces[j])
                    {
                        aux = dulces[i];
                        dulces[i] = dulces[j];
                        dulces[j] = aux;
                    }
                }
            }
            max = dulces[11];
            min = dulces[0];
            if (min == max)
            {
                cout << min << endl;
                return 0;
            }
            else res = min;
        }
        cout << res << endl;
    }
    return 0;
}