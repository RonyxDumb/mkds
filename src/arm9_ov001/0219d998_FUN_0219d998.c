/* Decompiled C draft; module arm9_ov001; ROM address 0219d998. No matching claim. */
#include "types.h"
#include "deps/0219d998_FUN_0219d998.h"

void FUN_0219d998(void)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar3 = FUN_02192e84();
  if ((iVar3 == -1) && (*(int *)(*DAT_0219da98 + 0x20) == 6)) {
    FUN_02192e78(3);
  }
  piVar1 = DAT_0219da98;
  *(int *)(*DAT_0219da98 + 0x14) = *(int *)(*DAT_0219da98 + 0x14) + 1;
  sVar2 = func_0x020ae4c0(1,0,0xfa,*(undefined4 *)(*piVar1 + 0x14),10);
  piVar1 = DAT_0219da98;
  iVar8 = 0;
  iVar3 = 0;
  piVar5 = DAT_0219da9c;
  do {
    iVar6 = 0;
    if (0 < *piVar5) {
      do {
        if (iVar8 == 0) {
          *(short *)(iVar3 + *piVar1 + 0x18) = -sVar2;
        }
        else {
          *(short *)(iVar3 + *piVar1 + 0x18) = sVar2;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *piVar5);
    }
    iVar3 = iVar3 + 4;
    piVar5 = piVar5 + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  if ((((9 < *(int *)(*DAT_0219da98 + 0x14)) && (9 < *(int *)(*DAT_0219da98 + 0x14))) &&
      ((iVar3 = func_0x02128294(), iVar3 != 0 || (iVar3 = func_0x02128274(), iVar3 != 0)))) &&
     (iVar3 = FUN_02192e84(), iVar3 == -1)) {
    iVar3 = *DAT_0219da98;
    if (*(int *)(iVar3 + 0xc) == *(int *)(iVar3 + 0x10)) {
      FUN_02192ea0(*(undefined4 *)(iVar3 + 0x20));
      return;
    }
    uVar7 = 9;
    if (*(int *)(iVar3 + 0xc) == 1) {
      uVar7 = 10;
    }
    *(undefined4 *)(iVar3 + 4) = 6;
    func_0x02125ebc(0x21);
    uVar7 = func_0x020b3f7c(*(undefined4 *)(*DAT_0219da98 + 0x50),uVar7);
    uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_0219da98 + 0x54),4);
    func_0x02126230(uVar7,uVar4);
    *(undefined4 *)(*DAT_0219da98 + 0x14) = 0;
  }
  return;
}

