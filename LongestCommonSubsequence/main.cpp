#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

int LCS(string &X, string &Y, int xL, int yL, unordered_map <string, int> &memo);

int main()
{
	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		unordered_map <string, int> memo;
		string X, Y;
		int xL = 0, yL = 0;

		cin >> xL;
		cin >> X;
		cin >> yL;
		cin >> Y;

		cout << LCS(X, Y, xL, yL, memo) << '\n';
	}

	return 0;
}
int LCS(string &X, string &Y, int xL, int yL, unordered_map <string, int> &memo)
{
	string n = to_string(xL), m = to_string(yL);
	string reminder = n + "." + m;
	if (memo.count(reminder) > 0) return memo[reminder];

	if (xL == 0 || yL == 0)
		memo[reminder] = 0;
	else if (X[xL - 1] == Y[yL - 1])
		memo[reminder] = 1 + LCS(X, Y, xL - 1, yL - 1, memo);
	else
		memo[reminder] = max(LCS(X, Y, xL - 1, yL, memo), LCS(X, Y, xL, yL - 1, memo));

	return memo[reminder];
}