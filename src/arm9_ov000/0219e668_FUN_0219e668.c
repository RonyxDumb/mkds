/* Decompiled C draft; module arm9_ov000; ROM address 0219e668. No matching claim. */
#include "types.h"
#include "deps/0219e668_FUN_0219e668.h"

int * FUN_0219e668(void)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  longlong lVar14;
  undefined8 uVar15;
  
  pcVar10 = (char *)*DAT_0219e89c;
  if (pcVar10 == (char *)0x0) {
    return DAT_0219e89c;
  }
  if (*pcVar10 == '\0') {
    return (int *)0x0;
  }
  iVar5 = *DAT_0219e8a0;
  if (*(char *)(iVar5 + 0x15) == '\x02') {
    return (int *)0x2;
  }
  if (*(char *)(iVar5 + 0x15) == '\x03') {
    return (int *)0x3;
  }
  if (*(int *)(iVar5 + DAT_0219e8a4) == 0x13) {
    iVar5 = FUN_0219e8fc(0);
    piVar2 = DAT_0219e8a0;
    iVar11 = *DAT_0219e89c;
    if (*(int *)(iVar11 + 8) == iVar5) {
      if (*(int *)(iVar11 + 0xc) == iVar5) {
        *(undefined1 *)(*DAT_0219e8a0 + 0x16) = *(undefined1 *)(*DAT_0219e8a0 + 0xd);
        *(char *)(*piVar2 + DAT_0219e8a8) = *(char *)(*piVar2 + 0xd) + -1;
        piVar2 = (int *)FUN_0219f544(0);
        return piVar2;
      }
      uVar15 = FUN_021a350c();
      *(undefined8 *)(iVar11 + 0x18) = uVar15;
      *(undefined4 *)(iVar11 + 8) = 0;
      piVar2 = DAT_0219e8a0;
      iVar5 = *DAT_0219e8a0;
      if (*(char *)(iVar5 + 0x15) == '\0') {
        *(undefined4 *)(iVar5 + DAT_0219e8a4) = 3;
        *(undefined4 *)(*piVar2 + 0xe8) = 2;
        uVar15 = func_0x0200f5ac();
        *(undefined8 *)(*DAT_0219e8a0 + 0xec) = uVar15;
        return (int *)uVar15;
      }
      *(undefined4 *)(iVar5 + DAT_0219e8a4) = 4;
      piVar2 = (int *)FUN_0219fbec(1);
      return piVar2;
    }
    bVar1 = *(byte *)(iVar11 + 2);
    lVar14 = FUN_021a350c();
    lVar14 = lVar14 - *(longlong *)(iVar11 + 0x18);
    uVar9 = (uint)lVar14;
    uVar6 = (uint)((ulonglong)lVar14 >> 0x20);
    uVar3 = DAT_0219e8ac * (uint)bVar1;
    uVar7 = (int)uVar3 >> 0x1f;
    if (uVar6 <= uVar7 && (uint)(uVar3 <= uVar9) <= uVar6 - uVar7) {
      return (int *)(uVar9 - uVar3);
    }
    if (bVar1 < 6) {
      iVar11 = 1;
      iVar5 = *DAT_0219e8a0;
      if (*(char *)(iVar5 + 0xd) != '\0') {
        iVar12 = 2;
        iVar8 = 4;
        do {
          if ((*(uint *)(*DAT_0219e89c + 8) & 1 << *(sbyte *)(iVar5 + iVar11 + DAT_0219e8b0)) == 0)
          {
            iVar5 = *DAT_0219e8a0 + iVar8;
            FUN_021a0ae8(0x11,*(undefined4 *)(iVar5 + 0xf4),*(undefined4 *)(iVar5 + 0x24),
                         *(undefined2 *)(*DAT_0219e8a0 + iVar12 + 0xa4),0,0);
            piVar2 = (int *)FUN_0219fee4();
            if (piVar2 != (int *)0x0) {
              return piVar2;
            }
          }
          iVar12 = iVar12 + 2;
          iVar8 = iVar8 + 4;
          iVar11 = iVar11 + 1;
          iVar5 = *DAT_0219e8a0;
        } while (iVar11 <= (int)(uint)*(byte *)(iVar5 + 0xd));
      }
      piVar2 = (int *)(*(byte *)(*DAT_0219e89c + 2) + 1);
      *(char *)(*DAT_0219e89c + 2) = (char)piVar2;
      return piVar2;
    }
    FUN_0219e8b8(1,(uVar6 - uVar7) - (uint)(uVar3 > uVar9));
    FUN_0219f0f4();
    piVar2 = (int *)FUN_0219f23c(1);
    return piVar2;
  }
  piVar2 = (int *)(*(int *)(iVar5 + DAT_0219e8a4) - 3);
  if ((int *)0x1 < piVar2) {
    return piVar2;
  }
  uVar6 = (uint)*(byte *)(iVar5 + 0xd);
  if ((int)uVar6 < (int)((byte)pcVar10[1] - 1)) {
    return (int *)((byte)pcVar10[1] - 1);
  }
  if (pcVar10[2] == '\0') {
    lVar14 = FUN_021a350c();
    uVar7 = (uint)((ulonglong)(lVar14 - *(longlong *)(pcVar10 + 0x10)) >> 0x20);
    bVar13 = *(uint *)(pcVar10 + 4) <= (uint)(lVar14 - *(longlong *)(pcVar10 + 0x10));
    uVar6 = uVar7 - !bVar13;
    if (uVar7 != 0 || uVar7 < bVar13) goto LAB_0219e81e;
  }
  if (pcVar10[2] == '\0') {
    return (int *)0x0;
  }
  iVar5 = *DAT_0219e89c;
  uVar15 = FUN_021a350c(DAT_0219e89c,uVar6);
  uVar9 = (uint)uVar15 - *(uint *)(iVar5 + 0x18);
  uVar6 = (int)((ulonglong)uVar15 >> 0x20) - *(int *)(iVar5 + 0x1c);
  uVar7 = (uint)((uint)uVar15 < *(uint *)(iVar5 + 0x18));
  uVar3 = *(uint *)(iVar5 + 4) >> 2;
  if (uVar6 == uVar7 && (uint)(uVar3 <= uVar9) <= uVar6 - uVar7) {
    return (int *)(uVar9 - uVar3);
  }
LAB_0219e81e:
  if (*(int *)(*DAT_0219e8a0 + DAT_0219e8b4) != 0) {
    FUN_0219fb14();
    piVar2 = (int *)FUN_0219fee4();
    if (piVar2 != (int *)0x0) {
      return piVar2;
    }
  }
  piVar2 = DAT_0219e8a0;
  *(undefined4 *)(*DAT_0219e8a0 + DAT_0219e8a4) = 0x13;
  iVar5 = 1;
  if (*(char *)(*piVar2 + 0xd) != '\0') {
    iVar12 = 2;
    iVar11 = 4;
    do {
      iVar8 = *piVar2 + iVar11;
      FUN_021a0ae8(0x11,*(undefined4 *)(iVar8 + 0xf4),*(undefined4 *)(iVar8 + 0x24),
                   *(undefined2 *)(*piVar2 + iVar12 + 0xa4),0,0);
      piVar4 = (int *)FUN_0219fee4();
      if (piVar4 != (int *)0x0) {
        return piVar4;
      }
      iVar12 = iVar12 + 2;
      iVar11 = iVar11 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 <= (int)(uint)*(byte *)(*piVar2 + 0xd));
  }
  iVar5 = *DAT_0219e89c;
  uVar15 = FUN_021a350c();
  *(undefined8 *)(iVar5 + 0x18) = uVar15;
  *(undefined1 *)(iVar5 + 2) = 1;
  return (int *)0x1;
}

