/* Decompiled C draft; module arm9_ov000; ROM address 0219f9bc. No matching claim. */
#include "types.h"
#include "deps/0219f9bc_FUN_0219f9bc.h"

undefined4 FUN_0219f9bc(undefined4 param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  
  iVar3 = *DAT_0219faf4;
  if ((*(char *)(iVar3 + 0x17) == '\0') ||
     (*(int *)(iVar3 + 0x20) != *(int *)(iVar3 + DAT_0219faf8))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    *(undefined1 *)(iVar3 + 0x17) = 0;
    piVar2 = DAT_0219faf4;
    *(undefined4 *)(*DAT_0219faf4 + 0x20) = 0;
    FUN_021a4818(*(undefined4 *)(*piVar2 + 0x10));
  }
  uVar4 = (uint)*(byte *)(*DAT_0219faf4 + 0xd);
  if (uVar4 < 0x1f) {
    *(undefined4 *)(*DAT_0219faf4 + (uVar4 + 1) * 4 + 0xf4) = 0;
  }
  piVar2 = DAT_0219faf4;
  *(undefined1 *)(*DAT_0219faf4 + DAT_0219fafc) = 0xff;
  if (*(int *)(*piVar2 + DAT_0219fb00) != 0) {
    FUN_0219ac50();
    *(undefined4 *)(*DAT_0219faf4 + DAT_0219fb00) = 0;
  }
  piVar2 = DAT_0219faf4;
  *(undefined1 *)(*DAT_0219faf4 + 0x14) = *(undefined1 *)(*DAT_0219faf4 + 0xd);
  *(undefined4 *)(*piVar2 + DAT_0219fb04) = 0;
  if (bVar1) {
    iVar3 = *piVar2;
    if (*(char *)(iVar3 + 0x15) == '\0') {
      *(undefined4 *)(iVar3 + DAT_0219fb08) = 3;
      *(undefined4 *)(*piVar2 + 0xe8) = 2;
      uVar7 = func_0x0200f5ac();
      *(undefined8 *)(*DAT_0219faf4 + 0xec) = uVar7;
    }
    else if (*(char *)(iVar3 + 0x15) == '\x01') {
      *(undefined4 *)(iVar3 + DAT_0219fb08) = 4;
      FUN_0219fbec(1);
    }
    else if (*(char *)(iVar3 + 0x15) == '\x02') {
      *(undefined4 *)(iVar3 + DAT_0219fb08) = 0xe;
      *(undefined4 *)(*piVar2 + DAT_0219fb0c) = 0;
      *(undefined2 *)(*piVar2 + DAT_0219fb10) = 0;
      FUN_0219f124(param_1);
      piVar2 = DAT_0219faf4;
      iVar6 = 1;
      iVar3 = *DAT_0219faf4;
      uVar4 = (uint)*(byte *)(iVar3 + 0xd);
      if (uVar4 != 0) {
        iVar5 = 4;
        do {
          iVar3 = FUN_0219edb0(*(undefined4 *)(iVar3 + iVar5 + 0xf4),0xd);
          if (iVar3 == 0) {
            return 0;
          }
          iVar5 = iVar5 + 4;
          iVar6 = iVar6 + 1;
          iVar3 = *piVar2;
          uVar4 = (uint)*(byte *)(iVar3 + 0xd);
        } while (iVar6 <= (int)uVar4);
      }
      if (uVar4 == 0) {
        FUN_0219f23c(2);
      }
    }
  }
  else if (*(char *)(*piVar2 + 0x15) != '\x03') {
    FUN_0219f214();
  }
  return 1;
}

