/* Decompiled C draft; module arm9; ROM address 02084c54. No matching claim. */
#include "types.h"
#include "deps/02084c54_Model_CreateFromNsbmdWithoutCullReverse.h"

uint Model_CreateFromNsbmdWithoutCullReverse(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = Nsbmd_GetMDL0Block(param_2);
  iVar3 = Nsbtx_GetTEX0Block(param_2);
  *(undefined4 *)(param_1 + 0x68) = 0;
  uVar1 = uRam02084d34;
  *(undefined4 *)(param_1 + 100) = 0;
  IntrusiveListWrapper_InsertLast(uVar1,param_1 + 0x5c);
  *(undefined4 *)(param_1 + 100) = param_2;
  if (iVar3 != 0) {
    *(ushort *)(iVar3 + 0x10) = *(ushort *)(iVar3 + 0x10) & 0xfffe;
    *(ushort *)(iVar3 + 0x20) = *(ushort *)(iVar3 + 0x20) & 0xfffe;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0x18) = 0;
    *(ushort *)(iVar3 + 0x32) = *(ushort *)(iVar3 + 0x32) & 0xfffe;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    Tex0Block_MaybePrepareFields(iVar3);
    *(int *)(param_1 + 0x68) = iVar3;
    if ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) == uRam02084d38) {
      func_02010168(uVar2,iVar3);
    }
  }
  iVar3 = Nsbmd_GetMDL0Block(param_2);
  uVar2 = iVar3 + (uint)*(ushort *)(iVar3 + 0xe) + 0xc;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  StructML_MaybeInnerLoadModel(param_1,iVar3 + (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20),0);
  uVar2 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  return uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
}

