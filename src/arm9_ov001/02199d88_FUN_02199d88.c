/* Decompiled C draft; module arm9_ov001; ROM address 02199d88. No matching claim. */
#include "types.h"
#include "deps/02199d88_FUN_02199d88.h"

void FUN_02199d88(void)

{
  int *piVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar3 = DAT_02199e10;
  *(int *)(*DAT_02199e10 + 0xc) = *(int *)(*DAT_02199e10 + 0xc) + 1;
  sVar2 = func_0x020ae4c0(1,0xfa,0,*(undefined4 *)(*piVar3 + 0xc),10);
  iVar6 = 0;
  piVar3 = DAT_02199e18;
  iVar4 = DAT_02199e14;
  do {
    iVar5 = 0;
    if (0 < *piVar3) {
      do {
        if (iVar6 == 1) {
          *(short *)(*(int *)(*DAT_02199e10 + 0x1c) + (uint)*(byte *)(iVar4 + iVar5) * 0x40 + 4) =
               sVar2;
        }
        else {
          *(short *)(*(int *)(*DAT_02199e10 + 0x1c) + (uint)*(byte *)(iVar4 + iVar5) * 0x40 + 4) =
               -sVar2;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *piVar3);
    }
    piVar1 = DAT_02199e10;
    iVar4 = iVar4 + 4;
    piVar3 = piVar3 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 2);
  if (9 < *(int *)(*DAT_02199e10 + 0xc)) {
    *(undefined4 *)(*DAT_02199e10 + 4) = 2;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    func_0x02128374();
  }
  return;
}

