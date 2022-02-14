TARGET := hw1

SRC := $(shell find src/ -name '*.cpp')
OBJ := $(patsubst %.cpp,%.o,$(patsubst src/%,build/%,$(SRC)))

CPP := clang++
LD := clang

CPP_FLAGS := -c -D_USE_MATH_DEFINES -std=c++20 -g -O0
LD_FLAGS := -lstdc++ -lm

.PHONY: clean

all: build

$(OBJ): build/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CPP) -o $@ $< $(CPP_FLAGS)

build: $(OBJ)
	$(LD) -o $(TARGET) $(OBJ) $(LD_FLAGS)

clean:
	rm -rf build/ $(TARGET)

run: build
	./$(TARGET)