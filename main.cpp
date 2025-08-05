#include <iostream>
#include <string>

using namespace std;

int GetMonthAsInt(string month) {
	int monthInt = 0;
	
	if (month == "January")
		monthInt = 1;
	else if (month == "February")
		monthInt = 2;
	else if (month == "March")
		monthInt = 3;
	else if (month == "April")
		monthInt = 4;
	else if (month == "May")
		monthInt = 5;
	else if (month == "June")
		monthInt = 6;
	else if (month == "July")
		monthInt = 7;
	else if (month == "August")
		monthInt = 8;
	else if (month == "September")
		monthInt = 9;
	else if (month == "October")
		monthInt = 10;
	else if (month == "November")
		monthInt = 11;
	else if (month == "December")
		monthInt = 12;
	return monthInt;
}

int main () {
	
	// TODO: Read dates from input, parse the dates to find the ones
	//       in the correct format, and output in m-d-yyyy format
	
	string inputLine;
	
	getline(cin, inputLine);
	while (inputLine != "-1") {
		// Find the first space to separate month from the rest
		size_t firstSpace = inputLine.find(' ');
		
		// Find the comma to separate day from year
		size_t commaPos = inputLine.find(',');
		
		// Check if we found both space and comma, and comma comes after space
		if (firstSpace != string::npos && commaPos != string::npos && commaPos > firstSpace) {
			// Extract month (from start to first space)
			string month = inputLine.substr(0, firstSpace);
			
			// Extract day (from after first space to comma)
			string day = inputLine.substr(firstSpace + 1, commaPos - firstSpace - 1);
			
			// Extract year (from after comma and space to end)
			string year = inputLine.substr(commaPos + 2);
			
			// Validate the month
			int monthInt = GetMonthAsInt(month);
			
			// Check if month is valid (not 0) and day/year are not empty
			if (monthInt != 0 && !day.empty() && !year.empty()) {
				// Output in m-d-yyyy format
				cout << monthInt << "-" << day << "-" << year << endl;
			}
		}
		
		getline(cin, inputLine);
	}
	
	return 0;
}