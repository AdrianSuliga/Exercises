#include <iostream>
#include <string>
using namespace std;

int XOR(int a, int b);
int minimum_X(int S, int X);

int main()
{
	int t = 0;
	cin >> t;

	while (t--)
	{
		int sizeA = 0, final_bitwise = 0, final_answer = 0;
		cin >> sizeA >> final_bitwise;

		int* arrayA = new int[sizeA];

		for (int i = 0; i < sizeA; i++)
		{
			cin >> *arrayA;
			arrayA++;
		}
		arrayA -= sizeA;

		for (int i = 1; i < sizeA; i++)							//Calculating bitwsie of all known numbers Ai
		{										//final bitwise of known numbers is saved in array[sizeA-1] 
			arrayA[i] = XOR(arrayA[i - 1], arrayA[i]);
		}

		cout << minimum_X(arrayA[sizeA - 1], final_bitwise) << '\n';			//function minimum_X finds minimum X for which 
	}											//array[sizeA - 1] OR X == final_bitwise

	return 0;
}
int XOR(int a, int b)
{
	int Amax = 524288, bitwise = 0;								//Amax results from exrcise's constraints
	string bitA = "00000000000000000000", bitB = "00000000000000000000";
	string ans = "00000000000000000000";
										//strings have 20 chars, because Amax = 2^19, therefore maximum number of chars
										//needed to write numbers from arrayA in binary is 20.
	for (int i = 0; i < 20; i++)						//Converting a and b into binary and saving it into bitA and bitB variables
	{
		if (a / Amax == 1)
		{
			a -= Amax;
			bitA[i] = '1';
		}

		if (b / Amax == 1)
		{
			b -= Amax;
			bitB[i] = '1';
		}

		Amax /= 2;
	}

	for (int i = 0; i < 20; i++)					//Doing bitwise OR operation on a and b in binary
	{
		if (bitA[i] == '1' || bitB[i] == '1')
			ans[i] = '1';
	}

	Amax = 524288;

	for (int i = 0; i < 20; i++)					//Converting final bitwise into decimal number
	{
		if (ans[i] == '1')
		{
			bitwise += Amax;
		}
		Amax /= 2;
	}

	return bitwise;							//returning final bitwise
}
int minimum_X(int S, int final_bitwise)
{
	int Amax = 524288, X = 0;
	string bitS = "00000000000000000000", bitFinal_bitwise = "00000000000000000000";
	string ans = "00000000000000000000";
	
	for (int i = 0; i < 20; i++)					//Converting S and final_bitwise into binary in bitS and bitFinal_bitwise variables
	{
		if (S / Amax == 1)
		{
			S -= Amax;
			bitS[i] = '1';
		}

		if (final_bitwise / Amax == 1)
		{
			final_bitwise -= Amax;
			bitFinal_bitwise[i] = '1';
		}

		Amax /= 2;
	}

	for (int i = 0; i < 20; i++)					//Now, the most important part: S OR X == final_bitwise
	{
		if (bitS[i] == '1' && bitFinal_bitwise[i] == '1')	//1 OR X == 1, so X == 1 or X == 0 
			ans[i] = '0';					//X == 0 guarantees smaller number in the end
		if (bitS[i] == '0' && bitFinal_bitwise[i] == '0')	//0 OR X == 0, so X == 0
			ans[i] = '0';
		if (bitS[i] == '1' && bitFinal_bitwise[i] == '0')	//In this case it is impossible to put anything into X, 
			return -1;					//because 1 OR X != 0
		if (bitS[i] == '0' && bitFinal_bitwise[i] == '1')	//0 OR X == 1, so X == 1
			ans[i] = '1';
	}

	Amax = 524288;

	for (int i = 0; i < 20; i++)					//Converting X into decimal number
	{
		if (ans[i] == '1')
		{
			X += Amax;
		}
		Amax /= 2;
	}

	return X;
}
