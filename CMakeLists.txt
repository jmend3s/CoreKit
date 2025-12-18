
cmake_minimum_required(VERSION 3.20)

set(GCC_ARM_BASE "/opt/gcc-arm-none-eabi-10.3-2021.10")
set(STDCPP_INCLUDE_DIR
    "${GCC_ARM_BASE}/arm-none-eabi/include/c++/10.3.1"
)
set(STDCPP_TARGET_INCLUDE_DIR
    "${GCC_ARM_BASE}/arm-none-eabi/include/c++/10.3.1/arm-none-eabi"
)
include_directories(
    ${STDCPP_INCLUDE_DIR}
    ${STDCPP_TARGET_INCLUDE_DIR}
)

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
