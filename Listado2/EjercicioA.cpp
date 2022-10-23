// REALIZADO POR MI

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	string guest = {""};
	string residence = {""};
	string letters = {""};
	
	int cont = 0;
	string index = {""};

	cin>>guest;
	cin>>residence;
	cin>>letters;

	if (guest.size() + residence.size() == letters.size())
	{
		sort(guest.begin(), guest.end());
		sort(residence.begin(), residence.end());
		sort(letters.begin(), letters.end());

		string aux = guest + residence;
		sort(aux.begin(), aux.end());
		if(aux == letters)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}