/* Decompiled C draft; module arm9; ROM address 02046ae4. No matching claim. */
#include "types.h"
#include "deps/02046ae4_Scene_Menu2_Initialize.h"

void Scene_Menu2_Initialize(void)

{
  undefined4 uVar1;
  int iVar2;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  iVar2 = CreateDisplayConfig(uVar1,uRam02046b3c);
  DisplayEngineConfig_SetBg1Config(iVar2 + 0x28,0,0,0,0,4,0,0);
  SetGlobalDisplayConfig(iVar2);
  return;
}

