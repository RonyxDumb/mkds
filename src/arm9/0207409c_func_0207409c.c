/* Decompiled C draft; module arm9; ROM address 0207409c. No matching claim. */
#include "types.h"
#include "deps/0207409c_func_0207409c.h"

void func_0207409c(undefined4 param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_48 [24];
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  uVar6 = *(uint *)(uRam02074190 & 0xfffffffc) >> (uRam02074190 & 3) * 8 |
          *(uint *)(uRam02074190 & 0xfffffffc) << (uRam02074190 & 3) * -8 + 0x20;
  func_01ffccd0(auStack_48);
  uVar7 = uVar6 + 0xf0 & 3;
  uVar3 = *(uint *)(uVar6 + 0xf0 & 0xfffffffc);
  lVar1 = (longlong)
          (int)-(*(uint *)(uRam02074194 & 0xfffffffc) >> (uRam02074194 & 3) * 8 |
                *(uint *)(uRam02074194 & 0xfffffffc) << (uRam02074194 & 3) * -8 + 0x20) *
          (longlong)(int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 0x800;
  uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  local_1c = (uint)((longlong)local_28 * (longlong)(int)uVar7) >> 0xc |
             (int)((ulonglong)((longlong)local_28 * (longlong)(int)uVar7) >> 0x20) << 0x14;
  local_24 = (uint)((longlong)local_30 * (longlong)(int)uVar7) >> 0xc |
             (int)((ulonglong)((longlong)local_30 * (longlong)(int)uVar7) >> 0x20) << 0x14;
  local_20 = (uint)((longlong)local_2c * (longlong)(int)uVar7) >> 0xc |
             (int)((ulonglong)((longlong)local_2c * (longlong)(int)uVar7) >> 0x20) << 0x14;
  VecFx32_Add(param_1,(uint)(uintptr_t)(&local_24),(int *)(uintptr_t)(uVar6 + 0x24));
  puVar2 = puRam0207419c;
  uVar7 = uVar6 + 0x28 & 3;
  uVar3 = *(uint *)(uVar6 + 0x28 & 0xfffffffc);
  *(uint *)(uVar6 + 0x28) =
       (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) +
       (*(uint *)(uRam02074198 & 0xfffffffc) >> (uRam02074198 & 3) * 8 |
       *(uint *)(uRam02074198 & 0xfffffffc) << (uRam02074198 & 3) * -8 + 0x20);
  uVar4 = puVar2[1];
  uVar5 = puVar2[2];
  *(undefined4 *)(uVar6 + 0xc0) = *puVar2;
  *(undefined4 *)(uVar6 + 0xc4) = uVar4;
  *(undefined4 *)(uVar6 + 200) = uVar5;
  *(undefined4 *)(uVar6 + 0x134) = *(undefined4 *)(uVar6 + 0x24);
  *(undefined4 *)(uVar6 + 0x138) = *(undefined4 *)(uVar6 + 0x28);
  *(undefined4 *)(uVar6 + 0x13c) = *(undefined4 *)(uVar6 + 0x2c);
  uVar3 = uRam02074190;
  *(undefined4 *)(uVar6 + 0x88) = 0x1000;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(undefined4 *)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 0x248) = 0;
  func_020d4f94(uVar6 + 0x30);
  func_020d50c4();
  return;
}

