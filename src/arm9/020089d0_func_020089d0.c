/* Decompiled C draft; module arm9; ROM address 020089d0. No matching claim. */
#include "types.h"
#include "deps/020089d0_func_020089d0.h"

void func_020089d0(uint param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = piRam02008a0c;
  uVar1 = (ushort)(1 << (param_1 & 0xff));
  *(ushort *)(*piRam02008a0c + 2) = *(ushort *)(*piRam02008a0c + 2) & ~uVar1;
  iVar3 = *piVar2;
  *(ushort *)(iVar3 + 4) = *(ushort *)(iVar3 + 4) & ~uVar1;
  Mem_CpuFill16(0,*piVar2 + 0x10 + iRam02008a10 * param_1);
  return;
}

