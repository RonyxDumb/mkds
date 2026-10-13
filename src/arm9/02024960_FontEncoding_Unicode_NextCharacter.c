/* Decompiled C draft; module arm9; ROM address 02024960. No matching claim. */
#include "types.h"
#include "deps/02024960_FontEncoding_Unicode_NextCharacter.h"

undefined2 FontEncoding_Unicode_NextCharacter(undefined4 *param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)
           (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
  uVar1 = *puVar2;
  *param_1 = puVar2 + 1;
  return uVar1;
}

