/* Decompiled C draft; module arm9_ov001; ROM address 02187444. No matching claim. */
#include "types.h"
#include "deps/02187444_FUN_02187444.h"

void FUN_02187444(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = param_1;
  do {
    if (*(int *)(iVar1 + 0xd0) == 0) {
      iVar2 = iVar2 * 0x18;
      *(undefined4 *)(param_1 + iVar2 + 0xc4) = *(undefined4 *)(param_1 + 4);
      iVar1 = func_0x020d3d48(0);
      *(int *)(param_1 + iVar2 + 200) = -iVar1;
      *(undefined4 *)(param_1 + iVar2 + 0xcc) = *(undefined4 *)(param_1 + 0xc);
      if (*(int *)(param_1 + 0xd0 + iVar2) != 0) {
        func_0x0208b6b0(param_1 + 0xd0 + iVar2);
      }
      func_0x0208e490(param_2,(undefined4 *)(uintptr_t)(param_1 + 0xc4 + iVar2),1);
      *(undefined4 *)(param_1 + iVar2 + 0xbc) = 0;
      *(undefined4 *)(param_1 + iVar2 + 0xc0) = param_3;
      return;
    }
    iVar1 = iVar1 + 0x18;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return;
}

