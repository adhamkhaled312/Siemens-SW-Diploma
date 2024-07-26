#ifndef __PATIENT_PROFILE_H__
#define __PATIENT_PROFILE_H__
#include <string>
#include "../profile/profile.h"


class Patient_Profile : Profile
{

public:
    Patient_Profile(const std::string &name);

    std::string patientgetName() const;

    void patientsetName(const std::string& newName);
};

#endif 