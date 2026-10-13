/* Decompiled C draft; module arm9; ROM address 020362dc. No matching claim. */
#include "types.h"
#include "deps/020362dc_func_020362dc.h"

void func_020362dc(void)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  func_02036438();
  *(undefined4 *)(*piRam0203641c + iRam02036420) = 0;
  StructP_SetAFlag4_SkipBattleIntro(1);
  iVar3 = GetGlobal2DObject();
  *(undefined4 *)(*piRam0203641c + iRam02036424) = *(undefined4 *)(iVar3 + 0x20);
  iVar3 = GetGlobal2DObject();
  *(int *)*piRam0203641c = iVar3 + 0x14;
  iVar3 = GetVramBg1BaseOffset_Bottom();
  uVar4 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0203641c + iRam02036424),1);
  G2d_Sprite_CreateFromTiles(*piRam0203641c + 4,iVar3 + iRam02036428,0x20,4,4);
  puVar5 = (undefined4 *)*piRam0203641c;
  func_020362c4(puVar5 + 9,puVar5 + 1,*puVar5,1,4);
  func_0203629c(*piRam0203641c + 0x24,0x80,0,3,uRam0203642c,uVar4);
  piVar2 = piRam0203641c;
  iVar3 = 7;
  do {
    iVar6 = 0;
    do {
      uVar1 = (ushort)((iVar6 + iVar3 + 1U & 1) << 0xc) | 1;
      *(ushort *)(*piVar2 + (iVar6 + iVar3 * 0x20) * 2 + 0x34) = uVar1;
      *(ushort *)(*piVar2 + (iVar6 + (iVar3 + 7) * 0x20) * 2 + 0x34) = uVar1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x20);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  DC_SomeClean(*piVar2 + 0x34,uRam02036430);
  TEQSub_Fn27Impl_Fn29Impl(*piRam0203641c + 0x34,0,uRam02036430);
  CARD_func_0054__mkds_36264(*piRam0203641c + 0x34,uRam02036430);
  piVar2 = piRam0203641c;
  iVar3 = 10;
  do {
    iVar6 = 0;
    do {
      *(short *)(*piVar2 + (iVar6 + iVar3 * 0x20) * 2 + 0x34) =
           (short)iVar6 + ((short)iVar3 + -10) * 0x20 + 0x20;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x20);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xe);
  DC_SomeClean(*piVar2 + 0x34,uRam02036430);
  TEQSub_Fn25Impl(*piRam0203641c + 0x34,0,uRam02036430);
  func_02036258();
  func_02036820(*(undefined4 *)(*piRam0203641c + iRam02036434));
  return;
}

