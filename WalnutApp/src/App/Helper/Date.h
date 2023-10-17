#pragma once
#ifndef DATE
#define DATE

#include <iostream>
#include <string>
#include <format>
#include <sstream>
#include <chrono>

class Date {
public:
    enum Format {
        DDMMYYYY, MMDDYYYY, YYYYMMDD
    };

public:
    Date();
    Date(const std::string& dateString);
    Date(int day, int month, int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setFormat(Format format);
    std::string toString() const;
    int daysBetween(const Date& other) const;
    void parseFromString(const std::string& dateString);
    Date addDays(int days) const;
    Date minusDays(int days) const;
    int compareTo(const Date& other) const;
    static Date randomDate();

private:
    static bool isLeapYear(int year);
    static int daysInMonth(int month, int year);

private:
    int day;
    int month;
    int year;
    Format dateFormat = DDMMYYYY;
};



#endif // !DATE
