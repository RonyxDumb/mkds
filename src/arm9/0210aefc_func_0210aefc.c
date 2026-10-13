/* Decompiled C draft; module arm9; ROM address 0210aefc. No matching claim. */
#include "types.h"
#include "deps/0210aefc_func_0210aefc.h"

void func_0210aefc(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = iRam0210af3c;
  iVar3 = 0;
  *(undefined4 *)(iRam0210af3c + 0x60) = 0;
  *(undefined4 *)(iVar2 + 100) = 0;
  do {
    *(undefined4 *)(iVar2 + iVar3 * 4) = 0;
    iVar1 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    *(undefined4 *)(iVar2 + iVar1 + 0x40) = 0;
  } while (iVar3 < 8);
  *(undefined4 *)(iVar2 + 0x68) = 0x5f;
  *(undefined4 *)(iVar2 + 0x6c) = 0xffffffff;
  return;
}

