/* Decompiled C draft; module arm9; ROM address 02110838. No matching claim. */
#include "types.h"
#include "deps/02110838_func_02110838.h"

void func_02110838(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = iRam02110870;
  iVar3 = 0;
  *(undefined4 *)(iRam02110870 + 0x78) = 0;
  *(undefined4 *)(iVar2 + 0x70) = 0;
  *(undefined4 *)(iVar2 + 0x74) = 0;
  do {
    *(undefined4 *)(iVar2 + iVar3 * 4) = 0xd;
    iVar1 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    *(undefined4 *)(iVar2 + iVar1 + 0x38) = 2;
  } while (iVar3 < 0xe);
  return;
}

