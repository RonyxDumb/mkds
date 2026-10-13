/* Decompiled C draft; module arm9; ROM address 0214eb88. No matching claim. */
#include "types.h"
#include "deps/0214eb88_Os_InitializeTouchPanelFifo.h"

void Os_InitializeTouchPanelFifo(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*psRam0214ec0c == 0) {
    *psRam0214ec0c = 1;
    func_0214d5b8();
    puVar1 = puRam0214ec10;
    *(undefined2 *)((int)puRam0214ec10 + 0x32) = 0;
    *(undefined2 *)((int)puVar1 + 0x36) = 0;
    *(undefined2 *)(puVar1 + 3) = 0;
    *puVar1 = 0;
    puVar1[4] = 0;
    *(undefined2 *)(puVar1 + 0xc) = 0;
    *(undefined2 *)(puVar1 + 0xd) = 0;
    do {
      iVar2 = Fifo_IsHandlerReady(6,1);
    } while (iVar2 == 0);
    Fifo_RegisterHandler(6,uRam0214ec14);
    return;
  }
  return;
}

