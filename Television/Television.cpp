#include "Television.h"

Television::Television(string Brand, string Model, unsigned short int Inches, list<Port> port)
{
	brand = Brand;
	model = Model;
	// If else abbreviated.
	inches = Inches < 20 ? 20 : Inches;
	// Set the main port i.e. the television aerial.
	_port.push_front(Port{ R"(Aerial)" });
	// Set other ports.
	for (Port p : port) {
		_port.push_front(p);
	}
	// Set the current port i.e. the television aerial.
	currentPort = _port.back();

}

string Television::getBrand()
{
	return brand;
}

string Television::getModel()
{
	return model;
}

unsigned short int Television::getInches()
{
	return inches;
}
/* Takes the port name and connects or disconnects it depending on the state it was in before,
   return false instead of error*/
bool Television::changeStatePort(string namePort)
{
	// Foreach, a for that takes every element of a container.
	for (Port p : _port) {
		if (p.name == namePort) {
			p.state = p.state == true ? false : true;
			return true;
		}
	}
	return false;
}
// Create a string with all port names.
string Television::getPortName()
{
	string r = "";
	for (Port p : _port) {
		r += p.name + " ";
	}
	return r;
}
// Return a port searched by name and if it does not find it throws an exception.
Port Television::getPortFromName(string namePort)
{
	for (Port p : _port) {
		if (p.name == namePort) {
			return p;
		}
	}
	throw new exception("Invalid port name.");
}
// Return to the complete list of ports.
list<Port> Television::getPort()
{
	return _port;
}
// Set current port by name.
bool Television::setCurrentPort(string namePort)
{
	for (Port p : _port) {
		if (p.name == namePort) {
			currentPort = p;
			return true;
		}
	}
	return false;
}
// Connects or disconnects the current port by name.
void Television::changeStateCurrentPort()
{
	currentPort.state = currentPort.state == true ? false : true;
}

Port Television::getCurrentPort()
{
	return currentPort;
}

void Television::changePower()
{
	// If (on) {off} else {on}. 
	power = power == false ? true : false;
}

bool Television::getPower()
{
	return power;
}
// Increase volume for maximum to 100 if Television is on and mute is off.
bool Television::increaseVolume()
{
	if (power == true && mute == 0) {
		volume = volume < 100 ? volume + 1 : 100;
		return true;
	}
	else {
		return false;
	}
}
// Decrease volume for minimum to 0 if Television is on and mute is off.
bool Television::decreaseVolume()
{
	if (power == true && mute == 0) {
		volume = volume > 0 ? volume - 1 : 0;
		return true;
	}
	else {
		return false;
	}
}
// Set the volume to 0 by saving the previous state if Television is on.
bool Television::Mute()
{
	if (power == true) {
		if (mute == 0) {
			mute = volume;
			volume = 0;
		}
		else {
			volume = mute;
			mute = 0;
		}
	}
	return power;
}

unsigned short int Television::getVolume()
{
	return power == true ? volume : 0;
}
// Set channel for maximum to 100 only if aerial is setted and connected and if Television is on.
bool Television::setChannel(unsigned short int Channel)
{
	if (currentPort.name == "Aerial" && currentPort.state == true && power == true) {
		channel = Channel >= 0 && Channel <= 1000 ? Channel : 1000;
		return true;
	}
	else {
		return false;
	}
}
// Increase channel for maximum to 100 only if aerial is setted and connected and if Television is on.
bool Television::increaseChannel()
{
	if (currentPort.name == "Aerial" && currentPort.state == true && power == true) {
		channel = channel < 1000 ? channel + 1 : 1000;
		return true;
	}
	else {
		return false;
	}
}
// Decrease channel for minimum to 0 only if aerial is setted and connected and if Television is on.
bool Television::decreaseChannel()
{
	if (currentPort.name == "Aerial" && currentPort.state == true && power == true) {
		channel = channel > 0 ? channel - 1 : 0;
		return true;
	}
	else {
		return false;
	}
}
// Get channel only if aerial is setted and connected and if Television is on.
unsigned short int Television::getChannel()
{
	if (currentPort.name == "Aerial" && currentPort.state == true && power == true) {
		return channel;
	}
	else
	{
		return 0;
	}
}
