#include "ProtocolDefines.h"
#include <memory>
#include <vector>

class EthernetFrame;

class EthernetFrameParser
{
public:
    explicit EthernetFrameParser() = default;
    ~EthernetFrameParser() = default;

    std::shared_ptr<EthernetFrame> Parse(std::string& p_strFrameData) const;

private:
    FrameType GetFrameType(std::string& p_strFrameData) const;
};