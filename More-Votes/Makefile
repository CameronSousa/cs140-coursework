#
# Makefile v1.0 for More Votes CS
#

PLATFORM 	= CentOS_7
ARCH 		= intel_amd
COMPILE_ENV 	= GCC
VERSION 	= 1

C++ = g++
CFLAGS = -g
RM = /bin/rm

###########################################

all:	voteFunc.o hw10.o
	$(C++) $(CFLAGS) -o Vote hw10.o voteFunc.o

hw10.o:	hw10.c++ voting.h
	$(C++) $(CFLAGS) -c hw10.c++
	

voteFunc.o: voteFunc.c++ voting.h
	$(C++) $(CFLAGS) -c voteFunc.c++



clean:
	$(RM) Vote
