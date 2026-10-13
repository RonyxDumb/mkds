/* Decompiled C draft; module arm9_ov001; ROM address 02198d8c. No matching claim. */
#include "types.h"
#include "deps/02198d8c_FUN_02198d8c.h"

void FUN_02198d8c(void)

{
  int *piVar1;
  undefined2 uVar2;
  short sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  uVar2 = func_0x020ae4c0(1,0,0xffffff74,*(undefined4 *)(*DAT_02198e8c + 0x20),10);
  piVar1 = DAT_02198e8c;
  *(undefined2 *)(*DAT_02198e8c + 0x24) = uVar2;
  iVar6 = *piVar1;
  *(int *)(iVar6 + 0x20) = *(int *)(iVar6 + 0x20) + 1;
  sVar3 = func_0x020ae4c0(1,0,0xfa,*(undefined4 *)(*piVar1 + 0x20),10);
  piVar1 = DAT_02198e8c;
  iVar9 = 0;
  iVar6 = 0;
  piVar7 = DAT_02198e90;
  do {
    iVar8 = 0;
    if (0 < *piVar7) {
      do {
        if (iVar9 == 1) {
          *(short *)(iVar6 + *piVar1 + 0x26) = -sVar3;
        }
        else {
          *(short *)(iVar6 + *piVar1 + 0x26) = sVar3;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < *piVar7);
    }
    iVar6 = iVar6 + 4;
    piVar7 = piVar7 + 1;
    iVar9 = iVar9 + 1;
  } while (iVar9 < 2);
  sVar3 = func_0x02128244(*(undefined4 *)(*DAT_02198e8c + 0x20));
  piVar1 = DAT_02198e8c;
  *(short *)(*DAT_02198e8c + 0x30) = -sVar3;
  if (((9 < *(int *)(*piVar1 + 0x20)) && (9 < *(int *)(*piVar1 + 0x20))) &&
     (iVar6 = func_0x02128294(), piVar1 = DAT_02198e8c, iVar6 != 0)) {
    *(undefined4 *)(*DAT_02198e8c + 0x3c) = 0;
    if (*(int *)(*piVar1 + 0x1c) != 0) {
      func_0x02125ebc(0x21);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02198e8c + 0x88),0x10);
      uVar5 = func_0x020b3f7c(*(undefined4 *)(*DAT_02198e8c + 0x8c),4);
      func_0x02126230(uVar4,uVar5);
      piVar1 = DAT_02198e8c;
      *(undefined4 *)(*DAT_02198e8c + 4) = 5;
      *(undefined4 *)(*piVar1 + 0x20) = 0;
      func_0x021282c8();
      return;
    }
    FUN_02192ea0(*(undefined4 *)(*piVar1 + 0x34));
  }
  return;
}

