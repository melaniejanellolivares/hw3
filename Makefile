CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

OBJS = llrec-test.o llrec.o
OBJSSTACK = stacktest.o
all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

llrec-test.o: llrec-test.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp
		
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp
	

stacktest: $(OBJSSTACK) stack.h 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJSSTACK)



clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 