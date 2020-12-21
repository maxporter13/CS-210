//============================================================================
// Name        : projectOne.cpp
// Author      : Max POrter
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Chadatech Clock
//============================================================================

#include <iostream>
using namespace std;

class TimeClock;

class TimeClock {
public:
	int Mhour;
	int Shour;
	int minute;
	int second;
	TimeClock();
	void addOneHour();
	void addOneMinute();
	void addOneSecond();
};

//default constructor
TimeClock :: TimeClock()
{
	Mhour = 13;
	Shour = 1;
	minute = 2;
	second = 7;
}

//adds an hour to the standard hour (Shour) and the military hour (Mhour)
void TimeClock :: addOneHour()
{
	if(Mhour == 23) Mhour = 0;
	else Mhour = Mhour + 1;
	if(Shour == 12) Shour = 1;
	else Shour = Shour + 1;
}

//adds a minute and checks if the hour is done and needs to be incremented
void TimeClock :: addOneMinute()
{
	minute = minute + 1;
	if(minute == 60)
	{
		minute = 0;
		addOneHour();
	}
}

//adds a second and checks if the minute is done and needs to be incremented
void TimeClock :: addOneSecond()
{
	second = second + 1;
	if(second == 60)
	{
		second = 0;
		addOneMinute();
	}
}

//displays the time
void displayTime(TimeClock& timeclock)
{
	int hour12,hour24;
	int minute,second;
	bool ampm = false;

	minute = timeclock.minute;
	second = timeclock.second;
	hour12 = timeclock.Shour;
	hour24 = timeclock.Mhour;
	//make a check if it is am or pm based on the 24 hour clock
	if(hour24 > 12) ampm = true;

	//display the clock
	cout << "**************************   **************************" << endl;
	cout << "*      12-Hour Clock     *   *      24-Hour Clock     *" << endl;
	cout << "*      ";
	//add a zero if the hour is less than 10 to display like "09"
	if(hour12 < 10) cout << "0";
	cout << timeclock.Shour << ":";
	//add a zero if the minute is less than 10 to display like "09"
	if(minute < 10) cout << "0";
	cout << timeclock.minute << ":";
	//add a zero if the second is less than 10 to display like "09"
	if(second < 10) cout << "0";
	cout << timeclock.second << " ";
	//print out am or pm based on our previous check
	if(ampm) cout << "PM";
	else cout << "AM";
	cout << "       *   *      ";
	//add a zero if the hour is less than 10 to display like "09"
	if(hour24 < 10) cout << "0";
	cout << timeclock.Mhour << ":";
	//add a zero if the minute is less than 10 to display like "09"
	if(minute < 10) cout << "0";
	cout << timeclock.minute << ":";
	//add a zero if the second is less than 10 to display like "09"
	if(second < 10) cout << "0";
	cout << timeclock.second << "          *" << endl;
	cout << "**************************   **************************" << endl;
}

//displays the menu interface
void displayMenu()
{
	//display the menu interface
	cout << "**************************" << endl;
	cout << "* 1 - Add One Hour       *" << endl;
	cout << "* 2 - Add One Minute     *" << endl;
	cout << "* 3 - Add One Second     *" << endl;
	cout << "* 4 - End Program        *" << endl;
	cout << "**************************" << endl;
}

int main() {
	TimeClock timeclock;
	displayTime(timeclock);
	do
	{
		displayMenu();
		//gather user input
		int input;
		cin >> input;
		if(input == 1)
		{
			//add one hour and display time
			timeclock.addOneHour();
			displayTime(timeclock);
		}
		else if (input == 2)
		{
			//add one minute and display time
			timeclock.addOneMinute();
			displayTime(timeclock);
		}
		else if (input == 3)
		{
			//add one second and display time
			timeclock.addOneSecond();
			displayTime(timeclock);
		}
		else if (input == 4)
		{
			//say goodbye and exit
			cout << "Goodbye!" << endl;
			exit(1);
		}
		else
		{
			cout << "Invalid input. Try again now:" << endl;
		}
	}while(true);
	return 0;
}
