/* Decompiled C draft; module arm9; ROM address 020ab758. No matching claim. */
#include "types.h"
#include "deps/020ab758_func_020ab758.h"

void func_020ab758(undefined2 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = piRam020ab794;
  *(undefined2 *)(*piRam020ab794 + 0x4a) = param_1;
  iVar3 = *piVar1;
  iVar2 = *(ushort *)(iVar3 + 0x4a) - 1;
  if (iVar2 <= (int)(uint)*(ushort *)(iVar3 + 0x46)) {
    *(short *)(iVar3 + 0x46) = (short)iVar2;
    *(undefined2 *)(*piVar1 + 0x48) = *(undefined2 *)(*piVar1 + 0x46);
    *(undefined2 *)(*(int *)(*piVar1 + 0x40) + (uint)*(ushort *)(*piVar1 + 0x4a) * 2) = 0;
  }
  return;
}

