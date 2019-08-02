cmake_minimum_required (VERSION 3.0.0)
project (G4STL LANGUAGES CXX)


if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE "Release" CACHE STRING
                "Choose the type of build, options are: Debug Release
                 RelWithDebInfo MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
        set (CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR} CACHE PATH
            "Install path prefix." FORCE)
endif ()

set (CMAKE_MACOSX_RPATH 1)
set (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")


find_package (Geant4 REQUIRED)
include (${Geant4_USE_FILE})


add_library (G4STL SHARED src/G4STL.cc src/G4STL.hh)
target_include_directories (G4STL PRIVATE ${Geant4_INCLUDE_DIR})
install (TARGETS G4STL DESTINATION lib)
install (FILES src/G4STL.hh DESTINATION include)


add_executable (test-read test/read.cc)
target_link_libraries (test-read G4STL ${Geant4_LIBRARIES})
target_include_directories (test-read PRIVATE ${Geant4_INCLUDE_DIR} src)
install (TARGETS test-read DESTINATION bin)
