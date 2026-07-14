set(CMAKE_SYSTEM_NAME Generic)

# Cross compiler
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

# Tools
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_SIZE arm-none-eabi-size)
set(CMAKE_STRIP arm-none-eabi-strip)

# Prevent try_compile from using the wrong compiler
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Flags can still be provided in the top-level CMakeLists
set(ARM_NONE_EABI_TOOLCHAIN TRUE)
