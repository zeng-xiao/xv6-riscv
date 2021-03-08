ps -ef | grep 'qemu-system-riscv64' | grep -v 'grep'| awk '{print $2}'| xargs kill -9 > /dev/null 2>&1 &
sleep 1
make qemu-gdb > /dev/null 2>&1 &
sleep 1 
riscv64-unknown-elf-gdb -q |& tee gdb.log
ps -ef | grep 'qemu-system-riscv64' | grep -v 'grep'| awk '{print $2}'| xargs kill -9 > /dev/null 2>&1 &
