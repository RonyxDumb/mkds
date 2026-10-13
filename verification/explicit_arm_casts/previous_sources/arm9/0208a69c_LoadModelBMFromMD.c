/* Decompiled C draft; module arm9; ROM address 0208a69c. No matching claim. */
#include "types.h"
#include "deps/0208a69c_LoadModelBMFromMD.h"

void LoadModelBMFromMD(undefined4 param_1,undefined4 *param_2,byte *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  char acStack_a8 [132];
  
  *(ushort *)(param_2 + 4) = (ushort)*param_3;
  *param_2 = 0;
  param_2[3] = 0;
  uVar9 = (uint)(param_2 + 3) & 3;
  uVar3 = *(uint *)((uint)(param_2 + 3) & 0xfffffffc);
  param_2[2] = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
  uVar9 = (uint)(param_2 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
  bVar1 = false;
  param_2[1] = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
  if (*param_3 != 0) {
    uVar2 = Mem_AllocateHeap(param_1,(uint)*param_3 * 0x6c);
    *param_2 = uVar2;
  }
  if (param_3[1] != 0) {
    uVar2 = Mem_AllocateHeap(param_1,(uint)param_3[1] * 0x38);
    param_2[1] = uVar2;
  }
  if (param_3[2] != 0) {
    uVar2 = Mem_AllocateHeap(param_1,(uint)param_3[2] * 0x38);
    param_2[2] = uVar2;
  }
  if ((*param_3 == 1) && (1 < param_3[3])) {
    uVar2 = Mem_AllocateHeap(param_1,0x38);
    param_2[3] = uVar2;
    bVar1 = true;
  }
  else if (param_3[3] != 0) {
    uVar2 = Mem_AllocateHeap(param_1,(uint)param_3[3] * 0x38);
    param_2[3] = uVar2;
  }
  uVar9 = 0;
  if (*param_3 != 0) {
    do {
      uVar4 = *(uint *)((uint)param_2 & 0xfffffffc);
      uVar3 = (uint)(param_3 + uVar9 * 4 + 4) & 3;
      uVar6 = *(uint *)((uint)(param_3 + uVar9 * 4 + 4) & 0xfffffffc);
      _snprintf(acStack_a8,0x80,pcRam0208aa20,uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
      uVar2 = find_buf_fn_from_thumb(acStack_a8);
      Model_CreateFromNsbmdWithoutCullReverse
                (uVar9 * 0x6c +
                 (uVar4 >> ((uint)param_2 & 3) * 8 | uVar4 << ((uint)param_2 & 3) * -8 + 0x20),uVar2
                );
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < *param_3);
  }
  uVar9 = 0;
  if (param_3[1] != 0) {
    do {
      uVar6 = *(uint *)((uint)param_2 & 0xfffffffc);
      uVar3 = (uint)(param_3 + uVar9 * 4 + 4) & 3;
      uVar7 = *(uint *)((uint)(param_3 + uVar9 * 4 + 4) & 0xfffffffc);
      uVar4 = (uint)(param_2 + 1) & 3;
      uVar5 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
      iVar8 = uVar9 * 0x38 + (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
      _snprintf(acStack_a8,0x80,pcRam0208aa24,uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20);
      Animation_CreateFrom
                (0,iVar8,uVar9 * 0x6c +
                         (uVar6 >> ((uint)param_2 & 3) * 8 |
                         uVar6 << ((uint)param_2 & 3) * -8 + 0x20),1);
      uVar2 = find_buf_fn_from_thumb(acStack_a8);
      Animation_RegisterAll(iVar8,uVar2,param_1);
      Animation_SetAt(iVar8,0);
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < param_3[1]);
  }
  uVar9 = 0;
  if (param_3[2] != 0) {
    do {
      uVar4 = *(uint *)((uint)param_2 & 0xfffffffc);
      uVar3 = (uint)(param_2 + 2) & 3;
      uVar6 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
      iVar8 = uVar9 * 0x38 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
      uVar3 = (uint)(param_3 + uVar9 * 4 + 4) & 3;
      uVar6 = *(uint *)((uint)(param_3 + uVar9 * 4 + 4) & 0xfffffffc);
      _snprintf(acStack_a8,0x80,pcRam0208aa28,uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
      Animation_CreateFrom
                (4,iVar8,uVar9 * 0x6c +
                         (uVar4 >> ((uint)param_2 & 3) * 8 |
                         uVar4 << ((uint)param_2 & 3) * -8 + 0x20),1);
      uVar2 = find_buf_fn_from_thumb(acStack_a8);
      Animation_RegisterAll(iVar8,uVar2,param_1);
      Animation_SetAt(iVar8,0);
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < param_3[2]);
  }
  if (!bVar1) {
    return;
  }
  uVar9 = (uint)(param_2 + 3) & 3;
  uVar3 = *(uint *)((uint)(param_2 + 3) & 0xfffffffc);
  uVar3 = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
  Animation_CreateFrom
            (2,uVar3,*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                     *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20,
             param_3[3]);
  uVar9 = 0;
  if (param_3[3] != 0) {
    do {
      uVar4 = (uint)(param_3 + uVar9 * 4 + 4) & 3;
      uVar6 = *(uint *)((uint)(param_3 + uVar9 * 4 + 4) & 0xfffffffc);
      _snprintf(acStack_a8,0x80,pcRam0208aa2c,uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
      find_buf_fn_from_thumb(acStack_a8);
      uVar2 = MaybeLoadBTP0Format();
      uVar2 = BTP0_LoadRawData(uVar2,0);
      Animation_Register(uVar3,uVar9,uVar2,0);
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < param_3[3]);
  }
  Animation_SetAt(uVar3,0);
  return;
}

