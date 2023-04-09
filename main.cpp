#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string dane_to_bin(string dane);
string bin_to_dane(string dane);

int main()
{
	string dane = "";
	bool date_to_bin = false;
	cin >> dane;

	for (int i = 0; i < dane.length(); i++)
	{
		if (dane[i] == '-')
		{
			date_to_bin = true;
			break;
		}
	}
	if (date_to_bin == true)
		cout << dane_to_bin(dane) << endl;
	if (date_to_bin == false)
		cout << bin_to_dane(dane) << endl;

	return 0;
}
string dane_to_bin(string dane)
{
	string answer = "", year = "", month = "", day = "";
	int fst = 0, snd = 0, licznik = 0, y = 0, m = 0, d = 0;

	for (int i = 0; i < dane.length(); i++)
	{
		if (dane[i] == '-')
		{
			licznik++;
			if (licznik == 1)
				fst = i;
			if (licznik == 2)
				snd = i;
		}
	}
	for (int i = 0; i < fst; i++)
		year += dane[i];
	for (int i = fst + 1; i < snd; i++)
		month += dane[i];
	for (int i = snd + 1; i < dane.length(); i++)
		day += dane[i];

	y = atoi(year.c_str());
	m = atoi(month.c_str());
	d = atoi(day.c_str());

	y -= 1980;
	
	licznik = 64;
	year = "0000000";
	for (int i = 0; i < 7; i++)
	{
		if (y / licznik != 0)
		{
			year[i] = '1';
			y -= licznik;
		}
		licznik /= 2;
	}
	licznik = 8;
	month = "0000";
	for (int i = 0; i < 4; i++)
	{
		if (m / licznik != 0)
		{
			month[i] = '1';
			m -= licznik;
		}
		licznik /= 2;
	}

	licznik = 16;
	day = "00000";
	for (int i = 0; i < 5; i++)
	{
		if (d / licznik != 0)
		{
			day[i] = '1';
			d -= licznik;
		}
		licznik /= 2;
	}

	answer += year + month + day;
	return answer;
}
string bin_to_dane(string dane)
{
	return "";
}