#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string dane_to_bin(string dane);
string bin_to_dane(string dane);
bool correct_date(int year, int month, int day);

int main()
{
	string dane = "";
	cin >> dane;

	if (dane.length() == 10)
		cout << dane_to_bin(dane) << endl;
	else if (dane.length() == 16)
		cout << bin_to_dane(dane) << endl;
	else
		cout << "ERROR" << endl;
	
	return 0;
}
string dane_to_bin(string dane)
{
	string answer = "", year = "", month = "", day = "";
	int licznik = 0, y = 0, m = 0, d = 0;
	bool flag = true;

	for (int i = 0; i < 4; i++)
		year += dane[i];
	for (int i = 5; i < 7; i++)
		month += dane[i];
	for (int i = 8; i < 10; i++)
		day += dane[i];

	y = atoi(year.c_str());
	m = atoi(month.c_str());
	d = atoi(day.c_str());

	flag = correct_date(y, m, d);
	if (flag == true)
	{
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
	if (flag == false)
		return "ERROR";
}
string bin_to_dane(string dane)
{
	string answer = "", year = "", month = "", day = "";
	int y = 0, m = 0, d = 0, licznik = 0;
	bool flag = true;

	for (int i = 0; i < 7; i++)
		year += dane[i];
	for (int i = 7; i < 11; i++)
		month += dane[i];
	for (int i = 11; i < 16; i++)
		day += dane[i];

	licznik = 1;
	for (int i = year.length() - 1; i >= 0; i--)
	{
		if (year[i] == '1')
			y += licznik;
		licznik *= 2;
	}
	y += 1980;

	licznik = 1;
	for (int i = month.length() - 1; i >= 0; i--)
	{
		if (month[i] == '1')
			m += licznik;
		licznik *= 2;
	}

	licznik = 1;
	for (int i = day.length() - 1; i >= 0; i--)
	{
		if (day[i] == '1')
			d += licznik;
		licznik *= 2;
	}
	flag = correct_date(y, m, d);
	if (flag == true)
	{
		year = "";
		month = "";
		day = "";

		string finalm = "", finald = "";

		year += to_string(y);
		month += to_string(m);
		day += to_string(d);

		if (month.length() < 2)
			finalm = finalm + "-" + "0" + month;
		else
			finalm = finalm + "-" + month;
		if (day.length() < 2)
			finald = finald + "-" + "0" + day;
		else
			finald = finald + "-" + day;

		answer += year + finalm + finald;
		return answer;
	}
	if (flag == false)
		return "ERROR";
}
bool correct_date(int year, int month, int day)
{
	bool przestepny = true;
	if (year < 1980 || year > 2107)
		return false;

	if (month < 1 || month > 12)
		return false;

	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && 
		(day < 1 || day > 31))
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
		return false;

	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			przestepny = true;
		else
			przestepny = false;

		if ((przestepny == true) && (day < 1 || day > 29))
			return false;
		if ((przestepny == false) && (day < 1 || day > 28))
			return false;
	}

	return true;
}
