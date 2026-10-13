/* Decompiled C draft; module arm9_ov003; ROM address 021ce4d4. No matching claim. */
#include "types.h"
#include "deps/021ce4d4_FUN_021ce4d4.h"

int FUN_021ce4d4(undefined4 param_1)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  
  uVar12 = func_0x0200f5ac();
  uVar6 = (uint)((ulonglong)uVar12 >> 0x20);
  iVar7 = *DAT_021ce590;
  bVar1 = false;
  uVar8 = *(uint *)(iVar7 + DAT_021ce594) + DAT_021ce59c;
  uVar9 = *(int *)(iVar7 + DAT_021ce598) +
          (uint)CARRY4(*(uint *)(iVar7 + DAT_021ce594),DAT_021ce59c);
  iVar4 = (uint)uVar12 - uVar8;
  if (uVar9 < uVar6 || uVar6 - uVar9 < (uint)(uVar8 <= (uint)uVar12)) {
    bVar2 = false;
    iVar11 = 0;
    iVar10 = iVar7 + DAT_021ce5a0;
    iVar4 = iVar7;
    do {
      iVar5 = func_0x02134d30(iVar10,DAT_021ce5a4,6);
      if (iVar5 != 0) {
        if (*(char *)(iVar4 + DAT_021ce5a8) == '\0') {
          bVar1 = true;
        }
        else {
          bVar2 = true;
        }
      }
      iVar10 = iVar10 + 7;
      iVar4 = iVar4 + 7;
      iVar11 = iVar11 + 1;
    } while (iVar11 < 0x10);
    if ((bVar2) && (bVar1)) {
      if (*(code **)(iVar7 + DAT_021ce5ac) != (code *)0x0) {
        (**(code **)(iVar7 + DAT_021ce5ac))(2);
      }
    }
    else if (bVar2) {
      if (*(code **)(iVar7 + DAT_021ce5ac) != (code *)0x0) {
        (**(code **)(iVar7 + DAT_021ce5ac))(1);
      }
    }
    else if ((!bVar1) && (*(code **)(iVar7 + DAT_021ce5ac) != (code *)0x0)) {
      (**(code **)(iVar7 + DAT_021ce5ac))(0);
    }
    piVar3 = DAT_021ce590;
    *(undefined4 *)(*DAT_021ce590 + DAT_021ce5b0) = 0;
    *(undefined1 *)(*piVar3 + DAT_021ce5b4) = 1;
    iVar4 = FUN_021d34c8(0,param_1);
  }
  return iVar4;
}

