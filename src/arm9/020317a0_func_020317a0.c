/* Decompiled C draft; module arm9; ROM address 020317a0. No matching claim. */
#include "types.h"
#include "deps/020317a0_func_020317a0.h"

void func_020317a0(void)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar1 = DAT_02031944;
  iVar2 = *DAT_02031944;
  switch(*(undefined4 *)(iVar2 + 0x70)) {
  case 2:
    if (*(int *)(iVar2 + 0x7c) != 0) {
      *(undefined4 *)(iVar2 + 0x7c) = 0;
      *(undefined4 *)(*piVar1 + 0x70) = 7;
      return;
    }
    puVar3 = (uint *)func_0202f14c();
    iVar2 = func_02055730(*puVar3 & 0xffff);
    if (iVar2 != 1) {
      if (iVar2 != 2) {
        return;
      }
      func_02032028();
      return;
    }
    if (*(int *)(*DAT_02031948 + 0x20) == 2) {
      StructP_SetAFlag4_SkipBattleIntro((*(ushort *)(*DAT_0203194c + DAT_02031950) & 0x40) != 0);
    }
    piVar1 = DAT_02031944;
    *(undefined4 *)(*DAT_02031944 + 0x70) = 4;
    if (*(int *)(*piVar1 + 0x84) == 0) {
      uVar4 = func_02032000();
      *(undefined4 *)(*DAT_02031944 + 0x74) = uVar4;
      func_02031f5c();
      *(undefined4 *)(*DAT_02031944 + 0x88) = 1;
      return;
    }
    break;
  case 4:
    if (*(int *)(iVar2 + 0x7c) != 0) {
      *(undefined4 *)(iVar2 + 0x7c) = 0;
      *(undefined4 *)(*piVar1 + 0x70) = 7;
      return;
    }
    iVar2 = func_02058cac();
    if (iVar2 != 1) {
      if (iVar2 != 2) {
        return;
      }
      func_02032028();
      return;
    }
    if ((*(int *)(*DAT_02031944 + 0x84) == 0) && (*(int *)(*DAT_02031944 + 0x8c) == 0)) {
      func_02031e80();
      func_02031b6c();
    }
    if (*(int *)(*DAT_02031944 + 0x9c) == 0) {
      Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_02031944 + 0x68),0x81);
      TextSystem_DisplayProgressDialog_Simple_from_thumb();
      func_02108d80();
      func_0205e5c4(1);
      piVar1 = DAT_02031944;
      *(undefined4 *)(*DAT_02031944 + DAT_02031954) = 0;
      *(undefined4 *)(*piVar1 + 0x9c) = 0x78;
      *(undefined4 *)(*piVar1 + 0x70) = 6;
      return;
    }
    break;
  case 6:
    if (*(char *)(*DAT_02031958 + 0x28) == '\0') {
      if (*(int *)(*DAT_0203195c + 0xc) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(*DAT_0203195c + 0x10);
      }
    }
    else {
      iVar5 = 1;
    }
    if ((iVar5 == 0) && (*(int *)(iVar2 + 0x9c) == 0)) {
      *(undefined4 *)(iVar2 + 0x70) = 0xb;
    }
    break;
  case 7:
  case 8:
    iVar2 = func_02054f58();
    if (iVar2 == 1) {
      *(undefined4 *)(*DAT_02031944 + 0x70) = 0xb;
      return;
    }
  }
  return;
}

