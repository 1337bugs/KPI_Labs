
#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>



using namespace std;


class Train {
private:
	bool isDriverPresent;
	bool inDepot;
	float load;
	int speed;
	char sys_state;
	friend void fixStuff(Train &T);
	friend void checkState(Train &T);
public:
	int trainNumber;
	string destination;
	string next_station;
	Train(int number, int driverPresence, char systemState) {
		isDriverPresent = driverPresence;
		inDepot = true;
		trainNumber = number;
		sys_state = systemState;
		speed = 0;
		load = 0;
	}

	void showDriverPresence() {
		if (isDriverPresent == 1) {
			cout << "Driver is present in the train" << endl;
		}
		else {
			cout << "Driver is somewhere out of the train" << endl;
		}
	}

	void show_dest() {
		cout << "Destination is: " << destination << endl;
		cout << endl;
	}
	void setOff() {
		speed = 40;
		load = 0;
		inDepot = false;
		cout << "The train is launched" << endl;
		cout << endl;

	}

	
	void switchSetData(int count) {
		switch (count) {
			case 1:
				if (isDriverPresent == true) {
					isDriverPresent = false;
				}
				else {
					isDriverPresent = true;
				}
			case 2:
				if (inDepot == true) {
					inDepot = false;
				}
				else {
					inDepot = true;
				}
		}
	}

	bool drvInfo() {
		return isDriverPresent;
	}

	bool depotInfo() {
		return inDepot;
	}


	void show_info() {
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Train number: " << trainNumber << endl;
		if (inDepot == true && speed == 0) {
			cout << "The train is in the depot" << endl;
		}
		else {
			cout << "The train is on the rails" << endl;
		}
		if (speed == 0) {
			cout << "Train stays still" << endl;
		}
		else {
			cout << "Speed: " << speed << endl;
		}
	/*	cout << "State of systems: ";
		if (sys_state == 0) {
			cout << "OK" << endl;
			cout << endl;
		}
		else if (sys_state == 1) {
			cout << "CHECK" << endl;
			cout << endl;
		}*/

		cout << "Load: " << load << "%" << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		
	}

	//~Train();
};


class Metro_Staff {
protected:
	int w_hours;
	int salary;
public:
	string name;
	Metro_Staff(string n_name, int working_hours, int s_salary) {
		name = n_name;
		w_hours = working_hours;
		salary = s_salary;
	}
	virtual void message() const {
		cout << endl;
		cout << "I work in the subway!" << endl;
		cout << endl;
	}
};

class Cashier : public Metro_Staff {
public:
	float commun;
	Cashier(string n_name, int working_hours, int s_salary, float communication) : Metro_Staff(n_name, working_hours, s_salary) { //fix odd shit with constructor (working hrs)
		name = n_name;
		w_hours = working_hours;
		salary = s_salary;
		commun = communication;
	}
	void sellTicket(int number) {
		int total = 0;
		total = number * 5;
		cout << "Total is: " << total << endl;
		cout << "Here are your " << number << " tickets" << endl;
	}
	void message() {
		cout << "Ticket price is 5UAH" << endl;
	}
	void show_info() {
		cout << endl;
		cout << endl;
		cout << "Name: " << name << endl;
		cout << "Working hours: " << w_hours << endl;
		cout << "Salary: " << salary << endl;
		cout << "Communication, %: " << commun << endl;
		cout << endl;
		cout << endl;
	}
};

class Mechanic : public Metro_Staff {
public:
	int xp_years;
	int salary;
	Mechanic(string n_name, int working_hours, int s_salary, int exp_yrs) : Metro_Staff(n_name, working_hours, s_salary) { 
		name = n_name;
		w_hours = working_hours;
		xp_years = exp_yrs;
		salary = s_salary;
	}
	friend void fixStuff(Train &T) {
		cout << " Mechanic: I fix stuff!" << endl;
		cout << "Wait..." << endl;
		Sleep(700);
		T.sys_state = 0;
		cout << "Issues fixed" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	}
	void show_info() {
		cout << endl;
		cout << endl;
		cout << "Name: " << name << endl;
		cout << "Working hours: " << w_hours << endl;
		cout << "Salary: " << salary << endl;
		cout << "Experience: " << xp_years << endl;
		cout << endl;
		cout << endl;
	}
	friend void checkState(Train &T) {
		cout << "Wait..." << endl;
		Sleep(700);
		if (T.sys_state == 0) {
			cout << "Everything is ok" << endl;

		}
		if (T.sys_state == 1) {
			cout << "Train needs to be fixed" << endl;
		}
		cout << endl;
	}
};

class Driver : public Metro_Staff {
public:
	Driver(string n_name, int working_hours, int s_salary) : Metro_Staff(n_name, working_hours, s_salary) {
		name = n_name;
	}
	void message() {
		cout << "Driver: I like trains!" << endl;
	}

};

class HeadOfDepartment : public Metro_Staff {
private:
	class User {
	private:
		string pass_phrase;
		string password;
	public:
		bool p_right;
		int n;
		string name;
		User(string username) {
			p_right = false;
			n = 0;
			name = username;
		}

		void checkForgot() {
			cout << "Do you remember your password? Enter 1 for ""YES"" and 0 for ""NO"" " << endl;
			cin >> n;
			if (n == 1) {
				pass_phrase == "password";
			}
			else {
				cout << "Please contact system administrator" << endl;
				system("pause");
				exit(0);
				
			}

		}
		void checkPass() { //fix this
			cout << "Please enter your password:" << endl;
			cin >> password;
			while (password == pass_phrase) {
				cout << "Password is wrong. Please try again" << endl;
				cout << "Enter q to exit" << endl;
				cin >> password;
				if (password == pass_phrase)
					break;
				if (password == "q") {
					exit(0);
				}
			}
			p_right = true;
		}
		/*	void showInfo() {
		//cout << "Name: " << name << endl;
		cout << "Password: " << "XXXXXXXXXX" << endl;
		}	*/
	};

public:
	int subordNum;
	HeadOfDepartment(string n_name, int working_hours, int s_salary, int subordNum) : Metro_Staff(n_name, working_hours, s_salary) {
		name = n_name;
		w_hours = working_hours;
		salary = s_salary;
		subordNum = subordNum;
	}
	
	void login() {
		User Chief("Sergei");
		Chief.checkForgot();
		Chief.checkPass();
	}
	
	void message() {
		cout << "I have the power!" << endl;
	}
	
	void messageDefault() {
		cout << "Dear passengers, please don't crowd up and be move faster carefully to prevent accidents" << endl;
	}

	void messageAnnounce() {
		cout << "Attention, announcement!" << endl;
	}

	void messageTrains() {
		cout << "Trains are to arrive in several minutes" << endl;
	}

	void callDriver(Driver &D, Train &T) {
		cout << "Wait a bit..." << endl;
		Sleep(2000);
		cout << endl;
		if (T.drvInfo() == true) {
			cout << "";
			D.message();
			cout << "" << endl;
			
			cout << "Driver is here" << endl;
		}
		else {
			cout << "Calling the driver" << endl;
			Sleep(1000);
			T.switchSetData(1);
			cout << "";
			D.message();
			cout << "" << endl;

			cout << "Driver is here" << endl;

		}
		cout << "Now driver is in the train" << endl;
	}
	

	//make connection to class User
	
};




int main() {

	
	HeadOfDepartment newBoss("Oleg Sergeevich", 4, 10000, 5);
	newBoss.login();
	
	Driver driver1("Andrei", 8, 6500);
	Driver driver2("Nikolay", 8, 6500);
	Driver driver3("Alexandr", 8, 6500);
	
	Train train1(1067, 0, 0);
	Train train2(1068, 0, 1);
	Train train3(1069, 1, 0);
	
	Cashier cashier1("Oleg", 8, 7000, 85);


	Mechanic Mech1("Aleksei", 6, 6500, 3);
	
	int count = 0;
	int n_count = 0;
	
	while (true) {
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Choose what is needed to be done: " << endl;
		cout << "1. See info about trains' status" << endl;
		cout << "2. Call the drivers" << endl;
		cout << "3. Check trains' state" << endl;
		cout << "4. Fix the trains" << endl;
		cout << "5. Launch train movement" << endl;
		cout << "6. Open messages and announcements menu" << endl;
		cout << "7. Check how cashier works" << endl;
		cout << "10. Enter 0 to exit" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cin >> count;
		switch (count) {
		case 1:
			cout << "Info:";
			train1.show_info();
			cout << "Train " << train1.trainNumber << ": ";
			train1.showDriverPresence();
			train2.show_info();
			cout << "Train " << train2.trainNumber << ": ";
			train2.showDriverPresence();
			train3.show_info();
			cout << "Train " << train3.trainNumber << ": ";
			train3.showDriverPresence();
			break;
		case 2:
			newBoss.callDriver(driver1, train1);
			newBoss.callDriver(driver2, train2);
			newBoss.callDriver(driver3, train3);
			break;
			
		case 3:
			cout << "Train" << train1.trainNumber << ": ";
			checkState(train1);
			cout << "Train" << train3.trainNumber << ": ";
			checkState(train2);
			cout << "Train" << train3.trainNumber << ": ";
			checkState(train3);
			count = 0;
			break;
		case 4:
			fixStuff(train1);
			fixStuff(train2);
			fixStuff(train3);
			count = 0;
			break;
		case 5:
			train1.setOff();
			train2.setOff();
			train3.setOff();
		case 6:
			while (true) {
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "1. Default announcement" << endl;
				cout << "2. Important announcement" << endl;
				cout << "3. Train announcement" << endl;
				cout << "4. Back to main menu" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cin >> n_count;
				switch (n_count) {
				case 1:
					newBoss.messageDefault();
					break;
				case 2:
					newBoss.messageAnnounce();
					break;
				case 3:
					newBoss.messageTrains();
					break;
				case 4:
					n_count++;
					break;
				}
				if (n_count >= 1)
					n_count = 0;
					break;
			}
			break;
		case 7:
			cout << "Going to the cashier..." << endl;
			Sleep(700);
			cout << endl;
			cout << "--";
			cashier1.message();
			cout << "--";
			cout << endl;
			break;
		case 0:
			cout << "Logging out..." << endl;
			Sleep(2000);
			exit(0);
		}
	}



	system("pause");
	return 0;
}


