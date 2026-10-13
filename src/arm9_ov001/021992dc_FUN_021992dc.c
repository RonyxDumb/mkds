/* Decompiled C draft; module arm9_ov001; ROM address 021992dc. No matching claim. */
#include "types.h"
#include "deps/021992dc_FUN_021992dc.h"

void FUN_021992dc(void)

{
  int *piVar1;
  int *piVar2;
  undefined2 uVar3;
  short sVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  piVar1 = DAT_0219936c;
  *(int *)(*DAT_0219936c + 0x20) = *(int *)(*DAT_0219936c + 0x20) + 1;
  uVar3 = func_0x020ae4c0(1,0xffffff74,0,*(undefined4 *)(*piVar1 + 0x20),10);
  piVar1 = DAT_0219936c;
  *(undefined2 *)(*DAT_0219936c + 0x24) = uVar3;
  sVar4 = func_0x020ae4c0(1,0xfa,0,*(undefined4 *)(*piVar1 + 0x20),10);
  piVar1 = DAT_0219936c;
  iVar8 = 0;
  iVar6 = 0;
  piVar5 = DAT_02199370;
  do {
    iVar7 = 0;
    if (0 < *piVar5) {
      do {
        if (iVar8 == 1) {
          *(short *)(iVar6 + *piVar1 + 0x26) = -sVar4;
        }
        else {
          *(short *)(iVar6 + *piVar1 + 0x26) = sVar4;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < *piVar5);
    }
    piVar2 = DAT_0219936c;
    iVar6 = iVar6 + 4;
    piVar5 = piVar5 + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  if (9 < *(int *)(*DAT_0219936c + 0x20)) {
    *(undefined4 *)(*DAT_0219936c + 4) = 1;
    *(undefined4 *)(*piVar2 + 0x20) = 0;
  }
  return;
}

