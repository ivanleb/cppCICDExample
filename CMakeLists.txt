cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_executable(helloworld_cli main.cpp)

add_library(helloworld lib.cpp)

add_executable(test_version test_version.cpp)

set_target_properties(helloworld_cli helloworld test_version PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED ON
      COMPILE_OPTIONS "-Wpendantic; -Wall; -Wextra"
)

target_link_libraries( test_version
      ${Boost_LIBRARIES}
      helloworld
)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT ivan_leb@mail.ru)

include(CPack)

enable_testing()

add_test(helloworld_tests test_version)
