/* Decompiled C draft; module arm9; ROM address 0200895c. No matching claim. */
#include "types.h"
#include "deps/0200895c_func_0200895c.h"

void func_0200895c(uint param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = piRam020089b8;
  uVar1 = (ushort)(1 << (param_1 & 0xff));
  *(ushort *)(*piRam020089b8 + 2) = *(ushort *)(*piRam020089b8 + 2) & ~uVar1;
  *(ushort *)(*piVar2 + 4) = *(ushort *)(*piVar2 + 4) & ~uVar1;
  iVar3 = iRam020089bc * param_1;
  *(undefined4 *)(*piVar2 + iVar3 + iRam020089bc) = 0;
  *(undefined4 *)(*piVar2 + iVar3 + iRam020089c0) = 0;
  *(undefined2 *)(*piVar2 + iVar3 + iRam020089c4) = 0;
  *(undefined2 *)(*piVar2 + iVar3 + iRam020089c8) = 0;
  Mem_CpuFill16(0,*piVar2 + 0x10 + iVar3,uRam020089cc);
  return;
}

