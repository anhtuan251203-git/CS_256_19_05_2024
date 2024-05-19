#include "Time.h"
#include<vector>
#pragma once
/**
 * @brief This class represents the submission status (result) of a project for a group.
 */
class Submission
{
private:
    //The ID of project 
    int projectID; 
    //The ID of group
    int groupID;
    //The submission status indicating whether it's on time (true) or late (false)
    bool status;
    //The submit date.
    Time submitDate;
public:
    /**
     * @brief Constructor for Submission class.
     * @param projectID The ID of project .
     * @param groupID The ID of group
     * @param submitDate The date that project was submited
     * @param status The submission status indicating whether it's on time (true) or late (false).
     */
    Submission(int projectID, int groupID, Time submitDate, bool status);

    Submission();
    /**
     * @brief Getter method for projectID.
     * @return The projectID of the submission.
     */
    int getProjectID() const;

    /**
     * @brief Setter method for projectID.
     * @param projectID The new projectID to set.
     */
    void setProjectID(int projectID);

    /**
     * @brief Getter method for gruopID.
     *
     * @return The ID of the group.
     */
    int getGroupID() const;

    /**
    * @brief Setter method for groupID.
    *
    * @param groupID The new groupID to set.
    */
    void setGroupID(int groupID);

    /**
     * @brief Getter method for status.
     * @return True if the submission was on time, false otherwise.
     */
    bool getStatus() const;

    /**
     * @brief Setter method for status.
     * @param status The new status to set.
     */
    void setStatus(bool status);

    /**
     * @brief Getter method for submitDate.
     * @return The date when the project was submitted.
     */
    Time getSubmitDate() const;

    /**
     * @brief Setter method for submitDate.
     * @param The date when the project was submitted.
     */
    void setSubmitDate(Time submitDate);

    std::string submissionInfor();
    std::string submissionInforaProject();
    std::string submissionInforaGroup();
    std::string submissionInfor_overall();

    void saveSubmissionInfor(std::fstream&);

    /**
     * @brief Load the group information from a file.
     */
    void loadSubmissionInfor(std::fstream&);

};