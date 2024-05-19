#include "Project.h"

Project::Project(int projectID, Time dueDate) {
	this->projectID = projectID;
	this->dueDate = dueDate;
	this->description = "";
}

Project::Project(int projectID, std::string description, Time dueDate) {
	this->projectID = projectID;
	this->dueDate = dueDate;
	this->description = description;
}

Project::Project() = default;

int Project::getProjectID() const { return projectID; }

void Project::setProjectID(int projectID) { this->projectID = projectID; }

std::string Project::getDescription() const { return description; }

void Project::setDescription(std::string description) { this->description = description; }

Time Project::getDueDate() const { return dueDate; }

void Project::setDueDate(Time dueDate) { this->dueDate = dueDate; }

std::string Project::ProjectInfor()
{
	std::string infor;
	infor = "Project no" + std::to_string(getProjectID()) + " Due date: " + dueDate.toString() + "  Description: " + getDescription();
	return infor;
}

void Project::saveProjectInfor(std::fstream& outfile)
{
	outfile.write(reinterpret_cast<char*>(&projectID), sizeof(projectID));
	outfile.write(reinterpret_cast<char*>(&dueDate), sizeof(dueDate));
	outfile.write(reinterpret_cast<char*>(&description), sizeof(description));
}

void Project::loadProjectInfor(std::fstream& infile)
{
	infile.read(reinterpret_cast<char*>(&projectID), sizeof(projectID));
	infile.read(reinterpret_cast<char*>(&dueDate), sizeof(dueDate));
	infile.read(reinterpret_cast<char*>(&description), sizeof(description));
}

//std::string Project::toString() {}