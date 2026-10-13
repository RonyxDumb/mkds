/* Decompiled C draft; module arm9_ov003; ROM address 021c6e38. No matching claim. */
#include "types.h"
#include "deps/021c6e38_FUN_021c6e38.h"

void FUN_021c6e38(void)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_10 [4];
  int local_c;
  int local_8 [2];
  
  local_10[0] = *DAT_021c6ef4;
  local_10[1] = DAT_021c6ef4[1];
  iVar3 = FUN_021d283c(0x2c,4);
  *DAT_021c6ef8 = iVar3;
  FUN_021c20dc(&local_c,local_8);
  if (local_c == 0) {
    FUN_021cd948(*DAT_021c6ef8 + 8);
    uVar2 = FUN_021d3254(*DAT_021c6ef8 + 8,0x20);
    *(undefined1 *)(*DAT_021c6ef8 + 0x29) = uVar2;
  }
  FUN_021c6da4();
  FUN_021bf86c(local_c + 9);
  if (local_8[0] == 1) {
    FUN_021bf43c(0x81,0xffffffff);
  }
  else {
    FUN_021bf43c(local_10[local_c],0xffffffff);
  }
  FUN_021bf5ec(2);
  uVar4 = FUN_021d2288(0,0);
  *(undefined4 *)*DAT_021c6ef8 = uVar4;
  uVar4 = FUN_021d1c18(0,0x3e);
  piVar1 = DAT_021c6ef8;
  *(undefined4 *)(*DAT_021c6ef8 + 4) = uVar4;
  *(ushort *)(*(int *)(*piVar1 + 4) + 4) =
       *(ushort *)(*(int *)(*piVar1 + 4) + 4) & (ushort)DAT_021c6efc | (ushort)DAT_021c6f00;
  FUN_021c6914();
  FUN_021c696c();
  FUN_021c212c(DAT_021c6f04);
  return;
}

