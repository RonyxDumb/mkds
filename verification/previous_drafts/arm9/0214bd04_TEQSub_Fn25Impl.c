/* Decompiled C draft; module arm9; ROM address 0214bd04. No matching claim. */
#include "types.h"
#include "deps/0214bd04_TEQSub_Fn25Impl.h"

void TEQSub_Fn25Impl(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = func_0214a2a0();
  uVar2 = *(uint *)(uRam0214bd68 & 0xfffffffc) >> (uRam0214bd68 & 3) * 8 |
          *(uint *)(uRam0214bd68 & 0xfffffffc) << (uRam0214bd68 & 3) * -8 + 0x20;
  if ((uVar2 != 0xffffffff) && (0x1c < param_3)) {
    MI_DmaCopy16(uVar2,param_1,iVar1 + param_2,param_3);
    return;
  }
  CopyMemory16(param_1,iVar1 + param_2,param_3);
  return;
}

