/* Decompiled C draft; module arm9; ROM address 020d1198. No matching claim. */
#include "types.h"
#include "deps/020d1198_func_020d1198.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_020d1198(int param_1)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  _DAT_04000000 = _DAT_04000000 & 0xffff1fff;
  uVar3 = (*(uint *)(uRam020d1294 & 0xfffffffc) >> (uRam020d1294 & 3) * 8 |
          *(uint *)(uRam020d1294 & 0xfffffffc) << (uRam020d1294 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = GetB3C4_Cell_RaceStartBattleM(uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0);
  local_1c = 0x80000;
  local_18 = 0x60000;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4,0,&local_1c,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar4 = GetB3C4_Cell_RaceStartBattleM(2);
  local_14 = 0x80000;
  local_10 = 0x60000;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4,0,&local_14,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  return;
}

