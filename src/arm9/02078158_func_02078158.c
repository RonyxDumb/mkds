/* Decompiled C draft; module arm9; ROM address 02078158. No matching claim. */
#include "types.h"
#include "deps/02078158_func_02078158.h"

void func_02078158(void)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 local_20;
  undefined4 local_1c [2];
  
  piVar3 = piRam02078384;
  iVar6 = *piRam02078384;
  uVar7 = 0;
  local_20 = 2;
  if ((*(int *)(*piRam02078390 + 0xf8) == 0) &&
     (*(int *)(iVar6 + iRam02078388 + *(short *)(iVar6 + iRam0207838c) * 0x34 + 0x2c) == 0)) {
    local_1c[0] = 0xffffffff;
    if ((*(ushort *)(iRam02078394 + 0x2e0) & uRam02078398) == 0) {
      if ((*(ushort *)(iRam02078394 + 0x2e0) & uRam020783a4) != 0) {
        bVar1 = false;
        do {
          *(int *)*piVar3 = *(int *)*piVar3 + -1;
          if (*(int *)*piVar3 < 0) {
            *(int *)*piVar3 = 0x23;
          }
          iVar5 = func_02077a70(local_1c,*(undefined4 *)*piVar3);
          if (iVar5 != 0) {
            func_02078a9c(local_1c[0]);
            func_02078a34(*(undefined4 *)*piVar3);
            bVar1 = true;
            NNSi_MaybeSndPlayerStartSeq(uRam0207839c,0,uRam020783a8);
          }
          piVar4 = piRam02078384;
        } while (!bVar1);
        *(int *)(*piRam02078384 + 4) = *(int *)(*piRam02078384 + 4) + -1;
        iVar5 = *piVar4;
        if (*(int *)(iVar5 + 4) < 0) {
          *(int *)(iVar5 + 4) = *(int *)(iVar5 + 8) + -1;
        }
      }
    }
    else {
      bVar1 = false;
      do {
        *(int *)*piVar3 = *(int *)*piVar3 + 1;
        if (0x23 < *(int *)*piVar3) {
          *(int *)*piVar3 = 0;
        }
        iVar5 = func_02077a70(local_1c,*(undefined4 *)*piVar3);
        if (iVar5 != 0) {
          func_02078a9c(local_1c[0]);
          func_02078a34(*(undefined4 *)*piVar3);
          bVar1 = true;
          NNSi_MaybeSndPlayerStartSeq(uRam0207839c,0,uRam020783a0);
        }
        piVar4 = piRam02078384;
      } while (!bVar1);
      *(int *)(*piRam02078384 + 4) = *(int *)(*piRam02078384 + 4) + 1;
      iVar5 = *piVar4;
      if (*(int *)(iVar5 + 8) <= *(int *)(iVar5 + 4)) {
        *(undefined4 *)(iVar5 + 4) = 0;
      }
    }
  }
  bVar2 = false;
  bVar1 = false;
  func_02108e6c(2);
  if ((*(ushort *)(iRam020783ac + 0x2e0) & 0x10) == 0) {
    if ((*(ushort *)(iRam020783ac + 0x2e0) & 0x20) != 0) {
      *(short *)(iVar6 + 0x3a) = *(short *)(iVar6 + 0x3a) - (short)uRam020783b0;
      bVar2 = true;
    }
  }
  else {
    *(short *)(iVar6 + 0x3a) = *(short *)(iVar6 + 0x3a) + (short)uRam020783b0;
    bVar2 = true;
  }
  if ((*(ushort *)(iRam020783ac + 0x2e0) & 0x80) == 0) {
    if ((*(ushort *)(iRam020783ac + 0x2e0) & 0x40) != 0) {
      *(short *)(iVar6 + 0x3c) = *(short *)(iVar6 + 0x3c) - (short)uRam020783b0;
      if (*(short *)(iVar6 + 0x3c) < iRam020783b8) {
        *(short *)(iVar6 + 0x3c) = (short)iRam020783b8;
      }
      else {
        bVar1 = true;
      }
    }
  }
  else {
    *(short *)(iVar6 + 0x3c) = *(short *)(iVar6 + 0x3c) + (short)uRam020783b0;
    if (iRam020783b4 < *(short *)(iVar6 + 0x3c)) {
      *(short *)(iVar6 + 0x3c) = (short)iRam020783b4;
    }
    else {
      bVar1 = true;
    }
  }
  if ((bVar1) || (bVar2)) {
    uVar7 = 1;
  }
  func_02108e6c(1);
  if ((*(ushort *)(iRam020783ac + 0x2e0) & uRam020783bc) == 0) {
    if ((*(ushort *)(iRam020783ac + 0x2e0) & 2) != 0) {
      *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + -0x7b;
      if (*(int *)(iVar6 + 0x2c) < iRam020783c4) {
        *(int *)(iVar6 + 0x2c) = iRam020783c4;
      }
      else {
        local_20 = 1;
      }
    }
  }
  else {
    *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + 0x7b;
    if (*piRam020783c0 < *(int *)(iVar6 + 0x2c)) {
      *(int *)(iVar6 + 0x2c) = *piRam020783c0;
    }
    else {
      local_20 = 0;
    }
  }
  *(undefined2 *)(iVar6 + 0x3e) = *(undefined2 *)(iVar6 + 0x3c);
  func_02110aac(local_20,uVar7);
  func_02077b3c();
  func_02077b1c();
  return;
}

