#include <string>
#include "patient_profile.h"

using namespace std;

Patient_Profile::Patient_Profile(const string &name) : Profile(name) {}

string Patient_Profile::patientgetName() const
{
    return getName();
}

void Patient_Profile::patientsetName(const string &newName)
{
    setName(newName);
}
