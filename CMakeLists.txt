## Project Setup
cmake_minimum_required(VERSION 2.4.6)

project(string_utils)

## Configurations

# Use clang if available
IF(EXISTS /usr/bin/clang++)
  set(CMAKE_CXX_COMPILER /usr/bin/clang++)
ENDIF(EXISTS /usr/bin/clang++)


# Allow for building shared libs override
IF(NOT BUILD_SHARED_LIBS)
    set(BUILD_SHARED_LIBS OFF)
ENDIF(NOT BUILD_SHARED_LIBS)

# Allow for build type override
IF(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RELWITHDEBINFO")
ENDIF(NOT CMAKE_BUILD_TYPE)

# set the default path for built executables to the "bin" directory
IF(NOT EXECUTABLE_OUTPUT_PATH)
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
ENDIF(NOT EXECUTABLE_OUTPUT_PATH)
# set the default path for built libraries to the "lib" directory
IF(NOT LIBRARY_OUTPUT_PATH)
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
ENDIF(NOT LIBRARY_OUTPUT_PATH)

# Add the include folder to the include path
include_directories(${PROJECT_SOURCE_DIR}/include)


# Compile the libmdc2250 Library
add_library(string_utils src/string_utils.cpp)


# Configure make install
IF(NOT CMAKE_INSTALL_PREFIX)
    SET(CMAKE_INSTALL_PREFIX /usr/local)
ENDIF(NOT CMAKE_INSTALL_PREFIX)

INSTALL(TARGETS string_utils
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

INSTALL(FILES include/string_utils/string_utils.h 
        DESTINATION include/string_utils)

IF(NOT CMAKE_FIND_INSTALL_PATH)
    set(CMAKE_FIND_INSTALL_PATH ${CMAKE_ROOT})
ENDIF(NOT CMAKE_FIND_INSTALL_PATH)

# INSTALL(FILES Findstring_utils.cmake DESTINATION ${CMAKE_FIND_INSTALL_PATH}/Modules/)

ADD_CUSTOM_TARGET(uninstall @echo uninstall package)

IF (UNIX)
  ADD_CUSTOM_COMMAND(
    COMMENT "uninstall package"
    COMMAND xargs ARGS rm < install_manifest.txt
    
    TARGET  uninstall
  )
ELSE(UNIX)
  ADD_CUSTOM_COMMAND(
    COMMENT "uninstall only implemented in unix"
    TARGET  uninstall
  )
ENDIF(UNIX)
