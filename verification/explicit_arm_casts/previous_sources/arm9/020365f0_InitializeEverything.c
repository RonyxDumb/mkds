/* Decompiled C draft; module arm9; ROM address 020365f0. No matching claim. */
#include "types.h"
#include "deps/020365f0_InitializeEverything.h"

void InitializeEverything(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  InitializeSDKModules();
  InitializeBrightnessContexts();
  *(undefined4 *)(iRam0203666c + 4) = uRam02036668;
  uVar1 = Os_GetMemoryRegionStartAddress(0);
  *(undefined4 *)(iRam0203666c + 8) = uVar1;
  MemoryRegionAddressAccess();
  iVar2 = Os_GetMemoryRegionStartAddress(0);
  iVar3 = Os_GetMemoryRegionEndAddress(0);
  uVar1 = Mem_CreateExpHeap(iVar2,iVar3 - iVar2);
  *(undefined4 *)(iRam0203666c + 0xc) = uVar1;
  ExecutionContext_Create(uRam02036670,0);
  *(undefined4 *)(iRam0203666c + 0x10) = uRam02036674;
  InitializeGlobalG_M1();
  return;
}

