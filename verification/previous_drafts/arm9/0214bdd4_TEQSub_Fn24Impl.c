/* Decompiled C draft; module arm9; ROM address 0214bdd4. No matching claim. */
#include "types.h"
#include "deps/0214bdd4_TEQSub_Fn24Impl.h"

void TEQSub_Fn24Impl(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = GetAnotherSubEngineBGOffset();
  uVar2 = *(uint *)(uRam0214be38 & 0xfffffffc) >> (uRam0214be38 & 3) * 8 |
          *(uint *)(uRam0214be38 & 0xfffffffc) << (uRam0214be38 & 3) * -8 + 0x20;
  if ((uVar2 != 0xffffffff) && (0x1c < param_3)) {
    MI_DmaCopy16(uVar2,param_1,iVar1 + param_2,param_3);
    return;
  }
  CopyMemory16(param_1,iVar1 + param_2,param_3);
  return;
}

