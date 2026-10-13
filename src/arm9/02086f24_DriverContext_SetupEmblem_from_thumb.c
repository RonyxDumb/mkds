/* Decompiled C draft; module arm9; ROM address 02086f24. No matching claim. */
#include "types.h"
#include "deps/02086f24_DriverContext_SetupEmblem_from_thumb.h"

void DriverContext_SetupEmblem_from_thumb(undefined2 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = GetCharacterKartModel(param_1);
  iVar3 = Dict_SomeFn_0(iVar2 + *(int *)(iVar2 + 8) + 4,uRam02086fa0);
  iVar2 = iVar2 + *(int *)(iVar2 + 8);
  iVar2 = iVar2 + *(int *)(iVar2 + 4 + (uint)*(ushort *)(iVar2 + 10) +
                           iVar3 * (uint)*(ushort *)(iVar2 + 4 + (uint)*(ushort *)(iVar2 + 10)) + 4)
  ;
  uVar4 = *(uint *)(iVar2 + 0x14) & uRam02086fa4;
  uVar1 = *(ushort *)(iVar2 + 0x1c);
  Arm_FlushRange(param_2,uRam02086fa8);
  Arm_FlushRange(param_3,0x20);
  func_0214c6a8();
  func_0214c544(param_2,uVar4 * 8,uRam02086fa8);
  func_0214c4d4();
  func_0214c48c();
  SomeDmaCopy_0(param_3,(uint)uVar1 * 0x10,0x20);
  func_0214c3c0();
  return;
}

