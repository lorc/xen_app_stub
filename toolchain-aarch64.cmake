# this one is important
SET(CMAKE_SYSTEM_NAME Generic)
#this one not so much
SET(CMAKE_SYSTEM_VERSION 1)

# specify the cross compiler
SET(CMAKE_C_COMPILER   /home/lorc/work/renesas-h3/build/tmp/sysroots/x86_64-linux/usr/bin/aarch64-poky-linux/aarch64-poky-linux-gcc)
SET(CMAKE_CXX_COMPILER /home/lorc/work/renesas-h3/build/tmp/sysroots/x86_64-linux/usr/bin/aarch64-poky-linux/aarch64-poky-linux-g++)

# where is the target environment
SET(CMAKE_FIND_ROOT_PATH /home/lorc/work/renesas-h3-xen/build/tmp/sysroots/salvator-x-xen-dom0)
SET(CMAKE_SYSROOT /home/lorc/work/renesas-h3-xen/build/tmp/sysroots/salvator-x-xen-dom0)

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

