/* Decompiled C draft; module arm9; ROM address 02091828. No matching claim. */
#include "types.h"
#include "deps/02091828_func_02091828.h"

undefined1 func_02091828(int param_1,undefined4 param_2,char *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  uVar1 = *param_4;
  if (*param_3 == '\x01') {
    *(undefined4 *)(param_1 + 0xb8) = uRam02091884;
    *(undefined4 *)(param_1 + 0xbc) = 0x8000;
    *(undefined4 *)(param_1 + 0xb0) = 0;
    *(undefined4 *)(param_1 + 0xb4) = 0;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam02091888;
    *(undefined4 *)(param_1 + 200) = 1;
    func_020d26f8();
  }
  return uVar1;
}

