/* Decompiled C draft; module arm9; ROM address 0202fbc8. No matching claim. */
#include "types.h"
#include "deps/0202fbc8_Maybe_multi_select_member_s_group.h"

void Maybe_multi_select_member_s_group(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  int local_20;
  
  uVar2 = Mem_CreateOrphanChildHeap();
  iVar3 = Mem_AllocateHeap(uVar2,0xa8);
  *piRam0202fcf0 = iVar3;
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(iVar3),0xa8);
  piVar1 = piRam0202fcf0;
  *(undefined4 *)(*piRam0202fcf0 + 0xa4) = uVar2;
  *(undefined4 *)(*piVar1 + 0x40) = param_2;
  *(undefined4 *)(*piVar1 + 0x44) = param_3;
  uVar2 = find_buf_fn_from_thumb(uRam0202fcf4);
  piVar1 = piRam0202fcf0;
  *(undefined4 *)(*piRam0202fcf0 + 0xa0) = uVar2;
  *(undefined4 *)(*piVar1 + 0x4c) = 0;
  *(undefined4 *)(*piVar1 + 0x90) = 0xffffff40;
  func_020258d4(1,*piVar1,uRam0202fd00,uRam0202fd04,uRam0202fcf8,3,uRam0202fcfc);
  iVar3 = func_02148ca0();
  iVar6 = *piRam0202fcf0;
  iVar7 = iVar6 + 0x24;
  func_02025b20(iVar7,uRam0202fd14,uRam0202fd18,uRam0202fd1c,uRam0202fd08,uRam0202fd0c,uRam0202fd10,
                uRam0202fcfc);
  func_02025a50(1,*(undefined4 *)(*piRam0202fcf0 + 0xa4),(int *)(uintptr_t)(iVar7));
  local_20 = 0;
  psVar5 = psRam0202fd20;
  psVar8 = psRam0202fd20;
  do {
    iVar4 = func_02025a00(1,*(undefined4 *)(*piRam0202fcf0 + 0xa4),iVar7,psVar8,iVar3);
    iVar3 = iVar3 - iVar4;
    uVar2 = uRam0202fd24;
    if (-1 < *(int *)(psVar5 + 4)) {
      uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0202fcf0 + 0xa0));
    }
    func_0212426c(1,(int)*psVar5,*(undefined4 *)(iVar6 + 0x38),uVar2,*(undefined4 *)(iVar6 + 0x30),
                  *(undefined4 *)(iVar6 + 0x3c));
    psVar8 = psVar8 + 6;
    psVar5 = psVar5 + 6;
    local_20 = local_20 + 1;
  } while (local_20 < 5);
  func_0203003c(1);
  func_021281c8(0xf);
  *(undefined4 *)(*piRam0202fd28 + 0x20) = 2;
  func_02036820(*(undefined4 *)(*piRam0202fcf0 + 0xa4));
  return;
}

