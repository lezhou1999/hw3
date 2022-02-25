all:
	
	g++ -Wall TimeCode.cpp PaintDryTimer.cpp -o pdt
	g++ -Wall TimeCode.cpp NASAcdLaunchAnalysis.cpp -o nasa
	g++ -Wall TimeCode.cpp TimeCodeTests.cpp -o time-code


run:
	./tc
