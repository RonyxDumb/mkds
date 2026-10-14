/* Decompiled C draft; module arm9; ROM address 0208526c. No matching claim. */
#include "types.h"
#include "deps/0208526c_LoadedModelTexture_SomeFn.h"

void LoadedModelTexture_SomeFn(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = Nsbmd_GetMDL0Block(param_2);
  iVar3 = Nsbtx_GetTEX0Block(param_3);
  *(undefined4 *)(param_1 + 0xc) = 0;
  uVar1 = uRam02085334;
  *(undefined4 *)(param_1 + 8) = 0;
  IntrusiveListWrapper_InsertLast(uVar1,param_1);
  *(undefined4 *)(param_1 + 8) = param_2;
  if (iVar3 == 0) {
    return;
  }
  *(ushort *)(iVar3 + 0x10) = *(ushort *)(iVar3 + 0x10) & 0xfffe;
  *(ushort *)(iVar3 + 0x20) = *(ushort *)(iVar3 + 0x20) & 0xfffe;
  *(undefined4 *)(iVar3 + 8) = 0;
  *(undefined4 *)(iVar3 + 0x18) = 0;
  *(ushort *)(iVar3 + 0x32) = *(ushort *)(iVar3 + 0x32) & 0xfffe;
  *(undefined4 *)(iVar3 + 0x2c) = 0;
  Tex0Block_MaybePrepareFields(iVar3);
  *(int *)(param_1 + 0xc) = iVar3;
  if ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) == uRam02085338) {
    func_02010168(uVar2,iVar3);
    return;
  }
  return;
}

