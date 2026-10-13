/* Decompiled C draft; module arm7; ROM address 0600aea0. No matching claim. */
#include "types.h"
#include "deps/0600aea0_FUN_0600aea0.h"

void FUN_0600aea0(void)

{
  int iVar1;
  int local_8 [2];
  
  local_8[0] = DAT_0600af1c;
  FUN_06018844(0x58,2,(int)(uintptr_t)(local_8));
  local_8[0] = local_8[0] + DAT_0600af20;
  iVar1 = FUN_0600a450();
  if ((iVar1 == 0x14) && (local_8[0] = local_8[0] - DAT_0600af24, (*DAT_0600af28 & 2) != 0)) {
    local_8[0] = local_8[0] - DAT_0600af2c;
  }
  *DAT_0600af30 = (short)local_8[0];
  return;
}

