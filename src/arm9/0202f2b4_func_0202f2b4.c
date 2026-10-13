/* Decompiled C draft; module arm9; ROM address 0202f2b4. No matching claim. */
#include "types.h"
#include "deps/0202f2b4_func_0202f2b4.h"

void func_0202f2b4(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  
  iVar2 = Mem_AllocateHeapAligned(param_1,DAT_0202f430,0x20);
  *DAT_0202f434 = iVar2;
  CARD_func_0054__mkds_2f51c(iVar2,DAT_0202f430);
  uVar3 = CreateDisplayConfig(param_1,DAT_0202f438);
  DisplayConfig_SetTopEngineBg1Config_0(uVar3,0,0,0,0,0xc,0,0);
  DisplayConfig_SetBottomEngineBg3Config_0(uVar3,2,0,0,0,0xf,6);
  SetGlobalDisplayConfig(uVar3);
  iVar2 = func_0202f19c();
  if (iVar2 == 0) {
    local_38 = 1;
    local_34 = GetLoadedFont_from_thumb();
    local_30 = 0;
    local_2c = 1;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 1;
    iVar2 = GetB488SomeMode();
    local_18 = (uint)(iVar2 == 0);
    local_14 = 0;
    PrepareNavigationContextFiles_from_thumb();
    InitializeNavigationContext_from_thumb(param_1,&local_38);
  }
  CreateGlobalNN_from_thumb(param_1,*DAT_0202f434);
  uVar3 = GetB488SomeMode();
  switch(uVar3) {
  case 0:
    iVar2 = func_0202f19c();
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 4;
    }
    *(undefined4 *)(*DAT_0202f434 + DAT_0202f43c) = uVar3;
    Maybe_banner(param_1);
    func_02053d00();
    break;
  case 1:
    *(undefined4 *)(*DAT_0202f434 + DAT_0202f43c) = 5;
    func_0203b1fc(param_1);
    break;
  case 2:
    *(undefined4 *)(*DAT_0202f434 + DAT_0202f43c) = 6;
    func_0203b1c8(param_1);
    break;
  case 3:
    *(undefined4 *)(*DAT_0202f434 + DAT_0202f43c) = 7;
    func_0203b194(param_1);
  }
  iVar2 = DAT_0202f43c;
  piVar1 = DAT_0202f434;
  *(undefined4 *)(*DAT_0202f434 + DAT_0202f440) = *(undefined4 *)(*DAT_0202f434 + DAT_0202f43c);
  *(undefined4 *)(*piVar1 + DAT_0202f448) =
       *(undefined4 *)(DAT_0202f444 + *(int *)(*piVar1 + iVar2) * 4);
  uVar3 = Mem_CreateChildExpHeap(param_1);
  *(undefined4 *)(*DAT_0202f434 + DAT_0202f44c) = uVar3;
  iVar2 = func_0202f19c();
  if (iVar2 == 0) {
    MaybeVerifyMultiSelectFiles_from_thumb();
  }
  OamBuffer_SomeFn_from_thumb(*DAT_0202f434,*DAT_0202f434 + DAT_0202f450);
  SetSomeDispcntTopMask(0x10);
  SetSomeDispcntSubMask(0x10);
  iVar2 = *DAT_0202f434;
  (*(code *)**(undefined4 **)(iVar2 + DAT_0202f448))
            (*(undefined4 *)(iVar2 + DAT_0202f44c),iVar2,iVar2 + DAT_0202f450);
  return;
}

