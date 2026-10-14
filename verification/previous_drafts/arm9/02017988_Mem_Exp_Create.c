/* Decompiled C draft; module arm9; ROM address 02017988. No matching claim. */
#include "types.h"
#include "deps/02017988_Mem_Exp_Create.h"

undefined4 Mem_Exp_Create(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_2 + param_1 & 0xfffffffc;
  uVar1 = param_1 + 3U & 0xfffffffc;
  if ((uVar1 <= uVar3) && (0x4b < uVar3 - uVar1)) {
    uVar2 = Mem_Exp_Initialize();
    return uVar2;
  }
  return 0;
}

