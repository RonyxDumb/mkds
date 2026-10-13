/* Decompiled C draft; module arm9_ov003; ROM address 021c2840. No matching claim. */
#include "types.h"
#include "deps/021c2840_FUN_021c2840.h"

void FUN_021c2840(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  iVar3 = FUN_021d285c(DAT_021c28cc,0x20);
  piVar1 = DAT_021c28d0;
  *DAT_021c28d0 = iVar3;
  *(undefined4 *)(iVar3 + DAT_021c28d4) = param_1;
  *(undefined1 *)(*piVar1 + DAT_021c28d8) = 0;
  *(undefined1 *)(*piVar1 + DAT_021c28dc) = 0;
  local_28 = *DAT_021c28e0;
  local_24 = DAT_021c28e0[1];
  local_20 = DAT_021c28e0[2];
  uStack_1c = DAT_021c28e0[3];
  local_18 = DAT_021c28e0[4];
  uStack_14 = DAT_021c28e0[5];
  local_10 = DAT_021c28e0[6];
  local_24 = FUN_021c2530(*DAT_021c28e4,0xf);
  local_20 = FUN_021c2530(*DAT_021c28e4,0x10);
  cVar2 = FUN_021c20d0();
  local_10 = CONCAT31(local_10._1_3_,cVar2 + '1');
  FUN_021d1358(*DAT_021c28d0,&local_28);
  iVar3 = FUN_021d11d4();
  if (iVar3 == 0) {
    func_0x0200fd1c();
  }
  uVar4 = FUN_021d3544(0,DAT_021c28e8,0,0x78);
  *(undefined4 *)(*DAT_021c28d0 + DAT_021c28ec) = uVar4;
  return;
}

