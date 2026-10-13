/* Decompiled C draft; module arm9; ROM address 020db050. No matching claim. */
#include "types.h"
#include "deps/020db050_func_020db050.h"

void func_020db050(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  ushort uVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_2c;
  uint local_28;
  uint local_24;
  undefined1 auStack_20 [20];
  
  if (*(ushort *)(param_2 + 0xd4) == uRam020db18c) {
    func_020d7938(param_2 + 0xa4,uRam020db190,(int *)(void *)(auStack_20));
    func_01ffccd0((int *)(uintptr_t)(param_2 + 0x28),(uint)(uintptr_t)(auStack_20));
  }
  else {
    uVar4 = func_020d88fc(param_2 + 0xcc);
    func_020e6d34((undefined4 *)(uintptr_t)(uVar4),param_2 + 0x28);
  }
  uVar1 = param_2 + 0x24U & 3;
  uVar5 = *(uint *)(param_2 + 0x24U & 0xfffffffc);
  local_24 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0x20U & 3;
  uVar7 = *(uint *)(param_2 + 0x20U & 0xfffffffc);
  uVar5 = param_2 + 0xc4U & 3;
  uVar6 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  lVar3 = (longlong)(int)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) *
          (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  local_28 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  uVar1 = param_2 + 0xc4U & 3;
  uVar6 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  uVar5 = param_2 + 0x1cU & 3;
  uVar7 = *(uint *)(param_2 + 0x1cU & 0xfffffffc);
  lVar3 = (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) *
          (longlong)
          (((int)(0x1000 - (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20)) >> 1) + 0x1000);
  local_2c = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  uVar1 = param_2 + 4U & 3;
  uVar5 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(param_2 + 0x4c) = (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8U & 3;
  uVar5 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 0xcU & 3;
  uVar5 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) >> 4;
  if (*(ushort *)(param_2 + 0xf0) < 0x14) {
    *(ushort *)
     ((*(uint *)(uRam020db194 & 0xfffffffc) >> (uRam020db194 & 3) * 8 |
      *(uint *)(uRam020db194 & 0xfffffffc) << (uRam020db194 & 3) * -8 + 0x20) + 0x18) =
         *(ushort *)(param_2 + 0xf0);
  }
  else {
    local_2c = -local_2c;
    *(short *)((*(uint *)(uRam020db194 & 0xfffffffc) >> (uRam020db194 & 3) * 8 |
               *(uint *)(uRam020db194 & 0xfffffffc) << (uRam020db194 & 3) * -8 + 0x20) + 0x18) =
         *(short *)(param_2 + 0xf0) + -0x14;
  }
  uVar5 = uRam020db194;
  uVar7 = *(uint *)(uRam020db194 & 0xfffffffc) >> (uRam020db194 & 3) * 8 |
          *(uint *)(uRam020db194 & 0xfffffffc) << (uRam020db194 & 3) * -8 + 0x20;
  uVar2 = *(ushort *)(param_2 + 0x100);
  uVar1 = uVar7 + 0x14 & 3;
  uVar6 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
  *(uint *)(uVar7 + 0x14) = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0xffe0ffff;
  uVar1 = uVar7 + 0x14 & 3;
  uVar6 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
  *(uint *)(uVar7 + 0x14) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20 | (uint)uVar2 << 0x10;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  func_020e67c4(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,param_2 + 0x28,(uint)(uintptr_t)(&local_2c),0,param_4);
  return;
}

