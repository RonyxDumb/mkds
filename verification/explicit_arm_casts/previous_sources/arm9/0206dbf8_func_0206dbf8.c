/* Decompiled C draft; module arm9; ROM address 0206dbf8. No matching claim. */
#include "types.h"
#include "deps/0206dbf8_func_0206dbf8.h"

undefined4 func_0206dbf8(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  undefined1 auStack_24 [12];
  undefined1 auStack_18 [12];
  uint uVar7;
  
  uVar7 = param_2 + 0x4cU & 3;
  uVar6 = *(uint *)(param_2 + 0x4cU & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if ((uVar7 & 0x400000) == 0) {
    uVar6 = param_2 + 0x7cU & 3;
    uVar5 = *(uint *)(param_2 + 0x7cU & 0xfffffffc);
    if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x200) == 0) {
      bVar2 = true;
      if (((uVar7 & DAT_0206de14) == 0) &&
         (uVar7 = param_2 + 0x48U & 3, uVar6 = *(uint *)(param_2 + 0x48U & 0xfffffffc),
         ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x1800) == 0)) {
        uVar7 = param_2 + 0x180U & 3;
        uVar6 = *(uint *)(param_2 + 0x180U & 0xfffffffc);
        uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
        bVar1 = false;
        if ((uVar7 != 0) && ((uVar7 != 1 && (uVar7 != 2)))) {
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
      uVar6 = param_2 + 0x180U & 3;
      uVar5 = *(uint *)(param_2 + 0x180U & 0xfffffffc);
      if (((uVar5 >> uVar6 * 8 == 0 && uVar5 << uVar6 * -8 + 0x20 == 0) &&
          (uVar6 = param_2 + 0x48U & 3, uVar5 = *(uint *)(param_2 + 0x48U & 0xfffffffc),
          ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x1800) == 0)) &&
         ((uVar7 & DAT_0206de14) == 0)) {
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
  if (!bVar2) {
    return 0;
  }
  iStack_30 = *(int *)(param_1 + 0x120);
  iStack_2c = *(int *)(param_1 + 0x124);
  iStack_28 = *(int *)(param_1 + 0x128);
  VecFx32_Subtract(param_2 + 0x80,param_1 + 0x80,auStack_24);
  VecFx32_CrossProduct(param_1 + 0x138,auStack_24,auStack_18);
  iVar3 = Vector3_DotProduct(auStack_18,param_1 + 300);
  if (iVar3 < 0) {
    iStack_30 = -iStack_30;
    iStack_2c = -iStack_2c;
    iStack_28 = -iStack_28;
  }
  StructMQRacerEntry_SomeFn_4(param_2,&iStack_30,1);
  DriverContext_MaybeQueuePlaySfx(param_2,0xe8,0x7f,0);
  uVar7 = param_2 + 0x7cU & 3;
  uVar6 = *(uint *)(param_2 + 0x7cU & 0xfffffffc);
  if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x200) != 0) {
    uVar7 = param_2 + 0x514U & 3;
    uVar6 = *(uint *)(param_2 + 0x514U & 0xfffffffc);
    uVar5 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar7 = uVar5 + 0x2c;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(uVar5 + 0x2c) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) ^ 0x80;
  }
  uVar7 = param_1 + 0x7cU & 3;
  uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar4 = 1;
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x200;
  if (uVar7 == 0) {
    return uVar4;
  }
  switch(*(undefined2 *)(param_2 + 0x74)) {
  case 0:
    if (uVar7 != 0) {
      uVar7 = param_1 + 0x514U & 3;
      uVar6 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar5 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      uVar7 = uVar5 + 0x2c;
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(uint *)(uVar5 + 0x2c) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) ^ 0x400000;
    }
    return uVar4;
  case 1:
    if (uVar7 != 0) {
      uVar7 = param_1 + 0x514U & 3;
      uVar6 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar5 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      uVar7 = uVar5 + 0x2c;
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(uint *)(uVar5 + 0x2c) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) ^ 0x800000;
    }
    return uVar4;
  case 2:
    if (uVar7 != 0) {
      uVar7 = param_1 + 0x514U & 3;
      uVar6 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar5 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      uVar7 = uVar5 + 0x2c;
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(uint *)(uVar5 + 0x2c) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) ^ 0x1000000;
    }
    return uVar4;
  case 3:
    if (uVar7 != 0) {
      uVar7 = param_1 + 0x514U & 3;
      uVar6 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar5 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      uVar7 = uVar5 + 0x2c;
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(uint *)(uVar5 + 0x2c) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) ^ 0x2000000;
    }
  }
  return uVar4;
}

