<br>

# RISC-V Bare Metal Assembly for ESP32-C3, and ESP32-C6

<br>

# Table of Contents
[Requirements](#requirements)  
[Build](#build-instructions)   
<br>

# Requirements

1. RISC-V Cross Compiler
2. Make
3. esptool

<br>

# Install Cross Compiler

**Linux**   
><br>apt install gcc-riscv64-unknown-elf  
<br>

<br>

**macOS**  
><br>brew tap riscv-software-src/riscv  
brew install riscv-tools  
<br>

<br>

**Windows, macOS, Linux**  
><br>The xPack GNU RISC-V Embedded GCC  
A standalone cross-platform (Windows, macOS, GNU/Linux) binary distribution of GNU RISC-V Embedded GCC.  <br>
https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack  
<br>

<br>

# Install Make

**Linux**  
><br>apt install make   
<br>

**macOS**
><br>brew install make  
<br>

**Windows**  
><br>[https://github.com/xpack-dev-tools/windows-build-tools-xpack/](https://github.com/xpack-dev-tools/windows-build-tools-xpack/)  
<br>

<br>

# Install Python
>Note: Optional as there are binary releases of esptool available below.

**Linux**  
><br>Python is usually installed by default.  
Open a terminal and type: `python`  
<br>
apt install python  
<br>

<br>

**Linux, macOS, Windows**  
><br>[https://www.python.org/downloads/](https://www.python.org/downloads/)  
<br>

<br>

# Install esptool

**Linux, macOS, Windows**  
><br>Binary Release<br>[https://github.com/espressif/esptool/releases](https://github.com/espressif/esptool/releases)  
<br>Python Version  
[https://docs.espressif.com/projects/esptool/en/latest/esp32/installation.html](https://docs.espressif.com/projects/esptool/en/latest/esp32/installation.html)  
pip install esptool  
<br>

<br>

# Build Instructions

```
Configure build environment variables

Linux / macOS:
export BMV_CC=riscv64-unknown-elf-gcc
export BMV_ESPTOOL=esptool
export BMV_CHIP=esp32c3
export BMV_PORT=/dev/ttyACM0

Windows:
set BMV_CC=riscv-none-elf-gcc
set BMV_ESPTOOL=esptool
set BMV_CHIP=esp32c3
set BMV_PORT=COM3

Note: BMV_CC, BMV_ESPTOOL must specify the full path if they are not in your PATH.
Binary:
export BMV_ESPTOOL=/opt/riscv/esptool/esptool
Python:
export BMV_ESPTOOL="python /opt/riscv/esptool/esptool.py"
```

```
Open a command prompt, and change to the root directory of this project.

build:
make -C examples/blink/

flash:
make -C examples/blink/ flash

help:
make -C examples/blink help
```

<br>

# Usage

> Environment Variables

| variable                | default                 | valid values                                            |
| ----------------------- | ----------------------- | ------------------------------------------------------- |
| BMV_CC                  | riscv64-unknown-elf-gcc | riscv64-unknown-elf-gcc, riscv-none-elf-gcc, clang, ... |
| BMV_ESPTOOL             | esptool                 | esptool, "python esptool.py"                            |
| BMV_CHIP                | esp32c3                 | esp32c3, esp32c6                                        |
| BMV_PORT                | /dev/ttyACM0            | /dev/ttyUSB0, /dev/ttyACM0, ..., COM1, COM2, ...        |

>Environment Override

`make -C examples/blink clean flash BMV_CC=clang BMV_ESPTOOL=/opt/riscv/esptool/esptool BMV_CHIP=esp32c3 BMV_PORT=/dev/ttyACM0`

>Show available make commands

`make -C examples/blink help`  
