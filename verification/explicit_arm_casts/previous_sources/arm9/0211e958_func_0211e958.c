/* Decompiled C draft; module arm9; ROM address 0211e958. No matching claim. */
#include "types.h"
#include "deps/0211e958_func_0211e958.h"

void func_0211e958(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  int local_28;
  undefined2 *local_24;
  int local_20;
  int local_1c;
  
  puVar1 = puRam0211eaf8;
  *puRam0211eaf8 = *puRam0211eaf8 & 0xfffc | 1;
  puVar2 = puRam0211eafc;
  *puRam0211eafc = *puRam0211eafc & 0xfffc | 1;
  *puVar1 = *puVar1 & 0x43 | (ushort)uRam0211eb00;
  *puVar2 = *puVar2 & 0x43 | (ushort)uRam0211eb04;
  uVar4 = Mem_CreateOrphanChildHeap();
  iVar5 = Mem_AllocateHeap(uVar4,0x54);
  piVar3 = piRam0211eb08;
  *piRam0211eb08 = iVar5;
  *(undefined4 *)(iVar5 + 0x28) = uVar4;
  *(undefined4 *)(*piVar3 + 0x38) = 0;
  *(undefined4 *)(*piVar3 + 0x48) = param_2;
  *(undefined4 *)(*piVar3 + 0x4c) = param_3;
  *(undefined4 *)(*piVar3 + 0x50) = 0;
  iVar5 = func_020cccb4();
  if ((iVar5 == 0x19) || (iVar5 = func_020cccb4(), iVar5 == 0xd)) {
    *(undefined4 *)(*piRam0211eb08 + 0x2c) = 1;
  }
  else {
    *(undefined4 *)(*piRam0211eb08 + 0x2c) = 0;
  }
  func_0211efec();
  uVar4 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0211eb0c);
  piVar3 = piRam0211eb08;
  *(undefined4 *)(*piRam0211eb08 + 0x24) = uVar4;
  if (*psRam0211eb10 == 2) {
    iVar5 = *piVar3;
    func_0211f4b0(*(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 0x4c));
    func_0211f380();
  }
  else {
    iVar5 = *piVar3;
    func_02124ed0(*(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 4),
                  *(undefined4 *)(iVar5 + 8),iVar5 + 0x18);
    iVar5 = *piRam0211eb08;
    func_02124ed0(*(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 0x10),
                  *(undefined4 *)(iVar5 + 0x14),iVar5 + 0x1c);
    local_28 = 0;
    local_24 = puRam0211eb24;
    puVar8 = puRam0211eb18;
    iVar5 = iRam0211eb14;
    puVar9 = puRam0211eb1c;
    puVar10 = puRam0211eb20;
    do {
      puVar7 = (undefined4 *)*piRam0211eb08;
      iVar6 = func_021243ac(puVar7[10],*local_24,puVar7[2],*puVar10,*puVar9,*puVar8,*puVar7,
                            puVar7[1],puVar7[6],iVar5);
      iVar5 = iVar5 - iVar6;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      local_24 = local_24 + 1;
      local_28 = local_28 + 1;
    } while (local_28 < 4);
    local_1c = func_02148ca0();
    local_20 = 0;
    puVar8 = puRam0211eb1c;
    puVar9 = puRam0211eb18;
    puVar10 = puRam0211eb20;
    puVar11 = puRam0211eb24;
    do {
      iVar5 = *piRam0211eb08;
      iVar5 = func_021243ac(*(undefined4 *)(iVar5 + 0x28),*puVar11,*(undefined4 *)(iVar5 + 0x14),
                            *puVar10,*puVar8,*puVar9,*(undefined4 *)(iVar5 + 0xc),
                            *(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar5 + 0x1c),local_1c);
      local_1c = local_1c - iVar5;
      puVar9 = puVar9 + 1;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
      local_20 = local_20 + 1;
    } while (local_20 < 4);
    func_0211de40(*(undefined4 *)(*piRam0211eb08 + 0x28));
  }
  func_0211ed80();
  iVar5 = func_020cccb4();
  if ((iVar5 == 0x19) || (iVar5 = func_020cccb4(), iVar5 == 0xd)) {
    func_0211eb28();
  }
  else {
    func_0211ec54();
  }
  func_02036820(*(undefined4 *)(*piRam0211eb08 + 0x28));
  return;
}

