#pragma once

#include "ProtocolDefines.h"
#include <string>
#include <map>

class EthernetFrame
{
public:
    explicit EthernetFrame(std::string& p_strFrameData);
    virtual ~EthernetFrame() = default;

    virtual void ParseFields();
    std::string GetFrameData() const;
    std::map<std::string, std::string> GetFieldsValues() const;

protected:
    std::map<std::string, std::string> m_mFieldStringToValue;
    std::string& m_strFrameData;

private:
    std::map<EthernetFrameFields, std::string> m_mFieldToString;  //! Ethernet Specific fields
};