# Install script for directory: /root/zephyrproject/zephyr

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/root/zephyr-sdk-0.16.0/riscv64-zephyr-elf/bin/riscv64-zephyr-elf-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/zephyr/arch/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/zephyr/lib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/zephyr/soc/riscv/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/zephyr/boards/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/zephyr/subsys/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/zephyr/drivers/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/canopennode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/chre/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/cmsis/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/fatfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/altera/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/atmel/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/hal_espressif/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/hal_ethos_u/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/hal_gigadevice/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/hal_infineon/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/microchip/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/hal_nordic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/nuvoton/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/hal_nxp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/openisa/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/quicklogic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/hal_renesas/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/hal_rpi_pico/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/silabs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/st/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/stm32/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/hal_telink/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/ti/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/hal_wurthelektronik/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/xtensa/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/libmetal/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/liblc3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/littlefs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/loramac-node/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/lvgl/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/lz4/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/mbedtls/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/mcuboot/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/mipi-sys-t/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/nanopb/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/nrf_hw_models/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/open-amp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/openthread/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/picolibc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/segger/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/sof/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/tflite-micro/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/tinycrypt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/TraceRecorder/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/trusted-firmware-m/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/trusted-firmware-a/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/uoscore-uedhoc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/zcbor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/zscilib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/modules/thrift/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/zephyr/kernel/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/zephyr/cmake/flash/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/zephyr/cmake/usage/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/nimunozb/Documentos/embebidos/repositorios/evse-embebidos-software/i5ether/test/EthNativePosix/build/zephyr/cmake/reports/cmake_install.cmake")
endif()

