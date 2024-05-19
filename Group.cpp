#include "Group.h"
#include <fstream>
#include <cstring>

Group::Group(int groupID){
	this->groupID = groupID;
}

Group::Group() = default;

Group::~Group() = default;

int Group::getGroupID() const { return groupID; }

void Group::setGroupID(int groupID) { this->groupID = groupID; }

std::vector<Student> Group::getStudentList()
{
	return studentList;
}

int Group::getNumberOfStudent() const { return static_cast<int>(studentList.size()); }

void Group::addNewStudent(Student* student) 
{
	if (student->getGroupStatus() == true) 
	{
		std::cout << "This student already been in other group";
		return;
	}
	else 
	{
		student->setGroupID(this->groupID);
		student->setGroupStatus(true);
		studentList.push_back(*student);
	}
	
}

void Group::displayGroupInfor() {
	std::cout << "\nGroup " << groupID << ": \n";
	for (int i = 0; i < studentList.size(); i++)
	{
		std::cout << "\t" << studentList[i].getStudentName() << std::endl;
	}
}

void Group::saveGroupInfor(std::fstream& outfile)
{
	outfile.write(reinterpret_cast<char*>(&groupID), sizeof(groupID));
	size_t listSize = studentList.size();
	outfile.write(reinterpret_cast<const char*>(&listSize), sizeof(listSize));
	for (const auto& student : studentList) {
		outfile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
	}
}

void Group::loadGroupInfor(std::fstream& infile)
{
	infile.read(reinterpret_cast<char*>(&groupID), sizeof(groupID));
	size_t listSize;
	infile.read(reinterpret_cast<char*>(&listSize), sizeof(listSize));
	studentList.resize(listSize);
	for (auto& student : studentList) 
	{
		infile.read(reinterpret_cast<char*>(&student), sizeof(Student));
	}
}




 
