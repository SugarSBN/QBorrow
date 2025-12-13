


# installation


For MacOS users, we have compiled the executable file, just run
```bash
cd build
./qborrow --help
```
or
```bash
cd build
make adder
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


cmake ..

or 

cmake -DANTLR4_JAR_PATH=/path/to/antlr-4.13.2-complete.jar -DANTLR4_RUNTIME_PREFIX_PATH=/path/to/antlr4/runtime/cpp -DCVC5_PREFIX_PATH=/path/to/cvc5 -DBITWUZLA_PREFIX_PATH=/path/to/bitwuzla ..


make mcx
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

For multi-controlled NOT gate:

||501 qubits| 1001 qubits | 1501 qubits | 2001 qubits| 2501 qubits| 3001 qubits | 3501 qubits|
|----|---|---|---|---|----|---|---|---|
CVC5|<1s |1s| 3s|6s|10s|14s|19s|
Bitwuzla|3s|15s|32s|67s|102s|146s|189s|


For adder circuit:
||99 qubits| 149 qubits| 199 qubits | 249 qubits | 299 qubits | 349 qubits | 399 qubits |
|----|---|---|---|---|---|---|
CVC5|5s | 23s|73s|170s|357s|660s|1079s|
Bitwuzla|3s|12s|29s|99s|155s|230s|303s|

