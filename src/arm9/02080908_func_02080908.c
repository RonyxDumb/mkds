/* Decompiled C draft; module arm9; ROM address 02080908. No matching claim. */
#include "types.h"
#include "deps/02080908_func_02080908.h"

void func_02080908(int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  longlong lVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int local_54 [6];
  undefined1 auStack_3c [12];
  int local_30;
  int local_2c;
  int local_28;
  
  iVar10 = 0;
  uVar9 = (*(uint *)(uRam02080ab8 & 0xfffffffc) >> (uRam02080ab8 & 3) * 8 |
          *(uint *)(uRam02080ab8 & 0xfffffffc) << (uRam02080ab8 & 3) * -8 + 0x20) + 0xbc;
  uVar5 = uVar9 & 3;
  uVar8 = *(uint *)(uVar9 & 0xfffffffc);
  local_54[0] = 0;
  local_54[1] = 0;
  local_54[2] = 0;
  local_54[5] = 0xc8000;
  uVar11 = *(uint *)(uRam02080ab8 & 0xfffffffc) >> (uRam02080ab8 & 3) * 8 |
           *(uint *)(uRam02080ab8 & 0xfffffffc) << (uRam02080ab8 & 3) * -8 + 0x20;
  local_54[4] = 0xc8000;
  local_54[3] = 0xc8000;
  uVar9 = 0;
  iVar6 = -0x1000;
  if (*(short *)(uVar11 + 0x88) != 0) {
    do {
      uVar1 = uVar11 + 0x84 & 3;
      uVar11 = *(uint *)(uVar11 + 0x84 & 0xfffffffc);
      VecFx32_Subtract(uVar9 * 0x18 + (uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20),param_2,
                       (int *)(void *)(auStack_3c));
      iVar4 = VecFx32_Norm((uint)(uintptr_t)(auStack_3c));
      if (iVar4 < 0xc8000) {
        iVar7 = 0;
        do {
          if (iVar4 < local_54[iVar7 + 3]) {
            local_54[iVar7 + 3] = iVar4;
            local_54[iVar7] = uVar9 * 0x30 + (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
            break;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 3);
      }
      uVar11 = *(uint *)(uRam02080ab8 & 0xfffffffc) >> (uRam02080ab8 & 3) * 8 |
               *(uint *)(uRam02080ab8 & 0xfffffffc) << (uRam02080ab8 & 3) * -8 + 0x20;
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < *(ushort *)(uVar11 + 0x88));
  }
  uVar9 = 0;
  do {
    if (local_54[uVar9] != 0) {
      uVar5 = local_54[uVar9] + 0x20;
      uVar8 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      VecFx32_Subtract(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20,param_2,&local_30);
      lVar2 = (longlong)local_28 * (longlong)local_28 +
              (longlong)local_30 * (longlong)local_30 + (longlong)local_2c * (longlong)local_2c;
      if ((int)(uint)((uint)lVar2 < 0x10) <= (int)((ulonglong)lVar2 >> 0x20)) {
        Vector3_MaybeNormalize((uint)(uintptr_t)(&local_30),&local_30);
      }
      iVar4 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&local_30),param_3);
      if (iVar6 <= iVar4) {
        iVar10 = local_54[uVar9];
        iVar6 = iVar4;
      }
    }
    piVar3 = piRam02080abc;
    uVar9 = uVar9 + 1 & 0xffff;
  } while (uVar9 < 3);
  *param_1 = iVar10;
  param_1[1] = iVar10;
  iVar6 = piVar3[1];
  iVar10 = piVar3[2];
  param_1[2] = *piVar3;
  param_1[3] = iVar6;
  param_1[4] = iVar10;
  param_1[5] = 0;
  param_1[6] = 0;
  return;
}

