/* Decompiled C draft; module arm9_ov001; ROM address 0218f724. No matching claim. */
#include "types.h"
#include "deps/0218f724_FUN_0218f724.h"

void FUN_0218f724(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int local_2c [3];
  int local_20 [2];
  int local_18;
  
  if (*(int *)(*DAT_0218f848 + 8) == 4) {
    uVar1 = func_ov001_02181a88();
  }
  else {
    uVar1 = 0;
  }
  if (*(int *)(*DAT_0218f848 + 8) == 4) {
    uVar2 = func_ov001_02181a94();
  }
  else {
    uVar2 = 0;
  }
  func_0x021484d0(uVar2,uVar1,local_2c);
  iVar4 = 0;
  local_2c[1] = 0;
  if (*(int *)(*DAT_0218f848 + 8) == 4) {
    iVar4 = func_ov001_02181a68();
  }
  if (*(int *)(*DAT_0218f848 + 8) == 4) {
    iVar3 = func_ov001_02181a78();
  }
  else {
    iVar3 = 0;
  }
  if (*(int *)(*DAT_0218f848 + 8) == 4) {
    uVar1 = func_ov001_02181a94();
  }
  else {
    uVar1 = 0;
  }
  func_0x021484d0(param_1 + 4,uVar1,local_20);
  iVar4 = (int)(iVar3 - iVar4 & 0xffffU) >> 4;
  iVar3 = (int)*(short *)(DAT_0218f84c + (iVar4 * 2 + 1) * 2);
  iVar4 = (int)*(short *)(DAT_0218f84c + iVar4 * 4);
  uVar5 = func_0x02133048(local_18,local_18 >> 0x1f,iVar4,iVar4 >> 0x1f);
  uVar6 = func_0x02133048(local_20[0],local_20[0] >> 0x1f,iVar3,iVar3 >> 0x1f);
  local_2c[0] = local_2c[0] +
                ((((uint)uVar5 >> 0xc | (int)((ulonglong)uVar5 >> 0x20) << 0x14) +
                 ((uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14)) - local_20[0]);
  uVar5 = func_0x02133048(local_18,local_18 >> 0x1f,iVar3,iVar3 >> 0x1f);
  uVar6 = func_0x02133048(local_20[0],local_20[0] >> 0x1f,iVar4,iVar4 >> 0x1f);
  local_2c[2] = local_2c[2] +
                ((((uint)uVar5 >> 0xc | (int)((ulonglong)uVar5 >> 0x20) << 0x14) -
                 ((uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14)) - local_18);
  FUN_02188950(param_1,local_2c);
  return;
}

