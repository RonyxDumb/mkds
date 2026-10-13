/* Decompiled C draft; module arm9; ROM address 02011254. No matching claim. */
#include "types.h"
#include "deps/02011254_func_02011254.h"

undefined4 func_02011254(uint *param_1,uint param_2,int param_3)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  uint uStack_7c;
  undefined1 auStack_78 [12];
  undefined1 auStack_6c [12];
  undefined1 auStack_60 [12];
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  uVar6 = param_2 + 0x10 & 3;
  uVar4 = *(uint *)(param_2 + 0x10 & 0xfffffffc);
  if (uVar4 >> uVar6 * 8 == 0 && uVar4 << uVar6 * -8 + 0x20 == 0) {
    uVar2 = *(ushort *)(param_2 + param_3 * 2 + 0x1a);
    if ((uVar2 & 0x300) == 0x100) {
      uVar6 = param_2 + 0xc & 3;
      uVar4 = *(uint *)(param_2 + 0xc & 0xfffffffc);
      (*(code *)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20))(param_1,param_2,uVar2 & 0xff);
      return 1;
    }
    return 0;
  }
  iVar7 = 0;
  iVar5 = 0;
  uVar6 = param_2;
  uVar4 = param_2;
  do {
    uVar3 = *(ushort *)(param_3 * 2 + uVar4 + 0x1a) & 0x300;
    bVar8 = uVar3 == 0x100;
    if (bVar8) {
      uVar6 = uVar4 + 4 & 3;
      uVar3 = *(uint *)(uVar4 + 4 & 0xfffffffc);
      uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
      uVar6 = uVar4;
    }
    uVar1 = uVar4 + 0x10 & 3;
    uVar4 = *(uint *)(uVar4 + 0x10 & 0xfffffffc);
    uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    if (bVar8) {
      iVar7 = iVar7 + uVar3;
      iVar5 = iVar5 + 1;
    }
  } while (uVar4 != 0);
  if (iVar7 != 0) {
    if (iVar5 != 1) {
      Mem_CpuFastMemorySet(0,param_1,0x58);
      *param_1 = 0xffffffff;
      do {
        uVar2 = *(ushort *)(param_2 + param_3 * 2 + 0x1a);
        if (((uVar2 & 0x300) == 0x100) &&
           (uVar6 = param_2 + 4 & 3, uVar4 = *(uint *)(param_2 + 4 & 0xfffffffc),
           0 < (int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20))) {
          uVar6 = param_2 + 0xc & 3;
          uVar4 = *(uint *)(param_2 + 0xc & 0xfffffffc);
          (*(code *)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20))
                    (&uStack_7c,param_2,uVar2 & 0xff);
          if (iVar7 == 0x1000) {
            uVar6 = param_2 + 4 & 3;
            uVar4 = *(uint *)(param_2 + 4 & 0xfffffffc);
            uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
          }
          else {
            uVar6 = param_2 + 4 & 3;
            uVar4 = *(uint *)(param_2 + 4 & 0xfffffffc);
            uVar6 = FX_Div(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20,iVar7);
          }
          func_02011558(param_1 + 1,(uint)(uintptr_t)(auStack_78),uVar6,uStack_7c & 1);
          func_02011558(param_1 + 4,(uint)(uintptr_t)(auStack_6c),uVar6,uStack_7c & 8);
          func_02011558(param_1 + 7,(uint)(uintptr_t)(auStack_60),uVar6,uStack_7c & 0x10);
          if ((uStack_7c & 4) == 0) {
            uVar4 = (uint)(param_1 + 0x13) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 0x13) & 0xfffffffc);
            param_1[0x13] =
                 (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
                 ((uint)((longlong)(int)uVar6 * (longlong)iStack_30) >> 0xc |
                 (int)((ulonglong)((longlong)(int)uVar6 * (longlong)iStack_30) >> 0x20) << 0x14);
            uVar4 = (uint)(param_1 + 0x14) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 0x14) & 0xfffffffc);
            param_1[0x14] =
                 (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
                 ((uint)((longlong)(int)uVar6 * (longlong)iStack_2c) >> 0xc |
                 (int)((ulonglong)((longlong)(int)uVar6 * (longlong)iStack_2c) >> 0x20) << 0x14);
            uVar4 = (uint)(param_1 + 0x15) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 0x15) & 0xfffffffc);
            param_1[0x15] =
                 (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
                 ((uint)((longlong)(int)uVar6 * (longlong)iStack_28) >> 0xc |
                 (int)((ulonglong)((longlong)(int)uVar6 * (longlong)iStack_28) >> 0x20) << 0x14);
          }
          if ((uStack_7c & 2) == 0) {
            uVar4 = (uint)(param_1 + 10) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
            param_1[10] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
                          ((int)(uVar6 * iStack_54) >> 0xc);
            uVar4 = (uint)(param_1 + 0xb) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 0xb) & 0xfffffffc);
            param_1[0xb] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
                           ((int)(uVar6 * iStack_50) >> 0xc);
            uVar4 = (uint)(param_1 + 0xc) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 0xc) & 0xfffffffc);
            param_1[0xc] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
                           ((int)(uVar6 * iStack_4c) >> 0xc);
            uVar4 = (uint)(param_1 + 0xd) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 0xd) & 0xfffffffc);
            param_1[0xd] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
                           ((int)(uVar6 * iStack_48) >> 0xc);
            uVar4 = (uint)(param_1 + 0xe) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 0xe) & 0xfffffffc);
            param_1[0xe] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
                           ((int)(uVar6 * iStack_44) >> 0xc);
            uVar4 = (uint)(param_1 + 0xf) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 0xf) & 0xfffffffc);
            param_1[0xf] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) +
                           ((int)(uVar6 * iStack_40) >> 0xc);
          }
          else {
            uVar4 = (uint)(param_1 + 10) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
            param_1[10] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + uVar6;
            uVar4 = (uint)(param_1 + 0xe) & 3;
            uVar3 = *(uint *)((uint)(param_1 + 0xe) & 0xfffffffc);
            param_1[0xe] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + uVar6;
          }
          *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                     *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
                     uStack_7c;
        }
        uVar6 = param_2 + 0x10 & 3;
        uVar4 = *(uint *)(param_2 + 0x10 & 0xfffffffc);
        param_2 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
      } while (param_2 != 0);
      VecFx32_CrossProduct((uint)(uintptr_t)(param_1 + 10),(uint)(uintptr_t)(param_1 + 0xd),param_1 + 0x10);
      VecFx32_Normalize((uint)(uintptr_t)(param_1 + 10),param_1 + 10);
      VecFx32_Normalize((uint)(uintptr_t)(param_1 + 0x10),param_1 + 0x10);
      VecFx32_CrossProduct((uint)(uintptr_t)(param_1 + 0x10),(uint)(uintptr_t)(param_1 + 10),param_1 + 0xd);
      return 1;
    }
    uVar4 = uVar6 + 0xc & 3;
    uVar3 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
    (*(code *)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20))
              (param_1,uVar6,*(ushort *)(uVar6 + param_3 * 2 + 0x1a) & 0xff);
    return 1;
  }
  return 0;
}

