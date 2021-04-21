# Copyright CSCI 5801 Spring 2021 Team 20

# Default target
all: voting-system

.PHONY: voting-system
voting-system:
	# Make the build directory if it doesn't already exist
	mkdir -p build
	# Generate the necessary build files in the build directory with
	# optimizations enabled
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
	# Compile the configuration in build using the number of processors
	# the system has
	# 
	# By default this translates to `make -j$(nproc)` in the build directory
	cmake --build build --parallel $(nproc)

.PHONY: debug
debug:
	# Make the build directory if it doesn't already exist
	mkdir -p build
	# Generate the necessary build files in the build directory with
	# debugging symbols
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
	# Compile the configuration in build using the number of processors
	# the system has
	# 
	# By default this translates to `make -j$(nproc)` in the build directory
	cmake --build build --parallel $(nproc)

.PHONY: clean
clean:
	# Remove the build configuration and files
	rm -rf build