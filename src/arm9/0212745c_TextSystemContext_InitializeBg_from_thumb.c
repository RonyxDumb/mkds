/* Decompiled C draft; module arm9; ROM address 0212745c. No matching claim. */
#include "types.h"
#include "deps/0212745c_TextSystemContext_InitializeBg_from_thumb.h"

void TextSystemContext_InitializeBg_from_thumb(void)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  
  uVar2 = uRam021274c8;
  uVar1 = uRam021274c4;
  *puRam021274c0 = *puRam021274c0 & uRam021274c8 | ((*puRam021274c0 & uRam021274c4) >> 8 | 4) << 8;
  puVar3 = puRam021274cc;
  *puRam021274cc = *puRam021274cc & 0xfffc;
  *puVar3 = *puVar3 & 0x43 | (ushort)uRam021274d0;
  *puRam021274d4 = *puRam021274d4 & uVar2 | ((*puRam021274d4 & uVar1) >> 8 | 1) << 8;
  puVar3 = puRam021274d8;
  *puRam021274d8 = *puRam021274d8 & 0xfffc;
  *puVar3 = *puVar3 & 0x43 | (ushort)uRam021274dc;
  return;
}

