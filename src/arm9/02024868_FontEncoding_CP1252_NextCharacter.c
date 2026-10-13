/* Decompiled C draft; module arm9; ROM address 02024868. No matching claim. */
#include "types.h"
#include "deps/02024868_FontEncoding_CP1252_NextCharacter.h"

undefined1 FontEncoding_CP1252_NextCharacter(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)
           (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
  uVar1 = *puVar2;
  *param_1 = puVar2 + 1;
  return uVar1;
}

