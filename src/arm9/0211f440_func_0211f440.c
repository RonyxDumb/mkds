/* Decompiled C draft; module arm9; ROM address 0211f440. No matching claim. */
#include "types.h"
#include "deps/0211f440_func_0211f440.h"

void func_0211f440(void)

{
  ushort uVar1;
  int *piVar2;
  undefined2 uVar3;
  int iVar4;
  
  piVar2 = piRam0211f490;
  iVar4 = *piRam0211f490;
  uVar1 = *(ushort *)(*(int *)(iVar4 + 4) + 6);
  *(int *)(iVar4 + 0x24) = *(int *)(iVar4 + 0x24) + 1;
  uVar3 = ComputeValueInterpolation_from_thumb(1,0xc0,0,*(undefined4 *)(*piVar2 + 0x24),10);
  piVar2 = piRam0211f490;
  *(undefined2 *)(*(int *)(*piRam0211f490 + 0x10) + iRam0211f494) = uVar3;
  *(undefined2 *)(*(int *)(*piVar2 + 0x10) + (uVar1 + 0xe) * 0x40 + 6) = uVar3;
  if (9 < *(int *)(*piVar2 + 0x24)) {
    func_0211f5d0();
  }
  return;
}

