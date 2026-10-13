/* Decompiled C draft; module arm9_ov001; ROM address 021997dc. No matching claim. */
#include "types.h"
#include "deps/021997dc_FUN_021997dc.h"

void FUN_021997dc(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  int local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 *local_44;
  undefined4 *local_40;
  int local_3c;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28 [5];
  undefined1 local_23;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  
  local_50 = DAT_02199940;
  puVar4 = local_34;
  local_34[0] = *DAT_02199944;
  local_34[1] = DAT_02199944[1];
  local_34[2] = DAT_02199944[2];
  local_34[3] = DAT_02199944[3];
  local_40 = &local_30;
  local_30 = *DAT_02199948;
  local_2c = DAT_02199948[1];
  iVar5 = 0;
  puVar3 = DAT_0219994c;
  do {
    iVar2 = *DAT_02199950;
    iVar2 = func_0x021243ac(*(undefined4 *)(iVar2 + 0x50),*puVar3,*(undefined4 *)(iVar2 + 0x80),
                            *puVar4,puVar4[1],iVar5,*(undefined4 *)(iVar2 + 0x5c),
                            *(undefined4 *)(iVar2 + 0x74),*(undefined4 *)(iVar2 + 0x54),local_50);
    local_50 = local_50 - iVar2;
    iVar2 = *DAT_02199950;
    uVar1 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x88),*local_40);
    func_0x0212426c(0,*puVar3,*(undefined4 *)(*DAT_02199950 + 0x80),uVar1,
                    *(undefined4 *)(iVar2 + 0x74),*(undefined4 *)(iVar2 + 0x54));
    puVar4 = puVar4 + 2;
    puVar3 = puVar3 + 1;
    local_40 = local_40 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  local_4c = func_0x02148ca0();
  puVar4 = local_28;
  local_28[0] = *DAT_02199954;
  local_28[1] = DAT_02199954[1];
  local_28[2] = DAT_02199954[2];
  local_28[3] = DAT_02199954[3];
  local_28[4] = DAT_02199954[4];
  local_23 = DAT_02199954[5];
  local_44 = &local_20;
  local_20 = *DAT_02199958;
  uStack_1c = DAT_02199958[1];
  local_18 = DAT_02199958[2];
  local_3c = 0;
  puVar3 = DAT_02199960;
  puVar6 = DAT_0219995c;
  do {
    local_48 = *(undefined4 *)(*DAT_02199950 + 0x88);
    if (local_3c == 2) {
      local_48 = *(undefined4 *)(*DAT_02199950 + 0x8c);
    }
    iVar5 = *DAT_02199950;
    iVar5 = func_0x021243ac(*(undefined4 *)(iVar5 + 0x50),*puVar3,*(undefined4 *)(iVar5 + 0x84),
                            *puVar4,puVar4[1],*puVar6,*(undefined4 *)(iVar5 + 0x60),
                            *(undefined4 *)(iVar5 + 0x78),*(undefined4 *)(iVar5 + 0x58),local_4c);
    local_4c = local_4c - iVar5;
    iVar5 = *DAT_02199950;
    uVar1 = func_0x020b3f7c(local_48,*local_44);
    func_0x0212426c(1,*puVar3,*(undefined4 *)(*DAT_02199950 + 0x84),uVar1,
                    *(undefined4 *)(iVar5 + 0x78),*(undefined4 *)(iVar5 + 0x58));
    puVar6 = puVar6 + 1;
    puVar4 = puVar4 + 2;
    puVar3 = puVar3 + 1;
    local_44 = local_44 + 1;
    local_3c = local_3c + 1;
  } while (local_3c < 3);
  return;
}

