/* Decompiled C draft; module arm9_ov001; ROM address 02187af4. No matching claim. */
#include "types.h"
#include "deps/02187af4_FUN_02187af4.h"

void FUN_02187af4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = param_1 + 0xd0;
  iVar2 = param_1;
  do {
    if (*(int *)(iVar2 + 0xd0) != 0) {
      func_0x0208b6b0(iVar1);
    }
    iVar2 = iVar2 + 0x18;
    iVar1 = iVar1 + 0x18;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5);
  *(undefined4 *)(param_1 + 0xb8) = 0;
  return;
}

