/* Decompiled C draft; module arm9_ov000; ROM address 02184dbc. No matching claim. */
#include "types.h"
#include "deps/02184dbc_FUN_02184dbc.h"

void FUN_02184dbc(void)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = func_ov000_021806c4();
  if (((iVar2 == -1) && (iVar2 = FUN_02185184(), iVar2 == 0)) &&
     (*(int *)(*DAT_02184ec8 + 0x10) == 0xb)) {
    func_ov000_021806b8(0xe);
  }
  piVar5 = DAT_02184ec8;
  *(int *)(*DAT_02184ec8 + 0xc) = *(int *)(*DAT_02184ec8 + 0xc) + 1;
  if (*(int *)(*piVar5 + 0xc) < 0xb) {
    sVar1 = func_0x020ae4c0(1,0,0xfa,*(int *)(*piVar5 + 0xc),10);
  }
  else {
    sVar1 = 0xfa;
  }
  iVar7 = 0;
  piVar5 = DAT_02184ed0;
  iVar2 = DAT_02184ecc;
  do {
    iVar6 = 0;
    if (0 < *piVar5) {
      do {
        if (iVar7 == 1) {
          *(short *)(*(int *)(*DAT_02184ec8 + 0x1c) + (uint)*(byte *)(iVar2 + iVar6) * 0x40 + 4) =
               sVar1;
        }
        else {
          *(short *)(*(int *)(*DAT_02184ec8 + 0x1c) + (uint)*(byte *)(iVar2 + iVar6) * 0x40 + 4) =
               -sVar1;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *piVar5);
    }
    iVar2 = iVar2 + 4;
    piVar5 = piVar5 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  if (9 < *(int *)(*DAT_02184ec8 + 0xc)) {
    iVar2 = FUN_02185184();
    piVar5 = DAT_02184ec8;
    if (iVar2 != 0) {
      if (*(int *)(*DAT_02184ec8 + 0x10) == 0xb) {
        *(undefined4 *)(*DAT_02184ec8 + 4) = 6;
        *(undefined4 *)(*piVar5 + 0x10) = 0xffffffff;
        uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar5 + 0x38),0xf);
        uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02184ec8 + 0x3c),6);
        func_0x02126570(uVar3,uVar4);
        *(undefined4 *)(*DAT_02184ec8 + 0xc) = 0;
        return;
      }
    }
    iVar2 = func_ov000_021806c4();
    if (iVar2 == -1) {
      func_ov000_021806e0(*(undefined4 *)(*DAT_02184ec8 + 0x10));
    }
  }
  return;
}

