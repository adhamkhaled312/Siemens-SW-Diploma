#include "appointment.h"

using namespace std;

Appointment::Appointment(int id, const optional<int> &patient, const optional<int> &doctor, const tm &date)
    : id(id), patient_id(patient), doctor_id(doctor), date(date) {}

int Appointment::getId() const
{
    return id;
}

string Appointment::getDate() const
{
    stringstream ss;
    ss << put_time(&date, "%Y-%m-%d %H:%M:%S");
    return ss.str();
};

void Appointment::setDate(tm &new_date)
{
    date = new_date;
}
