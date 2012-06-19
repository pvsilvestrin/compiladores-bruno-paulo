gcc -S main.c -O3
..\a2i -B 0x20000 --no-info main.s -O2
nasm -fbin entry.asm -o kernel.bin
@echo Please insert a blank disk in drive A:
@pause
sys A:
