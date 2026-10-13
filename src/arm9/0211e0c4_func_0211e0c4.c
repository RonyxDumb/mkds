/* Decompiled C draft; module arm9; ROM address 0211e0c4. No matching claim. */
#include "types.h"
#include "deps/0211e0c4_func_0211e0c4.h"

void func_0211e0c4(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    func_020442d0(*(undefined4 *)(*DAT_0211e12c + 0xc));
    return;
  case 1:
    func_0204419c(*(undefined4 *)(*DAT_0211e12c + 0xc),*(ushort *)(*DAT_0211e12c + 0x10) & 0xff);
    return;
  case 2:
    LoadStaffGhost(*(undefined4 *)(*DAT_0211e12c + 0xc));
    break;
  case 4:
    func_02043fb0(*(undefined4 *)(*DAT_0211e12c + 0xc));
    return;
  }
  return;
}

