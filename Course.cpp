
#include "Course.h"

Course::Course(std::string courseID) {
	this->courseID = courseID;
	groupList.resize(0);
	projectList.resize(0);
	studentList.resize(0);
	submissionList.resize(0);
}

int Course::getNumberOfProjects() const {
	return int(projectList.size());
}
void Course::setNumberOfProjects(int number_of_projects) {
	this->number_of_projects = number_of_projects;
}
int Course::getNumberOfGroups() const {
	return int(groupList.size());
}
void Course::setNumbeOfGroups(int number_of_groups) {
	this->number_of_groups = number_of_groups;
}

void Course::getStudenList()
{
	for (Group& group : groupList)
	{
		for (Student& student : group.getStudentList())
		{
			studentList.push_back(student);
		}
	}
}
void Course::displayStudentList()
{
	for (Student& st : studentList) 
	{
		std::cout << st.toString() << std::endl;
	}
}

void Course::addNewStudent(int studentID, std::string studentName) {
	Student newStudent = Student(studentID, studentName);
	studentList.push_back(newStudent);
}

void Course::addNewGroup(int groupID) {
	Group newGroup = Group(groupID);
	groupList.push_back(newGroup);

}
void Course::addStudentToAGroup(Student* student, int groupID) {
	if (student->getGroupStatus() == true) {
		std::cout << "This student was in another group, can not add";
	}
	else
	{
		Group* group = findGroupByID(groupID);
		group->addNewStudent(student);
	}

}
void Course::deleteStudentFromAGroup() {
}
void Course::addNewProject(int projectID, Time dueDate) {
	Project newProject = Project(projectID, dueDate);
	projectList.push_back(newProject);

}
void Course::submit(int groupID, int projectID, Time submitDate) {
	Project* project = findProjectbyID(projectID);
	Time dueDate = project->getDueDate();
	bool status = dueDate.isOnTime(submitDate);
	Submission submission_result = Submission(projectID, groupID, submitDate, status);
	submissionList.push_back(submission_result);
}
Student* Course::findStudentByID(int studentID) {
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].getStudentID() == studentID)
		{
			return &studentList[i];
		}
	}
	return nullptr;

}
Group* Course::findGroupByID(int ID) {
	for (int i = 0; i < groupList.size(); i++) {
		if (groupList[i].getGroupID() == ID) {
			return &groupList[i];
		}
	}
	return nullptr;
}

Project* Course::findProjectbyID(int ID) {
	for (int i = 0; i < projectList.size(); i ++) {
		if (projectList[i].getProjectID() == ID) {
			return &projectList[i];
		}
	}
	return nullptr;
}

Submission* Course::findSubmission(int projectID, int groupID) {
	for (int i = 0; i < submissionList.size(); i++) {
		if ((submissionList[i].getGroupID() == groupID) && (submissionList[i].getProjectID() == projectID)) {
			return &submissionList[i];
		}
	}
	return nullptr;
}

void Course::statSubmissionByProjectID(int projectID, Time currentTime) {
	if (findProjectbyID(projectID) == nullptr) {
		std::cout << "Can not find project id";
	}
	else {
		std::cout << "Project " << projectID << " deadline: " << findProjectbyID(projectID)->getDueDate().toString() << std::endl;
		for (int i = 0; i < groupList.size(); i++) {
			int groupID = groupList[i].getGroupID();
			Submission* submission = findSubmission(projectID, groupID);
			if (submission != nullptr) {
				std::cout << submission->submissionInforaProject() << std::endl;
			}
			else {
				if (!findProjectbyID(projectID)->getDueDate().isOnTime(currentTime)) {
					std::cout << " Group " << std::to_string(groupID) << "  Status: Not Submitted\n";
				}
				else {
					std::cout << " Group " << std::to_string(groupID) << "  Status: Not Yet Submitted\n";
				}
			}
		}
	}
}

void Course::statSubmissionByGroupID(int groupID, Time currentTime) {
	if (findGroupByID(groupID) == nullptr) {
		std::cout << "Can not find group id";
	}
	else {
		for (int i = 0; i < projectList.size(); i++) {
			int projectID = projectList[i].getProjectID();
			Submission* submission = findSubmission(projectID, groupID);
			if (submission != nullptr) {
				std::cout << submission->submissionInforaGroup() << std::endl;
			}
			else {
				if (!findProjectbyID(projectID)->getDueDate().isOnTime(currentTime)) {
					std::cout << "Project " + std::to_string(projectID) <<  "  Status: Not Submitted" << std::endl;
				}
				else
				{
					std::cout << "Project " + std::to_string(projectID) <<  "  Status: Not Yet Submitted" << std::endl;
				}
			}
		}
	}
}

void Course::statSubmissionByStatus(int projectID, bool status) {
	if (findProjectbyID(projectID) == nullptr) {
		std::cout << "Can not fine the project ID";
	}
	else {
		for (int groupID = 1; groupID <= groupList.size(); groupID++) {
			Submission* submission = findSubmission(projectID, groupID);
			if (submission != nullptr) {
				if (submission->getStatus() == 0) {
					std::cout << "Group " << groupID << " did not submitted project " << projectID << " on time.("
						<< submission->getSubmitDate().toString() << ")" << std::endl;
				}
			}
		}
	}
}

//void Course::statOverall(Time date) {
//
//	const int projectIDWidth = 12;
//	const int statusWidth = 25;
//
//	auto printHorizontalLine = [&](int totalWidth) {
//		std::cout << '+';
//		for (int i = 0; i < totalWidth; ++i) {
//			std::cout << '-';
//		}
//		std::cout << '+' << std::endl;
//		};
//
//	int totalWidth = projectIDWidth + (int(projectList.size())* statusWidth) + int(projectList.size()) + 1;
//
//	printHorizontalLine(totalWidth);
//	std::cout << '|'
//		<< std::left << std::setw(projectIDWidth+1) << "" << '|';
//
//	for (int projectID = 1; projectID <= projectList.size(); projectID++) {
//		std::cout << std::left << std::setw(statusWidth) << (" Project " + std::to_string(projectID)) << '|';
//	}
//	std::cout << std::endl;
//	printHorizontalLine(totalWidth);
//
//	for (int i = 0; i < groupList.size(); i++) {
//		int groupID = groupList[i].getGroupID();
//		std::cout << '|'
//			<< std::left << std::setw(projectIDWidth+1) << (" Group " + std::to_string(groupID)) << '|';
//
//		for (int projectID = 1; projectID <= projectList.size(); projectID++)
//		{
//			std::string status="";
//			if (projectList[projectID - 1].getDueDate().isOnTime(date) == false)
//			{
//				
//				Submission* submission = findSubmission(projectID, groupID);
//				if (submission != nullptr) {
//					status = submission->submissionInfor_overall();
//				}
//				else {
//					if (!findProjectbyID(projectID)->getDueDate().isOnTime(date)) {
//						status = "not submitted";
//					}
//					else {
//						status = "not yet submitted";
//					}
//				}
//				std::cout << std::left << std::setw(statusWidth) << status << '|';
//			}
//			else std::cout << std::left << std::setw(statusWidth) <<status <<'|';
//		}
//		std::cout << std::endl;
//		printHorizontalLine(totalWidth);
//	}
//}

void Course::statOverall(Time date) {
	Time currentTime;
	currentTime.getCurrentTime();

	const int projectIDWidth = 12;
	const int statusWidth = 25;

	auto printHorizontalLine = [&](int totalWidth) {
		std::cout << '+';
		for (int i = 0; i < totalWidth; ++i) {
			std::cout << '-';
		}
		std::cout << '+' << std::endl;
		};

	int totalWidth = projectIDWidth + (int(projectList.size()) * statusWidth) + int(projectList.size()) + 1;

	printHorizontalLine(totalWidth);
	std::cout << '|'
		<< std::left << std::setw(projectIDWidth + 1) << "" << '|';

	for (int projectID = 1; projectID <= projectList.size(); projectID++) {
		std::cout << std::left << std::setw(statusWidth) << (" Project " + std::to_string(projectID)) << '|';
	}
	std::cout << std::endl;
	std::cout << '|'
		<< std::left << std::setw(projectIDWidth + 1) << "" << '|';
	for (int projectID = 1; projectID <= projectList.size(); projectID++) {
		std::cout << std::left << std::setw(statusWidth) << (" DL " + projectList[projectID - 1].getDueDate().toString()) << '|';
	}
	std::cout << std::endl;
	printHorizontalLine(totalWidth);

	for (int i = 0; i < groupList.size(); i++) {
		int groupID = groupList[i].getGroupID();
		std::cout << '|'
			<< std::left << std::setw(projectIDWidth + 1) << (" Group " + std::to_string(groupID)) << '|';

		for (int projectID = 1; projectID <= projectList.size(); projectID++)
		{
			std::string status = "";
			if (projectList[projectID - 1].getDueDate().isOnTime(date) == false)
			{

				Submission* submission = findSubmission(projectID, groupID);
				if (submission != nullptr) {
					status = submission->submissionInfor_overall();
				}
				else {
					if (!findProjectbyID(projectID)->getDueDate().isOnTime(currentTime)) {
						status = "not submitted";
					}
					else {
						status = "not yet submitted";
					}
				}
				std::cout << std::left << std::setw(statusWidth) << status << '|';
			}
			else std::cout << std::left << std::setw(statusWidth) << status << '|';
		}
		std::cout << std::endl;
		printHorizontalLine(totalWidth);
	}
}

void Course::loadAllGroupInfor(std::string fileName)
{
	std::fstream inFile;
	inFile.open(fileName, std::ios::in | std::ios::binary);
	if (!inFile.is_open())
	{
		std::cerr << "file not found!";
		return;
	}
	size_t listSize;
	inFile.read(reinterpret_cast<char*>(&listSize), sizeof(listSize));
	groupList.resize(listSize);
	for (Group& gr : groupList) {
		gr.loadGroupInfor(inFile);
	}
	inFile.close();
}

void Course::displayGroupList()
{
	for (Group& gr : groupList) {
		gr.displayGroupInfor();
		std::cout << std::endl;
	}
}

void Course::saveAllGroupInfor(std::string fileName) {
	std::fstream outfile(fileName, std::ios::out | std::ios::binary);
	if (!outfile.is_open())
	{
		std::cout << "file not found!";
		return;
	}
	size_t listSize = groupList.size();
	outfile.write(reinterpret_cast<const char*>(&listSize), sizeof(listSize));
	for (Group& gr : groupList) {
		gr.saveGroupInfor(outfile);
	}
	std::cout << "Write succeed";
	outfile.close();
}

void Course::saveAllSubmissionInfor(std::string fileName) {

	std::fstream outfile(fileName, std::ios::out | std::ios::binary);
	if (!outfile.is_open())
	{
		std::cout << "file not found!";
		return;
	}
	size_t listSize = submissionList.size();
	outfile.write(reinterpret_cast<const char*>(&listSize), sizeof(listSize));
	for (Submission& sub : submissionList) {
		sub.saveSubmissionInfor(outfile);
	}
	outfile.close();
}

void Course::loadAllSubmissionInfor(std::string fileName) {
	std::fstream inFile;
	inFile.open(fileName, std::ios::in | std::ios::binary);
	if (!inFile.is_open())
	{
		std::cerr << "file not found!";
		return;
	}
	size_t listSize;
	inFile.read(reinterpret_cast<char*>(&listSize), sizeof(listSize));
	submissionList.resize(listSize);
	for (Submission& sub : submissionList) {
		sub.loadSubmissionInfor(inFile);
	}
	inFile.close();
}
void Course::displaySubmissionList()
{
	for (Submission& sub : submissionList) {
		std::cout << '\n' << sub.submissionInfor();
	}
}


void Course::saveAllProjectInfor(std::string fileName) {

	std::fstream outfile(fileName, std::ios::out | std::ios::binary);
	if (!outfile.is_open())
	{
		std::cout << "file not found!";
		return;
	}
	size_t listSize = projectList.size();
	outfile.write(reinterpret_cast<const char*>(&listSize), sizeof(listSize));
	for (Project& pj : projectList) {
		pj.saveProjectInfor(outfile);
	}
	outfile.close();
}
void Course::loadAllProjectInfor(std::string fileName) {
	std::fstream inFile;
	inFile.open(fileName, std::ios::in | std::ios::binary);
	if (!inFile.is_open())
	{
		std::cerr << "file not found!";
		return;
	}
	size_t listSize;
	inFile.read(reinterpret_cast<char*>(&listSize), sizeof(listSize));
	projectList.resize(listSize);
	for (Project& pj : projectList) {
		pj.loadProjectInfor(inFile);
	}
	inFile.close();
}
void Course::displayProjectList()
{
	for (Project& pj : projectList)
	{
		std::cout << '\n' << pj.ProjectInfor();
	}
}
