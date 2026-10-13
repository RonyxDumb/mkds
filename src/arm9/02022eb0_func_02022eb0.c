/* Decompiled C draft; module arm9; ROM address 02022eb0. No matching claim. */
#include "types.h"
#include "deps/02022eb0_func_02022eb0.h"

int func_02022eb0(uint *param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7,uint param_8)

{
  sbyte sVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int local_3c;
  int local_38;
  int local_30;
  
  if ((int)param_2 < 8) {
    iVar8 = 0x1f - LZCOUNT(param_2);
  }
  else {
    iVar8 = 3;
  }
  if ((int)param_3 < 8) {
    iVar4 = 0x1f - LZCOUNT(param_3);
  }
  else {
    iVar4 = 3;
  }
  iVar4 = iRam020231d4 + iVar4 * 8;
  sVar1 = *(sbyte *)(iVar4 + iVar8 * 2);
  bVar2 = *(byte *)(iVar4 + iVar8 * 2 + 1);
  uVar5 = (uint)bVar2;
  uVar6 = param_2 & -1 << sVar1;
  uVar7 = param_3 & -1 << bVar2;
  if (param_6 == 0) {
    local_3c = 1;
  }
  else {
    local_3c = 2;
  }
  uVar3 = func_02024168();
  for (local_30 = 0; local_30 < (int)param_3 >> uVar5; local_30 = local_30 + 1) {
    for (iVar8 = 0; iVar8 < (int)param_2 >> sVar1; iVar8 = iVar8 + 1) {
      *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
                 uRam020231dc | param_5 + (local_30 << uVar5) * 8 & 0xffU |
                 (param_4 + (iVar8 << sVar1) * 8 & uRam020231d8) << 0x10;
      *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
                 uRam020231e0 | uVar3;
      *(ushort *)(param_1 + 1) = (ushort)param_1[1] & 0xfc00 | (ushort)param_7;
      param_7 = param_7 + (((local_3c << sVar1) << uVar5) >> (param_8 & 0xff));
      *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
                 0xffffdfff | param_6 << 0xd;
      param_1 = param_1 + 2;
    }
  }
  local_38 = ((int)param_2 >> sVar1) * ((int)param_3 >> uVar5);
  if (uVar6 < param_2) {
    iVar8 = func_02022eb0(param_1,param_2 - uVar6,uVar7,param_4 + uVar6 * 8,param_5,param_6,param_7,
                          param_8);
    param_1 = param_1 + iVar8 * 2;
    param_7 = param_7 + (uVar7 * local_3c * (param_2 - uVar6) >> (param_8 & 0xff));
    local_38 = local_38 + iVar8;
  }
  if (uVar7 < param_3) {
    iVar8 = func_02022eb0(param_1,uVar6,param_3 - uVar7,param_4,param_5 + uVar7 * 8,param_6,param_7,
                          param_8);
    param_1 = param_1 + iVar8 * 2;
    param_7 = param_7 + ((param_3 - uVar7) * local_3c * uVar6 >> (param_8 & 0xff));
    local_38 = local_38 + iVar8;
  }
  if ((uVar6 < param_2) && (uVar7 < param_3)) {
    iVar8 = func_02022eb0(param_1,param_2 - uVar6,param_3 - uVar7,param_4 + uVar6 * 8,
                          param_5 + uVar7 * 8,param_6,param_7,param_8);
    local_38 = local_38 + iVar8;
  }
  return local_38;
}

