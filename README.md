# CoreKit

> **Modern C++ for real-time robotics**

CoreKit is a modern C++ robotics framework designed for embedded and real-time systems. It provides portable hardware abstractions, robotics-focused services, and a modular architecture that scales from resource-constrained microcontrollers to complex distributed robotic platforms.

The project is currently built on top of Zephyr RTOS and is architected for future portability across FreeRTOS, Linux RT, and bare-metal environments.

> **Project Status:** Early-stage development, architected for production use.

---

# Vision

Building robotics software often requires repeatedly solving the same infrastructure problems:

- Hardware abstraction
- Device communication
- Real-time scheduling
- Telemetry
- Sensor integration
- Motor control
- Platform portability

CoreKit aims to provide a unified software foundation that allows developers to focus on robotic behavior and application logic rather than low-level platform details.

The long-term goal is a consistent robotics framework that spans everything from microcontrollers to distributed robotic systems.

---

# Why CoreKit?

Modern embedded robotics development typically follows one of two paths:

### 1. Direct RTOS / HAL usage (e.g. Zephyr APIs directly)

- High control over hardware
- Low abstraction overhead
- But:
  - Tight coupling to platform APIs
  - Poor portability across RTOSes
  - Hard to unit test outside hardware
  - Business logic often mixed with hardware code

### 2. Heavy frameworks or middleware stacks

- Good abstraction and structure
- But:
  - Often too large for embedded systems
  - High dependency footprint
  - Limited determinism for real-time control
  - Difficult to tailor for constrained systems

### CoreKit’s approach

CoreKit sits between these extremes:

- Thin, explicit abstraction layers over hardware
- No hidden runtime complexity
- Zero dynamic allocation in critical paths
- Designed for deterministic execution
- Fully testable outside hardware
- Portable across RTOS and bare-metal targets

Instead of replacing Zephyr or other RTOSes, CoreKit structures and standardizes how you build systems on top of them.

It answers one question:

> How to build scalable, testable, real-time robotics software without locking ourselves into a specific platform or introducing unnecessary complexity?

---

# Design Principles

CoreKit is built around a strict set of engineering principles:

 - ### Portability
    - Application logic should not depend on the underlying operating system or hardware.
   
 - ### Testability
   - Every component must be testable on host systems without hardware dependency.

 - ### Hardware Abstraction
   - Platform-specific code is isolated behind explicit interfaces.

 - ### Zero Dynamic Allocation
   - Deterministic behavior is prioritized over convenience in real-time paths.

 - ### Minimal Dependencies
   - External dependencies are avoided to maintain portability and build simplicity.

 - ### Real-Time Safety
   - All design decisions consider timing predictability and execution determinism.

---

# Architecture

CoreKit uses a layered architecture that enforces separation of concerns:

```
Application
     ↓
 Services
     ↓
 Managers
     ↓
  Drivers
     ↓
    HAL
     ↓
   OSAL
     ↓
  Platform
```
**Layer Responsibilities**
 - Application

**Robot-specific behavior and mission logic:**
 - Services

**Reusable system-level functionality:**

 - Logging
 - Telemetry
 - Messaging
 - Sensor fusion
 - Motion control
 - Managers

**Subsystem orchestration and lifecycle management:**
 - Drivers

**Hardware-independent device drivers:**
 - HAL (Hardware Abstraction Layer)

**Unified interfaces for peripherals:**

 - GPIO
 - SPI
 - I2C
 - UART
 - PWM
 - ADC

**OSAL** (Operating System Abstraction Layer)

**RTOS-specific abstractions:** (tasks, scheduling, synchronization).
 - Platform

**Underlying OS + hardware-specific implementation:**
 - Current Modules
 - Core Infrastructure
   - Logging
   - OSAL

**Hardware Abstractions:**

 - GPIO
 - SPI
 - I2C
 - UART
 - PWM
 - ADC
   
 **Drivers:**
 - NRF24L01
 - IMU support
   
---

## Roadmap

**Communication:**
 - CAN bus
 - Messaging framework
 - Telemetry system
 - Ground control communication

**Control Systems:**
 - PID controllers
 - Sensor fusion
 - BLDC motor control
 - Field-Oriented Control (FOC)

**Platform Expansion:**
 - FreeRTOS support
 - Linux RT support
 - Bare-metal targets

---

## Supported Platforms
**Current:**

 - Zephyr RTOS

**Planned:**
 - FreeRTOS
 - Linux RT
 - Bare-metal systems

**Language & Toolchain:**
 - C++17 (primary standard)
 - C interoperability where needed
 - No dependency on STL in core framework

**Build system:**
 - CMake
 - West (Zephyr module integration)

---

## Testing Philosophy

*Testing is a core design constraint, not an afterthought.*

**CoreKit supports:**
 - Host-based unit tests
 - Target-based embedded tests
 - Mocked hardware interfaces
 - CI-ready architecture

All modules are designed to be testable without hardware dependencies.

---

## Companion Repository

CoreKit focuses on the framework itself.

**[CoreX](https://github.com/jmend3s/CoreX) provides:**
 - Usage examples
 - Integration tests
 - Reference applications
 - Real-world robotics implementations

---

## Intended Audience

**CoreKit is designed for:**

 - Robotics engineers
 - Embedded developers
 - Research and prototyping teams
 - Students learning embedded systems
 - Robotics startups and industrial applications

---

## Contributing

Contributions and architectural discussions are welcome.

Development guidelines will evolve as the project matures.