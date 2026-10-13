/* Decompiled C draft; module arm9; ROM address 02047780. No matching claim. */
#include "types.h"
#include "deps/02047780_AllocateFindFileBuffer_KME_KM1_KM2_KSB_from_thumb.h"

int AllocateFindFileBuffer_KME_KM1_KM2_KSB_from_thumb(char *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_8c [128];
  
  iVar2 = 0;
  iVar1 = GetCurrentSceneId();
  if (((iVar1 == 1) || (iVar1 == 3)) || (iVar1 == 0xc)) {
    if (*param_1 == '/') {
      Util_SNPrintF(auStack_8c,0x80,uRam0204788c,*(undefined4 *)(iRam02047888 + 0x28),param_1);
    }
    else {
      Util_SNPrintF(auStack_8c,0x80,uRam02047890,*(undefined4 *)(iRam02047888 + 0x28),param_1);
    }
    iVar2 = AllocateReadFileBuffer_from_thumb(auStack_8c,8);
  }
  else {
    if (*(int *)(*piRam02047894 + iRam02047898) != 0) {
      if (*param_1 == '/') {
        Util_SNPrintF(auStack_8c,0x80,uRam0204789c,*(undefined4 *)(iRam02047888 + 0x18),param_1);
      }
      else {
        Util_SNPrintF(auStack_8c,0x80,uRam020478a0,*(undefined4 *)(iRam02047888 + 0x18),param_1);
      }
      iVar2 = AllocateReadFileBuffer_from_thumb(auStack_8c,8);
    }
    if ((iVar2 == 0) && (*(int *)(*piRam02047894 + iRam020478a4) != 0)) {
      if (*param_1 == '/') {
        Util_SNPrintF(auStack_8c,0x80,uRam020478a8,*(undefined4 *)(iRam02047888 + 0x1c),param_1);
      }
      else {
        Util_SNPrintF(auStack_8c,0x80,uRam020478ac,*(undefined4 *)(iRam02047888 + 0x1c),param_1);
      }
      iVar2 = AllocateReadFileBuffer_from_thumb(auStack_8c,8);
    }
    if ((iVar2 == 0) && (*(int *)(*piRam02047894 + iRam020478b0) != 0)) {
      if (*param_1 == '/') {
        Util_SNPrintF(auStack_8c,0x80,uRam020478b4,*(undefined4 *)(iRam02047888 + 0x20),param_1);
      }
      else {
        Util_SNPrintF(auStack_8c,0x80,uRam020478b8,*(undefined4 *)(iRam02047888 + 0x20),param_1);
      }
      iVar2 = AllocateReadFileBuffer_from_thumb(auStack_8c,8);
    }
  }
  return iVar2;
}

