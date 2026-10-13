/* Decompiled C draft; module arm9; ROM address 020a0064. No matching claim. */
#include "types.h"
#include "deps/020a0064_func_020a0064.h"

void func_020a0064(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  if (param_1 == 0) {
    return;
  }
  iVar7 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar7) {
      return;
    }
    uVar6 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar7 * 4;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    if (uVar6 == 0) break;
    uVar5 = uVar6 + 0x9c & 3;
    uVar2 = *(uint *)(uVar6 + 0x9c & 0xfffffffc);
    func_020d7da8(uVar6 + 200,uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20,0);
    uVar5 = uVar6 + 0x9c & 3;
    uVar2 = *(uint *)(uVar6 + 0x9c & 0xfffffffc);
    iVar3 = *(short *)((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x28) * 0x5000;
    *(int *)(uVar6 + 0xa4) =
         (int)((longlong)iRam020a0188 * (longlong)iVar3 >> 0x25) - (iVar3 >> 0x1f);
    uVar5 = uVar6 + 0xa4 & 3;
    uVar2 = *(uint *)(uVar6 + 0xa4 & 0xfffffffc);
    uVar8 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    *(uint *)(uVar6 + 0xcc) = uVar8;
    uVar5 = uVar6 + 200 & 3;
    uVar2 = *(uint *)(uVar6 + 200 & 0xfffffffc);
    uVar4 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    uVar5 = uVar6 + 0xd4 & 3;
    uVar9 = *(uint *)(uVar6 + 0xd4 & 0xfffffffc);
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar5 = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) * 0x54 +
            (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x34;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    lVar1 = (longlong)(int)uVar8 * (longlong)(int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
    *(uint *)(uVar6 + 0xd8) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar5 = uVar6 + 8 & 3;
    uVar2 = *(uint *)(uVar6 + 8 & 0xfffffffc);
    *(uint *)(uVar6 + 0xa0) = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    func_020d8bf8(uVar6 + 200,uVar6 + 4,uVar6 + 0x10);
    uVar5 = uVar6 + 0xa0 & 3;
    uVar8 = *(uint *)(uVar6 + 0xa0 & 0xfffffffc);
    uVar2 = uVar6 + 8 & 3;
    uVar4 = *(uint *)(uVar6 + 8 & 0xfffffffc);
    iVar7 = iVar7 + 1;
    *(uint *)(uVar6 + 0xa0) =
         (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) -
         (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
    *(undefined2 *)(uVar6 + 0xa8) = 0;
    *(undefined4 *)(uVar6 + 0xb4) = 0;
    *(undefined4 *)(uVar6 + 0xb8) = 0x50000;
    *(undefined4 *)(uVar6 + 0xbc) = 0;
    *(undefined4 *)(uVar6 + 0xc0) = 0xb6;
    *(undefined4 *)(uVar6 + 0xc4) = 0;
    uVar5 = uVar6 + 0x9c & 3;
    uVar2 = *(uint *)(uVar6 + 0x9c & 0xfffffffc);
    if (*(short *)((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x2a) == 0) {
      *(undefined4 *)(uVar6 + 0xec) = 2;
    }
    else {
      *(undefined4 *)(uVar6 + 0xec) = 0;
    }
  }
  return;
}

