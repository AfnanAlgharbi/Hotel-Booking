#pragma once
#include "Booking.h"
#ifndef HOTEL_H
#define HOTEL_H
class Hotel
{
private:
	char savedCommand;
	string saveDate, saveOldDate;
	Booking inventory;
	void bookRoom();
	void getTotal();
	void introList();
	void date();
	void recordDate();
	void infoDay();

public:
	Hotel();

};
#endif

