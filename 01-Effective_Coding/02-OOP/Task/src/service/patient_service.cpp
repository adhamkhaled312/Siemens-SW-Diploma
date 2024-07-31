#include "patient_service.h"
#include <iostream>

// Constructor to initialize the patient
PatientService::PatientService(const Patient &patient, DBManager &dbManager) : patient(patient), dbManager(dbManager) {
}

// Function to view the medical history of the patient
void PatientService::viewMedicalHistory() {

	Medical_History history = patient.gethistory();
	std::vector<Medical_Record> records = history.getMedicalHistory();

	std::cout << "Medical History:\n";
	for (const auto &record : records) {
		std::cout << "Record ID: " << record.getId() << "\n"
		          << "Date: " << record.getDate() << "\n"
		          << "Description: " << record.getDescription() << "\n\n";
	}
}

// Function to get the medical history of the patient
Medical_History PatientService::getMedicalHistory() {

	return patient.gethistory();
}

// Function to book an appointment for the patient with a specified doctor
bool PatientService::bookAppointment(int doctorId, const Appointment &appointment) {

	std::optional<Doctor> optionalDoctor = dbManager.getDoctor(doctorId);

	if (!optionalDoctor.has_value()) {
		std::cerr << "Doctor not found!" << std::endl;
		return false;
	}

	Doctor doctor = optionalDoctor.value();
	Schedule doctorSchedule = doctor.getSchedule();
	std::vector<Appointment> appointments = doctorSchedule.getAppointment();

	for (const auto &appt : appointments) {
		if (appt.getDate() == appointment.getDate()) {
			std::cerr << "Doctor is not available at the requested time!" << std::endl;
			return false;
		}
	}

	doctorSchedule.addAppointment(appointment);

	std::cout << "Appointment booked successfully!" << std::endl;
	return true;
}
