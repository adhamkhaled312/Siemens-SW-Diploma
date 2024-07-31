#include "doctor.h"

Doctor::Doctor(
    int id, const std::string &email, const std::string &password, const Profile &profile, Schedule &schedule)
    : User(id, email, password, profile), schedule(schedule) {
}

Schedule Doctor::getSchedule() {
	return schedule;
}
void Doctor::setSchedule(const Schedule &schedule) {
	this->schedule = schedule;
}

int Doctor::doctorgetID() const {
	return getID();
}

std::string Doctor::doctorgetEmail() const {
	return getEmail();
}

Profile Doctor::doctorgetProfile() const {
	return getProfile();
}

void Doctor::doctorsetProfile(const Profile &newprofile) {
	setProfile(newprofile);
}
