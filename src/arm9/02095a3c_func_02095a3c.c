/* Decompiled C draft; module arm9; ROM address 02095a3c. No matching claim. */
#include "types.h"
#include "deps/02095a3c_func_02095a3c.h"

void func_02095a3c(undefined4 param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uVar3;
  
  uVar3 = param_2 + 0xd8U & 3;
  uVar2 = *(uint *)(param_2 + 0xd8U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    if (uVar3 != 1) {
      return;
    }
    uVar3 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar7 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    *(uint *)(param_2 + 0xb8) = uVar7;
    uVar3 = param_2 + 0xb4U & 3;
    uVar2 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = param_2 + 0xc0U & 3;
    uVar6 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar3 = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) * 0x54 +
            (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x34;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    lVar1 = (longlong)(int)uVar7 * (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    *(uint *)(param_2 + 0xc4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    iVar5 = func_020d8cc8(param_2 + 0xb4);
    if (iVar5 != 0) {
      uVar3 = param_2 + 0xd0U & 3;
      uVar2 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
      *(uint *)(param_2 + 0xa0) =
           (uint)*(ushort *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0xe);
      *(undefined4 *)(param_2 + 0xd8) = 0;
    }
    func_020d879c(param_2 + 0xb4,(uint *)(uintptr_t)(param_2 + 4));
    uVar3 = param_2 + 0x78U & 3;
    uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
    if ((int)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x3fffffe0) < iRam02095d0c) {
      uVar3 = param_2 + 0xa4U & 3;
      uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      *(uint *)(param_2 + 0xa4) = uVar3 - 1;
      if ((int)uVar3 < 1) {
        *(undefined4 *)(param_2 + 0xb0) = 1;
      }
      else {
        *(undefined4 *)(param_2 + 0xb0) = 2;
      }
      uVar2 = uRam02095d10;
      uVar3 = param_2 + 0xb0U & 3;
      uVar4 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      *(ushort *)(param_2 + 0xac) =
           *(short *)(param_2 + 0xac) +
           ((ushort)(uVar4 >> uVar3 * 8) | (ushort)(uVar4 << uVar3 * -8 + 0x20));
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar3 = StructMapObject_GetAnimationBCAFrameCount
                        (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
      if (uVar3 <= *(ushort *)(param_2 + 0xac)) {
        *(undefined2 *)(param_2 + 0xac) = 0;
      }
      if ((*(short *)(param_2 + 0xac) != 0) && (*(short *)(param_2 + 0xac) != 0x1e)) {
        return;
      }
      uVar3 = param_2 + 0x78U & 3;
      uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
      if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) == 0) {
        uVar3 = param_2 + 0x70U & 3;
        uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
        uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
        uVar3 = iRam02095d14 + 0x68U & 3;
        uVar2 = *(uint *)(iRam02095d14 + 0x68U & 0xfffffffc);
        if (uVar4 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
          uStack_10 = 2;
        }
        else {
          uVar3 = iRam02095d14 + 0x8cU & 3;
          uVar2 = *(uint *)(iRam02095d14 + 0x8cU & 0xfffffffc);
          if (uVar4 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
            uStack_10 = 3;
          }
          else {
            uStack_10 = 4;
          }
        }
        iStack_14 = param_2 + 4;
        uStack_18 = uRam02095d18;
        uStack_c = func_020d4ef4();
        func_0210b7a8((uint)(uintptr_t)(&uStack_18));
        return;
      }
      return;
    }
    return;
  }
  *(undefined4 *)(param_2 + 0xb8) = 0;
  *(undefined4 *)(param_2 + 0xc4) = 0;
  uVar3 = param_2 + 0xa0U & 3;
  uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  *(uint *)(param_2 + 0xa0) = uVar3 - 1;
  if ((int)uVar3 < 1) {
    *(undefined4 *)(param_2 + 0xd8) = 1;
  }
  uVar3 = param_2 + 0x78U & 3;
  uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
  if (iRam02095d0c <= (int)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x3fffffe0)) {
    return;
  }
  uVar3 = param_2 + 0xa4U & 3;
  uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  *(uint *)(param_2 + 0xa4) = uVar2 - 1;
  uVar3 = uRam02095d10;
  if (0 < (int)uVar2) {
    *(undefined4 *)(param_2 + 0xb0) = 2;
    uVar2 = uRam02095d10;
    uVar3 = param_2 + 0xb0U & 3;
    uVar4 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    *(ushort *)(param_2 + 0xac) =
         *(short *)(param_2 + 0xac) +
         ((ushort)(uVar4 >> uVar3 * 8) | (ushort)(uVar4 << uVar3 * -8 + 0x20));
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar3 = StructMapObject_GetAnimationBCAFrameCount
                      (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
    if (uVar3 <= *(ushort *)(param_2 + 0xac)) {
      *(undefined2 *)(param_2 + 0xac) = 0;
    }
    return;
  }
  if (*(short *)(param_2 + 0xac) != 0) {
    uVar2 = param_2 + 0xb0U & 3;
    uVar4 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    *(ushort *)(param_2 + 0xac) =
         *(short *)(param_2 + 0xac) +
         ((ushort)(uVar4 >> uVar2 * 8) | (ushort)(uVar4 << uVar2 * -8 + 0x20));
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = StructMapObject_GetAnimationBCAFrameCount
                      (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    if (uVar3 <= *(ushort *)(param_2 + 0xac)) {
      *(undefined2 *)(param_2 + 0xac) = 0;
    }
    if ((*(short *)(param_2 + 0xac) != 0) && (*(short *)(param_2 + 0xac) != 0x1e)) {
      return;
    }
    uVar3 = param_2 + 0x78U & 3;
    uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) == 0) {
      uVar3 = param_2 + 0x70U & 3;
      uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
      uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar3 = iRam02095d14 + 0x68U & 3;
      uVar2 = *(uint *)(iRam02095d14 + 0x68U & 0xfffffffc);
      if (uVar4 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
        uStack_20 = 2;
      }
      else {
        uVar3 = iRam02095d14 + 0x8cU & 3;
        uVar2 = *(uint *)(iRam02095d14 + 0x8cU & 0xfffffffc);
        if (uVar4 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
          uStack_20 = 3;
        }
        else {
          uStack_20 = 4;
        }
      }
      iStack_24 = param_2 + 4;
      uStack_28 = uRam02095d18;
      uStack_1c = func_020d4ef4();
      func_0210b7a8((uint)(uintptr_t)(&uStack_28));
      return;
    }
    return;
  }
  return;
}

