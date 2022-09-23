#include <iostream>
#include <vector>

using namespace std;

class AdvertisingAgency
{
public:
    int numberOfRejections(vector<int>);
};

int AdvertisingAgency::numberOfRejections(vector<int> requests)
{
    int r = 0;
    for (int i = 0; i < requests.size() - 1; i++)
    {
        for (int j = i + 1; j < requests.size(); j++)
        {
            if (requests[j] == requests[i]){
                r++;
                break;
            }
        }
    }
    return r;
}
/*
int main()
{
    vector<int> a = {1, 2, 1, 2};

    AdvertisingAgency v;

    int r = v.numberOfRejections(a);
    cout << r << endl;

    return 0;
}*/