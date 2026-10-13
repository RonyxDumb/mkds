/* Decompiled C draft; module arm7; ROM address 06009d04. No matching claim. */
#include "types.h"
#include "deps/06009d04_FUN_06009d04.h"

void FUN_06009d04(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_06009d38;
  uVar2 = 0;
  do {
    *(undefined2 *)(*(ushort *)(iVar1 + uVar2 * 4) + 0x4808000) =
         *(undefined2 *)(iVar1 + uVar2 * 4 + 2);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  return;
}

