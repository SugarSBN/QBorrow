cmake_minimum_required(VERSION 3.10)
project(qborrow LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# (for -I)
set(PROJECT_INCLUDE_DIRS "")
# (for -L)
set(PROJECT_LINK_DIRS "/opt/homebrew/lib;/usr/local/lib")
#  (for -l)
set(PROJECT_LINK_LIBS "")

#========================================================================================
# Modify according to the installation path.                                            #
                                                                                        #
set(ANTLR4_JAR_DEFAULT_PATH "/Users/subonan/local/antlr4/antlr-4.13.2-complete.jar")    #
set(ANTLR4_RUNTIME_DEFAULT_PREFIX_PATH "/Users/subonan/local/antlr4/runtime/cpp")       #
set(BITWUZLA_DEFAULT_PREFIX_PATH "/Users/subonan/local/bitwuzla")                       #
set(CVC5_DEFAULT_PREFIX_PATH "/usr/local")                                              #
                                                                                        #
#=======================================================================================
 

## check java configuration

find_program(JAVA_EXECUTABLE NAMES java
    DOC "Path to the Java executable (java)"
)

if(NOT JAVA_EXECUTABLE)
    message(FATAL_ERROR "Java executable (java) not found. ANTLR4 code generation requires Java.
    Please install Java Development Kit (JDK) or Java Runtime Environment (JRE) and ensure 'java' is in your system's PATH.")
else()
    message(STATUS "Found Java executable: ${JAVA_EXECUTABLE}")
endif()

 

## check antlr4 jar file and runtime

### antlr4 jar file path

# by default

# otherwise, specified by user
if(EXISTS "${ANTLR4_JAR_DEFAULT_PATH}")
    set(ANTLR4_JAR_PATH "${ANTLR4_JAR_DEFAULT_PATH}" CACHE FILEPATH "Path to the antlr-4.x-complete.jar file" FORCE)
    message(STATUS "Using default ANTLR4 Jar path: ${ANTLR4_JAR_PATH}")
else()
    set(ANTLR4_JAR_PATH "" CACHE FILEPATH "Path to the antlr-4.x-complete.jar file" FORCE)
    message(STATUS "Default ANTLR4 Jar path does not exist: ${ANTLR4_JAR_DEFAULT_PATH}")
endif()

if(NOT ANTLR4_JAR_PATH)
    message(FATAL_ERROR "ANTLR4_JAR_PATH is not set.
    Please provide the path to your antlr-4.13.2-complete.jar file using CMake argument:
    cmake -DANTLR4_JAR_PATH=/path/to/antlr-4.13.2-complete.jar ..")
endif()

### 2. ANTLR4 Runtime C++

# by default, contain include and lib directories
set(ANTLR4_RUNTIME_INCLUDE_DEFAULT "${ANTLR4_RUNTIME_DEFAULT_PREFIX_PATH}/include/antlr4-runtime")
set(ANTLR4_RUNTIME_LIB_DEFAULT "${ANTLR4_RUNTIME_DEFAULT_PREFIX_PATH}/lib") 


set(ANTLR4_RUNTIME_FOUND FALSE)
if(EXISTS "${ANTLR4_RUNTIME_INCLUDE_DEFAULT}/antlr4-runtime.h")
    set(ANTLR4_RUNTIME_INCLUDE_DIR "${ANTLR4_RUNTIME_INCLUDE_DEFAULT}" CACHE PATH "ANTLR4 C++ Runtime include directory" FORCE)
    set(ANTLR4_RUNTIME_LIB_DIR "${ANTLR4_RUNTIME_LIB_DEFAULT}" CACHE PATH "ANTLR4 C++ Runtime library directory" FORCE)
    set(ANTLR4_RUNTIME_FOUND TRUE)
    message(STATUS "Using default ANTLR4 C++ Runtime: ${ANTLR4_RUNTIME_DEFAULT_PREFIX_PATH} (include & lib assumed)")
else()
    set(ANTLR4_RUNTIME_INCLUDE_DIR "" CACHE PATH "ANTLR4 C++ Runtime include directory" FORCE)
    set(ANTLR4_RUNTIME_LIB_DIR "" CACHE PATH "ANTLR4 C++ Runtime library directory" FORCE)
    message(FATAL_ERROR "ANTLR4 C++ Runtime include directory not found at default path: ${ANTLR4_RUNTIME_DEFAULT_PREFIX_PATH}/include.
    Please provide its installation prefix using CMake argument:
    cmake -DANTLR4_RUNTIME_PREFIX_PATH=/path/to/antlr4/runtime/cpp ..
    (ensure it contains an 'include' subdirectory with .. /include/antlr4-runtime/antlr4-runtime.h and a 'lib' subdirectory for libraries)")
endif()

list(APPEND PROJECT_INCLUDE_DIRS "${ANTLR4_RUNTIME_INCLUDE_DIR}")
list(APPEND PROJECT_LINK_DIRS "${ANTLR4_RUNTIME_LIB_DIR}")
list(APPEND PROJECT_LINK_LIBS "antlr4-runtime") 

 

# CVC5 

set(CVC5_INCLUDE_DEFAULT "${CVC5_DEFAULT_PREFIX_PATH}/include/")
set(CVC5_LIB_DEFAULT "${CVC5_DEFAULT_PREFIX_PATH}/lib") 

set(CVC5_FOUND FALSE)
if(EXISTS "${CVC5_INCLUDE_DEFAULT}/cvc5/cvc5.h")
    set(CVC5_INCLUDE_DIRS "${CVC5_INCLUDE_DEFAULT}" CACHE PATH "CVC5 include directory" FORCE)
    set(CVC5_LIB_DIRS "${CVC5_LIB_DEFAULT}" CACHE PATH "CVC5 library directory" FORCE)
    set(CVC5_FOUND TRUE)
    message(STATUS "Using default CVC5 library: ${CVC5_DEFAULT_PREFIX_PATH} (include & lib assumed)")
else()
    set(CVC5_INCLUDE_DIRS "" CACHE PATH "CVC5 include directory" FORCE)
    set(CVC5_LIB_DIRS "" CACHE PATH "CVC5 library directory" FORCE)
    message(FATAL_ERROR "CVC5 include directory not found at default path: ${CVC5_DEFAULT_PREFIX_PATH}/include.
    Please provide its installation prefix using CMake argument:
    cmake -DCVC5_PREFIX_PATH=/path/to/cvc5 ..
    (ensure it contains an 'include' subdirectory with .. /include/cvc5/cvc5.h and a 'lib' subdirectory for libraries)")
endif()


list(APPEND PROJECT_INCLUDE_DIRS "${CVC5_INCLUDE_DIRS}")
list(APPEND PROJECT_LINK_DIRS "${CVC5_LIB_DIRS}")
list(APPEND PROJECT_LINK_LIBS "cvc5") 


# Bitwuzla

set(BITWUZLA_INCLUDE_DEFAULT "${BITWUZLA_DEFAULT_PREFIX_PATH}/include/")
set(BITWUZLA_LIB_DEFAULT "${BITWUZLA_DEFAULT_PREFIX_PATH}/lib") 
set(BITWUZLA_FOUND FALSE)

if(EXISTS "${BITWUZLA_INCLUDE_DEFAULT}/bitwuzla/cpp/bitwuzla.h")
    set(BITWUZLA_INCLUDE_DIRS "${BITWUZLA_INCLUDE_DEFAULT}" CACHE PATH "Bitwulza include directory" FORCE)
    set(BITWUZLA_LIB_DIRS "${BITWUZLA_LIB_DEFAULT}" CACHE PATH "Bitwulza library directory" FORCE)
    set(BITWUZLA_FOUND TRUE)
    message(STATUS "Using default Bitwuzla library: ${BITWUZLA_DEFAULT_PREFIX_PATH} (include & lib assumed)")
else()
    set(BITWUZLA_INCLUDE_DIRS "" CACHE PATH "Bitwulza include directory" FORCE)
    set(BITWUZLA_LIB_DIRS "" CACHE PATH "Bitwuzla library directory" FORCE)
    message(FATAL_ERROR "Bitwulza include directory not found at default path: ${BITWUZLA_DEFAULT_PREFIX_PATH}/include.
    Please provide its installation prefix using CMake argument:
    cmake -DBITWUZLA_PREFIX_PATH=/path/to/bitwuzla ..
    (ensure it contains an 'include' subdirectory with /path/to/bitwuzla/include/bitwuzla/cpp/bitwuzla.h and a 'lib' subdirectory for libraries)")
endif()


list(APPEND PROJECT_INCLUDE_DIRS "${BITWUZLA_INCLUDE_DIRS}")
list(APPEND PROJECT_LINK_DIRS "${BITWUZLA_LIB_DIRS}")
list(APPEND PROJECT_LINK_LIBS "bitwuzla") 
list(APPEND PROJECT_LINK_LIBS "bitwuzlabb") 
list(APPEND PROJECT_LINK_LIBS "bitwuzlabv") 
list(APPEND PROJECT_LINK_LIBS "bitwuzlals") 

 

## ANTLR4 generation

set(ANTLR4_GRAMMAR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/grammar")
file(GLOB ANTLR4_GRAMMAR_FILES "${ANTLR4_GRAMMAR_DIR}/*.g4")

set(ANTLR4_GENERATED_HEADERS_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/frontend/antlr-gen") 
set(ANTLR4_GENERATED_SOURCES_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/frontend/antlr-gen")     

file(MAKE_DIRECTORY "${ANTLR4_GENERATED_HEADERS_OUTPUT_DIR}")
file(MAKE_DIRECTORY "${ANTLR4_GENERATED_SOURCES_OUTPUT_DIR}")

function(antlr4_generate GRAMMAR_FILE)
    get_filename_component(GRAMMAR_NAME "${GRAMMAR_FILE}" NAME_WE)


    set(TEMP_ANTLR4_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/temp_antlr4_gen/${GRAMMAR_NAME}")
    file(MAKE_DIRECTORY "${TEMP_ANTLR4_OUTPUT_DIR}")

    message(STATUS "Generating ANTLR4 files for ${GRAMMAR_FILE} to temporary directory: ${TEMP_ANTLR4_OUTPUT_DIR}")

    execute_process(
        COMMAND "${JAVA_EXECUTABLE}" -jar "${ANTLR4_JAR_PATH}" -Dlanguage=Cpp -visitor -o "${TEMP_ANTLR4_OUTPUT_DIR}" "${GRAMMAR_FILE}"
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        RESULT_VARIABLE ANTLR4_GEN_RESULT
        OUTPUT_VARIABLE ANTLR4_GEN_OUTPUT
        ERROR_VARIABLE ANTLR4_GEN_ERROR
    )

    if (NOT ANTLR4_GEN_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to generate ANTLR4 files for ${GRAMMAR_FILE}:\n${ANTLR4_GEN_ERROR}\n${ANTLR4_GEN_OUTPUT}")
    else()
        message(STATUS "ANTLR4 generation successful for ${GRAMMAR_FILE}. Moving files...")

        file(GLOB TEMP_HEADERS "${TEMP_ANTLR4_OUTPUT_DIR}/*.h")

        foreach(header_file IN LISTS TEMP_HEADERS)
            get_filename_component(HEADER_FILE_NAME "${header_file}" NAME)
            file(RENAME "${header_file}" "${ANTLR4_GENERATED_HEADERS_OUTPUT_DIR}/${HEADER_FILE_NAME}")
        endforeach()

        file(GLOB TEMP_SOURCES "${TEMP_ANTLR4_OUTPUT_DIR}/*.cpp")

        foreach(source_file IN LISTS TEMP_SOURCES)
            get_filename_component(SOURCE_FILE_NAME "${source_file}" NAME)
            file(RENAME "${source_file}" "${ANTLR4_GENERATED_SOURCES_OUTPUT_DIR}/${SOURCE_FILE_NAME}")
        endforeach()

        file(REMOVE_RECURSE "${TEMP_ANTLR4_OUTPUT_DIR}")
    endif()
endfunction()


foreach(GRAMMAR_FILE IN LISTS ANTLR4_GRAMMAR_FILES)
    antlr4_generate("${GRAMMAR_FILE}")
endforeach()



add_compile_options(-Wall -Wextra -O2)

add_executable(${PROJECT_NAME}
    src/main.cpp

    src/frontend/Argument.cpp
    src/frontend/Parser.cpp
    src/frontend/Preprocessor.cpp
    src/frontend/Program.cpp
    src/frontend/Printable.cpp

    src/frontend/AST/AST_Expr.cpp
    src/frontend/AST/AST_Stmt.cpp
    src/frontend/AST/AST_Register.cpp

    src/frontend/antlr-gen/QBorrowBaseListener.cpp
    src/frontend/antlr-gen/QBorrowBaseVisitor.cpp
    src/frontend/antlr-gen/QBorrowLexer.cpp
    src/frontend/antlr-gen/QBorrowListener.cpp
    src/frontend/antlr-gen/QBorrowParser.cpp
    src/frontend/antlr-gen/QBorrowVisitor.cpp

    src/backend/Verifier_CVC5.cpp
    src/backend/Verifier_Bitwuzla.cpp
)

# ( -I)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/frontend
    ${CMAKE_CURRENT_SOURCE_DIR}/include/frontend/AST
    ${CMAKE_CURRENT_SOURCE_DIR}/include/backend

    ${ANTLR4_GENERATED_HEADERS_OUTPUT_DIR}   
    ${PROJECT_INCLUDE_DIRS}                   
)

# ( -L)
target_link_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_LINK_DIRS}                     
)

# ( -l)
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${PROJECT_LINK_LIBS}            
    "gmp"
)



# Examples
function(add_example_target example_name)
    set(TARGET_NAME "${example_name}")
    set(EXAMPLE_FILE "${CMAKE_SOURCE_DIR}/examples/${example_name}.qbr")

    if (EXISTS "${EXAMPLE_FILE}")
        add_custom_target(
            ${TARGET_NAME}
            COMMAND env DYLD_LIBRARY_PATH="/opt/homebrew/lib" $<TARGET_FILE:${PROJECT_NAME}> ${EXAMPLE_FILE} $(ARGS)
            DEPENDS ${PROJECT_NAME} 
            COMMENT "Running ${PROJECT_NAME} with example ${example_name}.qbr"
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        )
    else()
        message(WARNING "Example file ${EXAMPLE_FILE} does not exist for target ${TARGET_NAME}.")
    endif()
endfunction()

add_example_target(adder)
add_example_target(mcx)