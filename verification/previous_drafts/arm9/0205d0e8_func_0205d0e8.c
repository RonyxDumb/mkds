/* Decompiled C draft; module arm9; ROM address 0205d0e8. No matching claim. */
#include "types.h"
#include "deps/0205d0e8_func_0205d0e8.h"

void func_0205d0e8(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = uRam0205d13c;
  iVar6 = 0;
  iVar5 = 0;
  do {
    uVar1 = uVar2 & 3;
    uVar3 = *(uint *)(uVar2 & 0xfffffffc);
    iVar4 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + iVar5;
    Mem_CpuCopy8((ushort *)(uintptr_t)(iVar4 + param_1 * 10),(uint *)(uintptr_t)(iVar4 + param_2 * 10),10);
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 0x50;
  } while (iVar6 < 4);
  return;
}

