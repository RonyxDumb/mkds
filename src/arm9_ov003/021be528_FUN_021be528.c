/* Decompiled C draft; module arm9_ov003; ROM address 021be528. No matching claim. */
#include "types.h"
#include "deps/021be528_FUN_021be528.h"

undefined4 FUN_021be528(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  func_0x0200fca0();
  piVar1 = DAT_021be55c;
  iVar2 = *DAT_021be55c;
  if (*DAT_021be560 == iVar2) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(DAT_021be564 + iVar2 * 4);
    *DAT_021be55c = iVar2 + 1;
    if (3 < iVar2 + 1) {
      *piVar1 = 0;
    }
  }
  func_0x0200fcb4();
  return uVar3;
}

