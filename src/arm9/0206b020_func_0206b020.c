/* Decompiled C draft; module arm9; ROM address 0206b020. No matching claim. */
#include "types.h"
#include "deps/0206b020_func_0206b020.h"

undefined4 func_0206b020(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  undefined1 auStack_24 [12];
  undefined1 auStack_18 [12];
  uint uVar6;
  
  uVar6 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if ((uVar6 & 0x400000) == 0) {
    uVar5 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0x200) == 0) {
      bVar2 = true;
      if (((uVar6 & uRam0206b168) == 0) &&
         (uVar6 = param_1 + 0x48U & 3, uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
         ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x1800) == 0)) {
        uVar6 = param_1 + 0x180U & 3;
        uVar5 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
        uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        bVar1 = false;
        if ((uVar6 != 0) && ((uVar6 != 1 && (uVar6 != 2)))) {
          bVar1 = true;
        }
        if (!bVar1) {
          bVar2 = false;
        }
      }
      if (bVar2) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
    }
    else {
      uVar5 = param_1 + 0x180U & 3;
      uVar3 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
      if (((uVar3 >> uVar5 * 8 == 0 && uVar3 << uVar5 * -8 + 0x20 == 0) &&
          (uVar5 = param_1 + 0x48U & 3, uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
          ((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0x1800) == 0)) &&
         ((uVar6 & uRam0206b168) == 0)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    iStack_30 = *(int *)(param_2 + 0x28);
    iStack_2c = *(int *)(param_2 + 0x2c);
    iStack_28 = *(int *)(param_2 + 0x30);
    VecFx32_Subtract(param_1 + 0x80,param_2 + 4,(int *)(void *)(auStack_24));
    VecFx32_CrossProduct(param_2 + 0x40,(uint)(uintptr_t)(auStack_24),(uint *)(void *)(auStack_18));
    iVar4 = Vector3_DotProduct((uint)(uintptr_t)(auStack_18),param_2 + 0x34);
    if (iVar4 < 0) {
      iStack_30 = -iStack_30;
      iStack_2c = -iStack_2c;
      iStack_28 = -iStack_28;
    }
    StructMQRacerEntry_SomeFn_59(param_1,&iStack_30,0);
    return 1;
  }
  return 0;
}

