/* Decompiled C draft; module arm9; ROM address 02021734. No matching claim. */
#include "types.h"
#include "deps/02021734_SetMDValue.h"

undefined1 SetMDValue(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = iRam02021760;
  *(undefined4 *)(iRam02021760 + param_1 * 0xc) = param_2;
  iVar1 = iVar1 + param_1 * 0xc;
  *(undefined4 *)(iVar1 + 4) = param_3;
  *(char *)(iVar1 + 8) = *(char *)(iVar1 + 8) + '\x01';
  return *(undefined1 *)(iVar1 + 8);
}

