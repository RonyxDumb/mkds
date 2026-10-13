/* Decompiled C draft; module arm9; ROM address 020213a4. No matching claim. */
#include "types.h"
#include "deps/020213a4_func_020213a4.h"

void func_020213a4(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  Os_DisableIrq();
  puVar2 = puRam020213e8;
  puVar1 = puRam020213e4;
  puVar3 = (undefined4 *)
           (*(uint *)((uint)puRam020213e4 & 0xfffffffc) >> ((uint)puRam020213e4 & 3) * 8 |
           *(uint *)((uint)puRam020213e4 & 0xfffffffc) << ((uint)puRam020213e4 & 3) * -8 + 0x20);
  if (puVar3 == (undefined4 *)0x0) {
    *puRam020213e4 = param_1;
    *puVar2 = param_1;
  }
  else {
    *puVar3 = param_1;
    *puVar1 = param_1;
  }
  *param_1 = 0;
  Os_RestoreIrq();
  return;
}

