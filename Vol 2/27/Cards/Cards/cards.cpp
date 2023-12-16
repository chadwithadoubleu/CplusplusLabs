#include <iostream>
#include <vector>

using namespace std;

enum suitType { clubs, spades, diamonds, hearts, unknownSuit };
enum valueType { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace, unknownValue };

struct card
{
	suitType cardSuit;
	valueType cardValue;
};

istream& operator>> (istream& in, suitType& someSuit);
ostream& operator<< (ostream& out, suitType& someSuit);
istream& operator>> (istream& in, valueType& val);
ostream& operator<< (ostream& out, valueType& val);
ostream& operator<< (ostream& out, card& someCard);

istream& operator>> (istream& in, suitType& someSuit)
{
	string inputSuit;
	in >> inputSuit;
	
	for (int i = 0; i < inputSuit.length(); i++)
	{
		if (inputSuit[i] >= 'A' && inputSuit[i] <= 'Z')
			inputSuit[i] += 32;
	}
	if (inputSuit == "clubs")
		someSuit = clubs;
	else if (inputSuit == "spades")
		someSuit = spades;
	else if (inputSuit == "diamonds")
		someSuit = diamonds;
	else if (inputSuit == "hearts")
		someSuit = hearts;
	else
		someSuit = unknownSuit;

	return in;
}

ostream& operator<< (ostream& out, suitType& someSuit)
{
	if (someSuit == clubs)
		out << "clubs";
	else if (someSuit == spades)
		out << "spades";
	else if (someSuit == diamonds)
		out << "diamonds";
	else if (someSuit == hearts)
		out << "hearts";
	else
		out << "Unknowns";

	return out;
}

istream& operator>> (istream& in, valueType& val)
{
	string inputVal;
	in >> inputVal;

	for (int i = 0; i < inputVal.length(); i++)
	{
		if (inputVal[i] >= 'A' && inputVal[i] <= 'Z')
		{
			inputVal[i] += 32;
		}
	}

	if (inputVal == "two")
		val = two;
	else if (inputVal == "three")
		val = three;
	else if (inputVal == "four")
		val = four;
	else if (inputVal == "five")
		val = five;
	else if (inputVal == "six")
		val = six;
	else if (inputVal == "seven")
		val = seven;
	else if (inputVal == "eight")
		val = eight;
	else if (inputVal == "nine")
		val = nine;
	else if (inputVal == "ten")
		val = ten;
	else if (inputVal == "jack")
		val = jack;
	else if (inputVal == "queen")
		val = queen;
	else if (inputVal == "king")
		val = king;
	else if (inputVal == "ace")
		val = ace;
	else
		val = unknownValue;

	return in;
}

ostream& operator<< (ostream& out, valueType& val)
{
	if (val == two)
		out << "two";
	else if (val == three)
		out << "three";
	else if (val == four)
		out << "four";
	else if (val == five)
		out << "five";
	else if (val == six)
		out << "six";
	else if (val == seven)
		cout << "seven";
	else if (val == eight)
		cout << "eight";
	else if (val == nine)
		cout << "nine";
	else if (val == ten)
		cout << "ten";
	else if (val == jack)
		cout << "jack";
	else if (val == queen)
		cout << "queen";
	else if (val == king)
		cout << "king";
	else if (val == ace)
		cout << "ace";
	else
		cout << "unknown number";

	return out;
}

ostream& operator<< (ostream& out, card& someCard)
{
	out << someCard.cardValue << " of " << someCard.cardSuit;
	return out;
}

int main()
{
	vector<card> cards;

	cout << "Input:" << endl;
	for (int i = 0; i < 13; i++)
	{
		cout << "Card Name: ";

		card newCard;
		valueType tempValue;
		cin >> tempValue;

		string buffer;
		cin >> buffer;

		suitType tempSuit;
		cin >> tempSuit;

		newCard.cardValue = tempValue;
		newCard.cardSuit = tempSuit;

		cards.push_back(newCard);
	}

	cout << endl << "Output:" << endl;

	for (int i = 0; i < cards.size(); i++)
	{
		cout << cards[i] << endl;
	}
}