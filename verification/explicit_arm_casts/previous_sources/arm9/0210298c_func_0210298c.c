/* Decompiled C draft; module arm9; ROM address 0210298c. No matching claim. */
#include "types.h"
#include "deps/0210298c_func_0210298c.h"

void func_0210298c(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  uVar6 = param_1 + 300U & 3;
  uVar11 = *(uint *)(param_1 + 300U & 0xfffffffc);
  uVar12 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
  iVar3 = GetGlobalHD5();
  uVar6 = param_1 + 0x11cU & 3;
  uVar11 = *(uint *)(param_1 + 0x11cU & 0xfffffffc);
  uVar6 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
  if (uVar6 == 0x3f) {
    func_021031f4(param_1);
  }
  if (uVar6 == 0x8f) {
    iVar10 = 0;
    uVar11 = (uint)*(byte *)((*(uint *)(uRam02102e60 & 0xfffffffc) >> (uRam02102e60 & 3) * 8 |
                             *(uint *)(uRam02102e60 & 0xfffffffc) << (uRam02102e60 & 3) * -8 + 0x20)
                            + 0x3d0);
    if (uVar11 != 0) {
      do {
        if ((((*(char *)(param_1 + iVar10 + 0x130) != '\0') &&
             (iVar4 = GetDriverEntry(iVar10), uVar5 = iVar4 + 0x7cU & 3,
             uVar7 = *(uint *)(iVar4 + 0x7cU & 0xfffffffc),
             ((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) & uRam02102e64) == 0)) &&
            (uVar5 = iVar4 + 0x4cU & 3, uVar7 = *(uint *)(iVar4 + 0x4cU & 0xfffffffc),
            ((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) & uRam02102e68) == 0)) &&
           (uVar5 = iVar4 + 0x48U & 3, uVar7 = *(uint *)(iVar4 + 0x48U & 0xfffffffc),
           ((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) & 0x10000) == 0)) {
          StructMQRacerEntry_SomeFn_38(iVar4,*(undefined1 *)(param_1 + iVar10 + 0x130));
          func_020f8e3c(iVar4,0xf0);
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)uVar11);
    }
  }
  uVar11 = param_1 + 0x160U & 3;
  uVar5 = *(uint *)(param_1 + 0x160U & 0xfffffffc);
  if (uVar5 >> uVar11 * 8 != 0 || uVar5 << uVar11 * -8 + 0x20 != 0) {
    if ((int)uVar6 <=
        (int)(*(uint *)(uRam02102e6c & 0xfffffffc) >> (uRam02102e6c & 3) * 8 |
             *(uint *)(uRam02102e6c & 0xfffffffc) << (uRam02102e6c & 3) * -8 + 0x20)) {
      return;
    }
    uVar6 = param_1 + 0x44U & 3;
    uVar11 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    func_020f0f70((uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) * 0x44 +
                  (*(uint *)(uRam02102e70 & 0xfffffffc) >> (uRam02102e70 & 3) * 8 |
                  *(uint *)(uRam02102e70 & 0xfffffffc) << (uRam02102e70 & 3) * -8 + 0x20),param_1);
    return;
  }
  uVar6 = param_1 + 0x138U & 3;
  uVar11 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  uVar6 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
  if (((3 < (int)uVar6) && ((int)uVar6 < 0xd)) &&
     ((uVar6 = uVar12 + 0x7c & 3, uVar11 = *(uint *)(uVar12 + 0x7c & 0xfffffffc),
      ((uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) & uRam02102e64) != 0 ||
      ((uVar6 = uVar12 + 0x4c & 3, uVar11 = *(uint *)(uVar12 + 0x4c & 0xfffffffc),
       ((uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) & uRam02102e68) != 0 ||
       (uVar6 = uVar12 + 0x48 & 3, uVar11 = *(uint *)(uVar12 + 0x48 & 0xfffffffc),
       ((uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) & 0x10000) != 0)))))) {
    *(undefined4 *)(param_1 + 0x138) = 0xd;
    func_0210300c(param_1);
    uVar6 = param_1 + 0x198U & 3;
    uVar11 = *(uint *)(param_1 + 0x198U & 0xfffffffc);
    if (uVar11 >> uVar6 * 8 != 0 || uVar11 << uVar6 * -8 + 0x20 != 0) {
      func_020f8e3c(uVar12,0xf3);
    }
  }
  uVar6 = uVar12 + 0x4c & 3;
  uVar11 = *(uint *)(uVar12 + 0x4c & 0xfffffffc);
  if (((uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) & 0x800) != 0) {
    *(undefined4 *)(param_1 + 0x160) = 1;
    *(undefined4 *)(param_1 + 0x198) = 0;
  }
  uVar6 = param_1 + 0x148U & 3;
  uVar11 = *(uint *)(param_1 + 0x148U & 0xfffffffc);
  uVar6 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
  if ((((*(short *)(param_1 + 0xd8) < 0x1f) &&
       (uVar11 = param_1 + 0x194U & 3, uVar12 = *(uint *)(param_1 + 0x194U & 0xfffffffc),
       uVar12 >> uVar11 * 8 == 0 && uVar12 << uVar11 * -8 + 0x20 == 0)) &&
      (uVar11 = param_1 + 0x198U & 3, uVar12 = *(uint *)(param_1 + 0x198U & 0xfffffffc),
      uVar12 >> uVar11 * 8 != 0 || uVar12 << uVar11 * -8 + 0x20 != 0)) &&
     (*(short *)(param_1 + 0xd8) = *(short *)(param_1 + 0xd8) + 7, 0x1f < *(short *)(param_1 + 0xd8)
     )) {
    *(undefined2 *)(param_1 + 0xd8) = 0x1f;
  }
  uVar11 = param_1 + 0x16cU & 3;
  uVar12 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
  *(uint *)(param_1 + 0x16c) = (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) - 1;
  uVar11 = param_1 + 0x16cU & 3;
  uVar12 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
  if ((int)(uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) < 1) {
    uVar11 = param_1 + 0x168U & 3;
    uVar12 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
    uVar5 = uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20;
    uVar11 = param_1 + 0x148U & 3;
    uVar12 = *(uint *)(param_1 + 0x148U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) *
            (longlong)(int)uVar5;
    *(uint *)(param_1 + 0x148) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar11 = param_1 + 0x14cU & 3;
    uVar12 = *(uint *)(param_1 + 0x14cU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) *
            (longlong)(int)uVar5;
    *(uint *)(param_1 + 0x14c) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar11 = param_1 + 0x194U & 3;
    uVar12 = *(uint *)(param_1 + 0x194U & 0xfffffffc);
    if (uVar12 >> uVar11 * 8 != 0 || uVar12 << uVar11 * -8 + 0x20 != 0) {
      uVar11 = param_1 + 0x170U & 3;
      uVar12 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
      *(ushort *)(param_1 + 0xd8) =
           *(short *)(param_1 + 0xd8) -
           ((ushort)(uVar12 >> uVar11 * 8) | (ushort)(uVar12 << uVar11 * -8 + 0x20));
      if (*(short *)(param_1 + 0xd8) < 1) {
        uVar11 = param_1 + 0x170U & 3;
        uVar12 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
        *(uint *)(param_1 + 0x16c) = -1 - (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20);
        *(undefined4 *)(param_1 + 0x198) = 0;
        *(undefined2 *)(param_1 + 0xd8) = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x16c) = 0;
      }
    }
    uVar11 = param_1 + 0x170U & 3;
    uVar12 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
    uVar12 = uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20;
    uVar11 = param_1 + 0x16cU & 3;
    uVar5 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
    uVar11 = uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20;
    if (((int)(uVar11 + uVar12) < 0 != SBORROW4(uVar11,-uVar12)) &&
       (iVar10 = func_0210300c(param_1), iVar10 != 0)) {
      *(undefined4 *)(param_1 + 0x160) = 1;
      *(undefined4 *)(param_1 + 0x198) = 0;
      return;
    }
  }
  else {
    uVar11 = param_1 + 0x148U & 3;
    uVar12 = *(uint *)(param_1 + 0x148U & 0xfffffffc);
    uVar7 = uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20;
    uVar11 = param_1 + 0x154U & 3;
    uVar5 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
    uVar12 = param_1 + 0x164U & 3;
    uVar8 = *(uint *)(param_1 + 0x164U & 0xfffffffc);
    uVar8 = uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20;
    lVar1 = (longlong)(int)uVar8 *
            (longlong)(int)((uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20) - uVar7);
    uVar11 = param_1 + 0x158U & 3;
    uVar9 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
    uVar12 = param_1 + 0x14cU & 3;
    uVar5 = *(uint *)(param_1 + 0x14cU & 0xfffffffc);
    lVar2 = (longlong)(int)uVar8 *
            (longlong)
            (int)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) -
                 (uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20));
    *(uint *)(param_1 + 0x148) =
         uVar7 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar11 = param_1 + 0x14cU & 3;
    uVar12 = *(uint *)(param_1 + 0x14cU & 0xfffffffc);
    *(uint *)(param_1 + 0x14c) =
         (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) +
         ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
  }
  lVar1 = (ulonglong)uRam02102e74 * (ulonglong)uVar6;
  iVar10 = ((int)uVar6 >> 0x1f) * uRam02102e74;
  uVar6 = param_1 + 0x13cU & 3;
  uVar5 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
  uVar11 = param_1 + 0x148U & 3;
  uVar12 = *(uint *)(param_1 + 0x148U & 0xfffffffc);
  *(uint *)(param_1 + 0x13c) =
       (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) +
       (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20);
  uVar6 = param_1 + 0x140U & 3;
  uVar5 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  uVar11 = param_1 + 0x14cU & 3;
  uVar12 = *(uint *)(param_1 + 0x14cU & 0xfffffffc);
  *(uint *)(param_1 + 0x140) =
       (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) +
       (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20);
  uVar11 = uRam02102e80;
  uVar6 = param_1 + 0x148U & 3;
  uVar12 = *(uint *)(param_1 + 0x148U & 0xfffffffc);
  uVar6 = (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) -
          ((uint)lVar1 >> 0xc | (iVar10 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  lVar1 = (ulonglong)uRam02102e78 * (ulonglong)uVar6;
  uVar12 = (uint)lVar1 >> 0xc |
           (((int)uVar6 >> 0x1f) * uRam02102e78 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar6 = uRam02102e78;
  if (((int)uVar12 <= (int)uRam02102e78) && (uVar6 = uVar12, (int)uVar12 < (int)uRam02102e7c)) {
    uVar6 = uRam02102e7c;
  }
  uVar12 = param_1 + 0x19cU & 3;
  uVar5 = *(uint *)(param_1 + 0x19cU & 0xfffffffc);
  *(uint *)(param_1 + 0x19c) = (uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20) + uVar6;
  uVar6 = param_1 + 0x19cU & 3;
  uVar12 = *(uint *)(param_1 + 0x19cU & 0xfffffffc);
  uVar6 = uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar11 * (ulonglong)uVar6;
  *(uint *)(param_1 + 0x19c) =
       (uint)lVar1 >> 0xc |
       (((int)uVar6 >> 0x1f) * uVar11 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar6 = param_1 + 0x19cU & 3;
  uVar11 = *(uint *)(param_1 + 0x19cU & 0xfffffffc);
  uVar6 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
  if (iRam02102e84 < (int)uVar6) {
    *(int *)(param_1 + 0x19c) = iRam02102e84;
  }
  else if ((int)uVar6 < iRam02102e88) {
    *(int *)(param_1 + 0x19c) = iRam02102e88;
  }
  uVar6 = param_1 + 0x180U & 3;
  uVar11 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  uVar5 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x174U & 3;
  uVar12 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
  uVar11 = param_1 + 0x18cU & 3;
  uVar7 = *(uint *)(param_1 + 0x18cU & 0xfffffffc);
  uVar7 = uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar7 *
          (longlong)(int)((uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) - uVar5);
  uVar6 = param_1 + 0x178U & 3;
  uVar8 = *(uint *)(param_1 + 0x178U & 0xfffffffc);
  uVar11 = param_1 + 0x184U & 3;
  uVar12 = *(uint *)(param_1 + 0x184U & 0xfffffffc);
  lVar2 = (longlong)(int)uVar7 *
          (longlong)
          (int)((uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) -
               (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20));
  *(uint *)(param_1 + 0x180) =
       uVar5 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar6 = param_1 + 0x184U & 3;
  uVar11 = *(uint *)(param_1 + 0x184U & 0xfffffffc);
  *(uint *)(param_1 + 0x184) =
       (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
       ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
  iVar4 = *(int *)(param_1 + 0x144);
  uVar6 = param_1 + 0x19cU & 3;
  uVar11 = *(uint *)(param_1 + 0x19cU & 0xfffffffc);
  uVar6 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)
          (int)((uVar6 << 0xb) >> 0xc | (((int)uVar6 >> 0x1f) << 0xb | uVar6 >> 0x15) << 0x14) *
          (longlong)*(int *)(param_1 + 0x13c);
  uVar6 = iVar3 + 0xcU & 3;
  uVar11 = *(uint *)(iVar3 + 0xcU & 0xfffffffc);
  iVar10 = -(*(int *)(param_1 + 0x13c) -
            ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14));
  lVar1 = (longlong)(int)(uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) * (longlong)iVar10;
  *(uint *)(param_1 + 0x50) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = iVar3 + 0x10U & 3;
  uVar11 = *(uint *)(iVar3 + 0x10U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) * (longlong)iVar10;
  *(uint *)(param_1 + 0x54) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = iVar3 + 0x14U & 3;
  uVar11 = *(uint *)(iVar3 + 0x14U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) * (longlong)iVar10;
  *(uint *)(param_1 + 0x58) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  VecFx32_AddScale1(*(undefined4 *)(param_1 + 0x140),iVar3,param_1 + 0x50,param_1 + 0x50);
  VecFx32_AddScale1(-iVar4,iVar3 + 0x15c,param_1 + 0x50,param_1 + 0x50);
  VecFx32_Add(iVar3 + 0x24,param_1 + 0x50,param_1 + 0x50);
  return;
}

