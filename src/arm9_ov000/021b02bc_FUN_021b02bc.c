/* Decompiled C draft; module arm9_ov000; ROM address 021b02bc. No matching claim. */
#include "types.h"
#include "deps/021b02bc_FUN_021b02bc.h"

int FUN_021b02bc(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x0200fca0();
  iVar2 = func_0x0200e070(DAT_021b02f4);
  if (iVar2 == 0) {
    if (*DAT_021b02f8 == 0) {
      *DAT_021b02f8 = 1;
      func_0x0200df68(DAT_021b02f4);
    }
  }
  func_0x0200fcb4(uVar1);
  return iVar2;
}

