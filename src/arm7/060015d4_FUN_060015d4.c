/* Decompiled C draft; module arm7; ROM address 060015d4. No matching claim. */
#include "types.h"
#include "deps/060015d4_FUN_060015d4.h"

void FUN_060015d4(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  
  iVar2 = FUN_06000680();
  uVar6 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar5 = *(ushort *)(uVar3 + 0xba);
  uVar6 = (uint)uVar5;
  if (param_2 == 0) {
    if (*(ushort *)(param_1 + 0x14) == 0) {
      return;
    }
    for (iVar2 = 0; uVar5 = (ushort)uVar6, iVar2 < (int)(uint)*(ushort *)(param_1 + 0x14);
        iVar2 = iVar2 + 1) {
      bVar1 = *(byte *)((uint)*(ushort *)(param_1 + 0x16) * iVar2 + param_1 + 0x1d);
      uVar4 = (int)(uint)bVar1 >> 2;
      if ((bVar1 & 2) == 0) {
        uVar4 = uVar4 + 0x19;
      }
      if (uVar4 < uVar6) {
        uVar6 = uVar4;
      }
    }
  }
  else if (4 < uVar6) {
    uVar5 = 4;
  }
  *(ushort *)(uVar3 + 0xba) = uVar5;
  return;
}

