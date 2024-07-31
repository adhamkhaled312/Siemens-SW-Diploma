#ifndef __PATIENT_H__
#define __PATIENT_H__

#include "../time/medical_history.h"
#include "../user/user.h"

class Patient : public User {
private:
	Medical_History history;

public:
	Patient(int id, const std::string &email, const std::string &password, const Profile &profile,
	    const Medical_History &history);

	Medical_History gethistory() const;

	int patientgetID() const;

	std::string patientgetEmail() const;

	Profile patientgetProfile() const;

	void patientsetProfile(const Profile &newprofile);
};

#endif 