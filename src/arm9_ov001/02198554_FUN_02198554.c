/* Decompiled C draft; module arm9_ov001; ROM address 02198554. No matching claim. */
#include "types.h"
#include "deps/02198554_FUN_02198554.h"

void FUN_02198554(void)

{
  undefined4 *puVar1;
  
  func_0x02125928();
  puVar1 = DAT_021985ac;
  *(undefined4 *)*DAT_021985ac = ((undefined4 *)*DAT_021985ac)[1];
  switch(*(undefined4 *)*puVar1) {
  case 0:
    FUN_02198768();
    return;
  case 1:
    FUN_021986e8();
    return;
  case 2:
    FUN_02198624();
    return;
  case 3:
    FUN_021985b0();
  }
  return;
}

