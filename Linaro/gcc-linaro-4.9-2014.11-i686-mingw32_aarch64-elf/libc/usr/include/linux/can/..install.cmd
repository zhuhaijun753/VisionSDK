cmd_/home/buildslave/workspace/BinaryRelease/label/x86_64/target/aarch64-none-elf/_build/sysroots/aarch64-none-elf/usr/include/linux/can/.install := /bin/bash scripts/headers_install.sh /home/buildslave/workspace/BinaryRelease/label/x86_64/target/aarch64-none-elf/_build/sysroots/aarch64-none-elf/usr/include/linux/can ./include/uapi/linux/can bcm.h error.h gw.h netlink.h raw.h; /bin/bash scripts/headers_install.sh /home/buildslave/workspace/BinaryRelease/label/x86_64/target/aarch64-none-elf/_build/sysroots/aarch64-none-elf/usr/include/linux/can ./include/linux/can ; /bin/bash scripts/headers_install.sh /home/buildslave/workspace/BinaryRelease/label/x86_64/target/aarch64-none-elf/_build/sysroots/aarch64-none-elf/usr/include/linux/can ./include/generated/uapi/linux/can ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/buildslave/workspace/BinaryRelease/label/x86_64/target/aarch64-none-elf/_build/sysroots/aarch64-none-elf/usr/include/linux/can/$$F; done; touch /home/buildslave/workspace/BinaryRelease/label/x86_64/target/aarch64-none-elf/_build/sysroots/aarch64-none-elf/usr/include/linux/can/.install
