CC = g++
CPPFLAGS = -std=c++20
SRC_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(patsubst src/%.cpp,compiled/%.o,$(SRC_FILES))

all: $(OBJ_FILES)

compiled/%.o : src/%.cpp
	@echo "Compiling $<"
	$(CC) $(CPPFLAGS) $< -o $@
	@echo "OK"

.PHONY: clean
clean:
	@echo "Cleaning compiled files"
	rm -rf compiled/*
