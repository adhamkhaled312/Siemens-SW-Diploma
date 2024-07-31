#ifndef __DOCTOR_PROFILE_H__
#define __DOCTOR_PROFILE_H__

#include <string>
#include "../profile/profile.h"

class Doctor_Profile : Profile
{

public:
    Doctor_Profile(const std::string &name);
    std::string doctorgetName() const;

    void doctorsetName(const std::string& newName);
};

#endif 