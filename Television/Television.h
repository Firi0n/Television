#pragma once
#include <iostream>
#include <list>

using namespace std;

struct Port
{
	// Name to identify the port.
	string name = "";
	// Port connected or not.
	bool state = false;
};

class Television
{
private:
	// Physical attributes.
	string brand;
	string model;
	unsigned short int inches;
		// List of ports on the televisioN.
	list<Port> _port;
	// Software attributes.
	Port currentPort;
	bool power = false;
	unsigned short int mute = 0;
	unsigned short int volume = 0;
	unsigned short int channel = 0;
public:
	/* The physical attributes do not change, so once initialized
	   they can no longer be modified but only read. */
	Television(string Brand, string Model, unsigned short int Inches, list<Port> port);
	string getBrand();
	string getModel();
	unsigned short int getInches();
	// Methods for when connecting an external device to the Television.
	bool changeStatePort(string namePort);
	string getPortName();
	Port getPortFromName(string namePort);
	list<Port> getPort();
	bool setCurrentPort(string namePort);
	void changeStateCurrentPort();
	Port getCurrentPort();
	// on / of.
	void changePower();
	bool getPower();
	// Volume methods.
	bool increaseVolume();
	bool decreaseVolume();
	bool Mute();
	unsigned short int getVolume();
	// Channel methods.
	bool setChannel(unsigned short int Channel);
	bool increaseChannel();
	bool decreaseChannel();
	unsigned short int getChannel();
};

