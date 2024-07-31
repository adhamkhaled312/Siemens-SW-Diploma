#include "patient.h"

    Patient::Patient(int id, const std::string& email, const std::string& password, const Profile& profile, const Medical_History& history )
    : User(id, email, password, profile), history(history) {}

    Medical_History Patient::gethistory() const{
        return history;
    }
    
    int Patient::patientgetID() const
    {
        return getID();
    }

    std::string Patient::patientgetEmail() const
    {
        return getEmail();
    }

    Profile Patient::patientgetProfile() const
    {
        return getProfile();
    }

    void Patient::patientsetProfile(const Profile &newprofile)
    {
        setProfile(newprofile);
    }