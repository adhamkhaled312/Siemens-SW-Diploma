#ifndef __ADMIN_PROFILE_H__
#define __ADMIN_PROFILE_H__

#include <string>
#include "../profile/profile.h"

class Admin_Profile : Profile
{

public:
    Admin_Profile(const std::string &name);

    std::string admingetName() const;

    void adminsetName(const std::string& newName);
};

#endif 