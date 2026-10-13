/* Decompiled C draft; module arm9_ov001; ROM address 02199a8c. No matching claim. */
#include "types.h"
#include "deps/02199a8c_FUN_02199a8c.h"

void FUN_02199a8c(void)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = FUN_02192e84();
  if (iVar2 == -1) {
    if (*(int *)(*DAT_02199b60 + 0x10) == 5) {
      FUN_02192e78(0xe);
    }
    else if (*(int *)(*DAT_02199b60 + 0x10) == 6) {
      FUN_02192e78(3);
    }
  }
  piVar3 = DAT_02199b60;
  *(int *)(*DAT_02199b60 + 0xc) = *(int *)(*DAT_02199b60 + 0xc) + 1;
  if (*(int *)(*piVar3 + 0xc) < 0xb) {
    sVar1 = func_0x020ae4c0(1,0,0xfa,*(int *)(*piVar3 + 0xc),10);
  }
  else {
    sVar1 = 0xfa;
  }
  iVar5 = 0;
  piVar3 = DAT_02199b68;
  iVar2 = DAT_02199b64;
  do {
    iVar4 = 0;
    if (0 < *piVar3) {
      do {
        if (iVar5 == 1) {
          *(short *)(*(int *)(*DAT_02199b60 + 0x1c) + (uint)*(byte *)(iVar2 + iVar4) * 0x40 + 4) =
               sVar1;
        }
        else {
          *(short *)(*(int *)(*DAT_02199b60 + 0x1c) + (uint)*(byte *)(iVar2 + iVar4) * 0x40 + 4) =
               -sVar1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *piVar3);
    }
    iVar2 = iVar2 + 4;
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  if (((9 < *(int *)(*DAT_02199b60 + 0xc)) &&
      (((iVar2 = *(int *)(*DAT_02199b60 + 0x10), iVar2 == 0 || (iVar2 == 3)) ||
       (iVar2 = func_0x02128274(), iVar2 != 0)))) && (iVar2 = FUN_02192e84(), iVar2 == -1)) {
    FUN_02192ea0(*(undefined4 *)(*DAT_02199b60 + 0x10));
  }
  return;
}

