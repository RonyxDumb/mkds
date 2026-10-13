/* Decompiled C draft; module arm9_ov003; ROM address 021cee98. No matching claim. */
#include "types.h"
#include "deps/021cee98_FUN_021cee98.h"

void FUN_021cee98(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 auStack_10 [4];
  int local_c;
  
  FUN_021d1770(*(undefined4 *)*DAT_021cef18,0,auStack_10,&local_c);
  local_c = local_c + -0xc;
  uVar2 = (uint)*(ushort *)(DAT_021cef1c + (uint)*(byte *)(*DAT_021cef18 + 0x1c) * 4);
  if ((int)uVar2 < local_c) {
    FUN_021cec50();
    return;
  }
  FUN_021cec50(uVar2);
  if (*(char *)(*DAT_021cef18 + 0x1c) == '\x05') {
    uVar1 = FUN_021d3544(0,DAT_021cef20,0,0x78);
    *(undefined4 *)(*DAT_021cef18 + 0x14) = uVar1;
  }
  else {
    uVar1 = FUN_021d3544(0,DAT_021cef24,0,0x78);
    *(undefined4 *)(*DAT_021cef18 + 0x14) = uVar1;
  }
  FUN_021d34c8(1,param_1);
  return;
}

