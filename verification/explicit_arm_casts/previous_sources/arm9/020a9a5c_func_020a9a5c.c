/* Decompiled C draft; module arm9; ROM address 020a9a5c. No matching claim. */
#include "types.h"
#include "deps/020a9a5c_func_020a9a5c.h"

void func_020a9a5c(uint param_1)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  
  if (param_1 == 0) {
    return;
  }
  iVar10 = 0;
  uVar2 = *puRam020a9c3c;
  uVar3 = *puRam020a9c40;
  uVar4 = *puRam020a9c44;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar10) {
      return;
    }
    uVar9 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar10 * 4;
    uVar1 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar9 = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
    if (uVar9 == 0) break;
    *(ushort *)(uVar9 + 2) = *(ushort *)(uVar9 + 2) | uVar3;
    puVar12 = (undefined4 *)(uVar9 + 0x11c);
    *(ushort *)(uVar9 + 2) = *(ushort *)(uVar9 + 2) | uVar4;
    *(ushort *)(uVar9 + 2) = *(ushort *)(uVar9 + 2) | uVar2;
    uVar1 = uVar9 + 0x9c & 3;
    uVar6 = *(uint *)(uVar9 + 0x9c & 0xfffffffc);
    iVar11 = *(short *)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x28) * 0xa000;
    *(int *)(uVar9 + 0xb4) =
         (int)((longlong)iRam020a9c48 * (longlong)iVar11 >> 0x25) - (iVar11 >> 0x1f);
    uVar1 = uVar9 + 0x9c & 3;
    uVar6 = *(uint *)(uVar9 + 0x9c & 0xfffffffc);
    iVar11 = *(short *)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x28) * 0x5000;
    *(int *)(uVar9 + 0xb8) =
         (int)((longlong)iRam020a9c48 * (longlong)iVar11 >> 0x25) - (iVar11 >> 0x1f);
    uVar1 = uVar9 + 0xb4 & 3;
    uVar6 = *(uint *)(uVar9 + 0xb4 & 0xfffffffc);
    *(uint *)(uVar9 + 0xb0) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
    uVar1 = uVar9 + 0x9c & 3;
    uVar6 = *(uint *)(uVar9 + 0x9c & 0xfffffffc);
    puVar5 = (undefined4 *)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
    uVar7 = puVar5[1];
    uVar8 = puVar5[2];
    *puVar12 = *puVar5;
    *(undefined4 *)(uVar9 + 0x120) = uVar7;
    *(undefined4 *)(uVar9 + 0x124) = uVar8;
    *(undefined4 *)(uVar9 + 4) = *puVar12;
    *(undefined4 *)(uVar9 + 8) = *(undefined4 *)(uVar9 + 0x120);
    *(undefined4 *)(uVar9 + 0xc) = *(undefined4 *)(uVar9 + 0x124);
    uVar1 = uVar9 + 0x120 & 3;
    uVar6 = *(uint *)(uVar9 + 0x120 & 0xfffffffc);
    *(uint *)(uVar9 + 0x120) = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x1000;
    uVar1 = uVar9 + 0x58 & 3;
    uVar6 = *(uint *)(uVar9 + 0x58 & 0xfffffffc);
    func_020e516c(uVar9 + 0xe8,puVar12,(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) << 1,0x1c);
    func_020d2450(uVar9);
    uVar1 = uVar9 + 0x9c & 3;
    uVar6 = *(uint *)(uVar9 + 0x9c & 0xfffffffc);
    func_020d7da8(uVar9 + 0xc4,uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,0);
    func_020d8918(uVar9 + 0xc4,uVar9 + 0x11c,uVar9 + 0x10);
    uVar1 = uVar9 + 0x120 & 3;
    uVar6 = *(uint *)(uVar9 + 0x120 & 0xfffffffc);
    *(uint *)(uVar9 + 0x120) = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x1000;
    uVar1 = uVar9 + 0x58 & 3;
    uVar6 = *(uint *)(uVar9 + 0x58 & 0xfffffffc);
    VecFx32_AddScale1(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,uVar9 + 0x34,uVar9 + 0x11c,
                      uVar9 + 4);
    if ((*(ushort *)(uVar9 + 2) & 0x800) == 0) {
      uVar1 = uVar9 + 0x9c & 3;
      uVar6 = *(uint *)(uVar9 + 0x9c & 0xfffffffc);
      iVar11 = *(short *)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x2a) + iRam020a9c4c;
      *(int *)(uVar9 + 0xac) =
           ((int)((longlong)iRam020a9c50 * (longlong)iVar11 >> 0x27) - (iVar11 >> 0x1f)) + 1;
      *(undefined4 *)(uVar9 + 0x130) = 0;
    }
    else {
      uVar1 = uVar9 + 0x9c & 3;
      uVar6 = *(uint *)(uVar9 + 0x9c & 0xfffffffc);
      *(uint *)(uVar9 + 0xa8) =
           (uint)*(ushort *)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x2a);
      *(undefined4 *)(uVar9 + 0x130) = 0;
    }
    iVar10 = iVar10 + 1;
  }
  return;
}

