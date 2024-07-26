#include "admin_service.h"
#include <iostream>

AdminService::AdminService(const Admin& admin, DBManager& dbmanager)
    : admin(admin), dbManager(dbmanager){}

void AdminService::addDoctor(Doctor doctor){
    dbManager.addDoctor(doctor);   
}

bool AdminService::removeDoctor(int doctor_id){
    return dbManager.removeDoctor(doctor_id);
}

void AdminService::viewDoctor(int doctor_id){
    Doctor doctor=getDoctor(doctor_id); 

    std::cout << "Doctor ID: " << doctor.getID()<<"\n"
        << "Email: "<<doctor.getEmail() <<"\n"
        << "Name: "<<doctor.getProfile().getName()<<std::endl;
}

Doctor AdminService::getDoctor(int doctor_id){
    std::optional<Doctor> optional_Doctor= dbManager.getDoctor(doctor_id);
    if (!optional_Doctor.has_value()) {
		throw std::invalid_argument("Doctor not found!");
	}
    Doctor doctor=optional_Doctor.value(); 
    return doctor;
 }

bool AdminService::removePatient(int patient_id){
    return dbManager.removePatient(patient_id);
 }

void AdminService::viewPatient(int patient_id){
    Patient patient = getPatient(patient_id);

    std::cout << "Patient ID: " << patient.getID()<<"\n"
        << "Email: "<<patient.getEmail() <<"\n"
        << "Name: "<<patient.getProfile().getName()<<std::endl;
  }

Patient AdminService::getPatient(int patient_id){
    std::optional<Patient> optional_Patient= dbManager.getPatient(patient_id);

    if (!optional_Patient.has_value()) {
		throw std::invalid_argument("Patient not found!");
	}

    Patient patient = optional_Patient.value();
    return patient;
}