#include "medical_record.h"

using namespace std;

Medical_Record::Medical_Record(int id, const tm &date, const string &description)
    : id(id), date(date), description(description) {}

int Medical_Record::getId() const
{
    return id;
};

string Medical_Record::getDescription() const
{
    return description;
};

string Medical_Record::getDate() const
{
    stringstream ss;
    ss << put_time(&date, "%Y-%m-%d %H:%M:%S");
    return ss.str();
};