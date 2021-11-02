compiler = g++
main_file = main.cpp
sources = parameter.cpp args.cpp
headers = xargs/*.hpp
object = main
std = gnu++17
parameters = -k -test 1 2 -l 2 -s -file text.txt 100

all: compile run

compile: ${main_file} ${sources} ${headers}
	${compiler} ${main_file} ${sources} -o ${object} -std=${std}

run: ${object}
	./${object} ${parameters}