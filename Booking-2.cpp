#include "Booking.h"
#include <iostream>
#include <iomanip>
#include <fstream>

Booking::Booking() {

	addToSystem(courtYard);
	addToSystem(scenic);
	addToSystem(deluxe);
	addToSystem(pentHouse);

}

Booking::~Booking() {

	inventory = nullptr;
	courtYard = nullptr;
	scenic = nullptr;
	deluxe = nullptr;
	pentHouse = nullptr;
	delete inventory, courtYard, scenic, deluxe, pentHouse;
}

void Booking::addToSystem(Room* hotel) {

	int currentSize = hotel->getRamount();
	int roomsConstructed = 0;
	static int index = 0, roomNumber;
	bool stop = false;

	if (hotel->getCategory() == "Standard Room: Courtyard")
		roomNumber = 101;
	else if (hotel->getCategory() == "Standard Room: Scenic")
		roomNumber = 201;
	else if (hotel->getCategory() == "Deluxe Suite")
		roomNumber = 236;
	else
		roomNumber = 301;



	while (!stop) {

		inventory[index] = *hotel;
		inventory[index].setNumber(roomNumber);

		index++;
		roomNumber++;
		currentSize--;

		if (currentSize == 0)
			stop = true;

	}

	hotel = nullptr;
	delete hotel;

}

void Booking::showInventory() {

	int cyardCount = 0, scenicCount = 0,
		deluxeCount = 0, pentCount = 0;

	for (int i = 0; i < totalMax; i++) {

		if (inventory[i].getCategory() == "Standard Room: Courtyard")
			cyardCount++;
		else if (inventory[i].getCategory() == "Standard Room: Scenic")
			scenicCount++;
		else if (inventory[i].getCategory() == "Deluxe Suite")
			deluxeCount++;
		else if (inventory[i].getCategory() == "Penthouse")
			pentCount++;

	}

	cout << "\nAvailable Rooms:\n\n";

	if (cyardCount > 0)
		cout << "1. Standard Courtyard rooms:     " << cyardCount << "\t$125.00" << endl;
	if (scenicCount > 0)
		cout << "2. Standard Scenics rooms:      " << scenicCount << "\t$145.00" << endl;
	if (deluxeCount > 0)
		cout << "3. Deluxe Suits:      " << deluxeCount << "\t$350.00" << endl;
	if (pentCount > 0)
		cout << "4. Penthouses:      " << pentCount << "\t$1135.00" << endl;
	


}

void Booking::bookR(int choice) {

	string clientName;

	cout << "Client's name:  ";
	getline(cin, clientName);
	getline(cin, clientName);

	for (int i = 0; i < totalMax; i++) {

		if ((choice == 1) && inventory[i].getCategory() == "Standard Room: Courtyard") {
			inventory[i].booked("reserved");
			bookedNum++;
			addRevenue(inventory[i]);
			inventory[i].setClient(clientName);
			cout << "\n" << " Room number: " << inventory[i].getNumber() << " reserved under  "<< clientName <<"\n";
			break;
		}
		else if ((choice == 2) && inventory[i].getCategory() == "Standard Room: Scenic") {
			inventory[i].booked("reserved");
			bookedNum++;
			addRevenue(inventory[i]);
			inventory[i].setClient(clientName);
			cout << "\n" << " Room number: " << inventory[i].getNumber() << " reserved under  " << clientName << "\n";
			break;
		}
		else if ((choice == 3) && inventory[i].getCategory() == "Deluxe Suite") {
			inventory[i].booked("reserved");
			bookedNum++;
			addRevenue(inventory[i]);
			inventory[i].setClient(clientName);
			cout << "\n" << " Room number: " << inventory[i].getNumber() << " reserved under  " << clientName << "\n";
			break;
		}
		else if ((choice == 4) && inventory[i].getCategory() == "Penthouse") {
			inventory[i].booked("reserved");
			bookedNum++;
			addRevenue(inventory[i]);
			inventory[i].setClient(clientName);
			cout << "\n" << " Room number: " << inventory[i].getNumber() << " reserved under  " << clientName << "\n";
			break;
		}
		

	}

}

bool Booking::validBooking(int choice)
{
	for (int i = 0; i < totalMax; i++) {

		if ((choice == 1) && inventory[i].getCategory() == "Standard Room: Courtyard") {
			return true;
		}
		else if ((choice == 2) && inventory[i].getCategory() == "Standard Room: Scenic") {
			return true;
		}
		else if ((choice == 3) && inventory[i].getCategory() == "Deluxe Suite") {
			return true;
		}
		else if ((choice == 4) && inventory[i].getCategory() == "Penthouse") {
			return true;
		}
		if (i == totalMax - 1)
			return false;

	}

}

void Booking::addRevenue(Room room) { revenue += room.getPrice(); }

int Booking::getRevenue() { return revenue; }

void Booking::getBookedR() {

	int cyards = 0, scenics = 0, deluxes = 0, pents = 0;

	for (int i = 0; i < totalMax; i++) {

		if (inventory[i].getCurrentR() == "Standard Room: Courtyard")
			cyards++;
		else if (inventory[i].getCurrentR() == "Standard Room: Scenic")
			scenics++;
		else if (inventory[i].getCurrentR() == "Deluxe Suite")
			deluxes++;
		else if (inventory[i].getCurrentR() == "Penthouse")
			pents++;

	}// end loop

	if (cyards > 0)
		cout << setw(64) << left << "Courtyards: " << setw(8) << right << cyards << endl;
	if (scenics > 0)
		cout << setw(64) << left << "Scenics: " << setw(8) << right << scenics << endl;
	if (deluxes > 0)
		cout << setw(64) << left << "Deluxes: " << setw(8) << right << deluxes << endl;
	if (pents > 0)
		cout << setw(64) << left << "Penthouses: " << setw(8) << right << pents << endl;


}

int Booking::getBamount()
{
	return bookedNum;
}

void Booking::filInfo(string path) {

	fstream dataFile;
	dataFile.open(path, ios::out);

	dataFile << "Client's name\t\t\t\t\tRoom Number\n\n";

	for (int i = 0; i < totalMax; i++)
		if (inventory[i].getCategory() == "Reserved")
			dataFile << setw(35) << left << inventory[i].getClient() << setw(8) << right << inventory[i].getNumber() << endl;

	dataFile << "\n\n" << setw(35) << left << "\nRooms Reserved:" <<
		setw(8) << right << getBamount();

	dataFile << setw(35) << left << "\nTotal Revenue:" << setw(2) << left
		<< "$ " << setw(8) << right << getRevenue() << endl;


	dataFile.close();

}