all:
	g++ -Wall TimeCode.cpp TimeCodeTests.cpp -o tc

run:
	./tc
