#ifndef __DB_H__
#define __DB_H__

#include <stdio.h>
#include <vector>

#include "../model/user/admin.h"
#include "../model/user/doctor.h"
#include "../model/user/user.h"
#include "../model/user/patient.h"

class DB
{
private:
    /* data */
    std::vector<Admin> admins;
    std::vector<Doctor> doctors;
    std::vector<Patient> patients;
    friend class DBManager;
public:
    DB(std::vector<Admin>, std::vector<Doctor>, std::vector<Patient>);
    ~DB();


};

#endif /* __DB_H__ */