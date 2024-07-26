#include "EthernetFrameParser.h"
#include "EthernetFrame.h"
#include "ECPRIFrame.h"

std::shared_ptr<EthernetFrame> EthernetFrameParser::Parse(std::string& p_strFrameData) const
{
	//! Extract the frame type
	FrameType eFrameType = GetFrameType(p_strFrameData);
	auto pFrame = [&]() -> std::shared_ptr<EthernetFrame>
	{
		switch (eFrameType)
		{
			case FrameType::RAW_ETHERNET:
				return std::make_shared<EthernetFrame>(p_strFrameData);
			case FrameType::ECPRI_CONTROL:
				return std::make_shared<ECPRIFrame>(p_strFrameData);
			default:
				return nullptr;
		}
	}();

	//! Parse the fields
	if (pFrame)
		pFrame->ParseFields();
	return pFrame;
}

FrameType EthernetFrameParser::GetFrameType(std::string& p_strFrameData) const
{
	std::string strType = std::move(p_strFrameData.substr(ETHERNET_TYPE_START_INDEX / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE, ETHERNET_TYPE_LENGTH / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE));
	return (TYPE_ECPRI == strType) ? FrameType::ECPRI_CONTROL : FrameType::RAW_ETHERNET;
}