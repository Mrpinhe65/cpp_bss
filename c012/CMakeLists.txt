cmake_minimum_required(VERSION 3.10)
project(c012_operator)

# 设置C标准
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 包含目录
include_directories(include)

# 查找所有源文件
file(GLOB SOURCES "src/*.cpp")

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 设置输出目录
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# 调试信息
target_compile_options(${PROJECT_NAME} PRIVATE -g)
