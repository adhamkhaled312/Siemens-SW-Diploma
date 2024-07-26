#ifndef __AUTH_H__
#define __AUTH_H__

#include "admin.h"
#include "db_manager.h"
#include "doctor.h"
#include "patient.h"

#include <iostream>
#include <optional>

class Authenticator {
private:
	DBManager db_manager;
	bool checkPassword(User user, std::string password);
public:
	explicit Authenticator(const DBManager &db_manager) : db_manager(db_manager) {}
    std::optional<Doctor> queryForDoctor(std::string name);
    std::optional<Patient> queryForPatient(std::string name);
    std::optional<Admin> queryForAdmin(std::string name);
    void addUser(User& user,int userType);
	bool authenticate(User& user);
};

#endif