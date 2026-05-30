
cmake_minimum_required(VERSION 3.20)
project(CoreKit)

zephyr_library()

zephyr_include_directories(
    communication
    drivers
    error
    hal
    io
    logging
    modules
    runtime
    services
    test
    time
    platformadapters
)

add_subdirectory(communication)
add_subdirectory(drivers)
add_subdirectory(error)
add_subdirectory(hal)
add_subdirectory(io)
add_subdirectory(logging)
add_subdirectory(modules)
add_subdirectory(runtime)
add_subdirectory(services)
add_subdirectory(test)
add_subdirectory(time)
add_subdirectory(platformadapters)
