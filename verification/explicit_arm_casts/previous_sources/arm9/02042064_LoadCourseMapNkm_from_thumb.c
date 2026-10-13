/* Decompiled C draft; module arm9; ROM address 02042064. No matching claim. */
#include "types.h"
#include "deps/02042064_LoadCourseMapNkm_from_thumb.h"

void LoadCourseMapNkm_from_thumb(undefined4 param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  char acStack_114 [256];
  
  iVar6 = *piRam02042148;
  if (*(int *)(iVar6 + 8) == 4) {
    if (*(int *)(iVar6 + 0xc) == 6) {
      iVar6 = FindFileBuffer_CRS_CST_from_thumb(uRam0204214c);
    }
    else {
      _snprintf(acStack_114,sRam02042150,pcRam02042154,iVar6 + 0x48);
      iVar6 = FindFileBuffer_CRS_CST_from_thumb(acStack_114);
    }
  }
  else if (*(int *)(iVar6 + 8) == 5) {
    iVar6 = FindFileBuffer_CRS_CST_from_thumb(uRam02042158);
    if (iVar6 == 0) {
      iVar6 = FindFileBuffer_CRS_CST_from_thumb(uRam0204215c);
    }
  }
  else {
    iVar6 = FindFileBuffer_CRS_CST_from_thumb(uRam02042160);
  }
  iVar3 = AllocateStructPE_from_thumb(param_1);
  *piRam02042164 = iVar3;
  *(undefined2 *)(iVar3 + iRam02042168) = *(undefined2 *)(iVar6 + 4);
  piVar8 = (int *)(iVar6 + 8);
  uVar2 = *(ushort *)(iVar6 + 6);
  iVar3 = 0;
  puVar7 = puRam0204216c;
  do {
    iVar4 = (*(code *)*puVar7)(iVar6 + (uint)uVar2 + *piVar8);
    if (iVar4 != 0) {
      piVar8 = piVar8 + 1;
    }
    puVar7 = puVar7 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x11);
  PopulatePathEntries_from_thumb(param_1);
  func_020429c8(param_1);
  piVar8 = piRam02042164;
  uVar5 = 0;
  *(undefined2 *)(*piRam02042164 + 0x9c) = 0;
  iVar6 = *piVar8;
  if (*(short *)(iVar6 + 0x50) != 0) {
    do {
      bVar1 = *(byte *)(*(int *)(*piVar8 + 0x4c) + uVar5 * 0xc + 10);
      if (*(ushort *)(*piVar8 + 0x9c) < (ushort)bVar1) {
        *(ushort *)(iVar6 + 0x9c) = (ushort)bVar1;
      }
      uVar5 = uVar5 + 1 & 0xffff;
      iVar6 = *piVar8;
    } while (uVar5 < *(ushort *)(iVar6 + 0x50));
  }
  return;
}

