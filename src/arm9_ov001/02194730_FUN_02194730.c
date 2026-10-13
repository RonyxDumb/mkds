/* Decompiled C draft; module arm9_ov001; ROM address 02194730. No matching claim. */
#include "types.h"
#include "deps/02194730_FUN_02194730.h"

void FUN_02194730(undefined4 param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  uint local_40;
  undefined2 *local_3c;
  undefined2 *local_38;
  undefined2 *local_34;
  undefined2 *local_30;
  undefined2 *local_2c;
  undefined2 *local_28;
  undefined2 *local_24;
  undefined2 *local_20;
  
  puVar1 = DAT_02194960;
  local_40 = 0;
  *DAT_02194960 = *DAT_02194960 & 0xfffc | 1;
  puVar2 = DAT_02194964;
  *DAT_02194964 = *DAT_02194964 & 0xfffc | 1;
  *puVar1 = *puVar1 & 0x43 | (ushort)DAT_02194968;
  *DAT_0219496c = *DAT_0219496c & 0x43 | (ushort)DAT_02194970;
  *puVar2 = *puVar2 & 0x43 | (ushort)DAT_02194974;
  iVar4 = func_0x02036bec(param_1,0x94);
  piVar3 = DAT_02194978;
  *DAT_02194978 = iVar4;
  *(undefined4 *)(iVar4 + 0x5c) = param_1;
  iVar4 = 0;
  *(undefined4 *)(*piVar3 + 0x60) = 0;
  *(undefined4 *)(*piVar3 + 0x78) = 0;
  *(undefined4 *)(*piVar3 + 0x7c) = 0;
  *(undefined4 *)(*piVar3 + 0x88) = 0;
  *(undefined4 *)(*piVar3 + 0x8c) = 0;
  iVar10 = 0;
  do {
    *(undefined4 *)(*piVar3 + iVar10 + 0x80) = 0;
    iVar10 = iVar10 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  FUN_021953d0();
  func_0x021172a8(param_1);
  func_0x0211dfb4(param_1);
  uVar5 = func_0x02111318();
  uVar6 = func_0x0211130c();
  func_0x020ae6d4(uVar5,uVar6);
  iVar4 = *DAT_02194978;
  func_0x02124ed0(param_1,*(undefined4 *)(iVar4 + 8),*(undefined4 *)(iVar4 + 0x10),(undefined4 *)(uintptr_t)(iVar4 + 0x50));
  iVar4 = *DAT_02194978;
  func_0x02124ed0(param_1,*(undefined4 *)(iVar4 + 0x1c),*(undefined4 *)(iVar4 + 0x24),(undefined4 *)(uintptr_t)(iVar4 + 0x54));
  uVar5 = func_0x02047a28(DAT_0219497c);
  piVar3 = DAT_02194978;
  *(undefined4 *)(*DAT_02194978 + 0x58) = uVar5;
  iVar4 = *piVar3;
  func_0x021243ac(param_1,0,*(undefined4 *)(iVar4 + 0x10),200,0x10,0,*(undefined4 *)(iVar4 + 4),
                  *(undefined4 *)(iVar4 + 8),*(undefined4 *)(iVar4 + 0x50),DAT_02194980);
  iVar4 = func_0x02148ca0();
  iVar10 = 0;
  local_3c = DAT_02194988;
  local_38 = DAT_0219498c;
  local_34 = DAT_02194990;
  local_30 = DAT_02194994;
  local_2c = DAT_02194998;
  local_28 = DAT_0219499c;
  local_24 = DAT_021949a0;
  local_20 = DAT_021949a4;
  puVar11 = DAT_02194984;
  do {
    iVar8 = *DAT_02194978;
    iVar8 = func_0x021243ac(param_1,*local_38,*(undefined4 *)(iVar8 + 0x24),*local_3c,*puVar11,
                            iVar10,*(undefined4 *)(iVar8 + 0x18),*(undefined4 *)(iVar8 + 0x1c),
                            *(undefined4 *)(iVar8 + 0x54),iVar4);
    iVar9 = *DAT_02194978;
    iVar9 = func_0x021243ac(param_1,*local_2c,*(undefined4 *)(iVar9 + 0x24),*local_30,*local_34,
                            iVar10 + 4,*(undefined4 *)(iVar9 + 0x18),*(undefined4 *)(iVar9 + 0x1c),
                            *(undefined4 *)(iVar9 + 0x54),iVar4 - iVar8);
    iVar9 = (iVar4 - iVar8) - iVar9;
    iVar4 = *DAT_02194978;
    iVar4 = func_0x021243ac(param_1,*local_20,*(undefined4 *)(iVar4 + 0x24),*local_24,*local_28,
                            iVar10 + 0xc,*(undefined4 *)(iVar4 + 0x18),*(undefined4 *)(iVar4 + 0x1c)
                            ,*(undefined4 *)(iVar4 + 0x54),iVar9);
    iVar4 = iVar9 - iVar4;
    puVar11 = puVar11 + 1;
    local_3c = local_3c + 1;
    local_38 = local_38 + 1;
    local_34 = local_34 + 1;
    local_30 = local_30 + 1;
    local_2c = local_2c + 1;
    local_28 = local_28 + 1;
    local_24 = local_24 + 1;
    local_20 = local_20 + 1;
    iVar10 = iVar10 + 1;
  } while (iVar10 < 4);
  iVar4 = 0;
  *(undefined4 *)(*DAT_02194978 + 0x74) = 0;
  do {
    uVar7 = FUN_02194d04(iVar4);
    local_40 = local_40 | uVar7;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  if (local_40 == 0) {
    *(undefined4 *)(*DAT_02194978 + 0x74) = 0x10;
  }
  uVar5 = func_0x02036bec(param_1,DAT_021949a8);
  piVar3 = DAT_02194978;
  *(undefined4 *)(*DAT_02194978 + 0x4c) = uVar5;
  func_0x0214cfe4(0,*(undefined4 *)(*piVar3 + 0x4c),DAT_021949a8);
  FUN_02194a50();
  return;
}

