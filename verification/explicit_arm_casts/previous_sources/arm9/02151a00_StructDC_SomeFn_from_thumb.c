/* Decompiled C draft; module arm9; ROM address 02151a00. No matching claim. */
#include "types.h"
#include "deps/02151a00_StructDC_SomeFn_from_thumb.h"

undefined4 StructDC_SomeFn_from_thumb(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_2c [24];
  
  Mem_CpuFill16(0,param_1,uRam02151a5c);
  iVar1 = iRam02151a60;
  iVar4 = 0;
  iVar3 = param_1;
  do {
    *(undefined1 *)(iVar3 + 0xe7) = 0xff;
    iVar3 = iVar3 + iVar1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  StructDW_SomeFn_from_thumb(auStack_2c);
  uVar2 = StructDW_SomeFn_2_from_thumb(auStack_2c);
  iVar1 = iRam02151a60;
  iVar3 = 0;
  do {
    Mem_CpuCopy8(uVar2,param_1 + 0xf0,0xe);
    param_1 = param_1 + iVar1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  return 0;
}

