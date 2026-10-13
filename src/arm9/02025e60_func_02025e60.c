/* Decompiled C draft; module arm9; ROM address 02025e60. No matching claim. */
#include "types.h"
#include "deps/02025e60_func_02025e60.h"

undefined4 func_02025e60(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  iVar1 = GetGlobalCA_from_thumb();
  switch(*(undefined4 *)(iVar1 + 200)) {
  case 0:
  case 1:
  case 3:
  case 5:
    uVar2 = *(undefined4 *)(DAT_02025ea8 + param_1 * 4);
    break;
  case 2:
    uVar2 = *(undefined4 *)(DAT_02025eac + param_1 * 4);
  }
  return uVar2;
}

