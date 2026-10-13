/* Decompiled C draft; module arm9; ROM address 0211a964. No matching claim. */
#include "types.h"
#include "deps/0211a964_func_0211a964.h"

void func_0211a964(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam0211a9d4;
  iVar5 = (uint)*(ushort *)(*(int *)(*piRam0211a9d4 + 4) + 6) + param_1;
  iVar4 = iVar5 * 0x40;
  iVar2 = *(int *)(*piRam0211a9d4 + 0x14) + 6;
  *(short *)(iVar2 + iVar4) = *(short *)(iVar2 + iVar4) + 1;
  iVar2 = *piVar1;
  func_02124100(param_1,1,*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x14),
                *(undefined4 *)(iVar2 + 4));
  puVar3 = (undefined4 *)*piRam0211a9d4;
  func_02124bc8(iVar5,puVar3[1],*puVar3,puVar3[3],puVar3[0x2d],puVar3[5]);
  piVar1 = piRam0211a9d4;
  iVar2 = *(int *)(*piRam0211a9d4 + 0x14) + 6;
  *(short *)(iVar2 + iVar4) = *(short *)(iVar2 + iVar4) + -1;
  iVar2 = *piVar1;
  func_02124100(param_1,0,*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x14),
                *(undefined4 *)(iVar2 + 4));
  return;
}

