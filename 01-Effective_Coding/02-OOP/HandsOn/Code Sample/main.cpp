#include "FileHandler.h"
#include "FrameAnalyzer.h"
#include <vector>
#include <iostream>

#define INPUT_FILE_NAME		"input_packets"
#define OUTPUT_FILE_NAME	"output_packets"

int main()
{
	FileHandler oFileHandler;
	std::string strInputFileName(INPUT_FILE_NAME);
	std::string strOutputFileName(OUTPUT_FILE_NAME);

	//! Read packets
	std::vector<std::string> vecPackets = oFileHandler.ReadFileIntoPackets(strInputFileName);

	//! Analyze packets
	FrameAnalyzer oFrameAnalyzer;
	std::vector<std::string> vecAnalyzedPackets = oFrameAnalyzer.AnalyzeFrames(vecPackets);

	//! Write analyzed packets
	oFileHandler.WritePacketsIntoFile(strOutputFileName, vecAnalyzedPackets);

	return 0;
}