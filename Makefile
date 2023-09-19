# Makefile for GPA calculator

CC = gcc
CXX = g++

CFLAGS = -Wall -std=c++11

SRCS = exread.cpp AuditDataset.cpp Course.cpp
OBJS = $(SRCS:.cpp=.o)

all: gpa

gpa: $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

test: gpa
	./gpa sample.txt

clean:
	rm -f $(OBJS) gpa

doc:
	doxygen

default: all

