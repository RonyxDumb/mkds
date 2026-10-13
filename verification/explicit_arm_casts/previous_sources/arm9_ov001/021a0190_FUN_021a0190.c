/* Decompiled C draft; module arm9_ov001; ROM address 021a0190. No matching claim. */
#include "types.h"
#include "deps/021a0190_FUN_021a0190.h"

void FUN_021a0190(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort *puVar1;
  int *piVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  ushort *puVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  int local_20;
  int local_1c;
  
  puVar9 = DAT_021a0368;
  *DAT_021a0368 = *DAT_021a0368 & 0xfffc | 1;
  puVar1 = DAT_021a036c;
  *DAT_021a036c = *DAT_021a036c & 0xfffc | 1;
  *puVar9 = *puVar9 & 0x43 | (ushort)DAT_021a0370;
  *puVar1 = *puVar1 & 0x43 | (ushort)DAT_021a0374;
  uVar4 = func_0x02036948();
  iVar5 = func_0x02036bec(uVar4,0xc0);
  piVar2 = DAT_021a0378;
  *DAT_021a0378 = iVar5;
  *(undefined4 *)(iVar5 + 0x5c) = uVar4;
  *(undefined4 *)(*piVar2 + 0x60) = 0;
  sVar3 = func_0x020295f8();
  piVar2 = DAT_021a0378;
  *(short *)(*DAT_021a0378 + 0x9e) = sVar3 + -1;
  iVar5 = 0;
  *(undefined2 *)(*piVar2 + 0x9c) = 0;
  *(undefined4 *)(*piVar2 + 0xac) = 0;
  *(undefined4 *)(*piVar2 + 0xa4) = 0;
  *(undefined4 *)(*piVar2 + 0xb4) = param_2;
  *(undefined4 *)(*piVar2 + 0xb8) = param_3;
  *(undefined4 *)(*piVar2 + 0xbc) = 0;
  iVar8 = 0;
  do {
    *(undefined4 *)(*piVar2 + iVar8 + 0x6c) = 0;
    iVar8 = iVar8 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 9);
  FUN_021a0e34();
  FUN_021a0e7c();
  func_0x020ae6d4(*(undefined4 *)(*DAT_021a0378 + 0xb4),*(undefined4 *)(*DAT_021a0378 + 0xb8));
  iVar5 = *DAT_021a0378;
  func_0x02124ed0(*(undefined4 *)(iVar5 + 0x5c),*(undefined4 *)(iVar5 + 4),
                  *(undefined4 *)(iVar5 + 8),iVar5 + 0x40);
  iVar5 = *DAT_021a0378;
  func_0x02124ed0(*(undefined4 *)(iVar5 + 0x5c),*(undefined4 *)(iVar5 + 0x10),
                  *(undefined4 *)(iVar5 + 0x18),iVar5 + 0x44);
  uVar4 = func_0x02047a28(DAT_021a037c);
  *(undefined4 *)(*DAT_021a0378 + 0x54) = uVar4;
  uVar4 = func_0x0204799c(DAT_021a0380);
  *(undefined4 *)(*DAT_021a0378 + 0x58) = uVar4;
  uVar4 = func_0x02047a28(DAT_021a0384);
  *(undefined4 *)(*DAT_021a0378 + 0x4c) = uVar4;
  iVar5 = func_0x0204799c(DAT_021a0388);
  piVar2 = DAT_021a0378;
  *(int *)(*DAT_021a0378 + 0x50) = iVar5 + 8;
  puVar6 = (undefined4 *)*piVar2;
  func_0x021243ac(puVar6[0x17],0,puVar6[2],0xd2,0x46,0,*puVar6,puVar6[1],puVar6[0x10],DAT_021a038c);
  iVar5 = func_0x02148ca0();
  local_1c = 0;
  local_20 = DAT_021a0390;
  puVar9 = DAT_021a039c;
  puVar10 = DAT_021a0394;
  puVar11 = DAT_021a0398;
  do {
    iVar8 = *DAT_021a0378;
    iVar8 = func_0x021243ac(*(undefined4 *)(iVar8 + 0x5c),*puVar9,*(undefined4 *)(iVar8 + 0x18),
                            *puVar11,*puVar10,*(undefined2 *)(local_20 + 10),
                            *(undefined4 *)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 0x10),
                            *(undefined4 *)(iVar8 + 0x44),iVar5);
    iVar7 = *DAT_021a0378;
    iVar7 = func_0x021243ac(*(undefined4 *)(iVar7 + 0x5c),puVar9[1],*(undefined4 *)(iVar7 + 0x18),
                            puVar11[1],puVar10[1],
                            (uint)*puVar9 + (uint)*(ushort *)(*(int *)(iVar7 + 0x10) + 6),
                            *(undefined4 *)(iVar7 + 0xc),*(int *)(iVar7 + 0x10),
                            *(undefined4 *)(iVar7 + 0x44),iVar5 - iVar8);
    iVar5 = (iVar5 - iVar8) - iVar7;
    local_20 = local_20 + 0x12;
    puVar10 = puVar10 + 2;
    puVar11 = puVar11 + 2;
    puVar9 = puVar9 + 2;
    local_1c = local_1c + 1;
  } while (local_1c < 9);
  FUN_021a64ac(*(undefined4 *)(*DAT_021a0378 + 0x5c));
  FUN_021a0b3c();
  *(undefined2 *)(*DAT_021a0378 + 0xb0) = *(undefined2 *)(*DAT_021a0378 + 0x9e);
  FUN_021a0774();
  FUN_021a04f0();
  func_0x02036820(*(undefined4 *)(*DAT_021a0378 + 0x5c));
  return;
}

