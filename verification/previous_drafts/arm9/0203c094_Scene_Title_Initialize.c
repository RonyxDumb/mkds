/* Decompiled C draft; module arm9; ROM address 0203c094. No matching claim. */
#include "types.h"
#include "deps/0203c094_Scene_Title_Initialize.h"

void Scene_Title_Initialize(void)

{
  GetActiveExecutionContext();
  ExecutionContext_GetHeapHandle();
  SomeVramConfig();
  LoadTitleFiles_from_thumb();
  MaybeResetInput();
  return;
}

