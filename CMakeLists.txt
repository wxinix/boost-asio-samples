cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 20)

project(boost-asio-samples)

if (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0601)
    set(BOOST_ROOT_DIR "C:/DevLibs/boost_1_81_0")
endif()

# Boost.Asio is header only.  Boost.Thread is required if we want to launch threads using boost::thread.
# Boost.System is required by Boost.Asio but it is header only so no build needed.
# https://www.boost.org/doc/libs/1_81_0/more/getting_started/windows.html#header-only-libraries

function(AddExecutableForEachCpp SRC_FILES)
	foreach(file_path ${SRC_FILES})
	    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" file_name ${file_path})
	    string(REPLACE ".cpp" "" exe_name ${file_name})
	    add_executable(${exe_name} ${file_path})
	    target_include_directories(${exe_name} PRIVATE ${BOOST_ROOT_DIR})
	endforeach(file_path ${SRC_FILES})
endfunction()

file(GLOB_RECURSE SRC_FILES *.cpp)
AddExecutableForEachCpp("${SRC_FILES}")