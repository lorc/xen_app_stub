cmake_minimum_required(VERSION 3.1)

project(el0_app)

set(LINKER_SCRIPT "app.ld")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_SOURCE_DIR}/${LINKER_SCRIPT}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

include(libutils/isoc/isoc.cmake)

enable_language(ASM)

add_executable(${PROJECT_NAME}.elf
  app_syscalls_a64.S
  app_entry.c
)

target_link_libraries (
    ${PROJECT_NAME}.elf
    isoc
)

