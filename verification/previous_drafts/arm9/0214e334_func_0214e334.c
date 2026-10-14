/* Decompiled C draft; module arm9; ROM address 0214e334. No matching claim. */
#include "types.h"
#include "deps/0214e334_func_0214e334.h"

void func_0214e334(ushort *param_1,ushort *param_2)

{
  ushort *puVar1;
  ushort uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = uRam0214e460;
  if (*(short *)(iRam0214e45c + 0x30) == 0) {
    uVar2 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = uVar2;
    uVar2 = param_2[3];
    param_1[2] = param_2[2];
    param_1[3] = uVar2;
    return;
  }
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  puVar1 = param_2 + 2;
  if (*puVar1 == 0) {
    param_2 = (ushort *)0x0;
  }
  if (*puVar1 != 0) {
    uVar4 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    uVar5 = uVar6 + 8 & 3;
    uVar7 = *(uint *)(uVar6 + 8 & 0xfffffffc);
    uVar7 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
    uVar5 = (uint)*param_2 * 4 - uVar4;
    lVar3 = (ulonglong)uVar5 * (ulonglong)uVar7;
    *param_1 = (ushort)((ulonglong)lVar3 >> 0x10) >> 6 |
               ((short)((int)uVar7 >> 0x1f) * (short)uVar5 +
               (short)uVar7 * -((short)((int)uVar4 >> 0x1f) + (ushort)((uint)*param_2 * 4 < uVar4))
               + (short)((ulonglong)lVar3 >> 0x20)) * 0x400;
    if ((short)*param_1 < 0) {
      *param_1 = 0;
    }
    else if (0xff < (short)*param_1) {
      *param_1 = 0xff;
    }
    uVar5 = uVar6 + 0xc & 3;
    uVar4 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
    uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar6 + 0x14 & 3;
    uVar6 = *(uint *)(uVar6 + 0x14 & 0xfffffffc);
    uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    uVar6 = (uint)param_2[1] * 4 - uVar4;
    lVar3 = (ulonglong)uVar6 * (ulonglong)uVar5;
    param_1[1] = (ushort)((ulonglong)lVar3 >> 0x10) >> 6 |
                 ((short)((int)uVar5 >> 0x1f) * (short)uVar6 +
                 (short)uVar5 *
                 -((short)((int)uVar4 >> 0x1f) + (ushort)((uint)param_2[1] * 4 < uVar4)) +
                 (short)((ulonglong)lVar3 >> 0x20)) * 0x400;
    if (-1 < (short)param_1[1]) {
      if (0xbf < (short)param_1[1]) {
        param_1[1] = 0xbf;
      }
      return;
    }
    param_1[1] = 0;
    return;
  }
  *param_1 = (ushort)param_2;
  param_1[1] = (ushort)param_2;
  return;
}

