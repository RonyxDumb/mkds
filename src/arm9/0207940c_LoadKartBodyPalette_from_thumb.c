/* Decompiled C draft; module arm9; ROM address 0207940c. No matching claim. */
#include "types.h"
#include "deps/0207940c_LoadKartBodyPalette_from_thumb.h"

void LoadKartBodyPalette_from_thumb(int param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int extraout_r1;
  int iVar3;
  
  _s32_div_f(param_2,3);
  if (extraout_r1 == 0) {
    iVar3 = *(int *)(param_1 + 4);
    iVar2 = _s32_div_f(param_2,3);
    param_3 = param_3 + iVar2 * 0x20;
    Arm_FlushRange(param_3,0x10);
    iVar2 = Dict_SomeFn_0(iVar3 + *(int *)(iVar3 + 8) + 4,uRam02079474);
    iVar3 = iVar3 + *(int *)(iVar3 + 8);
    uVar1 = *(ushort *)
             (iVar3 + *(int *)(iVar3 + 4 + (uint)*(ushort *)(iVar3 + 10) +
                               iVar2 * (uint)*(ushort *)(iVar3 + 4 + (uint)*(ushort *)(iVar3 + 10))
                              + 4) + 0x1c);
    func_0214c48c();
    SomeDmaCopy_0(param_3,(uint)uVar1 * 0x10,0x10);
    func_0214c3c0();
  }
  return;
}

