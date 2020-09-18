# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CXXFLAGS  = -pthread -Wall -Werror -pedantic -std=c++11 -g

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp)

SRCS_H := $(wildcard *.h)

# the build target executable:
TARGET = main

all: $(TARGET)

$(TARGET): $(SRCS) $(SRCS_H)
	$(CC) $(CXXFLAGS) $(SRCS) -o $(TARGET)

val: all
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main

clean:
	$(RM) $(TARGET)
