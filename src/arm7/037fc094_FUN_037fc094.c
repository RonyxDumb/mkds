/* Decompiled C draft; module arm7; ROM address 037fc094. No matching claim. */
#include "types.h"
#include "deps/037fc094_FUN_037fc094.h"

uint FUN_037fc094(uint param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar5 = 0;
  for (param_2 = -param_2; param_2 < 0; param_2 = param_2 + 0x300) {
    iVar5 = iVar5 + -1;
  }
  for (; 0x2ff < param_2; param_2 = param_2 + -0x300) {
    iVar5 = iVar5 + 1;
  }
  uVar2 = thunk_FUN_03801214();
  lVar1 = (ulonglong)param_1 * (ulonglong)(uVar2 + 0x10000);
  uVar4 = (uint)lVar1;
  uVar3 = (0xfffeffff < uVar2) * param_1 +
          (uVar2 + 0x10000) * ((int)param_1 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20);
  uVar2 = iVar5 - 0x10;
  if ((int)uVar2 < 1) {
    uVar2 = -uVar2;
    uVar6 = uVar3 >> (uVar2 & 0xff);
    uVar7 = uVar4 >> (uVar2 & 0xff) | uVar3 << (iVar5 + 0x10U & 0xff) |
            uVar3 >> (uVar2 - 0x20 & 0xff);
  }
  else {
    if (0x1f < (int)uVar2) {
      return DAT_037fc1b8;
    }
    uVar6 = -uVar2 + 0x20;
    if ((uVar3 & (-1 << (uVar6 & 0xff) | 0xffffffffU >> (0x20 - uVar6 & 0xff) |
                 -1 << (-uVar2 & 0xff))) != 0 || (uVar4 & -1 << (uVar6 & 0xff)) != 0) {
      return DAT_037fc1b8;
    }
    uVar7 = uVar4 << (uVar2 & 0xff);
    uVar6 = uVar3 << (uVar2 & 0xff) | uVar4 >> (uVar6 & 0xff) | uVar4 << (iVar5 - 0x30U & 0xff);
  }
  if (uVar6 == 0 && uVar7 < 0x10) {
    uVar7 = 0x10;
  }
  else if (uVar6 != 0 || DAT_037fc1b8 < uVar7) {
    uVar7 = DAT_037fc1b8;
  }
  return uVar7 & 0xffff;
}

