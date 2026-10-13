/* Decompiled C draft; module arm9; ROM address 0200c7f4. No matching claim. */
#include "types.h"
#include "deps/0200c7f4_CTRDG_Initialize_from_thumb.h"

void CTRDG_Initialize_from_thumb(void)

{
  int iVar1;
  
  if (*piRam0200c848 == 0) {
    *piRam0200c848 = 1;
    CTRDGi_InitCommon_from_thumb();
    func_0214d5b8();
    do {
      iVar1 = Fifo_IsHandlerReady(0xd,1);
    } while (iVar1 == 0);
    Fifo_RegisterHandler(0xd,uRam0200c84c);
    func_0200c6b8();
    Fifo_RegisterHandler(0xd,0);
    Fifo_RegisterHandler(0xd,uRam0200c850);
    *puRam0200c854 = 0;
  }
  return;
}

