
cmake_minimum_required(VERSION 3.20)

zephyr_library()

zephyr_include_directories(
    application
    components
    core
    drivers
    services
)

add_subdirectory(application)
add_subdirectory(components)
add_subdirectory(core)
add_subdirectory(drivers)
add_subdirectory(services)
