/* Decompiled C draft; module arm9; ROM address 01ff9d18. No matching claim. */
#include "types.h"
#include "deps/01ff9d18_func_01ff9d18.h"

void func_01ff9d18(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = param_1 + 0x48U & 3;
  uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if ((((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0x80000) != 0) &&
     (*(short *)(param_1 + 0x23c) = *(short *)(param_1 + 0x23c) + -1,
     *(short *)(param_1 + 0x23c) < 1)) {
    uVar5 = param_1 + 0x48U & 3;
    uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0xfff7ffff;
    *(undefined2 *)(param_1 + 0x23c) = 0;
  }
  uVar5 = param_1 + 0x48U & 3;
  uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if ((((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0x100000) != 0) &&
     (*(short *)(param_1 + 0x538) = *(short *)(param_1 + 0x538) + -1,
     *(short *)(param_1 + 0x538) < 1)) {
    uVar5 = param_1 + 0x48U & 3;
    uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & uRam01ff9e54;
    *(undefined2 *)(param_1 + 0x538) = 0;
  }
  uVar5 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if ((((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0x1000000) == 0) &&
     (uVar5 = param_1 + 0x7cU & 3, uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
     ((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0x400) == 0)) {
    func_0206f914(param_1);
  }
  uVar5 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0x400) != 0) {
    uVar2 = GetSomeTimeOrDuration();
    uVar5 = param_1 + 0x410U & 3;
    uVar1 = *(uint *)(param_1 + 0x410U & 0xfffffffc);
    if ((uVar1 >> uVar5 * 8 == 0 && uVar1 << uVar5 * -8 + 0x20 == 0) &&
       (uVar5 = param_1 + 0x78U & 3, uVar1 = *(uint *)(param_1 + 0x78U & 0xfffffffc),
       (*(ushort *)(iRam01ff9e58 + (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) * 0x5c) & 1) !=
       0)) {
      *(undefined4 *)(param_1 + 0x410) = uVar2;
    }
    uVar5 = param_1 + 0x40cU & 3;
    uVar1 = *(uint *)(param_1 + 0x40cU & 0xfffffffc);
    uVar5 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
    if (uVar5 != 0) {
      uVar1 = param_1 + 0x410U & 3;
      uVar3 = *(uint *)(param_1 + 0x410U & 0xfffffffc);
      uVar1 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      if (uVar1 != 0) {
        iVar4 = uVar1 - uVar5;
        if (iVar4 < 1) {
          iVar4 = -iVar4;
        }
        if (iVar4 < 3) {
          DriverContext_MaybeApplyBoost(param_1,3,10);
        }
        uVar5 = param_1 + 0x4cU & 3;
        uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
        *(uint *)(param_1 + 0x4c) = (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0xfffffbff;
        return;
      }
      return;
    }
    return;
  }
  return;
}

