


# installation


For MacOS users, we have compiled the executable file, just run
```bash
cd build
./qborrow --help
```
or
```bash
cd build
make eg9-adder
```
to execute and verify examples.

If you want to build from source, please make sure that you have installed:
* CMake & Make
* antlr-4.x-complete.jar
* java
* antlr4 runtime for C++
* CVC5 
* Bitwuzla

One can either hardcode the path to includes & libraries into the CMakeLists.txt, or specify the path by arguments, e.g.
```bash
rm -rf build
mkdir build && cd build

cmake -DANTLR4_JAR_PATH=/path/to/antlr-4.13.2-complete.jar -DANTLR4_RUNTIME_PREFIX_PATH=/path/to/antlr4/runtime/cpp -DCVC5_PREFIX_PATH=/path/to/cvc5 -DBITWUZLA_PREFIX_PATH=/path/to/bitwuzla ..

make adder
```

Make sure that the following files & folders exist:
* /path/to/antlr-4.13.2-complete.jar 
* /path/to/antlr4/runtime/cpp/include/antlr4-runtime/antlr4-runtime.h
* /path/to/antlr4/runtime/cpp/lib
* /path/to/cvc5/include/cvc5/cvc5.h
* /path/to/cvc5/lib
* /path/to/bitwuzla/include/bitwuzla/cpp/bitwuzla.h
* /path/to/bitwuzla/lib

# Performance
For adder circuit:
||50 qubits| 100 qubits| 200 qubits |
|----|---|---|---|
CVC5|4s|71s|1069s|
Bitwuzla|3s|29s|313s|

For multi-controlled NOT gate:

||200 qubits| 400 qubits | 800 qubits | 1600 qubits| 3200 qubits|
|----|---|---|---|---|----|
CVC5|<1s|<1s|1s|4s|16s|
Bitwuzla|<1s|2s|10s|38s|156s|
