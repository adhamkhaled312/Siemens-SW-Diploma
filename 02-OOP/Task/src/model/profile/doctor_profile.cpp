#include <string>
#include "doctor_profile.h"

using namespace std;

    Doctor_Profile::Doctor_Profile(const string &name) : Profile(name) {}

    string Doctor_Profile::doctorgetName() const {
        return getName();
    }

    void Doctor_Profile::doctorsetName(const string& newName) {
        setName(newName);
    }
