#include <iostream>
#include <vector>

using namespace std;

class CandyBoxes
{
public:
    int remainingCandies(vector<int>);
};

int CandyBoxes::remainingCandies(vector<int> candies)
{
    int aux;
    for (int i = 0; i < candies.size() - 1; i++)
    {
        for (int j = i + 1; j < candies.size(); j++)
        {
            if (candies[i] > candies[j])
            {
                aux = candies[i];
                candies[i] = candies[j];
                candies[j] = aux;
            }
        }
    }
    int min = candies[0];
    int max = candies[candies.size() - 1];

    if (min == max)
        return min;
    else
    {
        int res;
        while(1)
        {
            candies[candies.size() - 1] -= candies[0];

            for (int i = 0; i < candies.size() - 1; i++)
            {
                for (int j = i + 1; j < candies.size(); j++)
                {
                    if (candies[i] > candies[j])
                    {
                        aux = candies[i];
                        candies[i] = candies[j];
                        candies[j] = aux;
                    }
                }
            }
            max = candies[candies.size() - 1];
            min = candies[0];
            if (min == max)
            {
                return min;
            }
            else
                res = min;
        }
        return res;
    }
}

int main()
{
    int n;
    cin>>n;
    CandyBoxes c;
    vector<int> candy;
    for (int i = 0; i < n; i++)
    {
        int aux;
        cin >> aux;
        candy.push_back(aux);
    }
    cout << c.remainingCandies(candy) << endl;
    return 0;
}