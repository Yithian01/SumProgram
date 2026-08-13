#include <iostream>

using namespace std;


int main()
{
	int Deck[52] = { 0, };
	string Emblem[] = { "¢»", "¢½", "¡Þ", "¢¿" };
	string SpecialCard[] = { "J", "Q", "K"};

	for (int i = 0; i < 52; ++i)
	{
		Deck[i] = i + 1;
	}

	srand((unsigned int)time(0));

	for (int i = 0; i < 100; ++i)
	{
		int Card_1 = rand() % 52;
		int Card_2 = rand() % 52;
		int Temp = Deck[Card_1];
		Deck[Card_1] = Card_2;
		Deck[Card_2] = Temp;
	}

	int PlayerCard[3];
	int ComputerCard[3];
	int PlayerScore = 0;
	int ComputerScore = 0;

	int CardCounter = 0;
	for (int i = 0; i < 3; ++i)
	{
		int CardEmblem = (Deck[CardCounter]-1) / 13;
		int CardNumber = Deck[CardCounter] % 13;
		int CardScore = CardNumber;

		if (CardNumber == 0)
		{
			CardScore = 10;
		}
		else if (CardNumber > 10)
		{
			CardScore = 10;
		}
		PlayerScore += CardScore;
		PlayerCard[i] = Deck[CardCounter];
		CardCounter++;
	}
	for (int i = 0; i < 3; ++i)
	{
		int CardEmblem = (Deck[CardCounter] - 1) / 13;
		int CardNumber = Deck[CardCounter] % 13;
		int CardScore = CardNumber;

		if (CardNumber == 0)
		{
			CardScore = 10;
		}
		else if (CardNumber > 10)
		{
			CardScore = 10;
		}
		ComputerScore += CardScore;
		ComputerCard[i] = Deck[CardCounter];
		CardCounter++;
	}

	bool bIsWin = false;
	if (PlayerScore > 21)
	{
		if (ComputerScore > 21)
		{
			bIsWin = true;
		}
	}
	else
	{
		if (PlayerScore >= ComputerScore)
		{
			bIsWin = true;
		}
	}

	if (bIsWin)
	{
		cout << "Player Win" << endl;
	}
	else
	{
		cout << "Computer Win" << endl;
	}

	return 0;
}