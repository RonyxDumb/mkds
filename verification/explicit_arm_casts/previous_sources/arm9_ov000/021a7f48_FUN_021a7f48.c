/* Decompiled C draft; module arm9_ov000; ROM address 021a7f48. No matching claim. */
#include "types.h"
#include "deps/021a7f48_FUN_021a7f48.h"

int FUN_021a7f48(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar8 + 0x68);
  iVar6 = 0;
  bVar1 = true;
  if ((*(char *)(iVar8 + 0x73) != '\0') && (*(char *)(iVar8 + 0x73) != '\x04')) {
    bVar1 = false;
  }
  if ((bVar1) && ((*(ushort *)(iVar8 + 0x70) & 4) == 0)) {
    iVar6 = -0x4c;
  }
  else {
    if (*(int *)(param_1 + 0x28) != 0) {
      FUN_021ae290(*(undefined2 *)(param_1 + 0x24),*(undefined2 *)(param_1 + 0x26));
    }
    bVar1 = true;
    if ((*(char *)(iVar8 + 0x73) != '\0') && (*(char *)(iVar8 + 0x73) != '\x04')) {
      bVar1 = false;
    }
    if (bVar1) {
      iVar5 = 0x36;
    }
    else {
      iVar5 = 0x2a;
    }
    iVar7 = *(int *)(iVar8 + 0x4c) + iVar5;
    iVar3 = *(int *)(iVar8 + 0x48);
    while (iVar4 = FUN_021a7eec(iVar7,iVar3 - iVar5,param_1), 0 < iVar4) {
      iVar4 = FUN_021adbf4(iVar7);
      if (iVar4 < 1) {
        bVar1 = true;
        if ((*(char *)(iVar8 + 0x73) != '\0') && (*(char *)(iVar8 + 0x73) != '\x04')) {
          bVar1 = false;
        }
        if (bVar1) {
          *(ushort *)(iVar8 + 0x70) = *(ushort *)(iVar8 + 0x70) & 0xfff1;
        }
        iVar6 = -0x4c;
        break;
      }
      iVar6 = iVar6 + iVar4;
    }
  }
  *(undefined2 *)(iVar2 + DAT_021a800c) = *(undefined2 *)(param_1 + 0x20);
  func_0x0200df9c(iVar2 + DAT_021a8010);
  return iVar6;
}

