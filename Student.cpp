#include "Student.h"

Student::Student(int studentID, std::string studentName) {
	this->studentID = studentID;
	this->studentName = studentName;
	this->groupStatus = false;
	this->groupID = -1;
}

Student::Student() = default;

int Student::getStudentID() const { return studentID; };

void Student::setStudentID(int studentID) { this->studentID = studentID; };
void Student::setStudentName(std::string studentName) {this->studentName = studentName;
}

std::string Student::getStudentName() const { return studentName; }
 
void Student::setGroupStatus(bool groupStatus) { this->groupStatus = groupStatus; }

bool Student::getGroupStatus() const { return groupStatus; }

void Student::setGroupID(int groupID) { this->groupID = groupID; }

int  Student::getGroupID() const { return groupID; }

std::string Student::toString() {
	std::string studentInfor =
		"Name: " + getStudentName() + '\n'
		+ "Group: " + std::to_string(getGroupID()) + '\n'
		+ "isInGroup: " + std::to_string(getGroupStatus());
	return studentInfor;
}