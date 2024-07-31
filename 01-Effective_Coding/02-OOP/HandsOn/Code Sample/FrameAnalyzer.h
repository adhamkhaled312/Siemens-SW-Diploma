#pragma once

#include "EthernetFrameParser.h"
#include <vector>
#include <string>
#include <memory>

class EthernetFrame;

class FrameAnalyzer
{
public:
    explicit FrameAnalyzer() = default;
    ~FrameAnalyzer() = default;

    std::vector<std::string> AnalyzeFrames(std::vector<std::string>& p_vecFrames) const;

private:
    std::string FormatOutputForFrame(const EthernetFrame& p_pFrame, unsigned int p_iPacketNum) const;
    void InsertStars(std::string& p_strAnalyzedFrame) const;
    EthernetFrameParser m_oEthernetFrameParser;
};