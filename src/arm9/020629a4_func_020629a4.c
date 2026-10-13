/* Decompiled C draft; module arm9; ROM address 020629a4. No matching claim. */
#include "types.h"
#include "deps/020629a4_func_020629a4.h"

void func_020629a4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = GX_GetBankForTex();
  uVar1 = uVar2 & 0xffff;
  func_020161b4((uVar2 & 1) +
                ((int)uVar1 >> 1 & 1U) + ((int)uVar1 >> 3 & 1U) + ((int)uVar1 >> 2 & 1U),1);
  func_02016414(0x10000,1);
  InitializeModelResourceList();
  return;
}

