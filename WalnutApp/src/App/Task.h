#pragma once

#ifndef TASK
#define TASK

#include <string>
#include <format>
#include "Helper/Helper.h"

class Task {
public:
	enum Status {
		PENDING, IN_PROCESS, DONE, CANCELED, OVERDUE
	};

	static std::string toString(Status status);

	enum Priority {
		IN_DAY, IN_THREE_DAYS, IN_WEEK, IN_TWO_WEEKS, IN_MONTH
	};

	static std::string toString(Priority priority);

public:
	Task();

	Task(Status status, std::string title, Priority priority, Date startDate, Date deadline, std::string note);

	void setStatus(Status status);

	Status getStatus() const;

	void setTitle(std::string title);

	std::string getTitle() const;

	void setPriority(Priority priority);

	Priority getPriority() const;

	void setStartDate(Date startDate);

	Date getStartDate() const;

	void setDeadline(Date deadline);

	Date getDeadline() const;

	void setNote(std::string note);

	std::string getNote() const;

	unsigned int getId() const;

	std::string toString() const;

private:
	unsigned int id;
	static unsigned int nextId;
	Status status;
	std::string title;
	Priority priority;
	Date startDate;
	Date deadline;
	std::string note;
};

#endif // !TASK
