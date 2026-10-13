/* Decompiled C draft; module arm9_ov000; ROM address 021887cc. No matching claim. */
#include "types.h"
#include "deps/021887cc_FUN_021887cc.h"

undefined4 FUN_021887cc(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_02188528();
  if (uVar1 == 1) {
    uVar1 = FUN_02189f00();
  }
  else if (uVar1 < 7) {
    uVar2 = func_0x0200fca0();
    uVar1 = FUN_02189e80();
    FUN_02188534();
    func_0x0200fcb4(uVar2);
  }
  else if (uVar1 < 9) {
    uVar1 = FUN_0218922c();
  }
  else if (uVar1 < 10) {
    uVar1 = FUN_021897bc();
  }
  else if (uVar1 < 0x10) {
    uVar1 = FUN_0218a294();
  }
  else if (uVar1 == 0x11) {
    uVar1 = FUN_021894c0();
  }
  FUN_02188534(uVar1);
  if (uVar1 == 0x10) {
    uVar2 = FUN_02188408();
    FUN_021884a8();
    return uVar2;
  }
  if (uVar1 == 0x12) {
    FUN_021884a8();
    return 0xffffffff;
  }
  return 0;
}

