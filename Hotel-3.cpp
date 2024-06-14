#include "Hotel.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

Hotel::Hotel() {

	date();
	introList();
	recordDate();

}

void Hotel::bookRoom() {


	string option;
	bool repeat = true, validChoice = false;

	int choice = 0;

	while (repeat) {

		cout << "5. Enter M to go to back to the menu or D to Exit";
		cout << "\nEnter a command or a value(1-4) to reserve a room >> ";
		cin >> option;

		if (option[0] == 'M' || option[0] == 'm' || option[0] == 'D' || option[0] == 'd') {
			savedCommand = option[0];
			cout << "\n";
			break;
		}

		if (isdigit(option[0]))
			choice = stoi(option);


		while (!isdigit(option[0]) || (choice < 1 || choice > 4) || !inventory.validBooking(choice)) {

			cout << "Invalid Input... Try Again >> ";
			cin >> option;

			if (option[0] == 'M' || option[0] == 'm' || option[0] == 'D' || option[0] == 'd') {
				repeat = false;
				savedCommand = option[0];
				cout << "\n";
				break;
			}

			if (isdigit(option[0]))
				choice = stoi(option);

		}

		if (option[0] != 'M' && option[0] != 'm' && option[0] != 'D' && option[0] != 'd') {
			inventory.bookR(choice);
			cout << "\n";
			inventory.showInventory();
			cout << "\n";
		}

	}

}

void Hotel::getTotal() {

	cout << "\n" << setw(65) << left << "\nRooms Reserved:" <<
		setw(8) << right << inventory.getBamount() << "\n\n";

	inventory.getBookedR();

	cout << "\n" << setw(65) << left << "\nTotal Revenue:" << setw(2) << left
		<< "$ " << setw(8) << right << inventory.getRevenue() << endl;

}

void Hotel::introList() {

	bool repeat = true;
	string option;

	while (repeat) {

		cout << "   Choose an option: " << endl;
		cout << "     A. Reserve a room" << endl;
		cout << "     B. Inventory/Revenue" << endl;
		cout << "     C. View Records" << endl;
		cout << "     D. Exit" << endl << endl;
		cout << "   Option:" << endl;
		cin >> option;

		while (option[0] != 'D' && option[0] != 'd' && option[0] != 'A' && option[0] != 'a'
			&& option[0] != 'B' && option[0] != 'b' && option[0] != 'C' && option[0] != 'c') {

			cout << "Try Again.";
			cin >> option;
		}

		if (option[0] == 'D' || option[0] == 'd')
			break;

		if (option[0] == 'A' || option[0] == 'a') {

			inventory.showInventory();
			bookRoom();

			if (savedCommand == 'D' || savedCommand == 'd')
				break;
			else
				continue;

		}

		if (option[0] == 'B' || option[0] == 'b')
			getTotal();

		if (option[0] == 'C' || option[0] == 'c') {

			date();
			infoDay();

		}

		cout << "\n";

	}

}

void Hotel::date() {

	string date, tempDate = "";
	static bool isTodaysDate = true;
	bool error = true;
	int month, day, year;

	if (isTodaysDate) {
		cout << ">>Type Today's Date [MM DD YYYY]: ";
		getline(cin, date);
	}
	else {
		getline(cin, date);
		cout << "\n>>Type a date you wish to review [MM DD YYYY]: ";
		getline(cin, date);
	}

	while (error) {

		if (date.length() == 10 && isdigit(date[0]) && isdigit(date[1]) && isdigit(date[3]) && isdigit(date[4])
			&& isdigit(date[6]) && isdigit(date[7]) && isdigit(date[8]) && isdigit(date[9])) {

			tempDate = tempDate + date[0] + date[1];
			month = stoi(tempDate);
			tempDate = "";

			tempDate = tempDate + date[3] + date[4];
			day = stoi(tempDate);
			tempDate = "";

			tempDate = tempDate + date[6] + date[7] + date[8] + date[9];
			year = stoi(tempDate);
			tempDate = "";

			if (month > 12)
				error = true;
			else if (day > 31)
				error = true;
			else
				error = false;
		}

		if (error) {
			cout << "\nDate typed incorrectly. Try again. >> ";
			getline(cin, date);
			continue;
		}

		if (isTodaysDate) {

			saveDate = "";
			saveDate = saveDate + date[0] + date[1] + "-" + date[3] + date[4] + "-"
				+ date[6] + date[7] + date[8] + date[9];

			isTodaysDate = false;
		}
		else {

			saveOldDate = "";
			saveOldDate = saveOldDate + date[0] + date[1] + "-" + date[3] + date[4] + "-"
				+ date[6] + date[7] + date[8] + date[9];

		}

	}

}

void Hotel::recordDate() {

	string path = "C:\\Users\\16193\\source\\repos\\new\\Hotel2Records\\"
		+ saveDate + ".txt";

	inventory.filInfo(path);

}

void Hotel::infoDay() {

	string sentence;
	fstream dataFile;

	string path = "C:\\Users\\16193\\source\\repos\\new\\Hotel2Records\\"
		+ saveOldDate + ".txt";

	dataFile.open(path, ios::in);

	if (dataFile.fail())
		cout << "\nInvalid input";
	else {

		cout << "\nDate: " << saveOldDate << "\n\n";
		while (getline(dataFile, sentence, '\n')) {

			cout << sentence << endl;
		}
		dataFile.close();
		cout << "\n\n";
	}
}
