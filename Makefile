default: all
all: build
.PHONY: modules cmake

init: modules

modules:
	git submodule update --init --depth 1 --recommend-shallow --single-branch

cmake:
	mkdir -p build/
	cmake -S . -B build

build: cmake
	make -C build

clean: 
	make -C build clean

program: build
	./tools/program.sh
