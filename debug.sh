ps -ef | grep 'qemu-system-riscv64' | grep -v 'grep'| awk '{print $2}'| xargs kill -9 > /dev/null 2>&1 &
sleep 0.1

if [[ ! -f kernel/kernel ]]; then
    make -j4
    echo $?
fi
ls .gdbinit
make qemu-gdb > /dev/null 2>&1 &
sleep 0.1 
#riscv64-unknown-elf-gdb -q |& tee gdb.log
riscv64-unknown-elf-gdb -q
ps -ef | grep 'qemu-system-riscv64' | grep -v 'grep'| awk '{print $2}'| xargs kill -9 > /dev/null 2>&1 &
