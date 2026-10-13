/* Decompiled C draft; module arm9; ROM address 0212c0e0. No matching claim. */
#include "types.h"
#include "deps/0212c0e0_func_0212c0e0.h"

uint * func_0212c0e0(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  
  iVar5 = param_2 * 0x24 + iRam0212c198;
  if (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 != 0 ||
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 != 0) {
    func_0212c688();
  }
  uVar1 = iVar5 + 0x18U & 3;
  uVar2 = *(uint *)(iVar5 + 0x18U & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) <= (uint)*(ushort *)(iVar5 + 8)) {
    iVar3 = IntrusiveListWrapper_NextItem(iVar5,0);
    if (iVar3 == 0) {
      return (uint *)0x0;
    }
    if (param_3 < (int)(uint)*(byte *)(iVar3 + 0x3d)) {
      return (uint *)0x0;
    }
    func_0212be78(iVar3);
  }
  puVar4 = (uint *)func_0212bdfc(param_3);
  if (puVar4 != (uint *)0x0) {
    func_0212bf14(iVar5,puVar4);
    *puVar4 = (uint)param_1;
    *param_1 = puVar4;
    return puVar4;
  }
  return (uint *)0x0;
}

