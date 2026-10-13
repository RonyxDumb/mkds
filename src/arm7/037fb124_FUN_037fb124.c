/* Decompiled C draft; module arm7; ROM address 037fb124. No matching claim. */
#include "types.h"
#include "deps/037fb124_FUN_037fb124.h"

void FUN_037fb124(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 uVar5;
  
  uVar3 = FUN_037faf70();
  iVar1 = (param_1 * 6 + 5) * 2;
  *(ushort *)(iVar1 + 0x40000b0) = *(ushort *)(iVar1 + 0x40000b0) & 0xcdff;
  *(ushort *)(iVar1 + 0x40000b0) = *(ushort *)(iVar1 + 0x40000b0) & 0x7fff;
  iVar2 = DAT_037fb1a0;
  uVar5 = *(undefined2 *)(iVar1 + 0x40000b0);
  uVar4 = (uint)*(ushort *)(iVar1 + 0x40000b0);
  if (param_1 == 0) {
    uVar5 = 0;
    uRam040000b0 = 0;
    *(undefined4 *)(DAT_037fb1a0 + 4) = 0;
    uVar4 = DAT_037fb1a4;
    *(uint *)(iVar2 + 8) = DAT_037fb1a4;
  }
  FUN_037faf84(uVar3,uVar4,uVar5);
  return;
}

