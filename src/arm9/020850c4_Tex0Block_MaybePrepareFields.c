/* Decompiled C draft; module arm9; ROM address 020850c4. No matching claim. */
#include "types.h"
#include "deps/020850c4_Tex0Block_MaybePrepareFields.h"

undefined4 Tex0Block_MaybePrepareFields(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  
  uVar4 = 1;
  bVar5 = true;
  bVar6 = true;
  bVar7 = true;
  if ((((*(ushort *)(param_1 + 0x10) & 1) == 0) && ((*(ushort *)(param_1 + 0x20) & 1) == 0)) &&
     ((*(ushort *)(param_1 + 0x32) & 1) == 0)) {
    iVar1 = Tex0Block_GetTextureDataSize();
    iVar2 = Tex0Block_GetCompressedTextureDataSize(param_1);
    iVar3 = Tex0Block_GetPaletteDataSize(param_1);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(code *)(*(uint *)(uRam0208525c & 0xfffffffc) >> (uRam0208525c & 3) * 8 |
                        *(uint *)(uRam0208525c & 0xfffffffc) << (uRam0208525c & 3) * -8 + 0x20))
                        (iVar1,0,0);
      bVar5 = iVar1 != 0;
    }
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(code *)(*(uint *)(uRam0208525c & 0xfffffffc) >> (uRam0208525c & 3) * 8 |
                        *(uint *)(uRam0208525c & 0xfffffffc) << (uRam0208525c & 3) * -8 + 0x20))
                        (iVar2,1,0);
      bVar6 = iVar2 != 0;
    }
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(code *)(*(uint *)(uRam02085260 & 0xfffffffc) >> (uRam02085260 & 3) * 8 |
                        *(uint *)(uRam02085260 & 0xfffffffc) << (uRam02085260 & 3) * -8 + 0x20))
                        (iVar3,*(ushort *)(param_1 + 0x20) & 0x8000,0);
      bVar7 = iVar3 != 0;
    }
    if (((!bVar5) || (!bVar6)) || (!bVar7)) {
      (*(code *)(*(uint *)(uRam02085264 & 0xfffffffc) >> (uRam02085264 & 3) * 8 |
                *(uint *)(uRam02085264 & 0xfffffffc) << (uRam02085264 & 3) * -8 + 0x20))(iVar3);
      (*(code *)(*(uint *)(uRam02085268 & 0xfffffffc) >> (uRam02085268 & 3) * 8 |
                *(uint *)(uRam02085268 & 0xfffffffc) << (uRam02085268 & 3) * -8 + 0x20))(iVar2);
      (*(code *)(*(uint *)(uRam02085268 & 0xfffffffc) >> (uRam02085268 & 3) * 8 |
                *(uint *)(uRam02085268 & 0xfffffffc) << (uRam02085268 & 3) * -8 + 0x20))(iVar1);
      return 0;
    }
    Tex0Block_SetTexturesVramKeys(param_1,iVar1,iVar2);
    Tex0Block_SetPaletteVramKey(param_1,iVar3);
    Tex0Block_MaybeCopyTexturesToMem(param_1,1);
    Tex0Block_MaybeCopyPaletteToMem(param_1,1);
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

