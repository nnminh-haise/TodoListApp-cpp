#include "Date.h"

Date::Date() {
    auto now = std::chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    struct tm timeinfo;
    localtime_s(&timeinfo, &currentTime);
    day = timeinfo.tm_mday;
    month = timeinfo.tm_mon + 1;
    year = timeinfo.tm_year + 1900;
}

Date::Date(const std::string& dateString) {
    std::istringstream iss(dateString);
    char delimiter;
    int day, month, year;

    if (!(iss >> day >> delimiter >> month >> delimiter >> year) || delimiter != '/')
        throw std::invalid_argument("Invalid date format");

    if (day < 1 || day > daysInMonth(month, year))
        throw std::out_of_range("Invalid day");

    if (month < 1 || month > 12)
        throw std::out_of_range("Invalid month");

    if (year < 1900 || year > 2100)
        throw std::out_of_range("Invalid year");

    day = day;
    month = month;
    year = year;
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

void Date::setFormat(Format dateFormat) {
    this->dateFormat = dateFormat;
}

Date Date::randomDate() {
    int maxDaysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int year = rand() % 201 + 1900;
    int month = rand() % 12 + 1;

    // * Leap year check and update days in month accordingly.
    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
        maxDaysInMonth[1] = 29;
    }

    int maxDays = maxDaysInMonth[month - 1];
    int day = rand() % maxDays + 1;

    return Date(day, month, year);
}

std::string Date::toString() const {
    switch (this->dateFormat) {
    case (MMDDYYYY): {
        return std::format("{:02}-{:02}-{}", this->month, this->day, this->year);
    }
    case (YYYYMMDD): {
        return std::format("{}-{:02}-{:02}", this->year, this->month, this->day);
    }
    }

    return std::format("{:02}-{:02}-{}", this->day, this->month, this->year);
}


int Date::daysBetween(const Date& other) const {
    int days1 = day;
    for (int m = 1; m < month; m++)
        days1 += daysInMonth(m, year);

    int days2 = other.day;
    for (int m = 1; m < other.month; m++)
        days2 += daysInMonth(m, other.year);

    for (int y = year; y < other.year; y++)
        days2 += isLeapYear(y) ? 366 : 365;

    return std::abs(days2 - days1);
}

void Date::parseFromString(const std::string& dateString)
{
    std::istringstream iss(dateString);
    char delimiter;
    int day, month, year;

    if (!(iss >> day >> delimiter >> month >> delimiter >> year) || delimiter != '/')
        throw std::invalid_argument("Invalid date format");

    if (day < 1 || day > daysInMonth(month, year))
        throw std::out_of_range("Invalid day");

    if (month < 1 || month > 12)
        throw std::out_of_range("Invalid month");

    if (year < 1900 || year > 2100)
        throw std::out_of_range("Invalid year");

    day = day;
    month = month;
    year = year;
}

//Date Date::operator+(int days) const {
//    Date result(*this);
//    int totalDays = day + days;
//
//    while (totalDays > daysInMonth(result.month, result.year)) {
//        totalDays -= daysInMonth(result.month, result.year);
//        ++result.month;
//        if (result.month > 12) {
//            result.month = 1;
//            ++result.year;
//        }
//    }
//
//    result.day = totalDays;
//    return result;
//}
//
//Date Date::operator-(int days) const {
//    Date result(*this);
//    int totalDays = day - days;
//
//    while (totalDays < 1) {
//        --result.month;
//        if (result.month < 1) {
//            result.month = 12;
//            --result.year;
//        }
//        totalDays += daysInMonth(result.month, result.year);
//    }
//
//    result.day = totalDays;
//    return result;
//}

Date Date::addDays(int days) const {
    Date result{};
    int totalDays = day + days;

    while (totalDays > daysInMonth(result.month, result.year)) {
        totalDays -= daysInMonth(result.month, result.year);
        ++result.month;
        if (result.month > 12) {
            result.month = 1;
            ++result.year;
        }
    }

    result.day = totalDays;
    return result;
}

Date Date::minusDays(int days) const {
    Date result{};
    int totalDays = day - days;

    while (totalDays < 1) {
        --result.month;
        if (result.month < 1) {
            result.month = 12;
            --result.year;
        }
        totalDays += daysInMonth(result.month, result.year);
    }

    result.day = totalDays;
    return result;
}

int Date::compareTo(const Date& other) const {

    if (this->year > other.year) {
        return 1;
    }
    else if (this->year == other.year) {
        if (this->month > other.month) {
            return 1;
        }
        else if (this->month == other.month) {
            if (this->day > other.day) {
                return 1;
            }
            else if (this->day == other.day) {
                return 0;
            }
        }
    }
    return -1;
}

//bool operator>(const Date& lhs, const Date& rhs) {
//    if (lhs.year > rhs.year)
//        return true;
//    else if (lhs.year == rhs.year) {
//        if (lhs.month > rhs.month)
//            return true;
//        else if (lhs.month == rhs.month)
//            return lhs.day > rhs.day;
//    }
//    return false;
//}

bool Date::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth(int month, int year) {
    static const int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month < 1 || month > 12)
        throw std::out_of_range("Invalid month");
    int days = daysPerMonth[month - 1];
    if (month == 2 && isLeapYear(year))
        days++;
    return days;
}