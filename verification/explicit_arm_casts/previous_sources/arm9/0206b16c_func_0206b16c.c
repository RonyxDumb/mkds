/* Decompiled C draft; module arm9; ROM address 0206b16c. No matching claim. */
#include "types.h"
#include "deps/0206b16c_func_0206b16c.h"

void func_0206b16c(int param_1)

{
  short *psVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = param_1 + 0x318U & 3;
  uVar2 = *(uint *)(param_1 + 0x318U & 0xfffffffc);
  if (uVar2 >> uVar5 * 8 == 0 && uVar2 << uVar5 * -8 + 0x20 == 0) {
    *(uint *)(param_1 + 0x260) =
         *(uint *)(uRam0206b340 & 0xfffffffc) >> (uRam0206b340 & 3) * 8 |
         *(uint *)(uRam0206b340 & 0xfffffffc) << (uRam0206b340 & 3) * -8 + 0x20;
  }
  else {
    uVar5 = param_1 + 0x44U & 3;
    uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if (((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0x10000) != 0) {
      if (*(short *)(param_1 + 0x370) == 0) {
        *(uint *)(param_1 + 0x260) =
             *(uint *)(uRam0206b348 & 0xfffffffc) >> (uRam0206b348 & 3) * 8 |
             *(uint *)(uRam0206b348 & 0xfffffffc) << (uRam0206b348 & 3) * -8 + 0x20;
      }
      else if (*(short *)(param_1 + 0x370) == 1) {
        *(uint *)(param_1 + 0x260) =
             *(uint *)(uRam0206b344 & 0xfffffffc) >> (uRam0206b344 & 3) * 8 |
             *(uint *)(uRam0206b344 & 0xfffffffc) << (uRam0206b344 & 3) * -8 + 0x20;
      }
      *(short *)(param_1 + 0x370) = *(short *)(param_1 + 0x370) + 1;
    }
  }
  uVar5 = param_1 + 0x318U & 3;
  uVar2 = *(uint *)(param_1 + 0x318U & 0xfffffffc);
  uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  if ((int)uVar5 < 1) {
    uVar5 = -uVar5;
  }
  if ((int)uVar5 <= iRam0206b34c) {
    uVar5 = param_1 + 0x318U & 3;
    uVar6 = *(uint *)(param_1 + 0x318U & 0xfffffffc);
    uVar2 = param_1 + 0x360U & 3;
    uVar3 = *(uint *)(param_1 + 0x360U & 0xfffffffc);
    *(uint *)(param_1 + 0x318) =
         (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) +
         (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    uVar5 = param_1 + 0x318U & 3;
    uVar2 = *(uint *)(param_1 + 0x318U & 0xfffffffc);
    uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    if ((int)uVar5 < 1) {
      uVar5 = -uVar5;
    }
    uVar2 = uVar5;
    iVar4 = iRam0206b34c;
    if (iRam0206b34c < (int)uVar5) {
      iVar4 = param_1 + 0x300;
      uVar2 = 0;
    }
    if (iRam0206b34c < (int)uVar5) {
      *(short *)(iVar4 + 0x14) = (short)uVar2;
    }
    else {
      uVar5 = param_1 + 0x360U & 3;
      uVar2 = *(uint *)(param_1 + 0x360U & 0xfffffffc);
      *(ushort *)(param_1 + 0x314) =
           *(short *)(param_1 + 0x314) +
           ((ushort)(uVar2 >> uVar5 * 8) | (ushort)(uVar2 << uVar5 * -8 + 0x20));
    }
    uVar5 = param_1 + 0x360U & 3;
    uVar2 = *(uint *)(param_1 + 0x360U & 0xfffffffc);
    *(uint *)(param_1 + 0x360) = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) - 10;
    func_01ffd190(param_1 + 0x31c,*(undefined2 *)(param_1 + 0x314),param_1 + 0x34c);
    func_01ffcf7c(param_1 + 0x34c,param_1 + 0x34c);
    return;
  }
  if (*(short *)(param_1 + 0x35c) == 0) {
    uVar5 = param_1 + 0x48U & 3;
    uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20 | 0x44000;
    *(undefined2 *)(param_1 + 0x23a) = 0;
    uVar5 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0xffffffef;
  }
  psVar1 = psRam0206b350;
  *(short *)(param_1 + 0x35c) = *(short *)(param_1 + 0x35c) + 1;
  if (*(short *)(param_1 + 0x35c) < *psVar1) {
    return;
  }
  *(undefined4 *)(param_1 + 0x180) = 0;
  uVar5 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0xffffffcf;
  uVar5 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0xfffdffff;
  DriverContext_UpdateCharacterAnimation(param_1,0,1);
  uVar5 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20 | 0x80000000;
  uVar5 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 2) == 0) {
    return;
  }
  uVar2 = *(uint *)(uRam0206b354 & 0xfffffffc) >> (uRam0206b354 & 3) * 8 |
          *(uint *)(uRam0206b354 & 0xfffffffc) << (uRam0206b354 & 3) * -8 + 0x20;
  uVar5 = uVar2 + 8;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) != 2) {
    return;
  }
  uVar2 = uVar2 + 0x18;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar5 * 8 != 0 || uVar2 << uVar5 * -8 + 0x20 != 0) {
    return;
  }
  uVar5 = param_1 + 0x310U & 3;
  uVar2 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
  func_02088c7c(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
  return;
}

