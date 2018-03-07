#include <iostream>
#include <string>

using namespace std;

const int route_length = 50;

class Train {
	private:
		bool isDriverPresent;
		int speed;
	public:
		string route;
		Train(int speed_c, bool driverPresence) {
			cout << "Please set the route name: ";
			speed = speed_c;
			isDriverPresent = driverPresence;
			getline(cin, route);
		}
		void getDriverStatus() {
			switch (isDriverPresent) {
				case 0:
					cout << "Driver presence: false" << endl;
				case 1:
					cout << "Driver presence: true" << endl;
			}
		};
		
		void setDriverStatus(int driverPresence) {
			switch (driverPresence) {
				case 0:
					this->isDriverPresent = false;
				case 1:
					this->isDriverPresent = true;
			}
		}
		
		friend ostream& operator << (ostream& peregruz, const Train &Train) {
			peregruz << Train.speed << " " << " " << boolalpha << Train.isDriverPresent << " " << Train.route << endl;
			return peregruz;
		}
		
};


/*class Driver {
	public:
		bool isDriving (int status);
	
};

bool isDriving (int status) {
	switch (status) {
		case 0:
			return false;
		case 1:
			return true;
	}
}


class CHS_Train {
	public:
		
	//	if (Mashinist.isDriving()==true) {
					 
		};
//};

class CHS_Underground {
	public:
		
	//	if (Mashinist.isDriving()==true) {
			
		};
//};


*/
int main() {
	

Train Route_0150(50, false);
cout << Route_0150;

Route_0150.setDriverStatus(1);

Route_0150.getDriverStatus();



return 0;	
}
