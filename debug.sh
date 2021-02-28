ps -ef | grep 'qemu-system-riscv64' | grep -v 'grep'| awk '{print $2}'| xargs kill -9 &
(make qemu-gdb) &
riscv64-unknown-elf-gdb
ps -ef | grep 'qemu-system-riscv64' | grep -v 'grep'| awk '{print $2}'| xargs kill -9 &
