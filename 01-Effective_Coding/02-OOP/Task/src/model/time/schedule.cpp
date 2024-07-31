#include "schedule.h"

using namespace std;

Schedule::Schedule(const vector<Appointment> &schedule)
    : schedule(schedule) {}

vector<Appointment> Schedule::getAppointment() const
{
    return schedule;
}

void Schedule::addAppointment(const Appointment &appointment)
{
    schedule.push_back(appointment);
}
