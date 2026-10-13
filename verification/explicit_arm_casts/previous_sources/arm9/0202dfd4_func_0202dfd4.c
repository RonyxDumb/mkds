/* Decompiled C draft; module arm9; ROM address 0202dfd4. No matching claim. */
#include "types.h"
#include "deps/0202dfd4_func_0202dfd4.h"

void func_0202dfd4(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar3 = Mem_AllocateHeap(param_1,uRam0202e210);
  *piRam0202e214 = iVar3;
  Mem_CpuFastMemorySet(0,iVar3,uRam0202e210);
  uVar4 = Mem_AllocateHeapAligned(param_1,uRam0202e218,0x20);
  *(undefined4 *)(*piRam0202e214 + iRam0202e21c) = uVar4;
  uVar4 = Mem_AllocateHeapAligned(param_1,uRam0202e220,0x20);
  *(undefined4 *)(*piRam0202e214 + iRam0202e224) = uVar4;
  iVar3 = CreateDisplayConfig(param_1,uRam0202e228);
  DisplayEngineConfig_SetBg0Config(iVar3 + 0x28,1,0,0,0,0,1,0);
  DisplayEngineConfig_SetBg3Config(iVar3 + 0x70,2,0,0,0,0xf,0);
  SetGlobalDisplayConfig(iVar3);
  Maybe_TimeAttack_ghost_get_m_b();
  local_40 = 1;
  local_3c = GetLoadedFont_from_thumb();
  local_38 = 1;
  local_34 = 1;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 1;
  local_20 = 1;
  local_1c = 0;
  PrepareNavigationContextFiles_from_thumb();
  InitializeNavigationContext_from_thumb(param_1,&local_40);
  TextSystem_SetUseDirectInput_from_thumb(1);
  CreateGlobalNN_from_thumb(param_1,*piRam0202e214);
  func_021172a8(param_1);
  iVar3 = iRam0202e22c;
  piVar1 = piRam0202e214;
  iVar6 = 0;
  iVar5 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar5 + iVar3) = 0xffffffff;
    iVar8 = iRam0202e230;
    piVar2 = piRam0202e214;
    iVar5 = iVar5 + 4;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x20);
  iVar3 = 0;
  iVar5 = 0;
  do {
    *(undefined4 *)(*piVar2 + iVar5 + iVar8) = 0xffffffff;
    iVar5 = iVar5 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 10);
  uVar4 = AllocateStructYE(param_1);
  iVar3 = iRam0202e234;
  piVar1 = piRam0202e214;
  *(undefined4 *)(*piRam0202e214 + iRam0202e234) = uVar4;
  SetStructYE_RunATFunction(*(undefined4 *)(*piVar1 + iVar3));
  WaitForWorkerTask();
  iVar3 = iRam0202e238;
  piVar1 = piRam0202e214;
  iVar5 = 0;
  do {
    func_0202e43c(iVar5);
    iVar8 = *(int *)(*piVar1 + iRam0202e234);
    iVar6 = GetCourseIdFromInternalId();
    iVar6 = func_0206174c(iVar8 + iVar6 * 0x30);
    if (iVar6 != 0) {
      *(int *)(*piVar1 + *(int *)(*piVar1 + iVar3) * 4 + iRam0202e22c) = iVar5;
      *(int *)(*piVar1 + iRam0202e23c) = *(int *)(*piVar1 + iRam0202e23c) + 1;
      *(int *)(*piVar1 + iVar3) = *(int *)(*piVar1 + iVar3) + 1;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x20);
  uVar4 = AllocateFX(param_1);
  iVar3 = iRam0202e240;
  piVar1 = piRam0202e214;
  *(undefined4 *)(*piRam0202e214 + iRam0202e240) = uVar4;
  RunSomeATFunction(*(undefined4 *)(*piVar1 + iVar3));
  WaitForWorkerTask();
  iVar5 = iRam0202e244;
  iVar3 = iRam0202e23c;
  piVar1 = piRam0202e214;
  uVar7 = 0;
  do {
    iVar6 = func_0206174c(*(int *)(*piVar1 + iRam0202e240) + iRam0202e248 * (uVar7 & 0xff));
    if (iVar6 != 0) {
      *(uint *)(*piVar1 + *(int *)(*piVar1 + iVar5) * 4 + iRam0202e230) = uVar7;
      *(int *)(*piVar1 + iVar3) = *(int *)(*piVar1 + iVar3) + 1;
      *(int *)(*piVar1 + iVar5) = *(int *)(*piVar1 + iVar5) + 1;
    }
    uVar7 = uVar7 + 1;
  } while ((int)uVar7 < 10);
  OamBuffer_SomeFn_from_thumb(*piRam0202e214,*piRam0202e214 + iRam0202e24c);
  uVar7 = uRam0202e254;
  *puRam0202e250 = *puRam0202e250 & uRam0202e254 | 0x10;
  *puRam0202e258 = *puRam0202e258 & uVar7 | 0x10;
  if (*(int *)(*piRam0202e25c + 0xc) == 0) {
    *(undefined4 *)(*piRam0202e214 + iRam0202e260) = 0;
  }
  else if (*(int *)(*piRam0202e25c + 0xc) == 1) {
    *(undefined4 *)(*piRam0202e214 + iRam0202e260) = 1;
  }
  iVar3 = iRam0202e260;
  piVar1 = piRam0202e214;
  *(undefined4 *)(*piRam0202e214 + iRam0202e264) = *(undefined4 *)(*piRam0202e214 + iRam0202e260);
  *(undefined4 *)(*piVar1 + iRam0202e26c) =
       *(undefined4 *)(iRam0202e268 + *(int *)(*piVar1 + iVar3) * 4);
  uVar4 = Mem_CreateChildExpHeap(param_1);
  iVar3 = iRam0202e270;
  piVar1 = piRam0202e214;
  *(undefined4 *)(*piRam0202e214 + iRam0202e270) = uVar4;
  iVar5 = *piVar1;
  (*(code *)**(undefined4 **)(iVar5 + iRam0202e26c))
            (*(undefined4 *)(iVar5 + iVar3),iVar5,iVar5 + iRam0202e24c);
  return;
}

