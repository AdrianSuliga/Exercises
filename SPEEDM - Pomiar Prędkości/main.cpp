#include <iostream>
#include <string>
#include <cstdlib>
#include <unordered_map>
using namespace std;

int minimalna_predkosc(int v, string &dane, int wystapienia, unordered_map<string, int>& memo);

int main()
{
	int t = 0, v = 0, dots = 0, n = 0;
	unordered_map <string, int> memo;
	unordered_map <int, int> wystapienia;
	string dane = "";

	cin >> t;

	for (int k = 0; k < t; k++)
	{
		cin >> n;
		int* testy = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> *testy;
			//*testy = 1;
			v += *testy;
			*testy *= 2;
			wystapienia[*testy] = 0;
			testy++;
		}
		testy -= n;

		for (int i = 0; i < n; i++)
		{
			wystapienia[*testy]++;
			testy++;
		}
		testy -= n;

		dane += " ";
		for (int i = 0; i < wystapienia.size(); i++)
		{
			dane += to_string(wystapienia[*testy]) + "." + to_string(*testy) + " ";
			dots += wystapienia[*testy];
			testy++;
		}
		testy -= dots;
		cout << v << " " << dane << " " << dots << endl;
		cout << minimalna_predkosc(v, dane, dots, memo) << " " << v << endl;

		delete[] testy;
		testy = NULL;
		v = 0; n = 0; dots = 0;
		dane = "";
	}

	return 0;
}
int minimalna_predkosc(int v, string &dane, int wystapienia, unordered_map<string, int>& memo)
{
	if (memo.count(dane) > 0) return memo[dane];
	int shortest = 2147483647;

	for (int i = 0; i < wystapienia; i++)
	{
		int temp_dot = wystapienia, first_space = 0, pointer = 0,
			second_space = 0, left = 0, right = 0;
		string temp_dane = "", dane_to_erase = "", temp_wyst = "", temp_num = "";

		for (int j = 0; j < dane.length(); j++)
		{
			if (dane[j] == ' ')
				first_space++;
			if (first_space == 1)
			{
				left = j;
				break;
			}
		}
		for (int j = 0; j <= dane.length(); j++)
		{
			if (dane[j] == ' ')
				second_space++;
			if (second_space == 2)
			{
				right = j;
				break;
			}
		}
		for (int j = left + 1; j < right; j++)
		{
			dane_to_erase += dane[j];
		}
		for (int j = 0; j < dane_to_erase.length(); j++)
		{
			if (dane_to_erase[j] == '.')
				pointer = j;
		}
		for (int j = pointer + 1; j <= dane_to_erase.length(); j++)
		{
			temp_num += dane_to_erase[j];
		}
		for (int j = 0; j < pointer; j++)
		{
			temp_wyst += dane_to_erase[j];
		}
		int temp_v = v - atoi(temp_num.c_str());
		if (temp_v >= 0)
		{
			temp_dane = dane;
			if (atoi(temp_wyst.c_str()) - 1 > 0)
			{
				pointer = atoi(temp_wyst.c_str()) - 1;
				temp_dane.replace(left + 1, temp_wyst.length(), to_string(pointer));
			}
			if (atoi(temp_wyst.c_str()) - 1 == 0)
			{
				temp_dane.erase(left + 1, right - left - 2);
			}

			temp_dot--;
			
			temp_v = minimalna_predkosc(temp_v, temp_dane, temp_dot, memo);
			if (temp_v < shortest)
				shortest = temp_v;
		}

		if (temp_v < 0 && v < shortest)
			shortest = v;
		if (shortest == 0)
			break;
	}

	memo[dane] = shortest;
	return shortest;
}
