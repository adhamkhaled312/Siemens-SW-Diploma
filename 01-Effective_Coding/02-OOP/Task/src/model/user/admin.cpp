#include "admin.h"

using namespace std;

   
    Admin::Admin(int id, const string &email, const string &password, const Profile &profile)
    : User(id, email, password, profile) {}

    int Admin::admingetID() const
    {
        return getID();
    }

    std::string Admin::admingetEmail() const
    {
        return getEmail();
    }

    Profile Admin::admingetProfile() const
    {
        return getProfile();
    }

    void Admin::adminsetProfile(const Profile &newprofile)
    {
        setProfile(newprofile);
    }

