/* Decompiled C draft; module arm9_ov001; ROM address 02196960. No matching claim. */
#include "types.h"
#include "deps/02196960_FUN_02196960.h"

void FUN_02196960(undefined4 param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  undefined2 *local_28;
  undefined2 *local_24;
  undefined2 *local_20;
  undefined2 *local_1c;
  undefined2 *local_18;
  
  puVar1 = DAT_02196c00;
  *DAT_02196c00 = *DAT_02196c00 & 0xfffc | 1;
  puVar2 = DAT_02196c04;
  *DAT_02196c04 = *DAT_02196c04 & 0xfffc | 1;
  puVar3 = DAT_02196c08;
  *DAT_02196c08 = *DAT_02196c08 & 0xfffc | 1;
  *puVar1 = *puVar1 & 0x43 | (ushort)DAT_02196c0c;
  *puVar2 = *puVar2 & 0x43 | (ushort)DAT_02196c10;
  *DAT_02196c14 = *DAT_02196c14 & 0x43 | (ushort)DAT_02196c18;
  *puVar3 = *puVar3 & 0x43 | (ushort)DAT_02196c1c;
  iVar5 = func_0x02036bec(param_1,0x94);
  piVar4 = DAT_02196c20;
  *DAT_02196c20 = iVar5;
  *(undefined4 *)(iVar5 + 0x4c) = param_1;
  iVar5 = 0;
  *(undefined4 *)(*piVar4 + 0x50) = 0;
  *(undefined4 *)(*piVar4 + 0x6c) = 0;
  *(undefined4 *)(*piVar4 + 0x70) = 0;
  *(undefined4 *)(*piVar4 + 0x74) = 0;
  *(undefined4 *)(*piVar4 + 0x88) = 0;
  *(undefined4 *)(*piVar4 + 0x8c) = 0;
  iVar10 = 0;
  do {
    *(undefined4 *)(*piVar4 + iVar10 + 0x78) = 0;
    iVar10 = iVar10 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  FUN_021978b4();
  func_0x021172a8(param_1);
  uVar6 = func_0x02111318();
  uVar7 = func_0x0211130c();
  func_0x020ae6d4(uVar6,uVar7);
  iVar5 = *DAT_02196c20;
  func_0x02124ed0(param_1,*(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0x10),(undefined4 *)(uintptr_t)(iVar5 + 0x38));
  iVar5 = *DAT_02196c20;
  func_0x02124ed0(param_1,*(undefined4 *)(iVar5 + 0x1c),*(undefined4 *)(iVar5 + 0x24),(undefined4 *)(uintptr_t)(iVar5 + 0x3c));
  uVar6 = func_0x02047a28(DAT_02196c24);
  *(undefined4 *)(*DAT_02196c20 + 0x40) = uVar6;
  uVar6 = func_0x0204799c(DAT_02196c28);
  *(undefined4 *)(*DAT_02196c20 + 0x44) = uVar6;
  uVar6 = func_0x0204799c(DAT_02196c2c);
  piVar4 = DAT_02196c20;
  *(undefined4 *)(*DAT_02196c20 + 0x48) = uVar6;
  iVar5 = DAT_02196c30;
  iVar10 = *piVar4;
  iVar10 = func_0x021243ac(param_1,0,*(undefined4 *)(iVar10 + 0x10),200,0x10,0,
                           *(undefined4 *)(iVar10 + 4),*(undefined4 *)(iVar10 + 8),
                           *(undefined4 *)(iVar10 + 0x38),DAT_02196c30);
  iVar8 = *DAT_02196c20;
  iVar8 = func_0x021243ac(param_1,1,*(undefined4 *)(iVar8 + 0x10),0x46,0x10,1,
                          *(undefined4 *)(iVar8 + 4),*(undefined4 *)(iVar8 + 8),
                          *(undefined4 *)(iVar8 + 0x38),iVar5 - iVar10);
  iVar8 = (iVar5 - iVar10) - iVar8;
  iVar5 = *DAT_02196c20;
  iVar5 = func_0x021243ac(param_1,2,*(undefined4 *)(iVar5 + 0x10),0x46,0x10,2,
                          *(undefined4 *)(iVar5 + 4),*(undefined4 *)(iVar5 + 8),
                          *(undefined4 *)(iVar5 + 0x38),iVar8);
  iVar8 = iVar8 - iVar5;
  iVar5 = *DAT_02196c20;
  iVar5 = func_0x021243ac(param_1,3,*(undefined4 *)(iVar5 + 0x10),0x7c,0x10,3,
                          *(undefined4 *)(iVar5 + 4),*(undefined4 *)(iVar5 + 8),
                          *(undefined4 *)(iVar5 + 0x38),iVar8);
  iVar10 = *DAT_02196c20;
  func_0x021243ac(param_1,4,*(undefined4 *)(iVar10 + 0x10),100,0x10,4,*(undefined4 *)(iVar10 + 4),
                  *(undefined4 *)(iVar10 + 8),*(undefined4 *)(iVar10 + 0x38),iVar8 - iVar5);
  iVar5 = func_0x02148ca0();
  iVar10 = 1;
  local_28 = DAT_02196c38;
  local_24 = DAT_02196c3c;
  local_20 = DAT_02196c40;
  local_1c = DAT_02196c44;
  local_18 = DAT_02196c48;
  puVar11 = DAT_02196c34;
  do {
    iVar8 = *DAT_02196c20;
    iVar8 = func_0x021243ac(param_1,*local_24,*(undefined4 *)(iVar8 + 0x24),*local_28,*puVar11,
                            iVar10,*(undefined4 *)(iVar8 + 0x18),*(undefined4 *)(iVar8 + 0x1c),
                            *(undefined4 *)(iVar8 + 0x3c),iVar5);
    iVar9 = *DAT_02196c20;
    iVar9 = func_0x021243ac(param_1,*local_18,*(undefined4 *)(iVar9 + 0x24),*local_1c,*local_20,
                            iVar10 + 5,*(undefined4 *)(iVar9 + 0x18),*(undefined4 *)(iVar9 + 0x1c),
                            *(undefined4 *)(iVar9 + 0x3c),iVar5 - iVar8);
    iVar5 = (iVar5 - iVar8) - iVar9;
    puVar11 = puVar11 + 1;
    local_28 = local_28 + 1;
    local_24 = local_24 + 1;
    local_20 = local_20 + 1;
    local_1c = local_1c + 1;
    local_18 = local_18 + 1;
    iVar10 = iVar10 + 1;
  } while (iVar10 < 5);
  iVar10 = *DAT_02196c20;
  func_0x021243ac(param_1,8,*(undefined4 *)(iVar10 + 0x24),0x98,0x10,0xd,
                  *(undefined4 *)(iVar10 + 0x18),*(undefined4 *)(iVar10 + 0x1c),
                  *(undefined4 *)(iVar10 + 0x3c),iVar5);
  iVar5 = *DAT_02196c20;
  uVar6 = func_0x020b3f7c(*(undefined4 *)(iVar5 + 0x48),3);
  func_0x0212426c(1,8,*(undefined4 *)(*DAT_02196c20 + 0x24),uVar6,*(undefined4 *)(iVar5 + 0x1c),
                  *(undefined4 *)(iVar5 + 0x3c));
  FUN_02197058();
  return;
}

