# CoreKit

> **Modern C++ for Real-Time Robotics**

CoreKit is a modern C++ framework built on top of **Zephyr RTOS** that simplifies the development of embedded robotics software.

Instead of scattering hardware-specific code throughout an application, CoreKit provides clean abstractions, reusable services, and a modular architecture that allows developers to focus on robot behavior rather than platform details.

Whether you're building a small RC controller, an autonomous robot, or a complete robotic system, CoreKit aims to provide a scalable foundation that grows with your project.

---

## Why CoreKit?

Developing robotics software often leads to tightly coupled code where application logic, hardware drivers, operating system APIs, and communication protocols become intertwined.

CoreKit solves this by introducing a layered architecture that separates responsibilities while remaining lightweight and efficient enough for real-time embedded systems.

### Without CoreKit

- Zephyr APIs spread throughout the application
- Hardware drivers coupled to business logic
- Difficult unit testing
- Poor code reuse
- Platform-specific code everywhere
- Hard to scale as projects grow

### With CoreKit

- Clean C++ interfaces
- Modular services
- Testable architecture
- Dependency injection
- Hardware abstraction
- Clear separation of concerns
- Robotics-oriented design

---

# Philosophy

CoreKit is built around a few fundamental principles.

- **Modern C++**
- **Composition over inheritance**
- **Dependency Injection**
- **Explicit ownership**
- **Test-first development**
- **Real-time friendly**
- **Platform abstraction**
- **Robotics first**

The goal is not to hide Zephyr.

Instead, CoreKit provides a cleaner, more maintainable architecture on top of it.

---

# Features

Current and planned features include:

### Hardware

- GPIO
- SPI
- I²C
- UART
- ADC
- PWM
- Timers

### Communication

- NRF24L01+
- CAN *(planned)*
- BLE *(planned)*
- Wi-Fi *(planned)*
- Ethernet *(planned)*

### Core

- Logging
- Error handling
- Configuration
- Services
- Dependency Injection
- Platform abstraction
- Unit testing

### Robotics

- Motor drivers
- Encoders
- IMU support
- PID controllers
- Sensor interfaces
- Robot abstractions
- Motion control *(planned)*
- Localization *(planned)*
- Sensor fusion *(planned)*

---

# Architecture

CoreKit follows a layered architecture.

```text
+--------------------------------------+
|            Application               |
+--------------------------------------+
|               Services               |
+--------------------------------------+
|      Hardware and Communication      |
+--------------------------------------+
|        Platform Abstraction          |
+--------------------------------------+
|            Zephyr RTOS               |
+--------------------------------------+
|              Hardware                |
+--------------------------------------+
````

Each layer has a single responsibility and depends only on the layer directly below it.

This separation makes projects easier to understand, maintain, and test.
 
 ---

# Why Zephyr?

CoreKit is built on top of Zephyr because it provides:

* Wide hardware support
* Excellent RTOS capabilities
* Modern device model
* Active open-source community
* Long-term maintainability
* Professional development tools

CoreKit embraces Zephyr instead of replacing it.

---

# Documentation

The complete documentation is available in the GitHub (Wiki)[https://github.com/jmend3s/CoreKit/wiki].

Topics include:

* Getting Started
* Architecture
* Core Components
* Services
* Communication
* Robotics
* Testing
* Design Decisions
* API Reference

---

# Examples

Practical examples are maintained in the companion (CoreX)[https://github.com/jmend3s/CoreX] repository.

Examples include:

* LED Blink
* GPIO
* SPI
* UART
* I²C
* PWM
* Timers
* Logging
* NRF24 Transmitter
* NRF24 Receiver
* Motor Driver
* IMU
  
---

# Testing

Testing is a core part of the framework.

CoreKit supports:

* Host unit testing
* Continuous Integration

Every module is designed to be testable independently from the underlying hardware whenever possible.

---

# Roadmap

## Current

* GPIO
* SPI
* Logging
* Error handling
* Dependency Injection
* Testing infrastructure

## In Progress

* Communication drivers
* Service framework
* Platform abstraction improvements

## Future

* BLE
* CAN
* Robotics algorithms
* Motion control
* Localization
* Sensor fusion
* ROS 2 integration
* Additional hardware platforms

---

# Contributing

Contributions are welcome.

Whether you're fixing bugs, improving documentation, adding drivers, or proposing architectural improvements, your help is appreciated.

Please read the contribution guidelines before opening a pull request.

---

# Vision

CoreKit aims to become a modern foundation for embedded robotics software.

Rather than being just another hardware abstraction library, it strives to provide a clean, scalable architecture that supports projects ranging from simple microcontroller applications to complex robotic systems while remaining lightweight enough for real-time embedded development.
