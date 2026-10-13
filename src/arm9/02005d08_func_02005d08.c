/* Decompiled C draft; module arm9; ROM address 02005d08. No matching claim. */
#include "types.h"
#include "deps/02005d08_func_02005d08.h"

undefined4 func_02005d08(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = 0;
  puVar2 = (undefined1 *)(param_1 + iRam02005d48 + param_2 * 0x68);
  if ((*(char *)(param_1 + iRam02005d48 + param_2 * 0x68) == '\x02') && (puVar2[1] == '\b')) {
    uVar1 = func_020065a8(param_3,1 << (param_2 & 0xff) & 0xffff,puVar2[2],
                          *(undefined4 *)(puVar2 + 0x10));
    *puVar2 = 1;
  }
  return uVar1;
}

