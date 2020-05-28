.PHONY: clean all

CC = g++

CFLAGS = -O3 -g -std=c++11

INCLUDES =

LIBS =

LDFLAGS = -lxml2

SRCS =

INCS = $(SRCS:.cpp=.h)

%.o: %.cpp $(INCS)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS) $(LDFLAGS) $(CFLAGS)

OBJS = $(SRCS:.cpp=.o)

TEST_FILE = test_xml2.cpp

all: test_xml2

test_xml2: $(OBJS) $(TEST_FILE)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS) $(LDFLAGS) $(CFLAGS)

clean:
	rm test_xml2
