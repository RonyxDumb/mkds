/* Decompiled C draft; module arm9; ROM address 020b3008. No matching claim. */
#include "types.h"
#include "deps/020b3008_func_020b3008.h"

void func_020b3008(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = piRam020b3028;
  *(undefined4 *)(*piRam020b3028 + 0x24) = 0;
  iVar3 = *piVar1;
  iVar2 = GetCurrentOptionMenuKind_from_thumb();
  *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar3 + iVar2 * 0x1c + 0x38);
  return;
}

