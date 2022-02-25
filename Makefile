all:
	
	g++ -Wall TimeCode.cpp PaintDryTimer.cpp -o pdt
	g++ -Wall TimeCode.cpp NASALaunchAnalysis.cpp -o nasa
	g++ -Wall TimeCode.cpp TimeCodeTests.cpp -o time-code


run:
	./tc
