#include "Time.h"
#include<string>
#pragma once
/**
 * @brief A class representing a project.
 */
class Project
{
private: 
	//The unique or signature identifier of the project
	int projectID;
	//Description about project
	std::string description;
	//The deadline of project, possible to replace by time_t type
	Time dueDate;
public:
	/**
	 * @brief Constructor for Project class.
	 * 
	 * @param projectID The unique identifier of the project.
	 * @param dueDate The deadline of the project.
	 */
	Project(int projectID, Time dueDate);

	/**
	 * @brief Constructor for Project class.
	 * 
	 * @param projectID The unique identifier of the project.
	 * @param description The description of the project.
	 * @param dueDate The deadline of the project.
	 */
	Project(int projectID, std::string description, Time dueDate);

	/**
	 * @brief Getter method for projectID.
	 * 
	 * @return The projectID of the project.
	 */
	int getProjectID() const;

	/**
	* @brief Setter method for projectID.
	* 
	* @param projectID The new projectID to set.
	*/
	void setProjectID(int projectID);

	/**
	 * @brief Getter method for description.
	 * 
	 * @return The description of the project.
	 */
	std::string getDescription() const;

	/**
	 * @brief Setter method for description.
	 * 
	 * @param new string description for project
	 */
	void setDescription(std::string description);

	/**
	 * @brief Getter method for dueDate.
	 * 
	 * @return The due date of the project.
	 */
	Time getDueDate() const;

	/**
	 * @brief Setter method for dueDate.
	 *
	 * @param The new due date of the project.
	 */
	void setDueDate(Time dueDate);

	/**
	 * @brief Convert the Project object to a string representation.
	 * @return A string representation of the Project object.
	 */
	std::string toString();


	
};
