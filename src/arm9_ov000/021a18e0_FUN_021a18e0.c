/* Decompiled C draft; module arm9_ov000; ROM address 021a18e0. No matching claim. */
#include "types.h"
#include "deps/021a18e0_FUN_021a18e0.h"

void FUN_021a18e0(uint param_1,int param_2,ushort *param_3)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  
  piVar2 = DAT_021a19f4;
  if (param_2 == 2) {
    if (*(int *)(*DAT_021a19f4 + DAT_021a19f8) == 1) {
      if ((char)*param_3 == '\x01') {
        *(undefined4 *)(*DAT_021a19f4 + DAT_021a19fc) = 0;
      }
      piVar2 = DAT_021a19f4;
      bVar1 = *(byte *)((int)param_3 + 1);
      *(char *)(*DAT_021a19f4 + (uint)bVar1 + DAT_021a1a00) = (char)param_3[1];
      iVar6 = *piVar2;
      *(undefined4 *)(iVar6 + (uint)bVar1 * 4 + 0xf4) = *(undefined4 *)(iVar6 + DAT_021a1a04);
      iVar6 = *piVar2;
      if ((*(char *)(iVar6 + 0x15) == '\0') || (*(char *)(iVar6 + 0x15) == '\x01')) {
        *(undefined1 *)(*DAT_021a19f4 + 0x16) = *(undefined1 *)(*DAT_021a19f4 + 0xd);
      }
      *(undefined4 *)(*DAT_021a19f4 + DAT_021a19f8) = 9;
    }
    FUN_0219ef68(param_1,3);
    return;
  }
  if (param_2 == 3) {
    if (*(int *)(*DAT_021a19f4 + DAT_021a19f8) != 0x10) {
      FUN_0219ef68(param_1,4);
      return;
    }
    puVar5 = (uint *)(*DAT_021a19f4 + DAT_021a1a08);
    *puVar5 = *puVar5 | 1 << (param_1 & 0xff);
    if (*(ushort *)(*piVar2 + DAT_021a1a0c) < *param_3) {
      *(ushort *)(*piVar2 + DAT_021a1a0c) = *param_3;
    }
    iVar3 = FUN_0219e8fc(0);
    iVar6 = DAT_021a1a00;
    piVar2 = DAT_021a19f4;
    iVar4 = *DAT_021a19f4;
    if (*(int *)(iVar4 + DAT_021a1a08) == iVar3) {
      iVar3 = 1;
      if (*(char *)(iVar4 + 0xd) != '\0') {
        do {
          FUN_0219ef68(*(undefined1 *)(iVar4 + iVar3 + iVar6),4);
          iVar3 = iVar3 + 1;
          iVar4 = *piVar2;
        } while (iVar3 <= (int)(uint)*(byte *)(iVar4 + 0xd));
      }
      *(undefined4 *)(iVar4 + DAT_021a19f8) = 0x11;
      return;
    }
  }
  else {
    if (param_2 != 4) {
      return;
    }
    if (*(int *)(*DAT_021a19f4 + DAT_021a19f8) == 9) {
      FUN_0219f544(4);
    }
  }
  return;
}

