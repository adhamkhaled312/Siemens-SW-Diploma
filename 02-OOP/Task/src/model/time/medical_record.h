#ifndef __MEDICAL_RECORD_H__
#define __MEDICAL_RECORD_H__

#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>


class Medical_Record{
private:
    int id;
    std::tm date;
    std::string description;

public:
    Medical_Record(int id, const std::tm& date, const std::string& description);

    int getId() const;

    std::string getDescription() const;

    std::string getDate() const ;


};

#endif 