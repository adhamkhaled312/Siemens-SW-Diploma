#include "ECPRIFrame.h"
#include <utility>

ECPRIFrame::ECPRIFrame(std::string& p_strFrameData)
: EthernetFrame(p_strFrameData)
{
	m_mFieldToString = 
	{
		{ ECPRIFrameFields::PRTOTOCOL_VERSION, "Protocol Version" },
		{ ECPRIFrameFields::RESERVED_AND_C, "Concatenation Indicator" },
		{ ECPRIFrameFields::MESSAGE_TYPE, "Message Type" },
		{ ECPRIFrameFields::PAYLOAD_SIZE, "Payload Size" },
		{ ECPRIFrameFields::RTC_ID, "RTC ID" },
		{ ECPRIFrameFields::SEQ_ID, "Sequence ID" }
	};
}

void ECPRIFrame::ParseFields()
{
	m_mFieldStringToValue.insert({ m_mFieldToString.at(ECPRIFrameFields::PRTOTOCOL_VERSION), m_strFrameData.substr(ECPRI_PRTOTOCOL_VERSION_START_INDEX / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE, ECPRI_PRTOTOCOL_VERSION_LENGTH / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE) });
	m_mFieldStringToValue.insert({ m_mFieldToString.at(ECPRIFrameFields::RESERVED_AND_C), m_strFrameData.substr(ECPRI_RESERVED_AND_C_START_INDEX / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE, ECPRI_RESERVED_AND_C_LENGTH / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE) });
	m_mFieldStringToValue.insert({ m_mFieldToString.at(ECPRIFrameFields::MESSAGE_TYPE), m_strFrameData.substr(ECPRI_MESSAGE_TYPE_START_INDEX / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE, ECPRI_MESSAGE_TYPE_LENGTH / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE) });
	m_mFieldStringToValue.insert({ m_mFieldToString.at(ECPRIFrameFields::PAYLOAD_SIZE), m_strFrameData.substr(ECPRI_PAYLOAD_SIZE_START_INDEX / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE, ECPRI_PAYLOAD_SIZE_LENGTH / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE) });
	m_mFieldStringToValue.insert({ m_mFieldToString.at(ECPRIFrameFields::RTC_ID), m_strFrameData.substr(ECPRI_RTC_ID_START_INDEX / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE, ECPRI_RTC_ID_LENGTH / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE) });
	m_mFieldStringToValue.insert({ m_mFieldToString.at(ECPRIFrameFields::SEQ_ID), m_strFrameData.substr(ECPRI_SEQ_ID_START_INDEX / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE, ECPRI_SEQ_ID_LENGTH / NUM_OF_BITS_IN_A_BYTE * NUM_OF_HEX_CHARS_IN_A_BYTE) });

	//! Call the parent function as well
	EthernetFrame::ParseFields();
}