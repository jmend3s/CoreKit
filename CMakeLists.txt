
cmake_minimum_required(VERSION 3.20)
project(CoreKit)

zephyr_library()

zephyr_include_directories(
    application
    components
    core
    drivers
    services
    system
)

add_subdirectory(components)
add_subdirectory(core)
add_subdirectory(drivers)
add_subdirectory(services)
add_subdirectory(system)
