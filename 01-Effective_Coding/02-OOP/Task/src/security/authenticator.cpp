#include <authenticator.h>

static const int PATIENT_OPTION=1;
static const int DOCTOR_OPTION=2;
static const int ADMIN_OPTION=3;

std::optional<Doctor> Authenticator::queryForDoctor(std::string email) {
	auto doctors = db_manager.getAllDoctors();
	for (const auto &doctor : doctors) {
        if (doctor.getEmail() == email) {
            return doctor;
        }
    }

	return std::nullopt;
}

std::optional<Patient> Authenticator::queryForPatient(std::string email) {
	auto patients = db_manager.getAllPatients();
    for (const auto &patient : patients) {
        if (patient.getEmail() == email) {
            return patient;
        }
    }

    return std::nullopt;
}

std::optional<Admin> Authenticator::queryForAdmin(std::string email) {
	auto admins = db_manager.getAllAdmins();
	for (const auto &admin : admins) {
		if (admin.getEmail() == email) {
			return admin;
		}
	}

	return std::nullopt;
}
bool Authenticator::checkPassword(User user, std::string password) {
	return user.getPassword() == password; // replace with actual password hashing and comparison logic
}

bool Authenticator::authenticate(User &user) {
	auto doctor = queryForDoctor(user.getEmail());

	if(doctor.has_value()) {
		return checkPassword(doctor.value(), user.getPassword());
	}

	auto patient = queryForPatient(user.getEmail());
	if(patient.has_value()) {
        return checkPassword(patient.value(), user.getPassword());
    }

	auto admin = queryForAdmin(user.getEmail());
	if(admin.has_value()) {
        return checkPassword(admin.value(), user.getPassword());
    }

    return false;
}
void Authenticator::addUser(User& user,int userType){
    switch(userType){
        case PATIENT_OPTION: db_manager.addPatient(static_cast<const Patient &>(user));break;
        case DOCTOR_OPTION: db_manager.addDoctor(static_cast<const Doctor &>(user));break;
        case ADMIN_OPTION: db_manager.addAdmin(static_cast<const Admin &>(user));break;
    }
}