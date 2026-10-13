/* Decompiled C draft; module arm9; ROM address 02082034. No matching claim. */
#include "types.h"
#include "deps/02082034_func_02082034.h"

void func_02082034(int param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  if (param_2 == 0) {
    iVar2 = GetGlobalHD4();
    iStack_30 = *(int *)(iVar2 + 0x15c);
    uStack_2c = *(undefined4 *)(iVar2 + 0x160);
    iStack_28 = *(int *)(iVar2 + 0x164);
    iStack_18 = *piRam020821bc;
    iStack_14 = piRam020821bc[1];
    iStack_10 = piRam020821bc[2];
    iVar3 = func_0203c5e4();
    if (iVar3 != 0) {
      FX_Atan2((int)*(short *)(iVar2 + 0x68),(int)*(short *)(iVar2 + 0x6a));
      VecFx32_Subtract(iVar2 + 0x24,iVar2 + 0x134,&iStack_18);
      iStack_18 = iStack_18 >> 4;
      iStack_14 = iStack_14 >> 4;
      iStack_10 = iStack_10 >> 4;
    }
    lVar1 = (longlong)iStack_28 * (longlong)iStack_28 + (longlong)iStack_30 * (longlong)iStack_30;
    uStack_2c = 0;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize(&iStack_30,&iStack_30);
    }
    VecFx32_AddScale1(*(uint *)(uRam020821c0 & 0xfffffffc) >> (uRam020821c0 & 3) * 8 |
                      *(uint *)(uRam020821c0 & 0xfffffffc) << (uRam020821c0 & 3) * -8 + 0x20,
                      &iStack_30,iVar2 + 0x9c,&iStack_24);
    uVar4 = iVar2 + 0x160U & 3;
    uVar5 = *(uint *)(iVar2 + 0x160U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) *
            (longlong)
            (int)(*(uint *)(uRam020821c4 & 0xfffffffc) >> (uRam020821c4 & 3) * 8 |
                 *(uint *)(uRam020821c4 & 0xfffffffc) << (uRam020821c4 & 3) * -8 + 0x20) + 0x800;
    iStack_20 = iStack_20 +
                (*(uint *)(uRam020821c8 & 0xfffffffc) >> (uRam020821c8 & 3) * 8 |
                *(uint *)(uRam020821c8 & 0xfffffffc) << (uRam020821c8 & 3) * -8 + 0x20) +
                ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000);
    VecFx32_Add(&iStack_24,&iStack_18,&iStack_24);
    uVar4 = param_1 + 0x20U & 3;
    uVar5 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 4;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(param_1 + 0x28) = iStack_24 + (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    uVar4 = param_1 + 0x20U & 3;
    uVar5 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 8;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) = iStack_20 + (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    uVar4 = param_1 + 0x20U & 3;
    uVar5 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0xc;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(param_1 + 0x30) = iStack_1c + (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    *(undefined4 *)(param_1 + 0x58) = 0x800;
    return;
  }
  return;
}

