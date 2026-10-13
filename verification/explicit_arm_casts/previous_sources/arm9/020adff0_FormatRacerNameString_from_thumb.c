/* Decompiled C draft; module arm9; ROM address 020adff0. No matching claim. */
#include "types.h"
#include "deps/020adff0_FormatRacerNameString_from_thumb.h"

void FormatRacerNameString_from_thumb(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [22];
  undefined1 auStack_26 [22];
  
  uVar3 = 0;
  do {
    *(undefined2 *)(param_2 + uVar3 * 2) = 0;
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 0xb);
  iVar1 = IsRacerPlayerOrGhostOrNet(param_1);
  if (iVar1 == 0) {
    iVar1 = GetCurrentRaceMode_0();
    if ((iVar1 == 0) || (iVar1 = GetCurrentRaceMode_0(), iVar1 == 4)) {
      uVar4 = GetRacerCharacterId_0(param_1);
      puVar2 = (undefined1 *)GetCharacterNameString_from_thumb(uVar4,param_3);
      uVar4 = 0x14;
    }
    else {
      uVar4 = func_020b47cc(uRam020ae0a4);
      uVar4 = Bmg_GetRawStringPointer_from_thumb(uVar4,0x72);
      CopyString16(auStack_3c,uVar4,9);
      uVar4 = GetRacerCpuIndex(param_1);
      ParticularSnprintf16(auStack_40,2,uRam020ae0a8,uVar4);
      SomeStrcat16(auStack_3c,auStack_40,1);
      puVar2 = auStack_3c;
      uVar4 = 10;
    }
  }
  else {
    puVar2 = (undefined1 *)GetRacerName(param_1);
    if (puVar2 == (undefined1 *)0x0) {
      return;
    }
    if (param_3 == 0) {
      uVar4 = GetClampedString10LengthForFontIndex0_from_thumb(puVar2,auStack_26);
    }
    else {
      uVar4 = 10;
    }
  }
  if (puVar2 != (undefined1 *)0x0) {
    CopyString16(param_2,puVar2,uVar4);
  }
  return;
}

