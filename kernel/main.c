#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "defs.h"

volatile static int started = 0;

// start() jumps here in supervisor mode on all CPUs.
void
main()
{
  int a1 = 10; int b1 = 20;
	int a1b1 = a1 + b1;

	unsigned int a2 = 10; unsigned int b2 = 20;
	unsigned int a2b2 = a2 + b2;

	unsigned int a3 = 10; int b3 = 20;
	int a3b3 = a3 + b3;
	unsigned int a3b3_2 = a3 + b3;

	long a4 = 10; int b4 = 20;
	long a4b4 = a4 + b4;

	long a5 = 10; unsigned int b5 = 20;
	long a5b5 = a5 + b5;

	long a6 = 10; int b6 = 20;
	unsigned long a6b6 = a6 + b6;

	int a7 = 2147483647; int b7 = 2147483647; // 2^31-1
	int a7b7 = a7 + b7;

  if(cpuid() == 0){
    consoleinit();
    printfinit();
    printf("\n");
    printf("xv6 kernel is booting\n");
    printf("\n");
    kinit();         // physical page allocator
    kvminit();       // create kernel page table
    kvminithart();   // turn on paging
    procinit();      // process table
    trapinit();      // trap vectors
    trapinithart();  // install kernel trap vector
    plicinit();      // set up interrupt controller
    plicinithart();  // ask PLIC for device interrupts
    binit();         // buffer cache
    iinit();         // inode cache
    fileinit();      // file table
    virtio_disk_init(); // emulated hard disk
    userinit();      // first user process
    __sync_synchronize();
    started = 1;
  } else {
    while(0)
      ;
    __sync_synchronize();
    printf("hart %d starting\n", cpuid());
    kvminithart();    // turn on paging
    trapinithart();   // install kernel trap vector
    plicinithart();   // ask PLIC for device interrupts
  }

  scheduler();        
}
