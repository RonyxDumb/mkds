/* Decompiled C draft; module arm9; ROM address 02120714. No matching claim. */
#include "types.h"
#include "deps/02120714_func_02120714.h"

void func_02120714(void)

{
  uint uVar1;
  int iVar2;
  
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(uRam021208c8 & 0xfffffffc) >> (uRam021208c8 & 3) * 8 |
               *(uint *)(uRam021208c8 & 0xfffffffc) << (uRam021208c8 & 3) * -8 + 0x20) + 0x1c),0,
               0x200);
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(uRam021208c8 & 0xfffffffc) >> (uRam021208c8 & 3) * 8 |
               *(uint *)(uRam021208c8 & 0xfffffffc) << (uRam021208c8 & 3) * -8 + 0x20) + 0x21c),0,
               0x910);
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(uRam021208c8 & 0xfffffffc) >> (uRam021208c8 & 3) * 8 |
               *(uint *)(uRam021208c8 & 0xfffffffc) << (uRam021208c8 & 3) * -8 + 0x20) +
               iRam021208cc),0,uRam021208d0);
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(uRam021208c8 & 0xfffffffc) >> (uRam021208c8 & 3) * 8 |
               *(uint *)(uRam021208c8 & 0xfffffffc) << (uRam021208c8 & 3) * -8 + 0x20) +
               iRam021208d4),0,0x60);
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(uRam021208c8 & 0xfffffffc) >> (uRam021208c8 & 3) * 8 |
               *(uint *)(uRam021208c8 & 0xfffffffc) << (uRam021208c8 & 3) * -8 + 0x20) +
               iRam021208d8),0,0x350);
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(uRam021208c8 & 0xfffffffc) >> (uRam021208c8 & 3) * 8 |
               *(uint *)(uRam021208c8 & 0xfffffffc) << (uRam021208c8 & 3) * -8 + 0x20) + 0x1d00),0,
               0x110);
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(uRam021208c8 & 0xfffffffc) >> (uRam021208c8 & 3) * 8 |
               *(uint *)(uRam021208c8 & 0xfffffffc) << (uRam021208c8 & 3) * -8 + 0x20) +
               iRam021208dc),0,0x110);
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(uRam021208c8 & 0xfffffffc) >> (uRam021208c8 & 3) * 8 |
               *(uint *)(uRam021208c8 & 0xfffffffc) << (uRam021208c8 & 3) * -8 + 0x20) +
               iRam021208e0),0,0x10);
  iVar2 = iRam021208e4;
  uVar1 = uRam021208c8;
  *(undefined4 *)
   ((*(uint *)(uRam021208c8 & 0xfffffffc) >> (uRam021208c8 & 3) * 8 |
    *(uint *)(uRam021208c8 & 0xfffffffc) << (uRam021208c8 & 3) * -8 + 0x20) + 0x1f34) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f38) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f3c) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 8000) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f44) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f48) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f4c) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f4d) = 0;
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
               *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar2),0,4);
  uVar1 = uRam021208c8;
  *(undefined1 *)
   ((*(uint *)(uRam021208c8 & 0xfffffffc) >> (uRam021208c8 & 3) * 8 |
    *(uint *)(uRam021208c8 & 0xfffffffc) << (uRam021208c8 & 3) * -8 + 0x20) + 0x1f52) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f53) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f54) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f55) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f56) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f57) = 0;
  return;
}

