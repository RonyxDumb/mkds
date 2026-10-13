/* Decompiled C draft; module arm9; ROM address 02007698. No matching claim. */
#include "types.h"
#include "deps/02007698_func_02007698.h"

void func_02007698(int param_1,uint param_2)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int *piVar4;
  byte bVar5;
  undefined2 uVar6;
  int iVar7;
  ushort *puVar8;
  short *psVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined1 local_48 [2];
  undefined2 local_46;
  undefined4 local_34;
  undefined1 auStack_30 [22];
  undefined2 local_1a;
  
  if (param_2 == 0) {
    return;
  }
  if (0xf < param_2) {
    return;
  }
  iVar7 = func_0200c2e0((char *)(uintptr_t)(param_1 + 10),local_48,param_2);
  iVar14 = DAT_020079a0;
  piVar4 = DAT_02007980;
  iVar15 = param_2 - 1;
  iVar10 = iVar15 * 4;
  iVar11 = *DAT_02007980;
  iVar16 = *(int *)(iVar11 + iVar10 + DAT_02007984);
  switch(local_48[0]) {
  case 7:
    if (iVar16 == 2) {
      if (iVar7 == 0) {
        return;
      }
      Mem_CpuCopy8((ushort *)(uintptr_t)(iVar7),&local_34,0x1d);
      piVar4 = DAT_02007980;
      *(undefined4 *)(*DAT_02007980 + iVar10 + DAT_02007988) = local_34;
      *(undefined2 *)(*piVar4 + iVar15 * 2 + DAT_0200798c) = local_1a;
      iVar14 = iVar15 * 0x16;
      Mem_CpuCopy8((ushort *)(void *)(auStack_30),(uint *)(uintptr_t)(*piVar4 + DAT_02007990 + iVar14),0x16);
      *(byte *)(*DAT_02007980 + DAT_02007990 + iVar14) =
           *(byte *)(*DAT_02007980 + DAT_02007990 + iVar14) & 0xf | (byte)((param_2 & 0xf) << 4);
      func_02007d18(param_2,10,(undefined4)(uintptr_t)(auStack_30));
    }
    if (iVar16 != 10) {
      return;
    }
    bVar5 = 0;
    bVar1 = *(byte *)(iVar7 + 0x1c);
    uVar13 = (uint)bVar1;
    if (uVar13 < 0x10) {
      iVar14 = *DAT_02007980;
      iVar7 = iVar14 + DAT_02007994 * uVar13;
      if ((*(char *)(iVar7 + DAT_02007998) == '\0') ||
         (*(int *)(iVar14 + iVar10 + DAT_02007988) !=
          *(int *)(*(int *)(iVar7 + DAT_0200799c) + 0x14))) goto LAB_020077a4;
      uVar12 = 0;
      do {
        if ((1 << uVar12 & (uint)*(ushort *)(iVar7 + DAT_020079a4)) != 0) {
          bVar5 = bVar5 + 1;
        }
        uVar12 = uVar12 + 1 & 0xff;
      } while (uVar12 < 0x10);
      if (*(byte *)(*(int *)(iVar7 + DAT_0200799c) + 0x18) <= bVar5) {
        *(undefined2 *)(iVar14 + iVar15 * 2 + DAT_020079a0) = 0;
        func_02007d18(param_2,0xb);
        return;
      }
    }
    else {
LAB_020077a4:
      *(undefined2 *)(*DAT_02007980 + iVar15 * 2 + DAT_020079a0) = 4;
    }
    iVar14 = DAT_020079a0;
    piVar4 = DAT_02007980;
    iVar7 = *DAT_02007980;
    psVar9 = (short *)(iVar7 + iVar15 * 2 + DAT_020079a0);
    sVar2 = *psVar9;
    if (sVar2 != 3) {
      if (sVar2 == 4) {
        *psVar9 = 0;
        func_02007d18(param_2,4);
        return;
      }
      return;
    }
    uVar12 = 1 << (param_2 & 0xff);
    if ((*(ushort *)(iVar7 + DAT_020079a8) & uVar12) == 0) {
      *(char *)(iVar7 + DAT_020079ac) = *(char *)(iVar7 + DAT_020079ac) + '\x01';
      uVar3 = (ushort)uVar12;
      *(ushort *)(*piVar4 + DAT_020079a8) = *(ushort *)(*piVar4 + DAT_020079a8) | uVar3;
      *(byte *)(*piVar4 + (param_2 - 1) + DAT_020079b0) = bVar1;
      iVar7 = DAT_02007994 * uVar13;
      puVar8 = (ushort *)(*piVar4 + iVar7 + DAT_020079a4);
      *puVar8 = *puVar8 | uVar3;
      puVar8 = (ushort *)(*piVar4 + iVar7 + DAT_020079b4);
      *puVar8 = *puVar8 | uVar3;
      *(undefined2 *)(*piVar4 + iVar15 * 2 + iVar14) = 0;
      func_02007d18(param_2,5);
      return;
    }
    break;
  case 8:
    if (iVar16 == 5) {
      func_02007d18(param_2,0xe,0);
      return;
    }
    if ((iVar16 == 0xe) && (*(short *)(iVar11 + iVar15 * 2 + DAT_020079a0) == 2)) {
      iVar7 = DAT_02007994 * (uint)*(byte *)(iVar11 + iVar15 + DAT_020079b0);
      puVar8 = (ushort *)(iVar11 + iVar7 + DAT_020079b8);
      *puVar8 = *puVar8 | (ushort)(1 << (param_2 & 0xff));
      *(undefined2 *)(*piVar4 + iVar7 + DAT_020079bc) = 0;
      *(undefined2 *)(*piVar4 + iVar15 * 2 + iVar14) = 0;
      func_02007d18(param_2,6,0);
      return;
    }
    break;
  case 9:
    if ((iVar16 == 6) && (uVar13 = (uint)*(byte *)(iVar11 + iVar15 + DAT_020079b0), uVar13 != 0xff))
    {
      iVar14 = DAT_02007994 * uVar13;
      uVar6 = func_02007148(*(undefined2 *)(iVar11 + iVar14 + DAT_020079c0),local_46);
      *(undefined2 *)(*piVar4 + iVar14 + DAT_020079c0) = uVar6;
      return;
    }
    break;
  case 10:
    if (iVar16 == 6) {
      uVar13 = (uint)*(byte *)(iVar11 + iVar15 + DAT_020079b0);
      if (uVar13 != 0xff) {
        puVar8 = (ushort *)(iVar11 + DAT_02007994 * uVar13 + DAT_020079b8);
        *puVar8 = *puVar8 & ~(ushort)(1 << (param_2 & 0xff));
        func_02007d18(param_2,7,0);
        return;
      }
    }
    else if ((iVar16 == 7) && (psVar9 = (short *)(iVar11 + iVar15 * 2 + DAT_020079a0), *psVar9 == 5)
            ) {
      *psVar9 = 0;
      func_02007d18(param_2,8);
    }
  }
  return;
}

