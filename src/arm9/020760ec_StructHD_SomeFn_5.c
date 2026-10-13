/* Decompiled C draft; module arm9; ROM address 020760ec. No matching claim. */
#include "types.h"
#include "deps/020760ec_StructHD_SomeFn_5.h"

void StructHD_SomeFn_5(int param_1,int param_2,undefined4 param_3)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_70;
  int local_6c;
  int local_68;
  int local_64;
  undefined1 auStack_60 [12];
  undefined1 auStack_54 [4];
  int local_50;
  int local_48;
  int local_44;
  int local_40;
  undefined1 auStack_3c [12];
  uint local_30;
  uint local_2c;
  uint local_28;
  
  local_6c = *piRam020764ec;
  local_68 = piRam020764ec[1];
  local_64 = piRam020764ec[2];
  uVar8 = 0;
  *puRam020764f0 = 0;
  *(undefined4 *)(param_1 + 600) = 0;
  iVar2 = func_01ffdee4((int *)(uintptr_t)(param_1 + 0x24),(undefined4 *)(uintptr_t)(param_1 + 0x134),0,
                        *(uint *)(uRam020764f4 & 0xfffffffc) >> (uRam020764f4 & 3) * 8 |
                        *(uint *)(uRam020764f4 & 0xfffffffc) << (uRam020764f4 & 3) * -8 + 0x20,2,
                        0xfffffffe,&local_6c,(int *)(void *)(auStack_60),(int *)(void *)(auStack_54),&local_70,0,0,0,0);
  if ((iVar2 != 0) && ((local_70 & 0xc00) == 0)) {
    if ((local_70 & uRam020764f8) == 0) {
      if (((local_70 & uRam0207650c) != 0) &&
         (((uVar3 = (*(uint *)(uRam02076510 & 0xfffffffc) >> (uRam02076510 & 3) * 8 |
                    *(uint *)(uRam02076510 & 0xfffffffc) << (uRam02076510 & 3) * -8 + 0x20) + 8,
           uVar5 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
           (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) != 2 ||
           (iVar2 = Vector3_DotProduct(uRam02076514,(uint)(uintptr_t)(auStack_60)), iVar2 < iRam02076518)) ||
          (uVar3 = param_1 + 0x28U & 3, uVar7 = *(uint *)(param_1 + 0x28U & 0xfffffffc),
          uVar5 = param_2 + 0x84U & 3, uVar6 = *(uint *)(param_2 + 0x84U & 0xfffffffc),
          (int)((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) -
               (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20)) <
          (int)(*(uint *)(uRam0207651c & 0xfffffffc) >> (uRam0207651c & 3) * 8 |
               *(uint *)(uRam0207651c & 0xfffffffc) << (uRam0207651c & 3) * -8 + 0x20))))) {
        VecFx32_Add((uint)(uintptr_t)(&local_6c),param_1 + 0x24,(int *)(uintptr_t)(param_1 + 0x24));
      }
    }
    else {
      local_48 = *(int *)(param_2 + 0x50);
      local_44 = *(int *)(param_2 + 0x54);
      local_40 = *(int *)(param_2 + 0x58);
      uVar8 = param_2 + 0x2a8U & 3;
      uVar3 = *(uint *)(param_2 + 0x2a8U & 0xfffffffc);
      if ((int)(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) < 1) {
        lVar1 = (longlong)local_64 * (longlong)local_64 +
                (longlong)local_6c * (longlong)local_6c + (longlong)local_68 * (longlong)local_68;
        local_48 = -local_48;
        local_44 = -local_44;
        local_40 = -local_40;
        iVar2 = 0;
        if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
          iVar2 = Vector3_MaybeNormalize((uint)(uintptr_t)(&local_6c),(int *)(void *)(auStack_3c));
        }
        if (((iVar2 != 0) &&
            (iVar2 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_3c),(uint)(uintptr_t)(auStack_54)), iVar2 < iRam020764fc)) &&
           (iVar2 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_3c),param_3), iRam02076500 < iVar2)) {
          *(undefined4 *)(param_1 + 0x254) = 1;
        }
      }
      *(undefined4 *)(param_1 + 600) = 1;
      iVar2 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&local_48),(uint)(uintptr_t)(auStack_54));
      uVar8 = param_1 + 0x254U & 3;
      uVar3 = *(uint *)(param_1 + 0x254U & 0xfffffffc);
      uVar8 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
      if ((uVar8 == 1) ||
         (((uVar8 == 3 && (iVar2 < iRam02076504)) &&
          (iVar2 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&local_48),param_3), iVar2 < 0)))) {
        iVar2 = iRam02076508;
        if (local_50 < iRam02076508) {
          *(undefined4 *)(param_1 + 0x254) = 3;
        }
        uVar8 = (uint)(iVar2 <= local_50);
        if (local_50 < iVar2) {
          *(uint *)(param_1 + 600) = uVar8;
        }
        else {
          uVar4 = VecFx32_Norm((uint)(uintptr_t)(&local_6c));
          *(undefined4 *)(param_1 + 0x170) = uVar4;
          *(undefined4 *)(param_1 + 0x254) = 1;
        }
      }
      else {
        iVar2 = VecFx32_CrossProduct_0(param_3,(uint)(uintptr_t)(auStack_54));
        if (iVar2 < 1) {
          *(undefined4 *)(param_1 + 0x25c) = 1;
        }
        else {
          *(undefined4 *)(param_1 + 0x254) = 0;
        }
        uVar8 = (uint)(0 < iVar2);
      }
    }
  }
  uVar3 = param_1 + 600U & 3;
  uVar5 = *(uint *)(param_1 + 600U & 0xfffffffc);
  if (uVar5 >> uVar3 * 8 == 0 && uVar5 << uVar3 * -8 + 0x20 == 0) {
    *(undefined4 *)(param_1 + 0x25c) = 0;
  }
  if ((uVar8 == 0) ||
     (uVar8 = param_1 + 0x25cU & 3, uVar3 = *(uint *)(param_1 + 0x25cU & 0xfffffffc),
     uVar3 >> uVar8 * 8 != 0 || uVar3 << uVar8 * -8 + 0x20 != 0)) {
    *(undefined4 *)(param_1 + 0x170) = 0;
    VecFx32_Subtract((uint)(uintptr_t)(&local_6c),param_1 + 0x17c,&local_30);
    local_30 = (uint)((ulonglong)uRam02076520 * (ulonglong)local_30) >> 0xc |
               (((int)local_30 >> 0x1f) * uRam02076520 +
               (int)((ulonglong)uRam02076520 * (ulonglong)local_30 >> 0x20)) * 0x100000;
    local_28 = (uint)((ulonglong)uRam02076520 * (ulonglong)local_28) >> 0xc |
               (((int)local_28 >> 0x1f) * uRam02076520 +
               (int)((ulonglong)uRam02076520 * (ulonglong)local_28 >> 0x20)) * 0x100000;
    local_2c = (uint)((ulonglong)uRam02076520 * (ulonglong)local_2c) >> 0xc |
               (((int)local_2c >> 0x1f) * uRam02076520 +
               (int)((ulonglong)uRam02076520 * (ulonglong)local_2c >> 0x20)) * 0x100000;
    VecFx32_Add(param_1 + 0x17c,(uint)(uintptr_t)(&local_30),param_1 + 0x17c);
    *(undefined4 *)(param_1 + 0x254) = 3;
  }
  else {
    uVar8 = param_1 + 0x254U & 3;
    uVar3 = *(uint *)(param_1 + 0x254U & 0xfffffffc);
    if (uVar3 >> uVar8 * 8 == 0 && uVar3 << uVar8 * -8 + 0x20 == 0) {
      uVar8 = param_2 + 0x2a0U & 3;
      uVar3 = *(uint *)(param_2 + 0x2a0U & 0xfffffffc);
      lVar1 = (ulonglong)(0x1000 - (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20)) * 0x5000;
      iVar2 = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) + 0x3000;
      *(uint *)(param_1 + 0x17c) =
           (uint)((longlong)local_6c * (longlong)iVar2) >> 0xc |
           (int)((ulonglong)((longlong)local_6c * (longlong)iVar2) >> 0x20) << 0x14;
      *(uint *)(param_1 + 0x180) =
           (uint)((longlong)local_68 * (longlong)iVar2) >> 0xc |
           (int)((ulonglong)((longlong)local_68 * (longlong)iVar2) >> 0x20) << 0x14;
      *(uint *)(param_1 + 0x184) =
           (uint)((longlong)local_64 * (longlong)iVar2) >> 0xc |
           (int)((ulonglong)((longlong)local_64 * (longlong)iVar2) >> 0x20) << 0x14;
      *(undefined4 *)(param_1 + 0x170) = 0;
    }
  }
  uVar8 = param_1 + 0x174U & 3;
  uVar3 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
  uVar5 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
  uVar8 = param_1 + 0x170U & 3;
  uVar3 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
  uVar8 = (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) - uVar5;
  lVar1 = (ulonglong)uRam02076524 * (ulonglong)uVar8;
  uVar3 = (uint)lVar1;
  *(uint *)(param_1 + 0x174) =
       uVar5 + (uVar3 + 0x800 >> 0xc |
               (((int)uVar8 >> 0x1f) * uRam02076524 + (int)((ulonglong)lVar1 >> 0x20) +
               (uint)(0xfffff7ff < uVar3)) * 0x100000);
  return;
}

