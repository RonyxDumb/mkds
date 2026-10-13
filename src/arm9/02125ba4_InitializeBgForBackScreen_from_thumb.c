/* Decompiled C draft; module arm9; ROM address 02125ba4. No matching claim. */
#include "types.h"
#include "deps/02125ba4_InitializeBgForBackScreen_from_thumb.h"

void InitializeBgForBackScreen_from_thumb(void)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  
  uVar2 = uRam02125c14;
  uVar1 = uRam02125c10;
  *puRam02125c0c = *puRam02125c0c & uRam02125c14 | ((*puRam02125c0c & uRam02125c10) >> 8 | 8) << 8;
  puVar3 = puRam02125c18;
  *puRam02125c18 = *puRam02125c18 & 0xfffc | 3;
  *puVar3 = *puVar3 & 0x43 | (ushort)uRam02125c1c;
  *puRam02125c20 = *puRam02125c20 & uVar2 | ((*puRam02125c20 & uVar1) >> 8 | 2) << 8;
  puVar3 = puRam02125c24;
  *puRam02125c24 = *puRam02125c24 & 0xfffc | 3;
  *puVar3 = *puVar3 & 0x43 | (ushort)uRam02125c28;
  return;
}

