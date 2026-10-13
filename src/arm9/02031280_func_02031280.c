/* Decompiled C draft; module arm9; ROM address 02031280. No matching claim. */
#include "types.h"
#include "deps/02031280_func_02031280.h"

void func_02031280(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 auStack_2a [20];
  undefined2 local_16;
  
  Maybe_multi_select_member_m();
  iVar8 = *piRam02031448;
  *(undefined4 *)(iVar8 + 0x70) = 2;
  puVar4 = (uint *)func_0202f14c();
  uVar5 = func_0204fe90(*puVar4 & 0xffff);
  *(undefined4 *)(*piRam02031448 + 0x84) = uVar5;
  Mem_CpuFill16(0,(int)(uintptr_t)(auStack_2a),0x16);
  if (*(int *)(*piRam02031448 + 0x84) == 0) {
    puVar4 = (uint *)func_0202f14c();
    iVar6 = func_0204ff14(*puVar4 & 0xffff,(int)(uintptr_t)(auStack_2a));
    if (iVar6 != 0) {
      local_16 = 0;
      func_0212426c(1,(int)*psRam0203144c,*(undefined4 *)(iVar8 + 0x54),auStack_2a,
                    *(undefined4 *)(iVar8 + 0x4c),*(undefined4 *)(iVar8 + 0x58));
      *(undefined4 *)(*piRam02031448 + 0x80) = 1;
    }
  }
  iVar6 = iRam02031450;
  *(undefined4 *)(*(int *)(iVar8 + 0x58) + iRam02031450) = 0;
  *(undefined4 *)(*(int *)(iVar8 + 0x58) + iRam02031454) =
       *(undefined4 *)(*(int *)(iVar8 + 0x58) + iVar6);
  uVar5 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02031448 + 100),10);
  if (*(int *)(*piRam02031448 + 0x84) == 0) {
    TextSystem_DisplayProgressDialog_TopScreen_from_thumb(uVar5,0,0,1,0,0,0);
  }
  else {
    TextSystem_DisplayProgressDialog_from_thumb(uVar5,0,0,1,0,1);
  }
  iVar6 = iRam02031458;
  if (*(int *)(*piRam02031448 + 0x84) != 0) {
    uVar7 = (uint)*(ushort *)(*(int *)(iVar8 + 0x38) + 6);
    uVar1 = *(ushort *)(*(int *)(iVar8 + 0x30) + 6);
    uVar2 = *(ushort *)(*(int *)(iVar8 + 0x54) + 6);
    uVar3 = *(ushort *)(*(int *)(iVar8 + 0x4c) + 6);
    iVar10 = 0;
    *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iRam02031458) = 0;
    iVar9 = iRam0203145c;
    *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iRam0203145c) =
         *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iVar6);
    iVar6 = iRam02031460;
    *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iRam02031460) =
         *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iVar9);
    iVar9 = iRam02031464;
    *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iRam02031464) =
         *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iVar6);
    iVar6 = iRam02031468;
    *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iRam02031468) =
         *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iVar9);
    iVar9 = iRam0203146c;
    *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iRam0203146c) =
         *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iVar6);
    iVar6 = iRam02031470;
    *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iRam02031470) =
         *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iVar9);
    iVar9 = iRam02031474;
    *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iRam02031474) =
         *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iVar6);
    *(undefined4 *)(*(int *)(iVar8 + 0x3c) + 0xc0) = *(undefined4 *)(*(int *)(iVar8 + 0x3c) + iVar9)
    ;
    iVar9 = 0;
    iVar6 = 0;
    do {
      *(undefined4 *)
       (*(int *)(iVar8 + 0x58) + (uint)*(ushort *)(*piRam02031448 + iVar9 + 0xea) * 0x40) = 0;
      *(undefined4 *)
       (*(int *)(iVar8 + 0x58) + (uint)*(ushort *)(*piRam02031448 + iVar9 + 0xe8) * 0x40) =
           *(undefined4 *)
            (*(int *)(iVar8 + 0x58) + (uint)*(ushort *)(*piRam02031448 + iVar9 + 0xea) * 0x40);
      iVar9 = iVar9 + 0xc;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 8);
    if (uVar7 != 0) {
      do {
        *(undefined4 *)(*(int *)(iVar8 + 0x3c) + (iVar6 + (uint)uVar1) * 0x40) = 0;
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)uVar7);
    }
    iVar6 = 0;
    iVar9 = (uint)uVar3 + (uint)uVar2;
    if (iVar9 != 0) {
      iVar10 = 0;
      do {
        *(undefined4 *)(*(int *)(iVar8 + 0x58) + iVar10) = 0;
        iVar10 = iVar10 + 0x40;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar9);
    }
  }
  func_021281c8(0xffffffff);
  func_02036820(*(undefined4 *)(*piRam02031448 + iRam02031478));
  return;
}

