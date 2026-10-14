/* Decompiled C draft; module arm9; ROM address 0205e180. No matching claim. */
#include "types.h"
#include "deps/0205e180_InitializeSceneOverlayConfig.h"

void InitializeSceneOverlayConfig(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)Mem_AllocateHeap(param_1,0x10);
  puVar1 = puRam0205e1c0;
  *puRam0205e1c0 = puVar2;
  *puVar2 = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 4) = 3;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xc) = 0;
  return;
}

