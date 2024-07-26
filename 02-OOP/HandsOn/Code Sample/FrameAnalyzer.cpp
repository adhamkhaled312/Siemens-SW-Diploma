#include "FrameAnalyzer.h"
#include "EthernetFrame.h"
#include <map>

std::vector<std::string> FrameAnalyzer::AnalyzeFrames(std::vector<std::string>& p_vecFrames) const
{
    std::vector<std::string> vecAnalyzedFrames = { };

    for (unsigned int uiPacketIndex = 0; uiPacketIndex < p_vecFrames.size(); ++uiPacketIndex)
	{
		//! Parse the string into its packet type
		std::shared_ptr<EthernetFrame> pFrame = std::move(m_oEthernetFrameParser.Parse(p_vecFrames.at(uiPacketIndex)));

		//! Write the data into output file
        vecAnalyzedFrames.push_back(FormatOutputForFrame(*pFrame.get(), uiPacketIndex));
	}

    return vecAnalyzedFrames;
}

std::string FrameAnalyzer::FormatOutputForFrame(const EthernetFrame& p_pFrame, unsigned int p_iPacketNum) const
{
    //! 1- Packet number
    std::string strOutput = "Packet # " + std::to_string(p_iPacketNum) + ":\n";

    //! 2- Packet Data
    strOutput += p_pFrame.GetFrameData() + "\n";

    //! 3- Fields
    std::map<std::string, std::string> mFields = p_pFrame.GetFieldsValues();
    for (auto const& pairField : mFields)
        strOutput += pairField.first + ": " + pairField.second + "\n";

    //! 4- Final formatting
    InsertStars(strOutput);

    return strOutput;
}

void FrameAnalyzer::InsertStars(std::string& p_strAnalyzedFrame) const
{
    p_strAnalyzedFrame += "\n";
    for (unsigned int uiIndex = 0; uiIndex < 230; ++uiIndex)
        p_strAnalyzedFrame += "*";
    p_strAnalyzedFrame += "\n";
}