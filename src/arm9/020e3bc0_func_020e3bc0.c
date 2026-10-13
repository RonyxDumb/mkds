/* Decompiled C draft; module arm9; ROM address 020e3bc0. No matching claim. */
#include "types.h"
#include "deps/020e3bc0_func_020e3bc0.h"

void func_020e3bc0(undefined4 param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = ((uint)*(ushort *)(param_2 + 0x144) +
           ((int)*(short *)(iRam020e3de0 + ((int)(uint)*(ushort *)(param_2 + 0x148) >> 4) * 4) *
            (uint)*(ushort *)(param_2 + 0x144) >> 0xc) & 0xffff) * -0x10000;
  uVar4 = uVar5 >> 0x10;
  iVar3 = uVar4 - *(ushort *)(param_2 + 0x14a);
  if (0x8000 < iVar3) {
    iVar3 = iVar3 + -0x10000;
  }
  uVar7 = param_2 + 0x28U & 3;
  uVar6 = *(uint *)(param_2 + 0x28U & 0xfffffffc);
  if (iVar3 < -0x8000) {
    iVar3 = iVar3 + 0x10000;
  }
  lVar2 = (longlong)(int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * (longlong)iVar3;
  *(uint *)(param_2 + 0x124) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  iVar1 = (int)uVar4 >> 4;
  uVar4 = param_2 + 0x2cU & 3;
  uVar7 = *(uint *)(param_2 + 0x2cU & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) * (longlong)iVar3;
  *(uint *)(param_2 + 0x128) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar4 = param_2 + 0x30U & 3;
  uVar7 = *(uint *)(param_2 + 0x30U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) * (longlong)iVar3;
  *(uint *)(param_2 + 300) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  *(short *)(param_2 + 0x14a) = (short)(uVar5 >> 0x10);
  *(undefined4 *)(param_2 + 0xa0) = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(param_2 + 0xa4) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(param_2 + 0xa8) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_2 + 0xac) = *(undefined4 *)(param_2 + 0x34);
  *(undefined4 *)(param_2 + 0xb0) = *(undefined4 *)(param_2 + 0x38);
  *(undefined4 *)(param_2 + 0xb4) = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(param_2 + 0xb8) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(param_2 + 0xbc) = *(undefined4 *)(param_2 + 0x44);
  iVar3 = iRam020e3de0;
  uVar5 = param_2 + 0x48U & 3;
  uVar4 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
  *(uint *)(param_2 + 0xc0) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  MTX_RotX33__from_thumb
            ((undefined4 *)(uintptr_t)(param_2 + 0x28),(int)*(short *)(iVar3 + iVar1 * 4),
             (int)*(short *)(iVar3 + (iVar1 * 2 + 1) * 2));
  MTX_Concat33(param_2 + 0x28,(uint *)(uintptr_t)(param_2 + 0xc4),(uint *)(uintptr_t)(param_2 + 0x28));
  uVar5 = param_2 + 0x104U & 3;
  uVar4 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
  VecFx32_AddScale1(-(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20),param_2 + 0x34,param_2 + 4,
                    (int *)(uintptr_t)(param_2 + 0xf4));
  if (*(short *)(param_2 + 0x150) == 0) {
    uVar5 = param_2 + 0x94U & 3;
    uVar4 = *(uint *)(param_2 + 0x94U & 0xfffffffc);
    if (uVar4 >> uVar5 * 8 != 0 || uVar4 << uVar5 * -8 + 0x20 != 0) {
      func_020d275c(param_2,uRam020e3de4);
    }
    *(short *)(param_2 + 0x148) = *(short *)(param_2 + 0x148) + *(short *)(param_2 + 0x146);
    uVar5 = (uint)*(ushort *)(param_2 + 0x148);
    if ((uVar5 < 0x4000) || (*(ushort *)(param_2 + 0x146) + 0x4000 <= uVar5)) {
      if ((0xbfff < uVar5) && (uVar5 < *(ushort *)(param_2 + 0x146) + 0xc000)) {
        *(undefined2 *)(param_2 + 0x150) = *(undefined2 *)(param_2 + 0x14e);
      }
    }
    else {
      *(undefined2 *)(param_2 + 0x150) = *(undefined2 *)(param_2 + 0x14c);
    }
    lVar2 = (ulonglong)((uint)*(ushort *)(param_2 + 0x14a) * -0x10000 >> 0x10) * 0x1680000 + 0x80000
    ;
    *(uint *)(param_2 + 0x154) =
         ((uint)lVar2 >> 0x14 | (int)((ulonglong)lVar2 >> 0x20) * 0x1000) << 1;
    uVar4 = param_2 + 0x154U & 3;
    uVar6 = *(uint *)(param_2 + 0x154U & 0xfffffffc);
    uVar5 = (*(uint *)(uRam020e3de8 & 0xfffffffc) >> (uRam020e3de8 & 3) * 8 |
            *(uint *)(uRam020e3de8 & 0xfffffffc) << (uRam020e3de8 & 3) * -8 + 0x20) + 0x2c;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    if ((int)uVar5 < (int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20)) {
      *(uint *)(param_2 + 0x154) = uVar5;
    }
    uVar5 = param_2 + 0x154U & 3;
    uVar4 = *(uint *)(param_2 + 0x154U & 0xfffffffc);
    if ((int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) < 0) {
      *(undefined4 *)(param_2 + 0x154) = 0;
    }
    return;
  }
  *(short *)(param_2 + 0x150) = *(short *)(param_2 + 0x150) + -1;
  return;
}

