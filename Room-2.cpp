#include "Room.h"

void Room::booked(string reserved) {

	currentR = category;
	category = reserved;

}

string Room::getCurrentR() { return this->currentR; }

void Room::setNumber(int number) { this->rNum = number; }

void Room::setClient(string guest) { this->client = guest; }
