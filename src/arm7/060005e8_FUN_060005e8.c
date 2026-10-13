/* Decompiled C draft; module arm7; ROM address 060005e8. No matching claim. */
#include "types.h"
#include "deps/060005e8_FUN_060005e8.h"

int FUN_060005e8(undefined4 param_1)

{
  undefined2 *puVar1;
  int local_8 [2];
  
  thunk_FUN_037f9854(DAT_06000660,param_1,1);
  thunk_FUN_037f97b4(DAT_06000664,local_8,1);
  if (*(short *)(local_8[0] + (uint)*(ushort *)(local_8[0] + 0xe) * 2 + 0x14) == 0xe) {
    puVar1 = (undefined2 *)thunk_FUN_03807424();
    *puVar1 = 0x80;
    puVar1[1] = 0x13;
    puVar1[2] = 0x18;
    thunk_FUN_038074cc();
    thunk_FUN_037fb9c0();
    thunk_FUN_037fb000();
  }
  return local_8[0];
}

