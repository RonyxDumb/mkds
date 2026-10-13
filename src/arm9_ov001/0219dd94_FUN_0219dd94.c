/* Decompiled C draft; module arm9_ov001; ROM address 0219dd94. No matching claim. */
#include "types.h"
#include "deps/0219dd94_FUN_0219dd94.h"

void FUN_0219dd94(void)

{
  int *piVar1;
  int *piVar2;
  short sVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar1 = DAT_0219de10;
  *(int *)(*DAT_0219de10 + 0x14) = *(int *)(*DAT_0219de10 + 0x14) + 1;
  sVar3 = func_0x020ae4c0(1,0xfa,0,*(undefined4 *)(*piVar1 + 0x14),10);
  piVar1 = DAT_0219de10;
  iVar7 = 0;
  iVar5 = 0;
  piVar4 = DAT_0219de14;
  do {
    iVar6 = 0;
    if (0 < *piVar4) {
      do {
        if (iVar7 == 1) {
          *(short *)(iVar5 + *piVar1 + 0x18) = sVar3;
        }
        else {
          *(short *)(iVar5 + *piVar1 + 0x18) = -sVar3;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *piVar4);
    }
    piVar2 = DAT_0219de10;
    iVar5 = iVar5 + 4;
    piVar4 = piVar4 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  if (9 < *(int *)(*DAT_0219de10 + 0x14)) {
    *(undefined4 *)(*DAT_0219de10 + 4) = 2;
    *(undefined4 *)(*piVar2 + 0x14) = 0;
    func_0x02128374();
  }
  return;
}

