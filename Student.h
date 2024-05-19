#include<string>
#pragma once
class Student
{
private:
	//The Unique or signature identifier of a student
	int studentID;
	std::string studentName;
	//represent that a student has joined a group or not
	bool groupStatus;
	//ID of the student's group, or -1 if not in a group
	int groupID;
public:
	Student();
	/**
	 * @brief Constructor for the Student class.
	 *
	 * @param studentName The name of the student.
	 */
	Student(int studentID, std::string studentName);

	int getStudentID() const;

	void setStudentID(int studentID);
	/**
	 * @brief Getter method for name.
	 *
	 * @return The student's name.
	 */
	std::string getStudentName() const;

	/**
	 * @brief Setter method for name.
	 *
	 * @param studentName The new name of the student.
	 */
	void setStudentName(std::string studentName);

	/**
	 * @brief Getter method for groupStatus, whether the student belongs to a group (true) or not (false).
	 *
	 * @return True if the student is in a group, false otherwise.
	 */
	bool getGroupStatus() const;

	/**
	 * @brief Setter method for groupStatus, whether the student belongs to a group (true) or not (false).
	 *
	 * @param groupStatus The group membership status.
	 */
	void setGroupStatus(bool groupStatus);

	/**
     * Sets the ID of the group the student belongs to (if applicable).
     *
     * @param groupID The ID of the student's group.
     */
	void setGroupID(int groupID);

	/**
     * @brief Gets the ID of the group the student belongs to (if applicable).
     *
     * @return The ID of the student's group, or -1 if not in a group.
     */
	int getGroupID() const;

	/**
     * @brief Creates a string representation of the student object.
     *
     * @return A string containing the student's name and group information.
     */
	std::string toString();

};

