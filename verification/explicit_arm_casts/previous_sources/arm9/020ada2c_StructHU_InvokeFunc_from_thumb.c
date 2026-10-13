/* Decompiled C draft; module arm9; ROM address 020ada2c. No matching claim. */
#include "types.h"
#include "deps/020ada2c_StructHU_InvokeFunc_from_thumb.h"

void StructHU_InvokeFunc_from_thumb(undefined4 param_1)

{
  OamBuffer_ResetValues16_from_thumb(*piRam020ada74 + 0xb0,*piRam020ada74 + iRam020ada78);
  (**(code **)(*piRam020ada74 + *(int *)(*piRam020ada74 + 0xc) * 8 + 0x18))(param_1);
  StructHU_IncrementSomeCounter(*piRam020ada74);
  NavigationContext_OnSceneUpdate_from_thumb();
  OamBuffer_SomeFn2_from_thumb(*piRam020ada74 + 0xb0,*piRam020ada74 + iRam020ada78);
  return;
}

