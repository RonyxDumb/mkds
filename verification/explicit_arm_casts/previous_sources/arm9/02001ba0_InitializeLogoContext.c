/* Decompiled C draft; module arm9; ROM address 02001ba0. No matching claim. */
#include "types.h"
#include "deps/02001ba0_InitializeLogoContext.h"

void InitializeLogoContext(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar2 = Mem_AllocateHeap(param_1,0x3c);
  uVar4 = uRam02001d0c;
  *puRam02001d08 = uVar2;
  iVar3 = CreateDisplayConfig(param_1,uVar4);
  DisplayEngineConfig_SetBg1Config(iVar3 + 0x28,1,0,0,0,0,1,0);
  DisplayEngineConfig_SetBg1Config(iVar3 + 0x70,1,0,0,0,0,2,0);
  SetGlobalDisplayConfig(iVar3);
  LoadLogoScreenGraphics
            (*(uint *)((uint)puRam02001d08 & 0xfffffffc) >> ((uint)puRam02001d08 & 3) * 8 |
             *(uint *)((uint)puRam02001d08 & 0xfffffffc) << ((uint)puRam02001d08 & 3) * -8 + 0x20,1,
             uRam02001d14,uRam02001d18,uRam02001d10);
  LoadLogoScreenGraphics
            ((*(uint *)((uint)puRam02001d08 & 0xfffffffc) >> ((uint)puRam02001d08 & 3) * 8 |
             *(uint *)((uint)puRam02001d08 & 0xfffffffc) << ((uint)puRam02001d08 & 3) * -8 + 0x20) +
             0xc,0,uRam02001d20,uRam02001d24,uRam02001d1c);
  StateDualHandler_Create
            ((*(uint *)((uint)puRam02001d08 & 0xfffffffc) >> ((uint)puRam02001d08 & 3) * 8 |
             *(uint *)((uint)puRam02001d08 & 0xfffffffc) << ((uint)puRam02001d08 & 3) * -8 + 0x20) +
             0x18,uRam02001d28,0xc,0);
  uVar4 = uRam02001d2c;
  puVar1 = puRam02001d08;
  uVar7 = *(uint *)((uint)puRam02001d08 & 0xfffffffc) >> ((uint)puRam02001d08 & 3) * 8 |
          *(uint *)((uint)puRam02001d08 & 0xfffffffc) << ((uint)puRam02001d08 & 3) * -8 + 0x20;
  uVar6 = uVar7 + 0x2c;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(uint *)(uVar7 + 0x2c) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 0xfffffffe;
  uVar6 = (uint)puVar1 & 3;
  uVar5 = *(uint *)((uint)puVar1 & 0xfffffffc);
  *(undefined4 *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x30) = 0;
  uVar4 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uVar4);
  *(undefined4 *)
   ((*(uint *)((uint)puRam02001d08 & 0xfffffffc) >> ((uint)puRam02001d08 & 3) * 8 |
    *(uint *)((uint)puRam02001d08 & 0xfffffffc) << ((uint)puRam02001d08 & 3) * -8 + 0x20) + 0x38) =
       uVar4;
  local_38 = 1;
  local_34 = GetLoadedFont_from_thumb();
  local_30 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_2c = 1;
  PrepareNavigationContextFiles_from_thumb();
  InitializeNavigationContext_from_thumb(param_1,&local_38);
  return;
}

