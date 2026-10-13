/* Decompiled C draft; module arm9; ROM address 02005d4c. No matching claim. */
#include "types.h"
#include "deps/02005d4c_func_02005d4c.h"

undefined4 func_02005d4c(int param_1,uint param_2,undefined4 param_3)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  
  uVar3 = 0;
  puVar4 = (undefined1 *)(param_1 + iRam02005da8 + param_2 * 0x68);
  if ((*(char *)(param_1 + iRam02005da8 + param_2 * 0x68) == '\x02') && (puVar4[1] == '\x02')) {
    sVar1 = func_02006ef8();
    uVar3 = func_020070d8();
    uVar2 = func_020070e4();
    uVar3 = func_020067f0(param_3,1 << (param_2 & 0xff) & 0xffff,puVar4[2],(int)sVar1,uVar3,uVar2);
    *puVar4 = 1;
  }
  return uVar3;
}

