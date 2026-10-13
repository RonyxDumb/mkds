/* Decompiled C draft; module arm7; ROM address 03801610. No matching claim. */
#include "types.h"
#include "deps/03801610_FUN_03801610.h"

void FUN_03801610(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (*DAT_0380170c == 0) {
    *DAT_0380170c = 1;
    puVar1 = DAT_03801710;
    *DAT_03801710 = 0;
    puVar1[1] = 5;
    FUN_03801cd4();
    FUN_038044dc();
    FUN_03803530();
    FUN_038026e4();
    thunk_FUN_037fb72c();
    FUN_037fb6c0(6,DAT_03801714);
    FUN_037fb6c0(9,DAT_03801714);
    FUN_037fb6c0(8,DAT_03801714);
    FUN_037fb6c0(4,DAT_03801714);
    FUN_037f98e8(DAT_03801718,DAT_0380171c,0x10);
    iVar2 = DAT_03801720;
    iVar3 = 0;
    do {
      FUN_037fb2fc(iVar3 * 0x18 + iVar2,0,0x18);
      puVar1 = DAT_03801710;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x10);
    DAT_03801710[0x123] = 0;
    puVar1[0x125] = 0;
    puVar1[0x124] = 0;
    FUN_037f92d0(DAT_03801724,DAT_03801728,0,DAT_03801718,0x200,param_1);
    FUN_037f9054(DAT_03801724);
  }
  return;
}

