/* Decompiled C draft; module arm9; ROM address 020366bc. No matching claim. */
#include "types.h"
#include "deps/020366bc_InitializeSDKModules.h"

void InitializeSDKModules(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  Os_DisableMainExRegion();
  Os_Initialize();
  *puRam02036760 = 0;
  Os_InitializeTick();
  Os_InitializeAlarm();
  FX_Initialize();
  Gfx_Initialize();
  SomeVramInit();
  MaybePrepareVram();
  SomeDispcntInit();
  uVar2 = uRam02036768;
  *puRam02036764 =
       (*(uint *)((uint)puRam02036764 & 0xfffffffc) >> ((uint)puRam02036764 & 3) * 8 |
       *(uint *)((uint)puRam02036764 & 0xfffffffc) << ((uint)puRam02036764 & 3) * -8 + 0x20) &
       0xfffeffff;
  Os_SetIrqHandler(1,uVar2);
  Os_EnableIrqHandler(1);
  uVar1 = *puRam0203676c;
  *puRam0203676c = 1;
  Os_EnableIrq(1,uVar1);
  GX_VBlankIntr(1);
  Fs_Initialize(0xffffffff);
  InitializeGlobalHN();
  uVar2 = MaybeInitializeDwc_from_thumb(uRam02036770);
  *puRam02036774 = uVar2;
  SomeVramConfig();
  return;
}

