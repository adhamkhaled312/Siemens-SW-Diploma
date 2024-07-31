#ifndef __PROFILE_H__
#define __PROFILE_H__
#include <string>

class Profile {
private:
    std::string name;
public:
    Profile(const std::string& name);

    std::string getName() const;
    
    void setName(const std::string& newName);

};

#endif 