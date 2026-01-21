
cmake_minimum_required(VERSION 3.20)
project(CoreKit)

zephyr_library()

zephyr_include_directories(
    application
    components
    core
    drivers
    hal
    scheduler
    services
    system
    tests
)

add_subdirectory(components)
add_subdirectory(core)
add_subdirectory(drivers)
add_subdirectory(hal)
add_subdirectory(scheduler)
add_subdirectory(services)
add_subdirectory(system)
add_subdirectory(tests)
