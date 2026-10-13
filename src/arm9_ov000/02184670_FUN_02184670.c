/* Decompiled C draft; module arm9_ov000; ROM address 02184670. No matching claim. */
#include "types.h"
#include "deps/02184670_FUN_02184670.h"

void FUN_02184670(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  int local_50;
  undefined1 *local_4c;
  undefined1 *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e [5];
  undefined1 local_29;
  undefined1 local_28 [5];
  undefined1 local_23;
  undefined1 local_22 [14];
  
  iVar2 = func_0x02148ca0();
  local_2e[0] = *DAT_02184888;
  local_2e[1] = DAT_02184888[1];
  local_2e[2] = DAT_02184888[2];
  local_2e[3] = DAT_02184888[3];
  local_2e[4] = DAT_02184888[4];
  local_29 = DAT_02184888[5];
  local_50 = 0;
  puVar7 = DAT_0218488c;
  puVar8 = DAT_02184890;
  puVar5 = &local_30;
  do {
    iVar4 = *DAT_02184894;
    iVar4 = func_0x021243ac(*(undefined4 *)(iVar4 + 0xd0),*puVar8,
                            *(undefined4 *)(iVar4 + DAT_021848a4),puVar5[2],puVar5[3],*puVar7,
                            *(undefined4 *)(iVar4 + DAT_02184898),
                            *(undefined4 *)(iVar4 + DAT_0218489c),
                            *(undefined4 *)(iVar4 + DAT_021848a0),iVar2);
    iVar2 = iVar2 - iVar4;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
    local_50 = local_50 + 1;
    puVar5 = puVar5 + 2;
  } while (local_50 < 3);
  puVar7 = local_22;
  iVar4 = 0xc;
  puVar5 = DAT_021848a8;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar7 = uVar1;
    puVar7 = puVar7 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  local_3c = 0;
  puVar5 = local_22;
  local_44 = DAT_021848b0;
  local_38 = 0;
  iVar4 = local_38;
  local_48 = puVar5;
  iVar9 = DAT_021848ac;
  do {
    do {
      iVar6 = *DAT_02184894;
      iVar6 = func_0x021243ac(*(undefined4 *)(iVar6 + 0xd0),*(undefined1 *)(local_44 + iVar4),
                              *(undefined4 *)(iVar6 + DAT_021848a4),*puVar5,puVar5[1],
                              *(undefined1 *)(iVar9 + iVar4),*(undefined4 *)(iVar6 + DAT_02184898),
                              *(undefined4 *)(iVar6 + DAT_0218489c),
                              *(undefined4 *)(iVar6 + DAT_021848a0),iVar2);
      iVar2 = iVar2 - iVar6;
      puVar5 = puVar5 + 2;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    iVar9 = iVar9 + 2;
    puVar5 = local_48 + 4;
    local_44 = local_44 + 2;
    local_3c = local_3c + 1;
    iVar4 = local_38;
    local_48 = puVar5;
  } while (local_3c < 3);
  puVar5 = local_28;
  local_28[0] = *DAT_021848b4;
  local_28[1] = DAT_021848b4[1];
  local_28[2] = DAT_021848b4[2];
  local_28[3] = DAT_021848b4[3];
  local_28[4] = DAT_021848b4[4];
  local_23 = DAT_021848b4[5];
  local_40 = 0;
  local_4c = DAT_021848b8;
  puVar7 = DAT_021848bc;
  do {
    iVar4 = *DAT_02184894;
    iVar4 = func_0x021243ac(*(undefined4 *)(iVar4 + 0xd0),*puVar7,
                            *(undefined4 *)(iVar4 + DAT_021848a4),*puVar5,puVar5[1],*local_4c,
                            *(undefined4 *)(iVar4 + DAT_02184898),
                            *(undefined4 *)(iVar4 + DAT_0218489c),
                            *(undefined4 *)(iVar4 + DAT_021848a0),iVar2);
    iVar2 = iVar2 - iVar4;
    iVar4 = *DAT_02184894;
    uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar4 + DAT_021848c0),9);
    func_0x0212426c(1,*puVar7,*(undefined4 *)(*DAT_02184894 + DAT_021848a4),uVar3,
                    *(undefined4 *)(iVar4 + DAT_0218489c),*(undefined4 *)(iVar4 + DAT_021848a0));
    local_4c = local_4c + 1;
    puVar5 = puVar5 + 2;
    puVar7 = puVar7 + 1;
    local_40 = local_40 + 1;
  } while (local_40 < 3);
  local_30 = *DAT_021848c4;
  local_2f = DAT_021848c4[1];
  func_ov000_0218065c();
  uVar3 = func_ov000_02180668();
  iVar4 = *DAT_02184894;
  func_0x021243ac(*(undefined4 *)(iVar4 + 0xd0),0xc,*(undefined4 *)(iVar4 + DAT_021848a4),local_30,
                  local_2f,*(undefined2 *)(*(int *)(iVar4 + DAT_0218489c) + 6),
                  *(undefined4 *)(iVar4 + DAT_02184898),*(int *)(iVar4 + DAT_0218489c),
                  *(undefined4 *)(iVar4 + DAT_021848a0),iVar2);
  iVar2 = *DAT_02184894;
  uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + DAT_021848c0),uVar3);
  func_0x0212426c(1,0xc,*(undefined4 *)(*DAT_02184894 + DAT_021848a4),uVar3,
                  *(undefined4 *)(iVar2 + DAT_0218489c),*(undefined4 *)(iVar2 + DAT_021848a0));
  return;
}

