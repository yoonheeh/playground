cmake_minimum_required(VERSION 3.13)

project(LTO_Definitive_Test CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Shared_library: helper_lib
add_library(helper_lib SHARED helper.cpp)
target_compile_options(helper_lib PRIVATE -O2)
# On Linux/macOS, it's good practice to enable Position Independent Code
set_target_properties(helper_lib PROPERTIES POSITION_INDEPENDENT_CODE ON)


# Executable: without_lto_so
# Executable without LTO and linked against shared libarry
add_executable(without_lto_so main.cpp)
target_compile_options(without_lto_so PRIVATE -O2)
target_link_libraries(without_lto_so PRIVATE helper_lib)

# Executable: with_lto
add_executable(with_lto main.cpp helper.cpp)
target_compile_options(with_lto PRIVATE -O2)
set_target_properties(with_lto PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)

message(STATUS "\nBuild complete. Run the definitive benchmark:")
message(STATUS "  hyperfine './without_lto_so' './with_lto'")
