.PHONY: clean all

CC = g++

CFLAGS = -O3 -g -std=c++11

INCLUDES =

LIBS =

LDFLAGS = -lfftw3

SRCS =

INCS = $(SRCS:.cpp=.h)

%.o: %.cpp $(INCS)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS) $(LDFLAGS) $(CFLAGS)

OBJS = $(SRCS:.cpp=.o)

TEST_FILE = test_fftw.cpp

all: test_fftw

test_fftw: $(OBJS) $(TEST_FILE)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS) $(LDFLAGS) $(CFLAGS)

clean:
	rm test_fftw
