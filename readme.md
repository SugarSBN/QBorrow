


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

One can either hardcode the path to includes & libraries into the CMakeLists.txt, or specify the path by arguments, e.g.
```bash
rm -rf build
mkdir build && cd build

cmake -DANTLR4_JAR_PATH=/path/to/antlr-4.13.2-complete.jar -DANTLR4_RUNTIME_PREFIX_PATH=/path/to/antlr4/runtime/cpp -DCVC5_PREFIX_PATH=/path/to/cvc5 ..

make eg9-adder
```

Make sure that the following files & folders exists:
* /path/to/antlr-4.13.2-complete.jar 
* /path/to/antlr4/runtime/cpp/include/antlr4-runtime/antlr4-runtime.h
* /path/to/antlr4/runtime/cpp/lib
* /path/to/cvc5/include/cvc5/cvc5.h
* /path/to/cvc5/lib
