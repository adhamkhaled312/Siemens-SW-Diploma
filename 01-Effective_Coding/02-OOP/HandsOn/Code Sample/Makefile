EXE_NAME = packet_analyzer

all:	exe

exe:
	g++ -std=c++11 -o $(EXE_NAME) FileHandler.cpp FrameAnalyzer.cpp EthernetFrame.cpp ECPRIFrame.cpp EthernetFrameParser.cpp main.cpp

clean:
	/bin/rm -f $(EXE_NAME)