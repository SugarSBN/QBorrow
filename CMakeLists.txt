cmake_minimum_required(VERSION 3.10)
project(qborrow LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 存储所有需要添加到 include 路径的目录
set(PROJECT_INCLUDE_DIRS "")
# 存储所有需要添加到 library search 路径的目录 (for -L)
set(PROJECT_LINK_DIRS "/opt/homebrew/lib;/usr/local/lib")
# 存储所有需要链接的库名称 (for -l)
set(PROJECT_LINK_LIBS "")

 

## 查找 Java 可执行文件

find_program(JAVA_EXECUTABLE NAMES java
    DOC "Path to the Java executable (java)"
)

if(NOT JAVA_EXECUTABLE)
    message(FATAL_ERROR "Java executable (java) not found. ANTLR4 code generation requires Java.
    Please install Java Development Kit (JDK) or Java Runtime Environment (JRE) and ensure 'java' is in your system's PATH.")
else()
    message(STATUS "Found Java executable: ${JAVA_EXECUTABLE}")
endif()

 

## ANTLR4 配置

### 1. ANTLR4 工具 JAR 文件路径

# 定义默认 JAR 路径
set(ANTLR4_JAR_DEFAULT_PATH "/Users/subonan/local/antlr4/antlr-4.13.2-complete.jar")

# 尝试使用默认路径，如果不存在则要求用户指定
if(EXISTS "${ANTLR4_JAR_DEFAULT_PATH}")
    set(ANTLR4_JAR_PATH "${ANTLR4_JAR_DEFAULT_PATH}" CACHE FILEPATH "Path to the antlr-4.x-complete.jar file" FORCE)
    message(STATUS "Using default ANTLR4 Jar path: ${ANTLR4_JAR_PATH}")
else()
    # 如果默认路径不存在，则将 ANTLR4_JAR_PATH 设置为空，以便后续检查触发错误
    set(ANTLR4_JAR_PATH "" CACHE FILEPATH "Path to the antlr-4.x-complete.jar file" FORCE)
    message(STATUS "Default ANTLR4 Jar path does not exist: ${ANTLR4_JAR_DEFAULT_PATH}")
endif()

# 最终检查 ANTLR4_JAR_PATH 是否已设置
if(NOT ANTLR4_JAR_PATH)
    message(FATAL_ERROR "ANTLR4_JAR_PATH is not set.
    Please provide the path to your antlr-4.13.2-complete.jar file using CMake argument:
    cmake -DANTLR4_JAR_PATH=/path/to/antlr-4.13.2-complete.jar ..")
endif()

### 2. ANTLR4 C++ 运行时库路径

# 定义默认运行时**前缀路径** (应包含 include 和 lib 目录)
set(ANTLR4_RUNTIME_DEFAULT_PREFIX_PATH "/Users/subonan/local/antlr4/runtime/cpp")
set(ANTLR4_RUNTIME_INCLUDE_DEFAULT "${ANTLR4_RUNTIME_DEFAULT_PREFIX_PATH}/include/antlr4-runtime")
set(ANTLR4_RUNTIME_LIB_DEFAULT "${ANTLR4_RUNTIME_DEFAULT_PREFIX_PATH}/lib") # 存储 lib 目录路径

# **只检查默认路径下的关键头文件是否存在**
set(ANTLR4_RUNTIME_FOUND FALSE)
if(EXISTS "${ANTLR4_RUNTIME_INCLUDE_DEFAULT}/antlr4-runtime.h")
    set(ANTLR4_RUNTIME_INCLUDE_DIR "${ANTLR4_RUNTIME_INCLUDE_DEFAULT}" CACHE PATH "ANTLR4 C++ Runtime include directory" FORCE)
    set(ANTLR4_RUNTIME_LIB_DIR "${ANTLR4_RUNTIME_LIB_DEFAULT}" CACHE PATH "ANTLR4 C++ Runtime library directory" FORCE)
    set(ANTLR4_RUNTIME_FOUND TRUE)
    message(STATUS "Using default ANTLR4 C++ Runtime: ${ANTLR4_RUNTIME_DEFAULT_PREFIX_PATH} (include & lib assumed)")
else()
    # 如果默认路径下未找到，设置为空，并通过错误消息要求用户提供
    set(ANTLR4_RUNTIME_INCLUDE_DIR "" CACHE PATH "ANTLR4 C++ Runtime include directory" FORCE)
    set(ANTLR4_RUNTIME_LIB_DIR "" CACHE PATH "ANTLR4 C++ Runtime library directory" FORCE)
    message(FATAL_ERROR "ANTLR4 C++ Runtime include directory not found at default path: ${ANTLR4_RUNTIME_DEFAULT_PREFIX_PATH}/include.
    Please provide its installation prefix using CMake argument:
    cmake -DANTLR4_RUNTIME_PREFIX_PATH=/path/to/antlr4/runtime/cpp ..
    (ensure it contains an 'include' subdirectory with .. /include/antlr4-runtime/antlr4-runtime.h and a 'lib' subdirectory for libraries)")
endif()

# 将找到的头文件目录和库目录添加到全局列表
list(APPEND PROJECT_INCLUDE_DIRS "${ANTLR4_RUNTIME_INCLUDE_DIR}")
list(APPEND PROJECT_LINK_DIRS "${ANTLR4_RUNTIME_LIB_DIR}")
list(APPEND PROJECT_LINK_LIBS "antlr4-runtime") # ANTLR4 C++ Runtime 库名

 

## CVC5 配置

### 1. CVC5 库前缀路径

# 定义默认 CVC5 前缀路径 (应包含 include 和 lib 目录)
set(CVC5_DEFAULT_PREFIX_PATH "/usr/local")
set(CVC5_INCLUDE_DEFAULT "${CVC5_DEFAULT_PREFIX_PATH}/include/cvc5")
set(CVC5_LIB_DEFAULT "${CVC5_DEFAULT_PREFIX_PATH}/lib") # 存储 lib 目录路径

# **只检查默认路径下的关键头文件是否存在**
set(CVC5_FOUND FALSE)
if(EXISTS "${CVC5_INCLUDE_DEFAULT}/cvc5.h")
    set(CVC5_INCLUDE_DIRS "${CVC5_INCLUDE_DEFAULT}" CACHE PATH "CVC5 include directory" FORCE)
    set(CVC5_LIB_DIRS "${CVC5_LIB_DEFAULT}" CACHE PATH "CVC5 library directory" FORCE)
    set(CVC5_FOUND TRUE)
    message(STATUS "Using default CVC5 library: ${CVC5_DEFAULT_PREFIX_PATH} (include & lib assumed)")
else()
    # 如果默认路径下未找到，设置为空，并通过错误消息要求用户提供
    set(CVC5_INCLUDE_DIRS "" CACHE PATH "CVC5 include directory" FORCE)
    set(CVC5_LIB_DIRS "" CACHE PATH "CVC5 library directory" FORCE)
    message(FATAL_ERROR "CVC5 include directory not found at default path: ${CVC5_DEFAULT_PREFIX_PATH}/include.
    Please provide its installation prefix using CMake argument:
    cmake -DCVC5_PREFIX_PATH=/path/to/cvc5 ..
    (ensure it contains an 'include' subdirectory with .. /include/cvc5/cvc5.h and a 'lib' subdirectory for libraries)")
endif()

# 将找到的头文件目录和库目录添加到全局列表
list(APPEND PROJECT_INCLUDE_DIRS "${CVC5_INCLUDE_DIRS}")
list(APPEND PROJECT_LINK_DIRS "${CVC5_LIB_DIRS}")
list(APPEND PROJECT_LINK_LIBS "cvc5") # CVC5 库名

 

## ANTLR4 代码生成

# 指定 ANTLR4 语法文件所在的目录
set(ANTLR4_GRAMMAR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/grammar")
file(GLOB ANTLR4_GRAMMAR_FILES "${ANTLR4_GRAMMAR_DIR}/*.g4")

# 定义 ANTLR4 生成文件的输出目录
set(ANTLR4_GENERATED_HEADERS_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/include") # ***修改点：改为 /src/include***
set(ANTLR4_GENERATED_SOURCES_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")       # 源文件输出目录

# 创建输出目录
file(MAKE_DIRECTORY "${ANTLR4_GENERATED_HEADERS_OUTPUT_DIR}")
file(MAKE_DIRECTORY "${ANTLR4_GENERATED_SOURCES_OUTPUT_DIR}")


# 定义一个函数来处理 ANTLR4 语法文件生成
function(antlr4_generate GRAMMAR_FILE)
    get_filename_component(GRAMMAR_NAME "${GRAMMAR_FILE}" NAME_WE)

    # ANTLR4 工具会将所有文件生成到同一个目录下，
    # 我们先生成到一个临时目录，然后手动分离
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

        # 确保这里能正确捕获到 Lexer 和 Parser 的头文件
        file(GLOB TEMP_HEADERS "${TEMP_ANTLR4_OUTPUT_DIR}/*.h")
        # message(STATUS "DEBUG: Temp generated headers: ${TEMP_HEADERS}") # <-- 新增调试
        foreach(header_file IN LISTS TEMP_HEADERS)
            get_filename_component(HEADER_FILE_NAME "${header_file}" NAME)
            file(RENAME "${header_file}" "${ANTLR4_GENERATED_HEADERS_OUTPUT_DIR}/${HEADER_FILE_NAME}")
        endforeach()

        # 确保这里能正确捕获到 Lexer 和 Parser 的 .cpp 源文件
        file(GLOB TEMP_SOURCES "${TEMP_ANTLR4_OUTPUT_DIR}/*.cpp")
        # message(STATUS "DEBUG: Temp generated sources: ${TEMP_SOURCES}") # <-- 新增调试
        foreach(source_file IN LISTS TEMP_SOURCES)
            get_filename_component(SOURCE_FILE_NAME "${source_file}" NAME)
            file(RENAME "${source_file}" "${ANTLR4_GENERATED_SOURCES_OUTPUT_DIR}/${SOURCE_FILE_NAME}")
        endforeach()

        # 清理临时目录
        file(REMOVE_RECURSE "${TEMP_ANTLR4_OUTPUT_DIR}")
    endif()
endfunction()


foreach(GRAMMAR_FILE IN LISTS ANTLR4_GRAMMAR_FILES)
    antlr4_generate("${GRAMMAR_FILE}")
endforeach()


# 使用通配符自动查找 src 目录下的所有 .cpp 文件
file(GLOB PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# --- 再次强调，这个调试信息最重要，用来确认 glob 是否成功 ---
# message(STATUS "DEBUG: PROJECT_SOURCES (from file(GLOB) for src/*.cpp): ${PROJECT_SOURCES}")

add_compile_options(-Wall -Wextra -O2)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES} # 添加所有 .cpp 源文件，包括 main.cpp, Argument.cpp 和 ANTLR4 生成的 .cpp
)

# 添加头文件搜索路径 (对应 -I)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/          # 你的应用源文件头文件
    ${ANTLR4_GENERATED_HEADERS_OUTPUT_DIR}    # ANTLR4 生成的头文件目录 (即 /src/include)
    ${PROJECT_INCLUDE_DIRS}                   # ANTLR4 Runtime 和 CVC5 的头文件目录
)

# 添加库搜索路径 (对应 -L)
target_link_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_LINK_DIRS}                      # ANTLR4 Runtime 和 CVC5 的库目录
)

# 链接库 (对应 -l)
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${PROJECT_LINK_LIBS}                      # ANTLR4 Runtime 和 CVC5 的库名称
)