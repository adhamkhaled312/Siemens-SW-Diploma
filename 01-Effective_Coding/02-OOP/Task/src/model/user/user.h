#ifndef __USER_H__
#define __USER_H__
#include "../profile/profile.h"
#include <string>

class User {
private:
	int id;
	std::string email;
	std::string password;
	Profile profile;

public:
	User(int id, const std::string &email, const std::string &password, const Profile &profile);

	int getID() const;

	std::string getEmail() const;

	Profile getProfile() const;

	void setProfile(const Profile &newprofile);
	std::string getPassword();

    void setEmail(const std::string &email);

    void setPassword(const std::string &password);
};

#endif 