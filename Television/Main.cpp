#include "Television.h"
#include <conio.h>
// Function that sends a message to the user takes his input and returns a value of the indicated type.
template <typename T>
T input(string Message);

int main()
{
	// Console title.
	system("title Television");
	// Variable initialization.
	string brand = "";
	string model = "";
	unsigned short int inches = 0;
	char Input = ' ';
	bool exit = false;
	// Input of the inizialization value for Television class.
	brand = input<string>("Insert the brand: ");
	model = input<string>("Insert the model: ");
	inches = input<unsigned short int>("Insert the inches: ");
	Television t( brand, model, inches, list<Port> {});
	// Console clear.
	system("cls");

	do
	{
		// Multiple user choice options.
		cout << endl << "Select one of the following alternatives by number:" << endl
			<< "0) Connect / disconnect the aerial;" << endl
			<< "1) Turn on/off the TV;" << endl
			<< "2) Increase the volume;" << endl
			<< "3) Decrease the volume;" << endl
			<< "4) Mute / unmute the volume;" << endl
			<< "5) Change the channel (only with the aerial connected);" << endl
			<< "6) Increase the channel (only with the aerial connected);" << endl
			<< "7) Decrease the channel (only with the aerial connected);" << endl
			<< "8) Reset;" << endl
			<< "9) Exit;" << endl << endl 
		// Program output.
			<< "Brand: " << t.getBrand() << ";" << endl
			<< "Model: " << t.getModel() << ";" << endl
			<< "Inches: " << t.getInches() << ";" << endl
			<< "State aerial: " << (t.getCurrentPort().state == true ? "Enable" : "Disable") << ";" << endl
			<< "Power: " << (t.getPower() == true ? "On" : "Off") << ";" << endl
			<< "Volume: " << t.getVolume() << ";" << endl
			<< "Channel: " << (t.getCurrentPort().state == true ? t.getChannel() : 0) << ";" << endl;
		// Control over the input.
		do
		{
			Input = _getch();
		} while (Input < '0' || Input > '9');
		// Console clear after the input.
		system("cls");
		// Program response based on user choice.
		switch (Input)
		{
		case '0':
			t.changeStateCurrentPort();
			break;
		case '1':
			t.changePower();
			break;
		case '2':
			t.increaseVolume();
			break;
		case '3':
			t.decreaseVolume();
			break;
		case '4':
			t.Mute();
			break;
		case '5':
			inches = input<unsigned short int>("\nChannel number: ");
			t.setChannel(inches);
			system("cls");
			break;
		case '6':
			t.increaseChannel();
			break;
		case '7':
			t.decreaseChannel();
			break;
		case '8':
			system("cls");
			main();
			break;
		case '9':
			exit = true;
			break;
		}

	} while (exit == false);
	// Press any key to close the window.
	system("pause");
}

template<typename T>
T input(string Message)
{
	T i;
	cout << Message;
	cin >> i;
	return i;
}
