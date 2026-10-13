/* Decompiled C draft; module arm9; ROM address 02048050. No matching claim. */
#include "types.h"
#include "deps/02048050_Arc_MountArchive_from_thumb.h"

void Arc_MountArchive_from_thumb(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char local_94 [128];
  
  pcVar4 = local_94;
  iVar3 = 0x80;
  do {
    *pcVar4 = '\0';
    pcVar4 = pcVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar6 = 0;
  iVar3 = *DAT_02048240;
  if (*(int *)(iVar3 + param_1 * 0x70 + 0x68) == 0) {
    iVar5 = param_1 * 0x18;
    uVar1 = *(undefined4 *)(DAT_02048244 + iVar5);
    uVar2 = *(undefined4 *)(DAT_02048248 + iVar5);
    uVar7 = *(undefined4 *)(DAT_0204824c + iVar5);
    if (*(char *)(DAT_02048250 + iVar5) != -1) {
      uVar6 = *(undefined4 *)(iVar3 + *(char *)(DAT_02048250 + iVar5) * 0xc + DAT_02048254);
    }
    switch(param_1) {
    case 0:
    case 1:
    case 6:
    case 7:
    case 8:
    case 10:
    case 0xe:
    case 0x10:
    case 0x12:
      SomeStrncpy_0(local_94,*(undefined4 *)(DAT_0204827c + param_1 * 0x18),0x80);
      break;
    case 2:
    case 0xf:
    case 0x11:
      FormatArchiveWithLanguage_from_thumb(*(undefined4 *)(DAT_0204827c + iVar5),local_94);
      break;
    case 3:
    case 0xd:
      FormatCourseCarc_from_thumb(local_94,*(undefined4 *)*DAT_02048258,param_1 != 3);
      break;
    case 5:
      if (param_2 == 1) {
        uVar6 = *(undefined4 *)(iVar3 + DAT_02048254);
      }
      else if (param_2 == 2) {
        uVar6 = *(undefined4 *)(iVar3 + DAT_0204825c);
      }
      else if (param_2 == 10) {
        uVar6 = *(undefined4 *)(iVar3 + DAT_02048260);
      }
      if (param_2 == 2) {
        if (*(int *)(*DAT_02048258 + 0xc) == 6) {
          Util_SNPrintF(local_94,0x80,DAT_02048264);
        }
        else {
          FormatSceneArchive_from_thumb(local_94,*(undefined4 *)(DAT_02048268 + 0x10));
        }
      }
      else if (param_2 == 10) {
        FormatResultCarc_from_thumb(local_94);
      }
      else {
        FormatSceneArchive_from_thumb(local_94,*(undefined4 *)(DAT_02048268 + param_2 * 8));
      }
      uVar7 = *(undefined4 *)(DAT_0204826c + param_2 * 8);
      break;
    case 9:
      if (param_2 == 1) {
        uVar6 = *(undefined4 *)(iVar3 + DAT_02048274);
      }
      else if (param_2 == 2) {
        uVar6 = *(undefined4 *)(iVar3 + DAT_02048270);
      }
      else if (param_2 == 10) {
        uVar6 = *(undefined4 *)(iVar3 + DAT_02048278);
      }
      if (param_2 == 2) {
        if (*(int *)(*DAT_02048258 + 0xc) == 6) {
          FormatStaffRollCarcWithLanguage_from_thumb(local_94);
        }
        else {
          FormatCarcWithLanguage2_from_thumb(local_94,*(undefined4 *)(DAT_02048268 + 0x10));
        }
      }
      else if (param_2 == 10) {
        FormatResultCarcWithLanguage_from_thumb(local_94);
      }
      else {
        FormatCarcWithLanguage2_from_thumb(local_94,*(undefined4 *)(DAT_02048268 + param_2 * 8));
      }
      break;
    case 0xb:
      FormatSceneArchiveWithRaceMode_from_thumb
                (local_94,*(undefined4 *)(DAT_02048268 + param_2 * 8),
                 *(undefined4 *)(*DAT_02048258 + 8));
      break;
    case 0xc:
      FormatRaceCarcWithLanguage_from_thumb
                (local_94,*(undefined4 *)(DAT_02048268 + param_2 * 8),
                 *(undefined4 *)(*DAT_02048258 + 8));
    }
    if (local_94[0] != '\0') {
      MountArchiveEntryImpl_from_thumb(param_1,local_94,uVar6,0,uVar2,uVar1,uVar7);
    }
    iVar3 = *(int *)(DAT_02048280 + param_1 * 0x18);
    if (iVar3 != -1) {
      Arc_MountArchive_from_thumb(iVar3,param_2);
    }
  }
  return;
}

