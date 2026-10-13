/* Decompiled C draft; module arm9_ov000; ROM address 021860ac. No matching claim. */
#include "types.h"
#include "deps/021860ac_FUN_021860ac.h"

void FUN_021860ac(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  int local_28;
  undefined4 local_24;
  
  iVar2 = DAT_02186278;
  piVar1 = DAT_02186274;
  local_28 = 0;
  while( true ) {
    if (*(int *)(*(int *)(*piVar1 + DAT_0218627c) + DAT_02186280) != 0) {
      func_0x0200e084(*(int *)(*piVar1 + DAT_0218627c) + DAT_02186284);
    }
    if (*(int *)(*(int *)(*piVar1 + DAT_0218627c) + 0x24) == 8) {
      iVar5 = FUN_02185ef4();
      if (iVar5 == 0xf) {
        if (1 < local_28) {
          FUN_02185954(0xf);
          *(int *)(*DAT_02186274 + 8) = -*(int *)(*DAT_02186274 + 8);
          return;
        }
        local_24 = 0;
      }
      else {
        if (iVar5 == 0x14) {
          FUN_02185954(0x14);
          return;
        }
        if (1 < local_28) {
          *(int *)(*DAT_02186274 + 8) = -*(int *)(*DAT_02186274 + 8);
          FUN_02185954();
          return;
        }
        local_24 = 1;
      }
    }
    else {
      *(undefined4 *)(*piVar1 + 8) = DAT_02186288;
      iVar5 = *(int *)(*(int *)(*piVar1 + DAT_0218627c) + 0x24);
      if (iVar5 == 7) {
        FUN_02185954(0x13);
        return;
      }
      if (2 < local_28) {
        if (iVar5 == 2) {
          FUN_02185954(9);
          return;
        }
        FUN_02185954(0xc);
        return;
      }
      local_24 = 1;
    }
    local_28 = local_28 + 1;
    lVar8 = func_0x0200f5ac();
    lVar9 = func_0x0200f5ac();
    uVar3 = (uint)(lVar9 - lVar8);
    uVar10 = func_0x02132e40(uVar3 * 0x40,
                             (int)((ulonglong)(lVar9 - lVar8) >> 0x20) * 0x40 | uVar3 >> 0x1a,
                             DAT_0218628c,0);
    uVar6 = (uint)((ulonglong)uVar10 >> 0x20);
    uVar3 = (uint)uVar10;
    uVar7 = uVar6 - (DAT_02186290 > uVar3);
    if (uVar6 == 0 && (DAT_02186290 <= uVar3) <= uVar6) {
      do {
        func_0x0200ed34(*piVar1 + iVar2,0,uVar7,uVar3);
        iVar5 = *piVar1;
        if (*(int *)(iVar5 + DAT_02186294) == 1) {
          *(undefined4 *)(iVar5 + 8) = DAT_02186288;
          func_0x0200ecc4(*piVar1 + DAT_02186278);
          FUN_02185954(0x13);
          return;
        }
        func_0x0200ecc4(iVar5 + iVar2);
        func_0x0200dc3c(DAT_02186290);
        lVar9 = func_0x0200f5ac();
        uVar3 = (uint)(lVar9 - lVar8);
        uVar10 = func_0x02132e40(uVar3 * 0x40,
                                 (int)((ulonglong)(lVar9 - lVar8) >> 0x20) * 0x40 | uVar3 >> 0x1a,
                                 DAT_0218628c,0);
        uVar6 = (uint)((ulonglong)uVar10 >> 0x20);
        uVar7 = (uint)uVar10;
        uVar3 = uVar6 - (DAT_02186290 > uVar7);
      } while (uVar6 == 0 && (DAT_02186290 <= uVar7) <= uVar6);
    }
    FUN_02186d04(*(undefined4 *)(*piVar1 + DAT_0218627c));
    func_0x0200ed34(*piVar1 + iVar2);
    uVar4 = FUN_02186298(local_24);
    *(undefined4 *)(*piVar1 + 4) = uVar4;
    iVar5 = *piVar1;
    if (*(int *)(iVar5 + 4) != 0) break;
    func_0x0200ecc4(iVar5 + iVar2);
  }
  *(undefined4 *)(iVar5 + 8) = DAT_02186288;
  func_0x0200ecc4(*piVar1 + DAT_02186278);
  return;
}

