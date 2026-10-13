/* Decompiled C draft; module arm9_ov000; ROM address 0218b3f4. No matching claim. */
#include "types.h"
#include "deps/0218b3f4_FUN_0218b3f4.h"

int FUN_0218b3f4(void)

{
  int iVar1;
  
  if (*DAT_0218b424 == 0) {
    iVar1 = FUN_0218e004(8,100,2,DAT_0218b430,DAT_0218b428,DAT_0218b42c);
    *DAT_0218b424 = iVar1;
  }
  return *DAT_0218b424;
}

