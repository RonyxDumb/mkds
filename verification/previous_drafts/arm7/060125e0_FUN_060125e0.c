/* Decompiled C draft; module arm7; ROM address 060125e0. No matching claim. */
#include "types.h"
#include "deps/060125e0_FUN_060125e0.h"

undefined4 FUN_060125e0(int param_1,int param_2)

{
  *(undefined2 *)(param_2 + 2) = 1;
  if ((*(ushort *)(param_1 + 0x10) & 1) != 0) {
    FUN_06014930();
  }
  if ((*(ushort *)(param_1 + 0x10) & 2) != 0) {
    FUN_060148d0();
  }
  if ((*(ushort *)(param_1 + 0x10) & 4) != 0) {
    FUN_06014818();
  }
  return 0;
}

