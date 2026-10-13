/* Decompiled C draft; module arm9; ROM address 0209c4f0. No matching claim. */
#include "types.h"
#include "deps/0209c4f0_func_0209c4f0.h"

void func_0209c4f0(uint param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar5;
  
  uVar2 = uRam0209c5b4;
  if (param_1 == 0) {
    return;
  }
  iVar8 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar8) {
      return;
    }
    uVar7 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar8 * 4;
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
    if (uVar7 == 0) break;
    uVar5 = uVar7 + 0x9c & 3;
    uVar4 = *(uint *)(uVar7 + 0x9c & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    if (*(short *)(uVar5 + 0x26) < 0) {
      *(short *)(uVar7 + 0x100) = (short)uVar2;
    }
    else {
      func_020d7da8(uVar7 + 0xf8,uVar5,0);
      *(undefined4 *)(uVar7 + 0xfc) = 0x3000;
      uVar5 = uVar7 + 0xf8 & 3;
      uVar4 = *(uint *)(uVar7 + 0xf8 & 0xfffffffc);
      uVar3 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      uVar5 = uVar7 + 0x104 & 3;
      uVar6 = *(uint *)(uVar7 + 0x104 & 0xfffffffc);
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) * 0x54 +
              (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x34;
      uVar4 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      lVar1 = (ulonglong)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) * 0x3000;
      *(uint *)(uVar7 + 0x108) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    }
    iVar8 = iVar8 + 1;
  }
  return;
}

