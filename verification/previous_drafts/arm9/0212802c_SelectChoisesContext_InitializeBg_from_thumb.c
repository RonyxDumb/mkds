/* Decompiled C draft; module arm9; ROM address 0212802c. No matching claim. */
#include "types.h"
#include "deps/0212802c_SelectChoisesContext_InitializeBg_from_thumb.h"

void SelectChoisesContext_InitializeBg_from_thumb(void)

{
  ushort *puVar1;
  
  puVar1 = puRam02128044;
  *puRam02128044 = *puRam02128044 & 0xfffc;
  *puVar1 = *puVar1 & 0x43 | (ushort)uRam02128048;
  return;
}

