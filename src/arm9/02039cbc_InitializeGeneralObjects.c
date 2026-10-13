/* Decompiled C draft; module arm9; ROM address 02039cbc. No matching claim. */
#include "types.h"
#include "deps/02039cbc_InitializeGeneralObjects.h"

void InitializeGeneralObjects(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10 [2];
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = AllocateHeapsAndBuffers(uVar1,&local_20,local_10,&local_1c,&local_18,&local_14);
  Card_SetUserCardPulledOutCallback(uRam02039df8);
  InitializeSceneOverlayConfig(local_20);
  InitializeGlobalZM(local_20);
  CreateMountManager_from_thumb(local_20);
  InitializeSystemContext(local_20);
  InitializeGlobalZE(local_20);
  if (*psRam02039dfc != 2) {
    InitializeGlobalB_from_thumb(local_20);
  }
  InitializeGlobalCO(local_20);
  InitializeSaveDataHolder_from_thumb(local_20);
  InitializeAudio(local_10[0],uVar1);
  func_02108e94(1);
  iVar2 = Os_IsEmulator();
  if (iVar2 == 0) {
    Rtc_Initialize();
  }
  Input_Initialize(local_20);
  InitializeSaveDataIoManager_from_thumb(local_20);
  InitializeWorker(local_20);
  InitializeOverlayManager(local_20);
  InitializeGlobalB488_from_thumb(local_20);
  LoadEmbeddedStatic2DArchive_from_thumb(local_20);
  InitializeGlobal1A44_from_thumb(local_20);
  func_02057ed4();
  if (*psRam02039dfc == 2) {
    PopulateMountDatas_MBChild_from_thumb(local_1c,local_18,local_14);
  }
  PopulateNextRaceConfig();
  InitializePrepareBackup_from_thumb();
  ResetOverlayManager();
  CreateGlobalB488_from_thumb();
  return;
}

