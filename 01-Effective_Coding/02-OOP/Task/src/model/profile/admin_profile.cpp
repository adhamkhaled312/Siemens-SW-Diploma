#include <string>
#include "admin_profile.h"

using namespace std;


    Admin_Profile::Admin_Profile(const string &name) : Profile(name) {}

    string Admin_Profile::admingetName() const {
        return getName();
    }

    void Admin_Profile::adminsetName(const string& newName) {
        setName(newName);
    }
