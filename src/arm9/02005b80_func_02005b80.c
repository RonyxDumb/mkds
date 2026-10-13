/* Decompiled C draft; module arm9; ROM address 02005b80. No matching claim. */
#include "types.h"
#include "deps/02005b80_func_02005b80.h"

undefined4 func_02005b80(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  puVar2 = (undefined1 *)(param_1 + iRam02005be4 + param_2 * 0x68);
  if (*(char *)(param_1 + iRam02005be4 + param_2 * 0x68) == '\x02') {
    iVar1 = func_02006ffc();
    uVar3 = uRam02005be8;
    if (iVar1 != 0) {
      uVar3 = 1;
    }
    if ((puVar2[1] == '\x06') &&
       (iVar1 = func_020063f4(*(undefined4 *)(puVar2 + 0x10),*(undefined4 *)(puVar2 + 0x14)),
       iVar1 != 0)) {
      uVar4 = func_020070d8();
      uVar4 = func_02006648(param_3,uVar3,puVar2[2],*(undefined4 *)(puVar2 + 0x10),
                            *(undefined4 *)(puVar2 + 0x14),iVar1,uVar4);
      *puVar2 = 1;
    }
  }
  return uVar4;
}

