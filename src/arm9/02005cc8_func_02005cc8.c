/* Decompiled C draft; module arm9; ROM address 02005cc8. No matching claim. */
#include "types.h"
#include "deps/02005cc8_func_02005cc8.h"

undefined4 func_02005cc8(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = 0;
  puVar2 = (undefined1 *)(param_1 + iRam02005d04 + param_2 * 0x68);
  if ((*(char *)(param_1 + iRam02005d04 + param_2 * 0x68) == '\x02') && (puVar2[1] == '\n')) {
    uVar1 = func_02006508(param_3,1 << (param_2 & 0xff) & 0xffff,puVar2[2]);
    *puVar2 = 1;
  }
  return uVar1;
}

