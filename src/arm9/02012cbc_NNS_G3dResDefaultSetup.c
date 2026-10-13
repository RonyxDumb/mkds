/* Decompiled C draft; module arm9; ROM address 02012cbc. No matching claim. */
#include "types.h"
#include "deps/02012cbc_NNS_G3dResDefaultSetup.h"

undefined4 NNS_G3dResDefaultSetup(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  uVar6 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar6 <= uRam02012ef8) {
    if (uVar6 < uRam02012ef8) {
      if (uRam02012efc < uVar6) {
        if (uVar6 != uRam02012f04) {
          return 0;
        }
      }
      else if ((uVar6 < uRam02012efc) && (uVar6 != uRam02012f00)) {
        return 0;
      }
    }
    return 1;
  }
  if (uRam02012f08 < uVar6) {
    if (uVar6 != uRam02012f10) {
      return 0;
    }
  }
  else {
    if (uRam02012f08 <= uVar6) {
      return 1;
    }
    if (uVar6 != uRam02012f0c) {
      return 0;
    }
  }
  bVar7 = true;
  bVar8 = true;
  bVar9 = true;
  iVar1 = Nsbtx_GetTEX0Block(param_1);
  if (iVar1 != 0) {
    iVar2 = Tex0Block_GetTextureDataSize();
    iVar3 = Tex0Block_GetCompressedTextureDataSize(iVar1);
    iVar4 = Tex0Block_GetPaletteDataSize(iVar1);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(code *)(*(uint *)(uRam02012f14 & 0xfffffffc) >> (uRam02012f14 & 3) * 8 |
                        *(uint *)(uRam02012f14 & 0xfffffffc) << (uRam02012f14 & 3) * -8 + 0x20))
                        (iVar2,0,0);
      bVar7 = iVar2 != 0;
    }
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(code *)(*(uint *)(uRam02012f14 & 0xfffffffc) >> (uRam02012f14 & 3) * 8 |
                        *(uint *)(uRam02012f14 & 0xfffffffc) << (uRam02012f14 & 3) * -8 + 0x20))
                        (iVar3,1,0);
      bVar8 = iVar3 != 0;
    }
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (*(code *)(*(uint *)(uRam02012f18 & 0xfffffffc) >> (uRam02012f18 & 3) * 8 |
                        *(uint *)(uRam02012f18 & 0xfffffffc) << (uRam02012f18 & 3) * -8 + 0x20))
                        (iVar4,*(ushort *)(iVar1 + 0x20) & 0x8000,0);
      bVar9 = iVar4 != 0;
    }
    if (((!bVar7) || (!bVar8)) || (!bVar9)) {
      (*(code *)(*(uint *)(uRam02012f1c & 0xfffffffc) >> (uRam02012f1c & 3) * 8 |
                *(uint *)(uRam02012f1c & 0xfffffffc) << (uRam02012f1c & 3) * -8 + 0x20))(iVar4);
      (*(code *)(*(uint *)(uRam02012f20 & 0xfffffffc) >> (uRam02012f20 & 3) * 8 |
                *(uint *)(uRam02012f20 & 0xfffffffc) << (uRam02012f20 & 3) * -8 + 0x20))(iVar3);
      (*(code *)(*(uint *)(uRam02012f20 & 0xfffffffc) >> (uRam02012f20 & 3) * 8 |
                *(uint *)(uRam02012f20 & 0xfffffffc) << (uRam02012f20 & 3) * -8 + 0x20))(iVar2);
      return 0;
    }
    Tex0Block_SetTexturesVramKeys(iVar1,iVar2,iVar3);
    Tex0Block_SetPaletteVramKey(iVar1,iVar4);
    Tex0Block_MaybeCopyTexturesToMem(iVar1,1);
    Tex0Block_MaybeCopyPaletteToMem(iVar1,1);
  }
  if (((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == uRam02012f0c) &&
     (uVar5 = Nsbmd_GetMDL0Block(param_1), iVar1 != 0)) {
    func_02010168(uVar5,iVar1);
  }
  return 1;
}

