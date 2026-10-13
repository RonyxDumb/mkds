/* Decompiled C draft; module arm9; ROM address 02043078. No matching claim. */
#include "types.h"
#include "deps/02043078_ComputeTotalDistanceRecursively_from_thumb.h"

int ComputeTotalDistanceRecursively_from_thumb(int param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  int local_20;
  
  psVar2 = (short *)(*(int *)(*piRam02043104 + 0x4c) + param_1 * 0xc);
  sVar1 = 0;
  local_20 = 0;
  iVar7 = 0;
  uVar5 = 0;
  if (psVar2[1] != 0) {
    do {
      iVar7 = iVar7 + *(int *)(*(int *)(*piRam02043104 + 0x44) +
                               (uint)(ushort)(*psVar2 + uVar5) * 0x24 + 0x18);
      uVar5 = uVar5 + 1;
    } while (uVar5 < (ushort)psVar2[1]);
  }
  uVar6 = 0;
  do {
    uVar4 = (uint)*(char *)((int)psVar2 + uVar6 + 4);
    if ((uVar4 != 0xffffffff) && (uVar4 != 0)) {
      iVar3 = ComputeTotalDistanceRecursively_from_thumb(uVar4 & 0xffff);
      local_20 = local_20 + iVar3;
      sVar1 = sVar1 + 1;
    }
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < 3);
  if (sVar1 != 0) {
    iVar3 = _s32_div_f(local_20,sVar1);
    iVar7 = iVar7 + iVar3;
  }
  return iVar7;
}

