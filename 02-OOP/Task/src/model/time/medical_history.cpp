#include "medical_history.h"

using namespace std;

Medical_History::Medical_History(const vector<Medical_Record> &medical_records)
    : medical_history(medical_records) {}

vector<Medical_Record> Medical_History::getMedicalHistory() const
{
    return medical_history;
}

void Medical_History::addMedicalRecord(const Medical_Record &record)
{
    medical_history.push_back(record);
}
