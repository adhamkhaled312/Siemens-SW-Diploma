#include "doctor_service.h"
#include <iostream>

// Constructor to initialize the doctor service with a doctor and DB manager
doctorService::doctorService(const Doctor &doctor, DBManager &dbManager) : doctor(doctor), dbManager(dbManager) {
}

// Function to view a patient's information
std::optional<Patient> doctorService::viewPatient(int patientId) {
	return dbManager.getPatient(patientId);
}

// Function to get the doctor's schedule
Schedule doctorService::getSchedule() {
	return doctor.getSchedule();
}

// Function to print the doctor's schedule
void doctorService::viewSchedule() {
	Schedule schedule = getSchedule();
	std::vector<Appointment> appointments = schedule.getAppointment();

	std::cout << "Doctor's Schedule:\n";
	for (const auto &appointment : appointments) {
		std::cout << "Appointment ID: " << appointment.getId() << "\n"
		          << "Date: " << appointment.getDate() << "\n"
		          << "\n\n";
	}
}

// Function to update the doctor's schedule
bool doctorService::updateSchedule(const Schedule &newSchedule) {

	if (dbManager.updateDoctorSchedule(doctor.getID(), newSchedule)) {
		std::cout << "Schedule updated successfully!" << std::endl;
		return true;
	} else {
		std::cerr << "Failed to update schedule!" << std::endl;
		return false;
	}
}

// Function to update a patient's medical record
bool doctorService::updateMedicalRecord(const Medical_Record &record) {
	auto optionalRecord = dbManager.getMedicalRecord(record.getId());

	if (optionalRecord.has_value()) {
		std::cerr << "Record not found!" << std::endl;
		return false;
	}

	// Update the medical record in the database
	if (dbManager.updateMedicalRecord(record.getId(), record)) {
		std::cout << "Medical record updated successfully!" << std::endl;
		return true;
	} else {
		std::cerr << "Failed to update medical record!" << std::endl;
		return false;
	}
}
