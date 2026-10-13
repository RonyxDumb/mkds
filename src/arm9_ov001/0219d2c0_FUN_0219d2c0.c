/* Decompiled C draft; module arm9_ov001; ROM address 0219d2c0. No matching claim. */
#include "types.h"
#include "deps/0219d2c0_FUN_0219d2c0.h"

void FUN_0219d2c0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 local_24;
  undefined1 local_18 [4];
  
  uVar3 = func_0x020369fc();
  iVar4 = func_0x02036bec(uVar3,DAT_0219d4ac);
  piVar1 = DAT_0219d4b0;
  *DAT_0219d4b0 = iVar4;
  *(undefined4 *)(iVar4 + DAT_0219d4b4) = uVar3;
  *(undefined4 *)*piVar1 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0x1c) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = 1;
  *(undefined4 *)(*piVar1 + 0x24) = 0xfffffffc;
  uVar3 = func_0x0204799c(DAT_0219d4b8);
  *(undefined4 *)(*DAT_0219d4b0 + DAT_0219d4bc) = uVar3;
  uVar3 = func_0x02047a28(DAT_0219d4c0);
  *(undefined4 *)(*DAT_0219d4b0 + DAT_0219d4c4) = uVar3;
  FUN_0219d03c();
  FUN_0219cf60();
  iVar4 = DAT_0219d4cc;
  piVar1 = DAT_0219d4b0;
  iVar8 = 0;
  puVar7 = DAT_0219d4c8;
  do {
    func_0x02124a98(*puVar7,1,*(undefined4 *)(*piVar1 + DAT_0219d4d0),
                    *(undefined4 *)(*piVar1 + iVar4));
    piVar2 = DAT_0219d4b0;
    puVar7 = puVar7 + 3;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 6);
  *(undefined4 *)(*DAT_0219d4b0 + DAT_0219d4d4) = param_3;
  *(undefined4 *)(*piVar2 + DAT_0219d4d8) = param_4;
  func_0x020ae6d4(param_3,param_4);
  piVar1 = DAT_0219d4b0;
  iVar4 = 0;
  iVar8 = 0;
  do {
    iVar6 = DAT_0219d4e4;
    iVar5 = *piVar1;
    func_0x02124ed0(*(undefined4 *)(iVar5 + DAT_0219d4b4),
                    *(undefined4 *)(iVar5 + iVar8 + DAT_0219d4dc),
                    *(undefined4 *)(iVar5 + iVar8 + DAT_0219d4e0),(undefined4 *)(uintptr_t)(iVar5 + DAT_0219d4e4 + iVar8));
    piVar2 = DAT_0219d4b0;
    iVar8 = iVar8 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  *(undefined2 *)(*(int *)(*DAT_0219d4b0 + iVar6) + 6) = 0xff60;
  *(undefined4 *)(*piVar2 + 0x14) = 0xa0;
  FUN_0219cec4();
  iVar4 = DAT_0219d4e8;
  piVar1 = DAT_0219d4b0;
  iVar8 = 0;
  puVar7 = DAT_0219d4c8;
  do {
    iVar6 = 0;
    do {
      *(undefined2 *)(*(int *)(*piVar1 + iVar4) + (uint)(byte)puVar7[iVar6] * 0x40 + 4) = 0xdc;
      iVar5 = DAT_0219d4f4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    puVar7 = puVar7 + 3;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 6);
  local_18[0] = *DAT_0219d4ec;
  local_18[1] = DAT_0219d4ec[1];
  local_18[2] = *DAT_0219d4f0;
  local_18[3] = DAT_0219d4f0[1];
  local_24 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + DAT_0219d4bc),6);
  if (param_2 == 0) {
    local_24 = func_0x020b3f7c(*(undefined4 *)(*DAT_0219d4b0 + DAT_0219d4bc),7);
  }
  iVar4 = 0;
  puVar9 = local_18 + 2;
  puVar7 = local_18;
  do {
    iVar8 = *DAT_0219d4b0;
    iVar8 = func_0x021243ac(*(undefined4 *)(iVar8 + DAT_0219d4b4),*puVar7,
                            *(undefined4 *)(iVar8 + DAT_0219d4e0),0xa8,0xd,*puVar9,
                            *(undefined4 *)(iVar8 + DAT_0219d4f8),
                            *(undefined4 *)(iVar8 + DAT_0219d4dc),
                            *(undefined4 *)(iVar8 + DAT_0219d4e4),iVar5);
    iVar5 = iVar5 - iVar8;
    iVar8 = *DAT_0219d4b0;
    func_0x0212426c(0,*puVar7,*(undefined4 *)(iVar8 + DAT_0219d4e0),local_24,
                    *(undefined4 *)(iVar8 + DAT_0219d4dc),*(undefined4 *)(iVar8 + DAT_0219d4e4));
    puVar9 = puVar9 + 1;
    puVar7 = puVar7 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  if (param_2 == 1) {
    *(undefined4 *)(*(int *)(*DAT_0219d4b0 + DAT_0219d4e4) + DAT_0219d4fc) = 0;
  }
  else {
    *(undefined4 *)(*(int *)(*DAT_0219d4b0 + DAT_0219d4e4) + DAT_0219d500) = 0;
  }
  *DAT_0219d504 = *DAT_0219d504 & 0x43 | (ushort)DAT_0219d508;
  func_0x021281c8(0xe);
  return;
}

