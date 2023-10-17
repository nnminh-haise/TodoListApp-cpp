#include "Task.h"

std::string Task::toString(Status status) {
	switch (status) {
	case Task::PENDING:
		return "Pending";
	case Task::IN_PROCESS:
		return "In process";
	case Task::DONE:
		return "Done";
	case Task::CANCELED:
		return "Canceled";
	case Task::OVERDUE:
		return "Overdue";
	}
	return std::string();
}

std::string Task::toString(Priority priority) {
	switch (priority) {
	case Task::IN_DAY:
		return "In day";
	case Task::IN_THREE_DAYS:
		return "In three days";
	case Task::IN_WEEK:
		return "In week";
	case Task::IN_TWO_WEEKS:
		return "In two weeks";
	case Task::IN_MONTH:
		return "In month";
	}
	return std::string();
}

Task::Task()
	: status(PENDING), title(""), priority(IN_DAY), startDate(Date()), deadline(Date()), note("")
{
	this->id = nextId;
	this->nextId++;
}

Task::Task(Status status, std::string title, Priority priority, Date startDate, Date deadline, std::string note)
	: status(status), title(title), priority(priority), startDate(startDate), deadline(deadline), note(note)
{
	this->id = nextId;
	this->nextId++;
}

void Task::setStatus(Status status) {
	this->status = status;
}

Task::Status Task::getStatus() const {
	return this->status;
}

void Task::setTitle(std::string title) {
	this->title = title;
}

std::string Task::getTitle() const {
	return this->title;
}

void Task::setPriority(Priority priority) {
	this->priority = priority;
}

Task::Priority Task::getPriority() const {
	return this->priority;
}

void Task::setStartDate(Date startDate) {
	this->startDate;
}

Date Task::getStartDate() const {
	return this->startDate;
}

void Task::setDeadline(Date deadline) {
	this->deadline = deadline;
}

Date Task::getDeadline() const {
	return this->deadline;
}

void Task::setNote(std::string note) {
	this->note = note;
}

std::string Task::getNote() const {
	return this->note;
}

unsigned int Task::getId() const {
	return this->id;
}

std::string Task::toString() const {
	return std::format(
		"[Task {}] status={}, title={}, priority={}, startDate={}, deadline={}, note={}",
		this->id,
		toString(this->status),
		this->title,
		toString(this->priority),
		this->startDate.toString(),
		this->deadline.toString(),
		this->note
	);
}



