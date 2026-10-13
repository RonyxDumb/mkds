/* Decompiled C draft; module arm9_ov003; ROM address 021c6668. No matching claim. */
#include "types.h"
#include "deps/021c6668_FUN_021c6668.h"

void FUN_021c6668(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int local_8 [2];
  
  iVar2 = FUN_021d283c(0x5c,4);
  *DAT_021c66f4 = iVar2;
  FUN_021c20dc(local_8,0);
  if (local_8[0] == 0) {
    *DAT_021c66f8 = 0;
    *DAT_021c66fc = 0;
  }
  uVar1 = FUN_021cd0d0(*DAT_021c66f4);
  *(undefined1 *)(*DAT_021c66f4 + 0x51) = uVar1;
  FUN_021c6588();
  FUN_021bf854();
  FUN_021bf43c(0x80,0xffffffff);
  FUN_021bf5ec(2);
  FUN_021c6508();
  FUN_021c6400();
  uVar3 = FUN_021d2288(0,0);
  *(undefined4 *)(*DAT_021c66f4 + 0xc) = uVar3;
  uVar3 = FUN_021d3544(1,DAT_021c6700,0,0x6e);
  *(undefined4 *)(*DAT_021c66f4 + 0x3c) = uVar3;
  FUN_021c5c68();
  FUN_021c590c();
  FUN_021c212c(DAT_021c6704);
  return;
}

