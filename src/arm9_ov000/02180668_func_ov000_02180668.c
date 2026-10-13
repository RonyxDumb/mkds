/* Decompiled C draft; module arm9_ov000; ROM address 02180668. No matching claim. */
#include "types.h"
#include "deps/02180668_func_ov000_02180668.h"

undefined4 func_ov000_02180668(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18 [4];
  
  local_18[0] = *puRam02180698;
  local_18[1] = puRam02180698[1];
  local_18[2] = puRam02180698[2];
  local_18[3] = puRam02180698[3];
  uVar1 = local_18[param_1];
  if ((param_1 == 2) && (*(uint *)(*piRam0218069c + 4) < 2)) {
    uVar1 = 6;
  }
  return uVar1;
}

