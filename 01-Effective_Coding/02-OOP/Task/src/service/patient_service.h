#ifndef __PATIENT_SERVICE_H__
#define __PATIENT_SERVICE_H__

#include "../database/db_manager.h"
#include "../time/appointment.h"
#include "../time/medical_history.h"
#include "../user/patient.h"

class PatientService {

  private:
	Patient patient;
	DBManager &dbManager;

  public:
	// Constructor to initialize the patient
	PatientService(const Patient &patient, DBManager &dbManager);

	// Function to view the medical history of the patient
	void viewMedicalHistory();

	// Function to get the medical history of the patient
	Medical_History getMedicalHistory();

	// Function to book an appointment for the patient with a specified doctor
	bool bookAppointment(int doctorId, const Appointment &appointment);
};

#endif
