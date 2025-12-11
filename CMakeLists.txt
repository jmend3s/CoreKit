
cmake_minimum_required(VERSION 3.20)

zephyr_library()

zephyr_include_directories(
    application
    components
    core
    drivers
    services
)

zephyr_library_sources(
    application/Application.cpp
    components/Timer.cpp
    core/Component.cpp
    core/Registry.cpp
    drivers/Gpio.cpp
    drivers/Pwm.cpp
    services/TimerService.cpp
)

#target_sources(${ZEPHYR_CURRENT_LIB_LITERAL}
#    PRIVATE
#        application/Application.cpp
#        components/Timer.cpp
#        core/Component.cpp
#        core/Registry.cpp
#        drivers/Gpio.cpp
#        drivers/Pwm.cpp
#        services/TimerService.cpp
#)
#
#target_include_directories(${ZEPHYR_CURRENT_LIB_LITERAL}
#    PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}
#        ${CMAKE_CURRENT_SOURCE_DIR}/application
#        ${CMAKE_CURRENT_SOURCE_DIR}/components
#        ${CMAKE_CURRENT_SOURCE_DIR}/core
#        ${CMAKE_CURRENT_SOURCE_DIR}/drivers
#        ${CMAKE_CURRENT_SOURCE_DIR}/services
#)

#add_library(CoreKit STATIC)
#target_link_libraries(CoreKit PUBLIC zephyr_interface)

#target_include_directories(CoreKit PUBLIC
#    ${CMAKE_CURRENT_SOURCE_DIR}
#    ${CMAKE_CURRENT_SOURCE_DIR}/application
#    ${CMAKE_CURRENT_SOURCE_DIR}/components
#    ${CMAKE_CURRENT_SOURCE_DIR}/core
#    ${CMAKE_CURRENT_SOURCE_DIR}/drivers
#    ${CMAKE_CURRENT_SOURCE_DIR}/services
#)

#add_subdirectory(application)
#add_subdirectory(components)
#add_subdirectory(core)
#add_subdirectory(drivers)
#add_subdirectory(services)
