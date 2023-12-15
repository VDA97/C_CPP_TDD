TARGET=a.out
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS= main.o Checkout.o
GTEST=-lgtest
GTEST_MAIN=-lgtest_main
PTHREAD=-lpthread
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(GTEST) $(GTEST_MAIN) $(PTHREAD)
 
main.o: main.cpp
	$(CC) -c $(CCFLAGS) $(GTEST) $(GTEST_MAIN) $(PTHREAD) main.cpp -o main.o

Checkout.o: Checkout.cpp
	$(CC) -c $(CCFLAGS) $(GTEST) $(GTEST_MAIN) $(PTHREAD) Checkout.cpp -o Checkout.o

clean:
	@rm -f *.o