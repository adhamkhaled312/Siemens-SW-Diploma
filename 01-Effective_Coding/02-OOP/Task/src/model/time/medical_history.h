#ifndef __MEDICAL_HISTORY_H__
#define __MEDICAL_HISTORY_H__

#include "medical_record.h"
#include <vector>



class Medical_History
{
private:
    std::vector<Medical_Record> medical_history;

public:
    Medical_History(const std::vector<Medical_Record> &medical_records);

    std::vector<Medical_Record> getMedicalHistory() const;

    void addMedicalRecord(const Medical_Record &record);
};

#endif 