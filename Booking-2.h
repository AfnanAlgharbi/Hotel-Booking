#pragma once
#ifndef BBOKING_H
#define BOOKING_H

#include "Room.h"

#include <string>
using namespace std;

class Booking {

private:

	int totalMax = 122, bookedNum = 0, revenue = 0;

	Room* inventory = new Room[totalMax];

	Room* courtYard = new Courtyard();
	Room* scenic = new Scenic();
	Room* deluxe = new DeluxeSuite();
	Room* pentHouse = new Penthouse();

	void addToSystem(Room*);
	void addRevenue(Room);

public:

	Booking();
	~Booking();

	void showInventory();
	void bookR(int);
	bool validBooking(int);
	int getRevenue();
	void getBookedR();
	int getBamount();
	void filInfo(string);

};

#endif
