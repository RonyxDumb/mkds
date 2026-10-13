/* Decompiled C draft; module arm9; ROM address 02077944. No matching claim. */
#include "types.h"
#include "deps/02077944_CreateGlobalHD5_from_thumb.h"

void CreateGlobalHD5_from_thumb(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = GetDriverEntry((int)*(char *)(*piRam02077988 + 0x62));
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  iVar3 = Mem_AllocateHeap(uVar2,uRam0207798c);
  *piRam02077990 = iVar3;
  func_02076a5c();
  GetMQRacerVector333(uVar1,*piRam02077990 + iRam02077994);
  StructHD_SomeFn_2(*piRam02077990);
  return;
}

