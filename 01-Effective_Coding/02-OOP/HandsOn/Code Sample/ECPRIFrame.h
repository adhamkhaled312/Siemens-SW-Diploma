#pragma once

#include "EthernetFrame.h"
#include "ProtocolDefines.h"
#include <map>
#include <string>

class ECPRIFrame : public EthernetFrame
{
public:
    explicit ECPRIFrame(std::string& p_strFrameData);
    ~ECPRIFrame() = default;

    void ParseFields() override;

private:
    std::map<ECPRIFrameFields, std::string> m_mFieldToString;  //! eCPRI Specific fields
};