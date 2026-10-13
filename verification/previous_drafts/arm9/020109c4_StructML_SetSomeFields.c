/* Decompiled C draft; module arm9; ROM address 020109c4. No matching claim. */
#include "types.h"
#include "deps/020109c4_StructML_SetSomeFields.h"

void StructML_SetSomeFields
               (int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
               undefined1 param_5)

{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  *(undefined1 *)(param_1 + 0x24) = param_4;
  *(undefined1 *)(param_1 + 0x25) = param_5;
  return;
}

