#include "db.h"

DB::DB(std::vector<Admin> admins, std::vector<Doctor> doctors, std::vector<Patient> patients)
{
    this->admins = admins;
    this->doctors = doctors;
    this->patients = patients;
}

DB::~DB()
{
}