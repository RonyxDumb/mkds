/* Decompiled C draft; module arm9; ROM address 01ff9320. No matching claim. */
#include "types.h"
#include "deps/01ff9320_func_01ff9320.h"

void func_01ff9320(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_58;
  undefined4 local_54;
  uint local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 8) == 0) {
    local_58 = uRam01ff9464;
  }
  else {
    local_58 = uRam01ff9460;
  }
  local_14 = 0x1000;
  local_54 = 3;
  local_10 = 2;
  local_18 = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  local_38 = 0;
  local_44 = 0;
  local_48 = 0;
  uVar2 = iRam01ff9468 +
          ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 7) * 4;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  (*(code *)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20))(&local_50,param_1);
  uVar2 = param_1 + 0x30 & 3;
  uVar3 = *(uint *)(param_1 + 0x30 & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  if (uVar2 != 0x1000) {
    lVar1 = (longlong)(int)uVar2 * (longlong)(int)local_50;
    local_50 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar2 = param_1 + 0x30 & 3;
    uVar3 = *(uint *)(param_1 + 0x30 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) *
            (longlong)(int)local_4c;
    local_4c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar2 = param_1 + 0x30 & 3;
    uVar3 = *(uint *)(param_1 + 0x30 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) *
            (longlong)(int)local_20;
    local_20 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  }
  uVar2 = param_1 + 0x34 & 3;
  uVar3 = *(uint *)(param_1 + 0x34 & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  if (uVar2 != 0x1000) {
    lVar1 = (longlong)(int)uVar2 * (longlong)(int)local_40;
    local_40 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar2 = param_1 + 0x34 & 3;
    uVar3 = *(uint *)(param_1 + 0x34 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) *
            (longlong)(int)local_3c;
    local_3c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar2 = param_1 + 0x34 & 3;
    uVar3 = *(uint *)(param_1 + 0x34 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) *
            (longlong)(int)local_1c;
    local_1c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  }
  func_01ff9048(local_58,&local_54,0x12);
  return;
}

