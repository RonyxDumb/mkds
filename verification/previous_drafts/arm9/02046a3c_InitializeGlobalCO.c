/* Decompiled C draft; module arm9; ROM address 02046a3c. No matching claim. */
#include "types.h"
#include "deps/02046a3c_InitializeGlobalCO.h"

void InitializeGlobalCO(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Mem_AllocateHeap(param_1,0x400);
  *puRam02046a84 = uVar1;
  uVar1 = Mem_AllocateHeap(param_1,0x21);
  *(undefined4 *)
   ((*(uint *)((uint)puRam02046a84 & 0xfffffffc) >> ((uint)puRam02046a84 & 3) * 8 |
    *(uint *)((uint)puRam02046a84 & 0xfffffffc) << ((uint)puRam02046a84 & 3) * -8 + 0x20) + 0x3dc) =
       uVar1;
  InitializeGlobalRE(param_1);
  InitializeGlobalLU(param_1);
  return;
}

