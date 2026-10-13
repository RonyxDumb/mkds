/* Decompiled C draft; module arm9; ROM address 02093270. No matching claim. */
#include "types.h"
#include "deps/02093270_func_02093270.h"

void func_02093270(undefined4 param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar3 = param_2 + 0xacU & 3;
  uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  switch(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) {
  case 0:
    uVar3 = param_2 + 0xa0U & 3;
    uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    *(uint *)(param_2 + 0xa0) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 1;
    uVar3 = param_2 + 0x9cU & 3;
    uVar5 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
    uVar2 = param_2 + 0xa0U & 3;
    uVar4 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    if ((int)*(short *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x2a) <=
        (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xa0) = 0;
      *(undefined4 *)(param_2 + 0xac) = 1;
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffe;
    }
    break;
  case 1:
    uVar3 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *(uint *)(param_2 + 0xa8) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x7b;
    uVar3 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    if (0xfff < (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xa8) = 0x1000;
      *(undefined4 *)(param_2 + 0xac) = 2;
    }
    uVar3 = param_2 + 0x98U & 3;
    uVar5 = *(uint *)(param_2 + 0x98U & 0xfffffffc);
    uVar2 = param_2 + 0xa8U & 3;
    uVar4 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar3 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x10;
    uVar5 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) *
            (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
    *(uint *)(param_2 + 0x5c) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    break;
  case 2:
    uVar3 = param_2 + 0xa0U & 3;
    uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    *(uint *)(param_2 + 0xa0) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 1;
    uVar3 = param_2 + 0x9cU & 3;
    uVar5 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
    uVar2 = param_2 + 0xa0U & 3;
    uVar4 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    if ((int)*(short *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x28) <=
        (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xa0) = 0;
      *(undefined4 *)(param_2 + 0xac) = 3;
    }
    func_020d275c(param_2,0x170);
    break;
  case 3:
    uVar3 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *(uint *)(param_2 + 0xa8) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0x29;
    uVar3 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 1) {
      *(undefined4 *)(param_2 + 0xa8) = 0;
      *(undefined4 *)(param_2 + 0xac) = 0;
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *DAT_02093474;
    }
    uVar3 = param_2 + 0x98U & 3;
    uVar5 = *(uint *)(param_2 + 0x98U & 0xfffffffc);
    uVar2 = param_2 + 0xa8U & 3;
    uVar4 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar3 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x10;
    uVar5 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) *
            (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
    *(uint *)(param_2 + 0x5c) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    break;
  case 4:
    func_020d275c(param_2,0x170);
  }
  uVar3 = StructMapObject_SomeFn_2
                    (*(uint *)(DAT_02093478 & 0xfffffffc) >> (DAT_02093478 & 3) * 8 |
                     *(uint *)(DAT_02093478 & 0xfffffffc) << (DAT_02093478 & 3) * -8 + 0x20);
  *(short *)(param_2 + 0xa4) = *(short *)(param_2 + 0xa4) + 1;
  if (uVar3 <= *(ushort *)(param_2 + 0xa4)) {
    *(undefined2 *)(param_2 + 0xa4) = 0;
  }
  if (*(ushort *)(param_2 + 0xb8) == DAT_0209347c) {
    uVar3 = param_2 + 0x9cU & 3;
    uVar5 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
    uVar2 = param_2 + 0x5cU & 3;
    uVar4 = *(uint *)(param_2 + 0x5cU & 0xfffffffc);
    uVar3 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 4;
    uVar5 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(param_2 + 8) =
         (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) -
         (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  }
  else {
    func_020d8cc8(param_2 + 0xb0);
    func_020d8a5c(param_2 + 0xb0,(uint *)(uintptr_t)(param_2 + 4));
    uVar3 = param_2 + 8U & 3;
    uVar4 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar2 = param_2 + 0x5cU & 3;
    uVar5 = *(uint *)(param_2 + 0x5cU & 0xfffffffc);
    *(uint *)(param_2 + 8) =
         (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) -
         (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
  }
  iVar7 = 0;
  uVar3 = (uint)*(byte *)((*(uint *)(DAT_02093480 & 0xfffffffc) >> (DAT_02093480 & 3) * 8 |
                          *(uint *)(DAT_02093480 & 0xfffffffc) << (DAT_02093480 & 3) * -8 + 0x20) +
                         0x3d0);
  if (uVar3 == 0) {
    return;
  }
  do {
    iVar6 = param_2 + iVar7 * 4;
    uVar2 = iVar6 + 0xd4;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    iVar7 = iVar7 + 1;
    if (0 < (int)uVar2) {
      *(uint *)(iVar6 + 0xd4) = uVar2 - 1;
    }
  } while (iVar7 < (int)uVar3);
  return;
}

