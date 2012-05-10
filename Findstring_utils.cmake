find_path(string_utils_INCLUDE_DIRS string_utils/string_utils.h /usr/include/ 
          /usr/local/include/ "$ENV{NAMER_ROOT}")

find_library(string_utils_LIBRARIES string_utils /usr/lib /usr/local/lib
             "$ENV{NAMER_ROOT}")

set(string_utils_FOUND TRUE)

if (NOT string_utils_INCLUDE_DIRS)
    set(string_utils_FOUND FALSE)
endif (NOT string_utils_INCLUDE_DIRS)

if (NOT string_utils_LIBRARIES)
    set(string_utils_FOUND FALSE)
endif (NOT string_utils_LIBRARIES)