#ifndef DOCTOR_SERVICE_H
#define DOCTOR_SERVICE_H

#include "../time/appointment.h"
#include "../time/medical_record.h"
#include "../time/schedule.h"
#include "../user/doctor.h"
#include "../user/patient.h"
#include "db_manager.h"

class doctorService {
  private:
	Doctor doctor;
	DBManager dbManager;

  public:
	doctorService(const Doctor &doctor, DBManager &dbManager);

	std::optional<Patient> viewPatient(int patientId);

	Schedule getSchedule();

	void viewSchedule();

	bool updateSchedule(const Schedule &schedule);

	bool updateMedicalRecord(const Medical_Record &record);
};

#endif // DOCTOR_SERVICE_H
