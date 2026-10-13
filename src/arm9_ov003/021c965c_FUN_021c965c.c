/* Decompiled C draft; module arm9_ov003; ROM address 021c965c. No matching claim. */
#include "types.h"
#include "deps/021c965c_FUN_021c965c.h"

void FUN_021c965c(void)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  
  iVar3 = FUN_021cdb6c();
  iVar4 = FUN_021d283c(0x48,4);
  piVar2 = DAT_021c9798;
  *DAT_021c9798 = iVar4;
  *(undefined1 *)(iVar4 + 0x43) = *(undefined1 *)(iVar3 + 0xf6);
  *(undefined1 *)(*piVar2 + 0x42) = 0xc;
  FUN_021c94c8();
  FUN_021c9500();
  if (*DAT_021c979c == '\0') {
    iVar4 = FUN_021c20d0();
    FUN_021bf43c(0x7c,(int)*(char *)(DAT_021c97a0 + iVar4),*(byte *)(iVar3 + 0xf4) + 1);
  }
  else {
    FUN_021bf43c(0x97,0xffffffff);
  }
  FUN_021bf5ec(1);
  FUN_021bf83c();
  uVar5 = func_0x02133068((uint)*DAT_021c97a4 * 0x37,0x91);
  FUN_021ccea4(2,0x55,0xf1,0x41,uVar5);
  uVar6 = FUN_021d2288(0,1);
  *(undefined4 *)(*DAT_021c9798 + 0x14) = uVar6;
  iVar8 = 0;
  iVar4 = 0;
  uVar1 = *(undefined1 *)(DAT_021c97a8 + 1);
  do {
    uVar6 = FUN_021d1c18(0,uVar1);
    *(undefined4 *)(*DAT_021c9798 + iVar4 + 0x18) = uVar6;
    iVar4 = iVar4 + 4;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 7);
  pcVar7 = (char *)(iVar3 + 0xe7);
  if (*pcVar7 == '\x01') {
    uVar6 = FUN_021d1c18(0,0x50);
    piVar2 = DAT_021c9798;
    *(undefined4 *)(*DAT_021c9798 + 0x34) = uVar6;
    *(ushort *)(*(int *)(*piVar2 + 0x34) + 4) =
         *(ushort *)(*(int *)(*piVar2 + 0x34) + 4) & (ushort)DAT_021c97ac | (ushort)DAT_021c97b0;
  }
  else if (*pcVar7 == '\x02') {
    uVar6 = FUN_021d1c18(0,0x51);
    piVar2 = DAT_021c9798;
    *(undefined4 *)(*DAT_021c9798 + 0x34) = uVar6;
    *(ushort *)(*(int *)(*piVar2 + 0x34) + 4) =
         *(ushort *)(*(int *)(*piVar2 + 0x34) + 4) & (ushort)DAT_021c97ac | (ushort)DAT_021c97b0;
  }
  uVar5 = FUN_021d3544(1,DAT_021c97b4,0,0x6e,uVar5,pcVar7);
  *(undefined4 *)(*DAT_021c9798 + 0x3c) = uVar5;
  uVar5 = FUN_021d3544(0,DAT_021c97b8,0,0x78);
  *(undefined4 *)*DAT_021c9798 = uVar5;
  FUN_021c8b94();
  FUN_021c81b8();
  FUN_021c212c(DAT_021c97bc);
  return;
}

