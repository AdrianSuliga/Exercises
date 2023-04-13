#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>
using namespace std;

int main()
{
	int dist, h, m;
	const int INF = 2000000000;
	bool flag = true;
	cin >> dist >> h;
	h++;

	int* distances = new int[h];
	int* costs = new int[h];

	int* d = new int[h];
	int* p = new int[h];

	unordered_map <int, bool> QS;
	stack <int> distance_from_previous_one;
	list <int> scope;

	for (int i = 0; i < h; i++)
	{
		QS[i] = true;
	}

	d[0] = 0;
	p[0] = -1;

	for (int i = 1; i < h; i++)				
	{
		d[i] = INF;
		p[i] = -1;
	}

	distances[0] = 0;
	costs[0] = 0;
	for (int i = 1; i < h; i++)				
	{
		cin >> distances[i] >> costs[i];
	}

	while (flag == true)
	{
		for (int i = 0; i < h; i++)
		{
			if (QS[i] == true)
			{
				m = i;
				break;
			}
		}

		for (int i = 0; i < h; i++)
		{
			if (QS[i] == true)
			{
				if (d[i] < d[m])
					m = i;
			}
		}

		QS[m] = false;

		if (m == 0)
			distance_from_previous_one.push(0);
		else
			distance_from_previous_one.push(distances[m]);

		for (int i = m; i < h; i++)
		{
			if (QS[i] == true)
			{
				if (distances[i] - distance_from_previous_one.top() <= 800)
				{
					scope.push_back(i);
					p[i] = m;
				}
			}
		}

		if (scope.empty() == false)
		{
			for (list <int>::iterator it = scope.begin(); it != scope.end(); it++)
			{
				if (d[*it] > d[p[*it]] + costs[*it])
					d[*it] = d[p[*it]] + costs[*it];
			}
		}

		scope.clear();
		flag = false;

		for (unordered_map <int, bool>::iterator it = QS.begin(); it != QS.end(); it++)
		{
			if (it->second == true)
			{
				flag = true;
				break;
			}
		}
	}

	for (int i = h - 1; i >= 0; i--)
	{
		if (dist - distances[i] <= 800)
		{
			scope.push_back(d[i]);
		}
	}

	scope.sort();
	cout << scope.front() << endl;
	
	delete[] distances;
	delete[] costs;
	delete[] d;
	delete[] p;

	QS.clear();

	d = NULL;
	p = NULL;
	distances = NULL;
	costs = NULL;

	return 0;
}
