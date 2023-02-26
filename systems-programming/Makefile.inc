CC=clang
DIR=../..
INCLUDE=${DIR}/include/
VPATH=../src
CFLAGS=-g \
	-I${INCLUDE} \
	${INCLUDE}/helper.c

