/* Decompiled C draft; module arm9; ROM address 02036108. No matching claim. */
#include "types.h"
#include "deps/02036108_func_02036108.h"

void func_02036108(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  func_02036438();
  *(undefined4 *)(*piRam02036238 + iRam0203623c) = 9;
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02036240);
  *(undefined4 *)(*piRam02036238 + iRam02036244) = uVar2;
  uVar2 = GetLoadedFont_from_thumb(0);
  *(undefined4 *)*piRam02036238 = uVar2;
  iVar3 = GetVramBg1BaseOffset_Bottom();
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02036238 + iRam02036244),0x79);
  G2d_Sprite_CreateFromTiles(*piRam02036238 + 4,iVar3 + iRam02036248,0x20,4,4);
  puVar4 = (undefined4 *)*piRam02036238;
  func_020362c4(puVar4 + 9,puVar4 + 1,*puVar4,1,4);
  func_0203629c(*piRam02036238 + 0x24,8,0,3,uRam0203624c,uVar2);
  piVar1 = piRam02036238;
  iVar3 = 0x16;
  do {
    iVar5 = 0;
    do {
      *(ushort *)(*piVar1 + (iVar5 + iVar3 * 0x20) * 2 + 0x34) =
           (ushort)((iVar5 + iVar3 + 1U & 1) << 0xc) | 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x20);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x18);
  DC_SomeClean(*piVar1 + 0x34,uRam02036250);
  TEQSub_Fn27Impl_Fn29Impl(*piRam02036238 + 0x34,0,uRam02036250);
  CARD_func_0054__mkds_36264(*piRam02036238 + 0x34,uRam02036250);
  piVar1 = piRam02036238;
  iVar3 = 0x14;
  do {
    iVar5 = 0;
    do {
      *(short *)(*piVar1 + (iVar5 + iVar3 * 0x20) * 2 + 0x34) =
           (short)iVar5 + ((short)iVar3 + -0x14) * 0x20 + 0x20;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x20);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x16);
  DC_SomeClean(*piVar1 + 0x34,uRam02036250);
  TEQSub_Fn25Impl(*piRam02036238 + 0x34,0,uRam02036250);
  iVar3 = func_02035e44();
  if (iVar3 != 0) {
    func_02036258();
  }
  func_02036820(*(undefined4 *)(*piRam02036238 + iRam02036254));
  return;
}

