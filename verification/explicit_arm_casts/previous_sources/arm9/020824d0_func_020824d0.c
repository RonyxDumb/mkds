/* Decompiled C draft; module arm9; ROM address 020824d0. No matching claim. */
#include "types.h"
#include "deps/020824d0_func_020824d0.h"

void func_020824d0(int param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int aiStack_48 [3];
  undefined1 auStack_3c [12];
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  
  if (param_2 == 0) {
    iVar3 = GetGlobalHD4();
    GetDriverEntry((int)*(char *)((*(uint *)(uRam02082658 & 0xfffffffc) >> (uRam02082658 & 3) * 8 |
                                  *(uint *)(uRam02082658 & 0xfffffffc) <<
                                  (uRam02082658 & 3) * -8 + 0x20) + 0x62));
    aiStack_48[0] = *(int *)(iVar3 + 0x15c);
    aiStack_48[2] = *(int *)(iVar3 + 0x164);
    lVar1 = (longlong)aiStack_48[2] * (longlong)aiStack_48[2] +
            (longlong)aiStack_48[0] * (longlong)aiStack_48[0];
    uStack_24 = *puRam0208265c;
    iStack_20 = puRam0208265c[1];
    uStack_1c = puRam0208265c[2];
    aiStack_48[1] = 0;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize(aiStack_48,aiStack_48);
    }
    VecFx32_CrossProduct(puRam0208265c,aiStack_48,auStack_3c);
    iStack_20 = -iStack_20;
    *(undefined4 *)(param_1 + 0x68) = 0x1000;
    uVar4 = uRam02082660;
    *(short *)(param_1 + 0x50) = (short)uStack_24;
    *(short *)(param_1 + 0x52) = (short)iStack_20;
    *(short *)(param_1 + 0x54) = (short)uStack_1c;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    VecFx32_AddScale1(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,aiStack_48,iVar3 + 0x9c,
                      &iStack_30);
    uVar5 = iVar3 + 0x160U & 3;
    uVar4 = *(uint *)(iVar3 + 0x160U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) *
            (longlong)
            (int)(*(uint *)(uRam02082664 & 0xfffffffc) >> (uRam02082664 & 3) * 8 |
                 *(uint *)(uRam02082664 & 0xfffffffc) << (uRam02082664 & 3) * -8 + 0x20) + 0x800;
    uVar2 = uRam02082668 & 3;
    uVar6 = *(uint *)(uRam02082668 & 0xfffffffc);
    uVar5 = param_1 + 0x20U & 3;
    uVar4 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(param_1 + 0x28) = iStack_30 + (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
    uVar5 = param_1 + 0x20U & 3;
    uVar4 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 8;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) =
         iStack_2c +
         (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) +
         ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) +
         (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
    uVar5 = param_1 + 0x20U & 3;
    uVar4 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0xc;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(param_1 + 0x30) = iStack_28 + (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
    return;
  }
  return;
}

