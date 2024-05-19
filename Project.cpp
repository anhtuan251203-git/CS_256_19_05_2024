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

int Project::getProjectID() const { return projectID; }

void Project::setProjectID(int projectID) { this->projectID = projectID; }

std::string Project::getDescription() const { return description; }

void Project::setDescription(std::string description) { this->description = description; }

Time Project::getDueDate() const { return dueDate; }

void Project::setDueDate(Time dueDate) { this->dueDate = dueDate; }

//std::string Project::toString() {}