cmake_minimum_required(VERSION 3.17)
project(SFML_TEST_FINAL)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} Main.cpp screens/MenuScreen.cpp screens/MenuScreen.h screens/Screen.h util/SpriteUtil.h gui/Button.cpp gui/Button.h)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)