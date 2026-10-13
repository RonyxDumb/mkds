/* Decompiled C draft; module arm9; ROM address 02047498. No matching claim. */
#include "types.h"
#include "deps/02047498_func_02047498.h"

void func_02047498(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *piRam020474d4 + iRam020474d8 + param_2 * 0xc;
  func_0204f4d0(param_1,*(undefined4 *)(*piRam020474d4 + iRam020474d8 + param_2 * 0xc),iVar1 + 4,
                *(uint *)(iVar1 + 8) & 0x1fffffff,(*(int *)(iVar1 + 8) << 2) >> 0x1f);
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & uRam020474dc | uRam020474e0;
  return;
}

