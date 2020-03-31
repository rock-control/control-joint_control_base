rock_library(trajectory_generation
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(trajectory_generation_bin Main.cpp
    DEPS trajectory_generation)

