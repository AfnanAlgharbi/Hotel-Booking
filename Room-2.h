#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <string>
using namespace std;

class Room
{

protected:
	int bookAmount;
	int price;
	int rNum;
	string category, currentR, client;


public:
	Room() {
		bookAmount = 0;
		price = 0;
		rNum = 0;
		category = "";
		currentR = "";
		client = "";
	}
	int getPrice() { return this->price; }
	int getRamount() { return this->bookAmount; }
	int getNumber() { return this->rNum; }
	string getClient() { return this->client; }
	string getCategory() { return this->category; }
	string getCurrentR();
	void booked(string);
	void setNumber(int);
	void setClient(string);

};
#endif

class Courtyard : public Room {

public:
	Courtyard() {

		price = 125;
		bookAmount = 70;
		category = "Standard Room: Courtyard";

	}

};

class Scenic : public Room {

public:
	Scenic() {

		price = 145;
		bookAmount = 35;
		category = "Standard Room: Scenic";

	}

};

class DeluxeSuite : public Room {

public:
	DeluxeSuite() {

		price = 350;
		bookAmount = 15;
		category = "Deluxe Suite";

	}

};

class Penthouse : public Room {

public:
	Penthouse() {

		price = 1135;
		bookAmount = 2;
		category = "Penthouse";

	}

};