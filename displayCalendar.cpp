
// CSC2034
// 02/05/2024
//Richard Sharp

#include <iostream> //cout
#include <string>   //class string
#include <cstdio>   //printf, NULL
using namespace std;

/**
 * @brief Calculates the day of the week for a given date.
 *
 * @param y Year
 * @param m Month
 * @param d Day
 * @return int Day of the week (0=Sunday, 1=Monday, ..., 6=Saturday)
 */
int day_of_week(int y, int m, int d) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

int main() {
    int year;           // The year input by user
    bool isLeapYear = false;    // True if year is a leap year
    int startDay;       // The 1st day of the month
    int dayCounter;     // Incrementer for each day of the year
    string week[7];
    const string DAYS_OF_WEEK[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };    // Name of days of the week
    const string MONTHS[] = { "January", "February", "March", "April",
                              "May", "June", "July", "August",
                              "September", "October", "November", "December" };    // Name of months
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31 };    // Days in each month

    // Get year for calendar
    cout << "Please enter a year to display:\n" << endl;
    cin >> year;

    // Adjust for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        isLeapYear = true;
        daysInMonth[1] = 29; // February has 29 days in a leap year
    }

    // Get first day of year
    startDay = day_of_week(year, 1, 1);

    // Print calendar for each month of designated year
    for (int curMonth = 0; curMonth < 12; curMonth++) {
        // Declare and initialize monthFormat with the current month and year
        string monthFormat = MONTHS[curMonth] + " " + to_string(year); // Corrected line
        // Print: [month] [year]
        printf("%21s\n", monthFormat.c_str());
        printf("-----------------------------\n");

        // Iterate over Days and print days header
        for (string currentDay : DAYS_OF_WEEK) {
            printf("%3s ", currentDay.c_str());
        }
        printf("\n");

        // Print blank spaces before first day of the month
        for (int column = 0; column < startDay; column++) {
            printf("    ");
        }

        // Print dates for each day of the month
        dayCounter = 1;
        while (dayCounter <= daysInMonth[curMonth]) {
            // Print each date starting from the correct start day
            for (int column = startDay; column < 7 && dayCounter <= daysInMonth[curMonth]; column++) {
                printf("%4d", dayCounter);
                dayCounter++;
                startDay++;
            }
            std::printf("\n");
            startDay %= 7;
        }


        std::printf("\n\n");
        startDay %= 7;
    }

    return 0;
}