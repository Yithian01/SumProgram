#include <iostream>

using namespace std;

int main()
{
	int Money = 10000;
	int Array[65] = { 0, };

	int Lotto[6] = { -1, -1, -1, -1, -1, -1 };
	int Counter = 0;
	bool bIsDuplicate = false;

	for (int i = 0; i < 64; ++i)
	{
		Array[i] = i + 1;
	}

	srand((unsigned int)time(nullptr));

	while (Counter < 6)
	{
		int tmp = rand() % 64;
		
		for (int i = 0; i < Counter; ++i)
		{
			if (tmp == Lotto[i])
			{
				bIsDuplicate = true;
			}
		}

		if (bIsDuplicate == false)
		{
			Lotto[Counter] = tmp;
			Counter++;
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << Lotto[i] << " ";
	}

	return 0;
}