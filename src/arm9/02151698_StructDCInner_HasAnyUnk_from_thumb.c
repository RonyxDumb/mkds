/* Decompiled C draft; module arm9; ROM address 02151698. No matching claim. */
#include "types.h"
#include "deps/02151698_StructDCInner_HasAnyUnk_from_thumb.h"

undefined4 StructDCInner_HasAnyUnk_from_thumb(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(char *)(param_1 + iVar1) != '\0') {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  return 0;
}

