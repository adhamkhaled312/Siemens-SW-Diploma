#include "profile.h"

using namespace std;


    Profile::Profile(const string& name) : name(name) {}

    string Profile::getName() const {
        return name;
    }

    void Profile::setName(const string& newName) {
        name = newName;
    }
