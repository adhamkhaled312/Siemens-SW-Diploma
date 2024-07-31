#include "db_manager.h"

DBManager::DBManager(DB db) : db(db) {
}

DBManager::~DBManager() {
}

void DBManager::addDoctor(const Doctor &doctor) {
	db.doctors.push_back(doctor);
}

bool DBManager::removeDoctor(int id) {
	for (int i = 0; i < db.doctors.size(); i++) {
		if (db.doctors[i].getID() == id) {
			db.doctors.erase(db.doctors.begin() + i);
			return true;
		}
	}
	return false;
}

std::optional<Doctor> DBManager::getDoctor(int id) {
	std::optional<Doctor> result;
	for (int i = 0; i < db.doctors.size(); i++) {
		if (db.doctors[i].getID() == id) {
			return db.doctors[i];
		}
	}
	return std::nullopt;
}

void DBManager::addPatient(const Patient &patient) {
	db.patients.push_back(patient);
}

bool DBManager::removePatient(int id) {
	for (int i = 0; i < db.patients.size(); i++) {
		if (db.patients[i].getID() == id) {
			db.patients.erase(db.patients.begin() + i);
			return true;
		}
	}
	return false;
}

std::optional<Patient> DBManager::getPatient(int id) {
	std::optional<Patient> result;
	for (int i = 0; i < db.patients.size(); i++) {
		if (db.patients[i].getID() == id) {
			return db.patients[i];
		}
	}
	return std::nullopt;
}

void DBManager::addAdmin(const Admin &admin) {
	db.admins.push_back(admin);
}

bool DBManager::removeAdmin(int id) {
	for (int i = 0; i < db.admins.size(); i++) {
		if (db.admins[i].getID() == id) {
			db.admins.erase(db.admins.begin() + i);
			return true;
		}
	}
	return false;
}

std::optional<Admin> DBManager::getAdmin(int id) {
	std::optional<Admin> result;
	for (int i = 0; i < db.admins.size(); i++) {
		if (db.admins[i].getID() == id) {
			return db.admins[i];
		}
	}
	return std::nullopt;
}
std::vector<Doctor> DBManager::getAllDoctors() {
	return db.doctors;
}
std::vector<Patient> DBManager::getAllPatients() {
	return db.patients;
}
std::vector<Admin> DBManager::getAllAdmins() {
	return db.admins;
}
bool DBManager::updateDoctorSchedule(int get_id, const Schedule &schedule) {
	for (auto &doctor : db.doctors) {
		if (doctor.getID() == get_id) {
			doctor.setSchedule(schedule);
			return true;
		}
	}
	return false;
}
std::optional<Medical_Record> DBManager::getMedicalRecord(int get_id) {
	auto patients = getAllPatients();
	for (auto &patient : patients) {
		auto history = patient.gethistory().getMedicalHistory();
		for (auto &record : history) {
			if (record.getId() == get_id) {
				return record;
			}
		}
	}

	return std::nullopt;
}

bool DBManager::updateMedicalRecord(int get_id, const Medical_Record &record) {
	auto patients = getAllPatients();
    for (auto &patient : patients) {
        auto history = patient.gethistory().getMedicalHistory();
        for (auto &rec : history) {
            if (rec.getId() == get_id) {
                rec = record;
                return true;
            }
        }
    }
    return false;
}
