/* Decompiled C draft; module arm9_ov000; ROM address 02181d44. No matching claim. */
#include "types.h"
#include "deps/02181d44_FUN_02181d44.h"

void FUN_02181d44(void)

{
  int *piVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = DAT_02181dc4;
  uVar2 = 0;
  *(int *)(*DAT_02181dc4 + 0xc) = *(int *)(*DAT_02181dc4 + 0xc) + 1;
  iVar4 = *piVar1;
  iVar5 = *(int *)(iVar4 + 0xc);
  if (iVar5 < 0x14) {
    if (iVar5 < 10) {
      uVar2 = func_0x020ae4c0(1,0xdc,0,iVar5,10);
    }
    else {
      uVar2 = func_0x020ae488(iVar5 + -10);
    }
  }
  else {
    *(undefined4 *)(iVar4 + 4) = 2;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    func_0x02128374();
  }
  piVar1 = DAT_02181dc4;
  iVar5 = 0;
  piVar3 = DAT_02181dcc;
  iVar4 = DAT_02181dc8;
  do {
    iVar6 = 0;
    if (0 < *piVar3) {
      do {
        *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(byte *)(iVar4 + iVar6) * 0x40 + 4) =
             uVar2;
        iVar6 = iVar6 + 1;
      } while (iVar6 < *piVar3);
    }
    iVar4 = iVar4 + 5;
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  return;
}

