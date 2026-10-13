/* Decompiled C draft; module arm9; ROM address 02076a5c. No matching claim. */
#include "types.h"
#include "deps/02076a5c_func_02076a5c.h"

void func_02076a5c(void)

{
  longlong lVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined1 auStack_48 [24];
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  iVar3 = GetDriverEntry((int)*(char *)((*(uint *)(uRam02076bb8 & 0xfffffffc) >>
                                         (uRam02076bb8 & 3) * 8 |
                                        *(uint *)(uRam02076bb8 & 0xfffffffc) <<
                                        (uRam02076bb8 & 3) * -8 + 0x20) + 0x62));
  StructHD_SomeFn((undefined4 *)(uintptr_t)(*(uint *)(uRam02076bbc & 0xfffffffc) >> (uRam02076bbc & 3) * 8 |
                  *(uint *)(uRam02076bbc & 0xfffffffc) << (uRam02076bbc & 3) * -8 + 0x20));
  uVar5 = *(uint *)(uRam02076bb8 & 0xfffffffc) >> (uRam02076bb8 & 3) * 8 |
          *(uint *)(uRam02076bb8 & 0xfffffffc) << (uRam02076bb8 & 3) * -8 + 0x20;
  uVar4 = uVar5 + 8;
  uVar6 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) == 4) &&
     ((*(ushort *)(uVar5 + 0x44) & 0x20) != 0)) {
    *(undefined4 *)
     ((*(uint *)(uRam02076bbc & 0xfffffffc) >> (uRam02076bbc & 3) * 8 |
      *(uint *)(uRam02076bbc & 0xfffffffc) << (uRam02076bbc & 3) * -8 + 0x20) + 0xf0) = 0xfffff000;
  }
  uVar5 = *(uint *)(uRam02076bbc & 0xfffffffc) >> (uRam02076bbc & 3) * 8 |
          *(uint *)(uRam02076bbc & 0xfffffffc) << (uRam02076bbc & 3) * -8 + 0x20;
  func_01ffccd0((int *)(void *)(auStack_48),iVar3 + 0xe0);
  uVar4 = uVar5 + 0xf0 & 3;
  uVar6 = *(uint *)(uVar5 + 0xf0 & 0xfffffffc);
  lVar1 = (longlong)
          (int)-(*(uint *)(uRam02076bc0 & 0xfffffffc) >> (uRam02076bc0 & 3) * 8 |
                *(uint *)(uRam02076bc0 & 0xfffffffc) << (uRam02076bc0 & 3) * -8 + 0x20) *
          (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0x800;
  uVar4 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  local_1c = (uint)((longlong)local_28 * (longlong)(int)uVar4) >> 0xc |
             (int)((ulonglong)((longlong)local_28 * (longlong)(int)uVar4) >> 0x20) << 0x14;
  local_24 = (uint)((longlong)local_30 * (longlong)(int)uVar4) >> 0xc |
             (int)((ulonglong)((longlong)local_30 * (longlong)(int)uVar4) >> 0x20) << 0x14;
  local_20 = (uint)((longlong)local_2c * (longlong)(int)uVar4) >> 0xc |
             (int)((ulonglong)((longlong)local_2c * (longlong)(int)uVar4) >> 0x20) << 0x14;
  VecFx32_Add(iVar3 + 0x80,(uint)(uintptr_t)(&local_24),(int *)(uintptr_t)(uVar5 + 0x24));
  puVar2 = puRam02076bc8;
  uVar4 = uVar5 + 0x28 & 3;
  uVar6 = *(uint *)(uVar5 + 0x28 & 0xfffffffc);
  *(uint *)(uVar5 + 0x28) =
       (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) +
       (*(uint *)(uRam02076bc4 & 0xfffffffc) >> (uRam02076bc4 & 3) * 8 |
       *(uint *)(uRam02076bc4 & 0xfffffffc) << (uRam02076bc4 & 3) * -8 + 0x20);
  uVar7 = puVar2[1];
  uVar9 = puVar2[2];
  *(undefined4 *)(uVar5 + 0xc0) = *puVar2;
  *(undefined4 *)(uVar5 + 0xc4) = uVar7;
  *(undefined4 *)(uVar5 + 200) = uVar9;
  *(undefined4 *)(uVar5 + 0x134) = *(undefined4 *)(uVar5 + 0x24);
  *(undefined4 *)(uVar5 + 0x138) = *(undefined4 *)(uVar5 + 0x28);
  *(undefined4 *)(uVar5 + 0x13c) = *(undefined4 *)(uVar5 + 0x2c);
  uVar6 = uRam02076bbc;
  *(undefined4 *)(uVar5 + 0x88) = 0x1000;
  uVar4 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(undefined4 *)((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0x248) = 0;
  func_020d4f94(uVar5 + 0x30);
  func_020d50c4();
  uVar6 = iVar3 + 0x84U & 3;
  uVar8 = *(uint *)(iVar3 + 0x84U & 0xfffffffc);
  uVar10 = *(uint *)(uRam02076bbc & 0xfffffffc) >> (uRam02076bbc & 3) * 8 |
           *(uint *)(uRam02076bbc & 0xfffffffc) << (uRam02076bbc & 3) * -8 + 0x20;
  uVar4 = uVar10 + 0xd4;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(uVar10 + 0x1c) =
       (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) +
       (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  return;
}

