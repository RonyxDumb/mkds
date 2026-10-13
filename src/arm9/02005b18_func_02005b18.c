/* Decompiled C draft; module arm9; ROM address 02005b18. No matching claim. */
#include "types.h"
#include "deps/02005b18_func_02005b18.h"

undefined4 func_02005b18(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  puVar3 = (undefined1 *)(param_1 + iRam02005b78 + param_2 * 0x68);
  if (*(char *)(param_1 + iRam02005b78 + param_2 * 0x68) == '\x02') {
    iVar1 = func_02006ffc();
    uVar4 = uRam02005b7c;
    if (iVar1 != 0) {
      uVar4 = 1;
    }
    if (puVar3[1] == '\x06') {
      uVar5 = func_020063f4(*(undefined4 *)(puVar3 + 0x10),*(undefined4 *)(puVar3 + 0x14));
      uVar2 = func_020070d8();
      uVar5 = func_02006648(param_3,uVar4,puVar3[2],*(undefined4 *)(puVar3 + 0x10),
                            *(undefined4 *)(puVar3 + 0x14),uVar5,uVar2);
      *puVar3 = 1;
    }
  }
  return uVar5;
}

