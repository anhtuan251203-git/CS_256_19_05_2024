#include<iostream>
#include "Group.H"
#include "Submission.h"
#include "Project.h"
#pragma once
class Course
{
private:
	std::string courseID;

	int number_of_projects;

	int number_of_groups;

	std::vector<Group> groupList;

	std::vector<Student> studentList;

	std::vector<Project> projectList;

	std::vector<Submission> submissionList;
public:
	/**
	* @brief Constructor
	*
	* @param courseID the signature indenfier of this course
	*/
	Course(std::string courseID);

	int getNumberOfProjects() const;
	void setNumberOfProjects(int number_of_projects);
	int getNumberOfGroups() const;
	void setNumbeOfGroups(int number_of_groups);

	void getStudenList();
	void displayStudentList();

	/**
	* @brief This funtion use for adding new student into studentList
	*
	* @param studentName - the name of the student
	*/
	void addNewStudent(int studentID, std::string studentName);

	/**
	* @brief This function use for adding a new group into groupList
	* @brief - Must add at least one student into this, unless delete this group
	*
	* @param groupID The ID of the group, has to be unique
	*
	*/
	void addNewGroup(int groupID);

	/**
	* @brief This funtion use for adding a new student into a group
	* @param *student a student poiter
	* @param groupID The ID of group student will be add
	*/
	void addStudentToAGroup(Student* student, int groupID);

	/**
	* @brief This funtion use for deleting a student from a group
	* @brief Check if student is in the Group.studentList
	* @brief If has, use this function: group.deleteStudent(Student *student)
	* @brief Else the student was not in group<ID>
	*
	* @param *student a student poiter
	* @param groupID The ID of group student will be delete
	*/
	void deleteStudentFromAGroup();

	/**
	* @brief This funtion use for adding a new project into the projectList
	*
	* @param projectID The signature identifier of a project, has to be unique
	*/
	void addNewProject(int projectID, Time dueDate);

	/**
	* @brief This function is submit method, use for submitting a submisstion
	* @brief This will check the group ID, project ID and whether is was submitted ontime
	* @brief A submission object will be added in to submitionList after this method.
	* @brief Submission(int projectID, int groupID, int submitDate, bool status)
	* - status will be true if ontime (compare submitDate and project.dueDate) or false otherwise
	* @brief Use function findProjectByID (int projectID) to get the information abou project
	*
	* @param groupID The ID of group
	* @param projectID The ID of project
	* @param submitDate the submitted date
	*/
	void submit(int groupID, int projectID, Time submitDate);

	Student* findStudentByID(int studentID);
	/**
	* @brief This function use for finding a group by its ID
	*
	* @param ID The ID of group
	* @return A group poiter - reference to addess of this group. Or nullptr if not found
	*
	*/
	Group* findGroupByID(int ID);

	/**
	* @brief This function use for finding a project by its ID
	*
	* @param ID The ID of project
	* @return A project poiter - reference to addess of this group. Or nullptr if not found
	*
	*/
	Project* findProjectbyID(int ID);

	/**
	* @brief This function use for finding a submisstion of a group of a project
	*
	* @param projectID ID of project
	* @param groupID The ID of group
	* @return A submission poiter - reference to addess of this group. Or nullptr if not found
	*
	*/
	Submission* findSubmission(int projectID, int groupID);

	/**
	* @brief This function use for finding a lis of submisstion with same project
	*
	* @param projectID ID of project
	* @return kết quả nộp bài của tất cả các nhóm theo project (một danh sách các đối tượng submission)
	*
	*/
	void statSubmissionByProjectID(int projectID, Time currentTime);

	/**
	* @brief This function use for finding a lis of submisstion with same ID
	*
	* @param projectID ID of project
	* @return Kết quả nộp bài của một nhóm cho tất cả các project (một danh sách các đối tượng submission)
	*
	*/
	void statSubmissionByGroupID(int groupID, Time currentTime);

	/**
	* @brief Kiểm tra kết quả nộp bài theo trạng thái (đúng hạn hoặc muộn)
	*
	* @param status - trạng thái muốn kiểm tra, 0 là muộn, 1 là đúng hạn
	*
	* @return kết quả nộp bài của các nhóm theo trạng thái muốn kiểm tra (một danh sách các đối tượng submission)
	*
	*/
	void statSubmissionByStatus(int project, bool status);

	/**
	* @brief Kiểm tra kết quả nộp bài theo ngày
	*
	* @param dueDate - ngày muốn kiểm tra
	*
	* @return kiểm tra xem đã có bao nhiêu nhóm đã nộp bài tới ngày muốn kiểm tra (danh sách cách đối tượng submission)
	*
	*/
	void statOverall(Time date);

	void saveAllGroupInfor(std::string fileName);
	void loadAllGroupInfor(std::string fileName);

	void saveAllSubmissionInfor(std::string fileName);
	void loadAllSubmissionInfor(std::string fileName);

	void saveAllProjectInfor(std::string fileName);
	void loadAllProjectInfor(std::string fileName);

	void displayProjectList();
	void displayGroupList();
	void displaySubmissionList();
};

