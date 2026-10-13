/* Decompiled C draft; module arm9_ov000; ROM address 02182fdc. No matching claim. */
#include "types.h"
#include "deps/02182fdc_FUN_02182fdc.h"

void FUN_02182fdc(undefined4 param_1)

{
  undefined1 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  int local_3c;
  undefined1 *local_38;
  undefined1 *local_34;
  int local_30;
  int local_2c;
  undefined1 local_1c [5];
  undefined1 local_17;
  
  iVar4 = func_0x02036bec(param_1,DAT_02183298);
  piVar2 = DAT_0218329c;
  *DAT_0218329c = iVar4;
  *(undefined4 *)(iVar4 + DAT_021832a0) = param_1;
  *(undefined4 *)*piVar2 = 0;
  *(undefined4 *)(*piVar2 + 4) = 0;
  *(undefined4 *)(*piVar2 + 8) = 1;
  *(undefined4 *)(*piVar2 + 0x20) = 0xffffffff;
  *(undefined4 *)(*piVar2 + 0x10) = 0;
  *(undefined4 *)(*piVar2 + 0x24) = 1;
  func_ov000_02180638();
  FUN_02182e18();
  func_0x0212b928(param_1,*(undefined4 *)(*DAT_0218329c + DAT_021832a4),3);
  iVar4 = DAT_021832ac;
  piVar2 = DAT_0218329c;
  iVar9 = 0;
  puVar8 = DAT_021832a8;
  do {
    func_0x02124a98(*puVar8,1,*(undefined4 *)(*piVar2 + DAT_021832b0),
                    *(undefined4 *)(*piVar2 + iVar4));
    puVar8 = puVar8 + 9;
    iVar9 = iVar9 + 1;
  } while (iVar9 < 2);
  uVar5 = func_ov000_021804f4();
  uVar6 = func_ov000_021804e0();
  func_0x020ae6d4(uVar5,uVar6);
  iVar4 = *DAT_0218329c;
  func_0x02124ed0(param_1,*(undefined4 *)(iVar4 + DAT_021832ac),
                  *(undefined4 *)(iVar4 + DAT_021832b4),(undefined4 *)(uintptr_t)(iVar4 + DAT_021832b8));
  uVar5 = func_0x0204799c(DAT_021832bc);
  *(undefined4 *)(*DAT_0218329c + DAT_021832c0) = uVar5;
  uVar5 = func_0x02047a28(DAT_021832c4);
  *(undefined4 *)(*DAT_0218329c + DAT_021832c8) = uVar5;
  local_3c = func_0x02148ca0();
  uVar1 = *DAT_021832cc;
  uVar5 = *DAT_021832d4;
  iVar4 = *DAT_0218329c;
  iVar4 = func_0x021243ac(param_1,uVar1,*(undefined4 *)(iVar4 + DAT_021832b4),*DAT_021832d0,
                          DAT_021832d0[1],DAT_021832a8[0xb],*(undefined4 *)(iVar4 + DAT_021832b0),
                          *(undefined4 *)(iVar4 + DAT_021832ac),
                          *(undefined4 *)(iVar4 + DAT_021832b8),local_3c);
  local_3c = local_3c - iVar4;
  iVar4 = *DAT_0218329c;
  uVar5 = func_0x020b3f7c(*(undefined4 *)(iVar4 + DAT_021832c0),uVar5);
  func_0x0212426c(1,uVar1,*(undefined4 *)(*DAT_0218329c + DAT_021832b4),uVar5,
                  *(undefined4 *)(iVar4 + DAT_021832ac),*(undefined4 *)(iVar4 + DAT_021832b8));
  piVar2 = DAT_0218329c;
  puVar8 = local_1c;
  local_1c[0] = *DAT_021832d8;
  local_1c[1] = DAT_021832d8[1];
  local_1c[2] = DAT_021832d8[2];
  local_1c[3] = DAT_021832d8[3];
  local_1c[4] = DAT_021832d8[4];
  local_17 = DAT_021832d8[5];
  iVar4 = 0;
  local_38 = DAT_021832a8;
  local_34 = DAT_021832dc;
  local_30 = DAT_021832e0;
  local_2c = 0;
  do {
    iVar9 = local_2c;
    if (iVar4 == 1) {
      *(uint *)(*piVar2 + 0xc) =
           (uint)*(byte *)(DAT_021832e8 + (uint)*(byte *)(*DAT_021832e4 + 0x54));
      if ((*(int *)(*piVar2 + 0xc) == 0) && (iVar9 = FUN_021832f0(), iVar9 == 0)) {
        *(undefined4 *)(*piVar2 + 0xc) = 2;
      }
      iVar9 = *(int *)(*piVar2 + 0xc);
    }
    iVar7 = *piVar2;
    iVar7 = func_0x021243ac(param_1,*local_34,*(undefined4 *)(iVar7 + DAT_021832b4),*puVar8,
                            puVar8[1],local_38[1],*(undefined4 *)(iVar7 + DAT_021832b0),
                            *(undefined4 *)(iVar7 + DAT_021832ac),
                            *(undefined4 *)(iVar7 + DAT_021832b8),local_3c);
    local_3c = local_3c - iVar7;
    if (iVar4 == 2) {
      uVar5 = func_0x020b3f7c(*(undefined4 *)(*piVar2 + DAT_021832c8),
                              *(undefined4 *)(local_30 + iVar9 * 4));
    }
    else if (iVar4 == 1) {
      uVar5 = func_ov000_02180668(*(undefined4 *)(*piVar2 + 0xc));
      uVar5 = func_0x020b3f7c(*(undefined4 *)(*piVar2 + DAT_021832c0),uVar5);
    }
    else {
      uVar5 = func_0x020b3f7c(*(undefined4 *)(*piVar2 + DAT_021832c0),
                              *(undefined4 *)(local_30 + iVar9 * 4));
    }
    iVar9 = *piVar2;
    func_0x0212426c(1,*local_34,*(undefined4 *)(iVar9 + DAT_021832b4),uVar5,
                    *(undefined4 *)(iVar9 + DAT_021832ac),*(undefined4 *)(iVar9 + DAT_021832b8));
    piVar3 = DAT_0218329c;
    local_38 = local_38 + 9;
    puVar8 = puVar8 + 2;
    local_34 = local_34 + 1;
    local_30 = local_30 + 0x10;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  iVar4 = 0;
  iVar9 = 0;
  do {
    if (iVar4 == 2) {
      *(undefined2 *)(*piVar3 + iVar9 + 0x14) = 0;
      *(undefined2 *)(*piVar3 + iVar9 + 0x16) = 0x28;
    }
    else if (iVar4 == 1) {
      *(undefined2 *)(*piVar3 + iVar9 + 0x14) = 0xff00;
      *(undefined2 *)(*piVar3 + iVar9 + 0x16) = 0;
    }
    else {
      *(short *)(*piVar3 + iVar9 + 0x14) = (short)DAT_021832ec;
      *(undefined2 *)(*piVar3 + iVar9 + 0x16) = 0;
    }
    piVar2 = DAT_0218329c;
    iVar9 = iVar9 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  *(undefined4 *)(*DAT_0218329c + 0x2c) = 0;
  *(undefined4 *)(*piVar2 + 0x30) = 0;
  func_0x0212a910(1,1);
  func_0x021281c8(0xe);
  return;
}

