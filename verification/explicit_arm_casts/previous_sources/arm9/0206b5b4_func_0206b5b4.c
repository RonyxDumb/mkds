/* Decompiled C draft; module arm9; ROM address 0206b5b4. No matching claim. */
#include "types.h"
#include "deps/0206b5b4_func_0206b5b4.h"

void func_0206b5b4(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  undefined1 auStack_48 [12];
  undefined1 auStack_3c [36];
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uVar4;
  
  if (*(short *)(param_1 + 0x35c) == 0) {
    *(undefined4 *)(param_1 + 0x2a8) = 0;
    uVar4 = param_1 + 0x318U & 3;
    uVar3 = *(uint *)(param_1 + 0x318U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if ((int)uVar4 < 1) {
      uVar4 = -uVar4;
    }
    if ((int)uVar4 < iRam0206b8f4) {
      uVar4 = param_1 + 0x360U & 3;
      uVar3 = *(uint *)(param_1 + 0x360U & 0xfffffffc);
      *(ushort *)(param_1 + 0x314) =
           *(short *)(param_1 + 0x314) -
           ((ushort)(uVar3 >> uVar4 * 8) | (ushort)(uVar3 << uVar4 * -8 + 0x20));
      uVar4 = param_1 + 0x318U & 3;
      uVar5 = *(uint *)(param_1 + 0x318U & 0xfffffffc);
      uVar3 = param_1 + 0x360U & 3;
      uVar2 = *(uint *)(param_1 + 0x360U & 0xfffffffc);
      *(uint *)(param_1 + 0x318) =
           (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
           (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
      uVar4 = param_1 + 0x360U & 3;
      uVar3 = *(uint *)(param_1 + 0x360U & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      if ((int)uVar4 < 0xc9) {
        *(undefined4 *)(param_1 + 0x360) = 200;
      }
      else {
        *(uint *)(param_1 + 0x360) =
             (uint)((ulonglong)uRam0206b8f8 * (ulonglong)uVar4) >> 0xc |
             (((int)uVar4 >> 0x1f) * uRam0206b8f8 +
             (int)((ulonglong)uRam0206b8f8 * (ulonglong)uVar4 >> 0x20)) * 0x100000;
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x314) = 0;
    }
    uVar4 = param_1 + 0x44U & 3;
    uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if ((((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x10000) != 0) &&
       (uVar4 = param_1 + 0x318U & 3, uVar3 = *(uint *)(param_1 + 0x318U & 0xfffffffc),
       (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) < 0x13000)) {
      uVar4 = param_1 + 0x260U & 3;
      uVar3 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
      *(uint *)(param_1 + 0x260) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x1800;
    }
    iVar1 = iRam0206b900;
    uVar4 = param_1 + 0x33cU & 3;
    uVar3 = *(uint *)(param_1 + 0x33cU & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if ((int)uVar4 < 1) {
      uVar4 = -uVar4;
    }
    if ((int)uVar4 < iRam0206b8fc) {
      *(short *)(param_1 + 0x338) = *(short *)(param_1 + 0x338) + 1000;
      uVar4 = param_1 + 0x33cU & 3;
      uVar3 = *(uint *)(param_1 + 0x33cU & 0xfffffffc);
      *(uint *)(param_1 + 0x33c) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 1000;
      *(int *)(param_1 + 0x334) =
           (int)*(short *)(iVar1 + ((int)(uint)*(ushort *)(param_1 + 0x338) >> 4) * 4);
    }
    else {
      *(undefined2 *)(param_1 + 0x338) = 0;
      *(undefined4 *)(param_1 + 0x334) = 0;
    }
    uVar4 = param_1 + 0x334U & 3;
    uVar3 = *(uint *)(param_1 + 0x334U & 0xfffffffc);
    iVar1 = (int)(iRam0206b904 * (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) >> 0xc & 0xffff)
            >> 4;
    func_02146f98(auStack_3c,param_1 + 0x328,(int)*(short *)(iRam0206b900 + iVar1 * 4),
                  (int)*(short *)(iRam0206b900 + (iVar1 * 2 + 1) * 2));
    MTX_MultVec33(param_1 + 0x31c,auStack_3c,auStack_48);
    func_01ffd190(auStack_48,*(undefined2 *)(param_1 + 0x314),param_1 + 0x34c);
  }
  else {
    local_18 = *puRam0206b908;
    uStack_14 = puRam0206b908[1];
    uStack_10 = puRam0206b908[2];
    uStack_c = puRam0206b908[3];
    func_01ffce48(param_1 + 0x34c,&local_18,param_1 + 0x34c,uRam0206b90c);
  }
  func_01ffcf7c(param_1 + 0x34c,param_1 + 0x34c);
  uVar4 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x80000000) != 0) {
    *(short *)(param_1 + 0x35c) = *(short *)(param_1 + 0x35c) + 1;
    if (0x1d < *(short *)(param_1 + 0x35c)) {
      *(undefined4 *)(param_1 + 0x180) = 0;
      uVar4 = param_1 + 0x4cU & 3;
      uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xffffffcf;
      uVar4 = param_1 + 0x48U & 3;
      uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x48) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffdffff;
      DriverContext_UpdateCharacterAnimation(param_1,0,1);
      uVar4 = param_1 + 0x44U & 3;
      uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      *(uint *)(param_1 + 0x44) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x80000000;
      uVar4 = param_1 + 0x7cU & 3;
      uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if (((((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 2) != 0) &&
          (uVar3 = *(uint *)(uRam0206b910 & 0xfffffffc) >> (uRam0206b910 & 3) * 8 |
                   *(uint *)(uRam0206b910 & 0xfffffffc) << (uRam0206b910 & 3) * -8 + 0x20,
          uVar4 = uVar3 + 8, uVar2 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
          (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) == 2)) &&
         (uVar3 = uVar3 + 0x18, uVar4 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
         uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0)) {
        uVar4 = param_1 + 0x310U & 3;
        uVar3 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
        func_02088c7c(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
      }
      uVar4 = param_1 + 0x4cU & 3;
      uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x7fffffef;
      uVar4 = param_1 + 0x44U & 3;
      uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x10) != 0) {
        *(undefined2 *)(param_1 + 0x388) = 0;
      }
      return;
    }
    return;
  }
  uVar4 = param_1 + 0x348U & 3;
  uVar3 = *(uint *)(param_1 + 0x348U & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) < 3) ||
     ((uVar4 = param_1 + 0x340U & 3, uVar5 = *(uint *)(param_1 + 0x340U & 0xfffffffc),
      uVar3 = param_1 + 0x84U & 3, uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc),
      (int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) <
      (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) &&
      (uVar4 = param_1 + 0x44U & 3, uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
      ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x10) == 0)))) {
    uVar4 = param_1 + 0x348U & 3;
    uVar3 = *(uint *)(param_1 + 0x348U & 0xfffffffc);
    *(uint *)(param_1 + 0x348) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 1;
    return;
  }
  uVar4 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 1) != 0) {
    func_020747f4(0);
  }
  if (*(short *)(param_1 + 0x35c) == 0) {
    *(undefined4 *)(param_1 + 0x4d0) = 0x46;
    uVar4 = param_1 + 0x48U & 3;
    uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x44000;
    *(undefined2 *)(param_1 + 0x23a) = *(undefined2 *)(param_1 + 0x35c);
    uVar4 = param_1 + 0x4cU & 3;
    uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x80000000;
    return;
  }
  return;
}

