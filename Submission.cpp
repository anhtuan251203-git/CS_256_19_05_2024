#include<iostream>
#include<iomanip>
#include "Submission.h"
#include <fstream>

Submission::Submission(int projectID, int groupID, Time submitDate, bool status) {
	this->projectID = projectID;
	this->groupID = groupID;
	this->submitDate = submitDate;
	this->status = status;
}

Submission::Submission() = default;

int Submission::getProjectID() const { return projectID; }


void Submission::setProjectID(int projectID) { this->projectID = projectID; }


int Submission::getGroupID() const { return groupID; }


void Submission::setGroupID(int groupID) { this->groupID = groupID; }


bool Submission::getStatus() const { return status; }


void Submission::setStatus(bool status) { this->status = status; }

Time Submission::getSubmitDate() const { return submitDate; }

void Submission::setSubmitDate(Time submitDate) 
{ this->submitDate = submitDate; }

std::string Submission::submissionInfor() 
{
	std::string status_sub;
	std::string infor;
	if (getStatus()) {
		status_sub = "On time";
	}
	else {
		status_sub = "late";
	}
	infor = "Project no" + std::to_string(getProjectID()) + " Group " + std::to_string(getGroupID()) + "  Status: "+ status_sub + " Submitted date: " + submitDate.toString();
	return infor;
}

std::string Submission::submissionInfor_overall()
{
	std::string status_sub;
	std::string infor;
	if (getStatus()) {
		status_sub = "on time";
	}
	else {
		status_sub = "late";
	}
	return status_sub;
}




