/* Decompiled C draft; module arm9; ROM address 020338f8. No matching claim. */
#include "types.h"
#include "deps/020338f8_func_020338f8.h"

void func_020338f8(undefined4 param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_38;
  undefined1 auStack_2a [22];
  
  iVar7 = *piRam02033a04;
  iVar3 = func_02148cb8();
  piVar2 = piRam02033a04;
  iVar6 = 0;
  uVar1 = *(ushort *)(*(int *)(iVar7 + 0x54) + 6);
  *(undefined2 *)(*piRam02033a04 + 0xcc) = 8;
  *(undefined2 *)(*piVar2 + 0xce) = 0x12;
  iVar8 = 0;
  if (*(short *)(*(int *)(iVar7 + 0x5c) + 6) != 0) {
    local_38 = iRam02033a08;
    do {
      iVar4 = func_02025a00(0,param_1,iVar7 + 0x48,(short *)(uintptr_t)(local_38),iVar3);
      iVar3 = iVar3 - iVar4;
      local_38 = local_38 + 8;
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)(uint)*(ushort *)(*(int *)(iVar7 + 0x5c) + 6));
  }
  uVar5 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02033a04 + 200),0x7a);
  func_0212426c(0,0,*(undefined4 *)(iVar7 + 0x5c),uVar5,*(undefined4 *)(iVar7 + 0x54),
                *(undefined4 *)(iVar7 + 0x60));
  uVar9 = 0;
  iVar3 = *piRam02033a04;
  if (0 < *(int *)(iVar3 + 0xd8)) {
    iVar8 = 0;
    do {
      if (*(int *)(iVar3 + iVar8 + 0xe4) == 0) {
        Mem_CpuFill16(0,(int)(uintptr_t)(auStack_2a),0x16);
        FormatRacerNameString_from_thumb(uVar9 & 0xffff,(int)(uintptr_t)(auStack_2a),1);
        iVar6 = iVar6 + 1;
        func_0212426c(0,iVar6,*(undefined4 *)(iVar7 + 0x5c),auStack_2a,*(undefined4 *)(iVar7 + 0x54)
                      ,*(undefined4 *)(iVar7 + 0x60));
      }
      iVar8 = iVar8 + 0xc;
      uVar9 = uVar9 + 1;
      iVar3 = *piRam02033a04;
    } while ((int)uVar9 < *(int *)(iVar3 + 0xd8));
  }
  while (iVar6 < 7) {
    iVar6 = iVar6 + 1;
    *(undefined4 *)(*(int *)(iVar7 + 0x60) + iVar6 * 0x40) = 0;
    *(undefined4 *)(*(int *)(iVar7 + 0x60) + (iVar6 + (uint)uVar1) * 0x40) = 0;
  }
  return;
}

