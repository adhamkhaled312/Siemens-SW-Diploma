#include "../database/db_manager.h"
#include "../user/patient.h"
#include "../user/admin.h"
#include "../user/doctor.h"
#include "../security/authenticator.h"

class AdminService{
private:
    Admin admin;
	DBManager dbManager;

public:
    AdminService(const Admin& admin, DBManager& dbmanager);

    void addDoctor(Doctor doctor);

    bool removeDoctor(int doctor_id);

    void viewDoctor(int doctor_id);

    Doctor getDoctor(int doctor_id);

    bool removePatient(int patient_id);

    void viewPatient(int patient_id);

    Patient getPatient(int patient_id);
    
};