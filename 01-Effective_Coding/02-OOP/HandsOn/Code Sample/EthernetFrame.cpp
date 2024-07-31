#include "EthernetFrame.h"
#include <utility>

EthernetFrame::EthernetFrame(std::string& p_strFrameData)
: m_mFieldStringToValue({ })
, m_strFrameData(p_strFrameData)
{
	m_mFieldToString = 
	{
		{ EthernetFrameFields::DEST_ADDRESS, "Destination Address" },
		{ EthernetFrameFields::SOURCE_ADDRESS, "Source Address" },
		{ EthernetFrameFields::TYPE, "Type" },
		{ EthernetFrameFields::FCS, "CRC" }
	};
}

void EthernetFrame::ParseFields()
{
	m_mFieldStringToValue.insert({ m_mFieldToString.at(EthernetFrameFields::DEST_ADDRESS), m_strFrameData.substr(ETHERNET_DEST_ADDRESS_START_INDEX / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE, ETHERNET_DEST_ADDRESS_LENGTH / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE) });
	m_mFieldStringToValue.insert({ m_mFieldToString.at(EthernetFrameFields::SOURCE_ADDRESS), m_strFrameData.substr(ETHERNET_SRC_ADDRESS_START_INDEX / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE, ETHERNET_SRC_ADDRESS_LENGTH / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE) });
	m_mFieldStringToValue.insert({ m_mFieldToString.at(EthernetFrameFields::TYPE), m_strFrameData.substr(ETHERNET_TYPE_START_INDEX / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE, ETHERNET_TYPE_LENGTH / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE) });
	m_mFieldStringToValue.insert({ m_mFieldToString.at(EthernetFrameFields::FCS), m_strFrameData.substr(m_strFrameData.length() - (ETHERNET_FCS_LENGTH / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE), ETHERNET_FCS_LENGTH / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE) });
}

std::string EthernetFrame::GetFrameData() const
{
	return m_strFrameData;
}

std::map<std::string, std::string> EthernetFrame::GetFieldsValues() const
{
	return m_mFieldStringToValue;
}
