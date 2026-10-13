/* Decompiled C draft; module arm7; ROM address 06009d3c. No matching claim. */
#include "types.h"
#include "deps/06009d3c_FUN_06009d3c.h"

void FUN_06009d3c(void)

{
  int iVar1;
  
  iVar1 = (*(uint *)(DAT_06009db8 & 0xfffffffc) >> (DAT_06009db8 & 3) * 8 |
          *(uint *)(DAT_06009db8 & 0xfffffffc) << (DAT_06009db8 & 3) * -8 + 0x20) + DAT_06009dbc;
  thunk_FUN_037fb218(0,iVar1,0x10);
  FUN_06018844(0x40,1,iVar1);
  FUN_06018844(0x41,1,iVar1 + 2);
  FUN_06018844(0x42,1,iVar1 + 4);
  FUN_06018844(0x43,1,iVar1 + 6);
  return;
}

