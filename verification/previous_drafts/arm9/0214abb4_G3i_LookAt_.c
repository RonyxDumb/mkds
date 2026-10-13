/* Decompiled C draft; module arm9; ROM address 0214abb4. No matching claim. */
#include "types.h"
#include "deps/0214abb4_G3i_LookAt_.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void G3i_LookAt_(uint param_1,undefined4 param_2,uint param_3,int param_4,int *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *unaff_r4;
  uint uVar6;
  uint uVar7;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  local_40 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
             (*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
             *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20);
  uVar1 = param_1 + 4 & 3;
  uVar7 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = param_3 + 4 & 3;
  uVar6 = *(uint *)(param_3 + 4 & 0xfffffffc);
  local_3c = (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) -
             (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
  uVar1 = param_1 + 8 & 3;
  uVar7 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar2 = param_3 + 8 & 3;
  uVar6 = *(uint *)(param_3 + 8 & 0xfffffffc);
  local_38 = (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) -
             (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
  VecFx32_Normalize((uint)(uintptr_t)(&local_40),&local_40);
  VecFx32_CrossProduct(param_2,(uint)(uintptr_t)(&local_40),&local_34);
  VecFx32_Normalize((uint)(uintptr_t)(&local_34),&local_34);
  VecFx32_CrossProduct((uint)(uintptr_t)(&local_40),(uint)(uintptr_t)(&local_34),&local_28);
  if (param_4 != 0) {
    *puRam0214ad44 = 2;
    unaff_r4 = piRam0214ad48;
    *piRam0214ad48 = local_34;
    *unaff_r4 = local_28;
    *unaff_r4 = local_40;
    *unaff_r4 = local_30;
    *unaff_r4 = local_24;
    *unaff_r4 = local_3c;
    *unaff_r4 = local_2c;
    *unaff_r4 = local_20;
    *unaff_r4 = local_38;
  }
  iVar3 = Vector3_DotProduct(param_1,(uint)(uintptr_t)(&local_34));
  iVar4 = Vector3_DotProduct(param_1,(uint)(uintptr_t)(&local_28));
  iVar5 = Vector3_DotProduct(param_1,(uint)(uintptr_t)(&local_40));
  if (param_4 != 0) {
    *unaff_r4 = -iVar3;
  }
  if (param_4 != 0) {
    *unaff_r4 = -iVar4;
    *unaff_r4 = -iVar5;
  }
  if (param_5 != (int *)0x0) {
    *param_5 = local_34;
    param_5[1] = local_28;
    param_5[2] = local_40;
    param_5[3] = local_30;
    param_5[4] = local_24;
    param_5[5] = local_3c;
    param_5[6] = local_2c;
    param_5[7] = local_20;
    param_5[8] = local_38;
    param_5[9] = -iVar3;
    param_5[10] = -iVar4;
    param_5[0xb] = -iVar5;
    return;
  }
  return;
}

