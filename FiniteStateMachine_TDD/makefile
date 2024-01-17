TARGET=a.out
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS= main.o FiniteStateMachine.o
GTEST=-lgtest
GTEST_MAIN=-lgtest_main
PTHREAD=-lpthread
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(GTEST) $(GTEST_MAIN) $(PTHREAD)
 
main.o: main.cpp
	$(CC) -c $(CCFLAGS) $(GTEST) $(GTEST_MAIN) $(PTHREAD) main.cpp -o main.o

FiniteStateMachine.o: Checkout.cpp
	$(CC) -c $(CCFLAGS) $(GTEST) $(GTEST_MAIN) $(PTHREAD) FiniteStateMachine.cpp -o FiniteStateMachine.o

clean:
	@rm -f *.o