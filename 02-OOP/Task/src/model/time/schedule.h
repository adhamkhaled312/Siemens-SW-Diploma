#ifndef __SCHEDULE_H__
#define __SCHEDULE_H__
#include "appointment.h"
#include <vector>

class Schedule {
  private:
	std::vector<Appointment> schedule;

  public:
	Schedule(const std::vector<Appointment> &schedule);

	std::vector<Appointment> getAppointment() const;

	void addAppointment(const Appointment &appointment);
};

#endif 