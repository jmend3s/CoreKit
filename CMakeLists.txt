
cmake_minimum_required(VERSION 3.20)
project(CoreKit)

zephyr_library()

zephyr_include_directories(
    drivers
    hal
    io
    runtime
    services
    test
    time
    zephyradapters
)

add_subdirectory(drivers)
add_subdirectory(hal)
add_subdirectory(io)
add_subdirectory(runtime)
add_subdirectory(services)
add_subdirectory(test)
add_subdirectory(time)
add_subdirectory(zephyradapters)
