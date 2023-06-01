cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

# bring in a testing framework
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.3.2
)
FetchContent_MakeAvailable(Catch2)

# bring in SFML (a graphics library)
FetchContent_Declare(SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

# name of our project, can access via ${PROJECT_NAME}
project(MyProject)

# every file goes in this list
set(FILES
  src/game_object.cpp
  src/game_object.h
  src/main.cpp
  src/player.h
  src/vector_test.cpp
  src/vector.h
  src/world.cpp
  src/world.h
)

set(SRC ${FILES})
list(FILTER SRC EXCLUDE REGEX "_test\.cpp$")
add_executable(${PROJECT_NAME} ${SRC})

# link up the SFML library with our main executable

target_link_libraries(${PROJECT_NAME} sfml-graphics)

# bundle assets (see the copy-assets.cmake file if you want to change the "assets" directory name)

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_LIST_DIR}/copy-assets.cmake
)
add_dependencies(${PROJECT_NAME} copy_assets)

# copy over any DLLs on Windows

if (WIN32 AND BUILD_SHARED_LIBS)
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS ${PROJECT_NAME})

# create tests executable

set(SRC_TESTS ${FILES})
list(REMOVE_ITEM SRC_TESTS src/main.cpp)
add_executable(tests ${SRC_TESTS})

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain sfml-graphics)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests)
