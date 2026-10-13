/* Decompiled C draft; module arm9; ROM address 0209297c. No matching claim. */
#include "types.h"
#include "deps/0209297c_func_0209297c.h"

undefined1 func_0209297c(int param_1,int param_2,undefined4 param_3,undefined1 *param_4)

{
  uint uVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c [2];
  int local_24;
  uint uVar8;
  
  uVar1 = 1 << (*(ushort *)(param_2 + 0x74) & 0xff);
  uVar2 = *param_4;
  if (((uint)*(byte *)(param_1 + 0xd0) & uVar1 & 0xff) == 0) {
    VecFx32_Subtract(param_2 + 0x80,param_1 + 4,local_2c);
    uVar5 = uRam02092b1c;
    uVar6 = param_1 + 0x48U & 3;
    uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    uVar8 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    uVar6 = param_1 + 0x40U & 3;
    uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    lVar3 = (longlong)local_2c[0] * (longlong)(int)uVar7 + (longlong)(int)uVar8 * (longlong)local_24
    ;
    uVar6 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
    lVar3 = (longlong)(int)uVar7 * (longlong)(int)uVar6;
    lVar4 = (longlong)(int)uVar8 * (longlong)(int)uVar6;
    local_38 = local_2c[0] - ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
    local_30 = local_24 - ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14);
    lVar3 = (longlong)(int)local_30 * (longlong)(int)local_30 +
            (longlong)(int)local_38 * (longlong)(int)local_38 +
            (longlong)(int)local_34 * (longlong)(int)local_34;
    if ((int)((ulonglong)lVar3 >> 0x20) < (int)(uint)((uint)lVar3 < 0x10)) {
      uVar6 = param_1 + 0x40U & 3;
      uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      lVar3 = (ulonglong)uRam02092b1c * (ulonglong)uVar6;
      *(uint *)(param_1 + 0x10) =
           (uint)lVar3 >> 0xc |
           (((int)uVar6 >> 0x1f) * uRam02092b1c + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
      uVar6 = param_1 + 0x44U & 3;
      uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      lVar3 = (ulonglong)uVar5 * (ulonglong)uVar6;
      *(uint *)(param_1 + 0x14) =
           (uint)lVar3 >> 0xc |
           (((int)uVar6 >> 0x1f) * uVar5 + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
      uVar6 = param_1 + 0x48U & 3;
      uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      lVar3 = (ulonglong)uVar5 * (ulonglong)uVar6;
      *(uint *)(param_1 + 0x18) =
           (uint)lVar3 >> 0xc |
           (((int)uVar6 >> 0x1f) * uVar5 + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
    }
    else {
      Vector3_MaybeNormalize((uint)(uintptr_t)(&local_38),&local_38);
      uVar6 = uRam02092b1c;
      *(uint *)(param_1 + 0x10) =
           (uint)((ulonglong)uRam02092b1c * (ulonglong)local_38) >> 0xc |
           (((int)local_38 >> 0x1f) * uRam02092b1c +
           (int)((ulonglong)uRam02092b1c * (ulonglong)local_38 >> 0x20)) * 0x100000;
      *(uint *)(param_1 + 0x14) =
           (uint)((ulonglong)uVar6 * (ulonglong)local_34) >> 0xc |
           (((int)local_34 >> 0x1f) * uVar6 + (int)((ulonglong)uVar6 * (ulonglong)local_34 >> 0x20))
           * 0x100000;
      *(uint *)(param_1 + 0x18) =
           (uint)((ulonglong)uVar6 * (ulonglong)local_30) >> 0xc |
           (((int)local_30 >> 0x1f) * uVar6 + (int)((ulonglong)uVar6 * (ulonglong)local_30 >> 0x20))
           * 0x100000;
    }
    *(byte *)(param_1 + 0xd0) = *(byte *)(param_1 + 0xd0) | (byte)uVar1;
  }
  return uVar2;
}

