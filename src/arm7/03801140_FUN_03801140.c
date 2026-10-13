/* Decompiled C draft; module arm7; ROM address 03801140. No matching claim. */
#include "types.h"
#include "deps/03801140_FUN_03801140.h"

void FUN_03801140(void)

{
  int iVar1;
  
  if (*(uint *)((uint)DAT_03801198 & 0xfffffffc) >> ((uint)DAT_03801198 & 3) * 8 == 0 &&
      *(uint *)((uint)DAT_03801198 & 0xfffffffc) << ((uint)DAT_03801198 & 3) * -8 + 0x20 == 0) {
    *DAT_03801198 = 1;
    thunk_FUN_037fb72c();
    do {
      iVar1 = FUN_037fb698(0xe,0);
    } while (iVar1 == 0);
    FUN_037fb6c0(0xe,DAT_0380119c);
  }
  return;
}

