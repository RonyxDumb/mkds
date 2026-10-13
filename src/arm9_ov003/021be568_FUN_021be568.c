/* Decompiled C draft; module arm9_ov003; ROM address 021be568. No matching claim. */
#include "types.h"
#include "deps/021be568_FUN_021be568.h"

void FUN_021be568(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  func_0x0200fca0();
  iVar2 = 0;
  *DAT_021be590 = 0;
  *DAT_021be594 = 0;
  puVar1 = DAT_021be598;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  func_0x0200fcb4();
  return;
}

