#ifndef __APPOINTMENT_H__
#define __APPOINTMENT_H__

#include <optional>
#include <ctime>
#include <sstream>
#include <iomanip>

class Appointment
{
private:
    int id;
    std::optional<int> patient_id;
    std::optional<int> doctor_id;
    std::tm date;

public:
    Appointment(int id, const std::optional<int> &patient, const std::optional<int> &doctor, const std::tm &date);

    int getId() const;

    std::string getDate() const;

    void setDate(std::tm &new_date);
};

#endif 