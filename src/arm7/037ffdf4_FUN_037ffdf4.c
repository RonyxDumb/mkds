/* Decompiled C draft; module arm7; ROM address 037ffdf4. No matching claim. */
#include "types.h"
#include "deps/037ffdf4_FUN_037ffdf4.h"

void FUN_037ffdf4(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *DAT_037ffe3c = param_1;
  uVar2 = FUN_037f8a1c();
  *DAT_037ffe40 = uVar2;
  puVar1 = DAT_037ffe44;
  *DAT_037ffe44 = 0;
  puVar1[1] = 0;
  puVar1 = DAT_037ffe48;
  *DAT_037ffe48 = 0;
  puVar1[1] = 0;
  FUN_038007d0();
  return;
}

