/* Decompiled C draft; module arm9; ROM address 02093484. No matching claim. */
#include "types.h"
#include "deps/02093484_func_02093484.h"

void func_02093484(uint param_1)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  if (param_1 == 0) {
    return;
  }
  iVar9 = 0;
  uVar1 = *puRam020935f0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar9) {
      return;
    }
    uVar8 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar9 * 4;
    uVar6 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
    if (uVar8 == 0) break;
    uVar6 = uVar8 + 0x9c & 3;
    uVar5 = *(uint *)(uVar8 + 0x9c & 0xfffffffc);
    uVar7 = uVar8 + 0x5c & 3;
    uVar3 = *(uint *)(uVar8 + 0x5c & 0xfffffffc);
    uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 4;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(uint *)(uVar8 + 8) =
         (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) -
         (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
    uVar6 = uVar8 + 0x9c & 3;
    uVar7 = *(uint *)(uVar8 + 0x9c & 0xfffffffc);
    uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    if (*(short *)(uVar6 + 0x26) < 0) {
      *(short *)(uVar8 + 0xb8) = (short)uRam020935f4;
    }
    else {
      func_020d7da8(uVar8 + 0xb0,uVar6,0);
      uVar6 = uVar8 + 0x9c & 3;
      uVar7 = *(uint *)(uVar8 + 0x9c & 0xfffffffc);
      iVar4 = (int)*(short *)((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x2e) << 0xc;
      iVar4 = (int)((longlong)iRam020935f8 * (longlong)iVar4 >> 0x25) - (iVar4 >> 0x1f);
      *(int *)(uVar8 + 0xb4) = iVar4;
      uVar6 = uVar8 + 0xb0 & 3;
      uVar7 = *(uint *)(uVar8 + 0xb0 & 0xfffffffc);
      uVar5 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      uVar6 = uVar8 + 0xbc & 3;
      uVar3 = *(uint *)(uVar8 + 0xbc & 0xfffffffc);
      uVar7 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar6 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) * 0x54 +
              (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 0x34;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      lVar2 = (longlong)iVar4 * (longlong)(int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20);
      *(uint *)(uVar8 + 0xc0) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    }
    uVar6 = uVar8 + 0x9c & 3;
    uVar7 = *(uint *)(uVar8 + 0x9c & 0xfffffffc);
    uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    if (((*(short *)(uVar6 + 0x28) == 0) && (*(short *)(uVar6 + 0x2a) == 0)) &&
       (*(short *)(uVar6 + 0x2c) == 0)) {
      *(undefined4 *)(uVar8 + 0xa8) = 0x1000;
      *(undefined4 *)(uVar8 + 0xac) = 4;
      *(ushort *)(uVar8 + 2) = *(ushort *)(uVar8 + 2) & 0xfffe;
    }
    else {
      uVar6 = uVar8 + 0xa0 & 3;
      uVar7 = *(uint *)(uVar8 + 0xa0 & 0xfffffffc);
      *(uint *)(uVar8 + 0xa0) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 1;
      uVar6 = uVar8 + 0x9c & 3;
      uVar5 = *(uint *)(uVar8 + 0x9c & 0xfffffffc);
      uVar7 = uVar8 + 0xa0 & 3;
      uVar3 = *(uint *)(uVar8 + 0xa0 & 0xfffffffc);
      if ((int)*(short *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x2c) <=
          (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
        *(undefined4 *)(uVar8 + 0xa0) = 0;
        *(undefined4 *)(uVar8 + 0xac) = 1;
        *(ushort *)(uVar8 + 2) = *(ushort *)(uVar8 + 2) | uVar1;
        *(undefined4 *)(uVar8 + 0x5c) = 0;
      }
    }
    iVar9 = iVar9 + 1;
  }
  return;
}

