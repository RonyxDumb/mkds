/* Decompiled C draft; module arm9; ROM address 0204bad8. No matching claim. */
#include "types.h"
#include "deps/0204bad8_func_0204bad8.h"

void func_0204bad8(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = iRam0204bb2c;
  *(undefined4 *)(iRam0204bb2c + 0x4c4) = 0;
  uVar1 = iVar2 + 0x4c4U & 3;
  uVar3 = *(uint *)(iVar2 + 0x4c4U & 0xfffffffc);
  *(uint *)(iVar2 + 0x4c0) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  Os_Thread_Create(iVar2 + 0x400,uRam0204bb30,iVar2,iVar2 + 0x400,0x400,0xf);
  Os_Thread_WakeUpDirect(iVar2 + 0x400);
  return;
}

