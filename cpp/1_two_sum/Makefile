.PHONY: clean all

CC = g++

CFLAGS = -O3 -g -std=c++11

INCLUDES =

LIBS =

LDFLAGS =

SRCS =

INCS = $(SRCS:.cpp=.h)

%.o: %.cpp $(INCS)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS) $(LDFLAGS) $(CFLAGS)

OBJS = $(SRCS:.cpp=.o)

TEST_FILE = two_sum_1.cpp

all: two_sum

two_sum: $(OBJS) $(TEST_FILE)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS) $(LDFLAGS) $(CFLAGS)

clean:
	rm two_sum
