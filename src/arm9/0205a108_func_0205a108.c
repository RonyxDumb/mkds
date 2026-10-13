/* Decompiled C draft; module arm9; ROM address 0205a108. No matching claim. */
#include "types.h"
#include "deps/0205a108_func_0205a108.h"

void func_0205a108(void)

{
  undefined4 uVar1;
  
  uVar1 = Mem_Frame_Create(uRam0205a138,0x50000,0);
  *(undefined4 *)
   ((*(uint *)(uRam0205a13c & 0xfffffffc) >> (uRam0205a13c & 3) * 8 |
    *(uint *)(uRam0205a13c & 0xfffffffc) << (uRam0205a13c & 3) * -8 + 0x20) + 0xa0) = uVar1;
  return;
}

