/* Decompiled C draft; module arm9_ov000; ROM address 021ae16c. No matching claim. */
#include "types.h"
#include "deps/021ae16c_FUN_021ae16c.h"

undefined4 FUN_021ae16c(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar1 = FUN_021ae314();
  uVar3 = 0;
  while( true ) {
    *(undefined4 *)(param_1 + 0x28) = uVar1;
    *(undefined1 *)(param_1 + 8) = 2;
    uVar4 = func_0x0200f5ac();
    *(uint *)(param_1 + 0x10) = (uint)uVar4 >> 0x10 | (int)((ulonglong)uVar4 >> 0x20) << 0x10;
    FUN_021aefc0(param_1,2,0x18);
    uVar2 = func_0x0200fca0();
    if (*DAT_021ae1e0 != 0) {
      *(undefined4 *)(param_1 + 4) = 1;
      func_0x0200e01c(0);
    }
    func_0x0200fcb4(uVar2);
    if (*(char *)(param_1 + 8) == '\x04') break;
    if ((*DAT_021ae1e0 == 0) || (uVar3 = uVar3 + 1, 2 < uVar3)) {
      return 1;
    }
  }
  return 0;
}

