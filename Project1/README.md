
## Building ##

### Background ###
This project uses CMake as the primary build system. As the requirements 
state that a Makefile must be provided, a wrapper Makefile sets up and
runs the necessary `cmake` command chain.

### Directions ###

#### Release Build ####
From the `Project1` directory, simply run `make`. This will build the `voting-system` executable and place it into the `build` directory.

#### Development Build ####
It is highly recommended that one takes a look at the `Makefile` commands under the **debug** target. This sequence of commands sets up an out of source build and makes cleaning the project very easy if something breaks (just remove the build directory).

* Make an out of source build location
  - `mkdir build`
* Generate the CMake configuration
  - `cd build`
  - `cmake .. -DCMAKE_BUILD_TYPE=Debug`
* Build the executable
  - `make -j$(nproc)`
