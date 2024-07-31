#ifndef __ADMIN_H__
#define __ADMIN_H__
#include "../user/user.h"

class Admin : public User {
public:
	Admin(int id, const std::string &email, const std::string &password, const Profile &profile);

	int admingetID() const;

	std::string admingetEmail() const;

	Profile admingetProfile() const;

	void adminsetProfile(const Profile &newprofile);
};

#endif 