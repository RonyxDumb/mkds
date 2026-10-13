/* Decompiled C draft; module arm9; ROM address 02040750. No matching claim. */
#include "types.h"
#include "deps/02040750_StructRC_SomeFn_2.h"

void StructRC_SomeFn_2(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  bool bVar7;
  
  uVar1 = uRam020408e4;
  uVar4 = *(uint *)(uRam020408e4 & 0xfffffffc) >> (uRam020408e4 & 3) * 8 |
          *(uint *)(uRam020408e4 & 0xfffffffc) << (uRam020408e4 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0x44;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  bVar7 = uVar2 == 0;
  if (bVar7) {
    uVar2 = 0;
  }
  if (bVar7) {
    *(short *)(param_1 + 0xe) = (short)uVar2;
    *(short *)((int)param_1 + 0x32) = (short)uVar2;
  }
  else {
    uVar4 = uVar4 + 0x4c;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(ushort *)(param_1 + 0xe) =
         (ushort)*(byte *)((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 7);
    uVar2 = uVar1 & 3;
    uVar4 = *(uint *)(uVar1 & 0xfffffffc);
    uVar2 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x4c;
    uVar4 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    *(short *)((int)param_1 + 0x32) =
         *(short *)(uVar2 + (uint)*(ushort *)(param_1 + 0xe) * 0xc) +
         *(short *)(uVar2 + (uint)*(ushort *)(param_1 + 0xe) * 0xc + 2) + -1;
  }
  iVar6 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0xb] = 0;
  *(undefined2 *)((int)param_1 + 0x3a) = 1;
  param_1[9] = 0;
  *param_1 = 0;
  uVar2 = uRam020408e4;
  *(undefined2 *)(param_1 + 0xc) = 0;
  *(short *)(param_1 + 0xd) =
       *(short *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                  *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x98) + -1;
  puVar5 = param_1 + 3;
  *(short *)((int)param_1 + 0x36) =
       *(short *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                  *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x98) + -1;
  *(ushort *)(param_1 + 0xf) = *(ushort *)(param_1 + 0xf) & 0xff0f | (ushort)((param_2 & 0xf) << 4);
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  *(undefined2 *)((int)param_1 + 0x3e) = 0;
  param_1[10] = 0;
  param_1[0x10] = 0;
  *(ushort *)(param_1 + 0xf) = *(ushort *)(param_1 + 0xf) & 0xfcff;
  uVar2 = uRam020408e8;
  do {
    uVar4 = uVar2 & 3;
    uVar3 = *(uint *)(uVar2 & 0xfffffffc);
    uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    MaybeConvertElapsedTime
              ((undefined1 *)(uintptr_t)((int)puVar5 + 2),(undefined1 *)(uintptr_t)((int)puVar5 + 3),(undefined2 *)(void *)(puVar5),0,
               uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
    iVar6 = iVar6 + 1;
    puVar5 = puVar5 + 1;
  } while (iVar6 < 5);
  uVar4 = *(uint *)(uRam020408e8 & 0xfffffffc) >> (uRam020408e8 & 3) * 8 |
          *(uint *)(uRam020408e8 & 0xfffffffc) << (uRam020408e8 & 3) * -8 + 0x20;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  MaybeConvertElapsedTime
            ((undefined1 *)(uintptr_t)((int)param_1 + 0x22),(undefined1 *)(uintptr_t)((int)param_1 + 0x23),(undefined2 *)(void *)(param_1 + 8),0,
             uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  if (param_2 ==
      (int)*(char *)((*(uint *)(uRam020408ec & 0xfffffffc) >> (uRam020408ec & 3) * 8 |
                     *(uint *)(uRam020408ec & 0xfffffffc) << (uRam020408ec & 3) * -8 + 0x20) + 0x62)
     ) {
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | 1;
  }
  *(ushort *)(param_1 + 0xf) =
       *(ushort *)(param_1 + 0xf) & 0xfff0 | (ushort)((param_2 + 1) * 0x10000 >> 0x10) & 0xf;
  return;
}

