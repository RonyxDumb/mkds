/* Decompiled C draft; module arm9_ov003; ROM address 021c4d3c. No matching claim. */
#include "types.h"
#include "deps/021c4d3c_FUN_021c4d3c.h"

void FUN_021c4d3c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_26 [26];
  
  iVar1 = FUN_021c27b4();
  uVar2 = FUN_021d2288(0,0);
  *DAT_021c4dbc = 0;
  *DAT_021c4dc0 = 0;
  FUN_021c4cd8();
  func_0x0214cfe4(0,(int)(uintptr_t)(auStack_26),0x16);
  func_0x0214cffc(iVar1 + 2,(int)(uintptr_t)(auStack_26),(uint)*(byte *)(iVar1 + 1) << 1);
  FUN_021d2070(uVar2,(uint)*DAT_021c4dc4,(uint)DAT_021c4dc4[1],
               (uint)DAT_021c4dc4[2] - (uint)*DAT_021c4dc4,
               (uint)DAT_021c4dc4[3] - (uint)DAT_021c4dc4[1],2,DAT_021c4dc8,auStack_26);
  FUN_021d1fd0(uVar2);
  FUN_021c27d0(DAT_021c4dcc);
  FUN_021c212c(DAT_021c4dd0);
  return;
}

