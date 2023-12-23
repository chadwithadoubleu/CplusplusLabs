#include <iostream>
#include <string>

using namespace std;

int main()
{
	string make, model, plate;

	cout << "Make of the car -->";
	cin >> make;
	cout << "Model of the car -->";
	cin >> model;
	cout << "Liscense plate of the car -->";
	cin >> plate;

	int temp = plate[0] + plate[1] + plate[2];
	temp += stoi(plate.substr(3, 6));
	int remainder = temp % 26;
	char letter = 'A' + remainder;
	string code = "";
	code += letter;
	code += to_string(temp);

	cout << "Make = " << make << endl;
	cout << "Model = " << model << endl;
	cout << plate << " = " << code << endl;

}