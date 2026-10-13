/* Decompiled C draft; module arm9_ov003; ROM address 021cf378. No matching claim. */
#include "types.h"
#include "deps/021cf378_FUN_021cf378.h"

void FUN_021cf378(uint param_1,undefined4 param_2,ushort *param_3)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = DAT_021cf58c;
  switch(param_2) {
  default:
    func_0x0200fd1c();
    break;
  case 1:
  case 4:
  case 5:
  case 6:
  case 8:
  case 0xb:
    break;
  case 2:
    iVar3 = FUN_021cf360();
    if (iVar3 == 2) {
      iVar3 = *DAT_021cf58c;
      func_0x0200fca0();
      *(ushort *)(iVar3 + 2) = *(ushort *)(iVar3 + 2) | (ushort)(1 << (param_1 & 0xff));
      func_0x0200fcb4();
      piVar2 = DAT_021cf58c;
      iVar4 = (param_1 - 1) * 0x1e;
      iVar3 = *DAT_021cf58c + 0x24 + iVar4;
      *(char *)(*DAT_021cf58c + 0x24 + iVar4) = (char)param_3[5];
      *(undefined1 *)(iVar3 + 1) = *(undefined1 *)((int)param_3 + 0xb);
      *(char *)(iVar3 + 2) = (char)param_3[6];
      *(undefined1 *)(iVar3 + 3) = *(undefined1 *)((int)param_3 + 0xd);
      *(char *)(iVar3 + 4) = (char)param_3[7];
      *(undefined1 *)(iVar3 + 5) = *(undefined1 *)((int)param_3 + 0xf);
      *(short *)(*piVar2 + iVar4 + 0x2a) = (short)param_1;
      return;
    }
    break;
  case 3:
    iVar3 = FUN_021cf284();
    if (iVar3 != 6) {
      uVar1 = ~(ushort)(1 << (param_1 & 0xff));
      func_0x0200fca0();
      piVar2 = DAT_021cf58c;
      *(ushort *)(*DAT_021cf58c + 2) = *(ushort *)(*DAT_021cf58c + 2) & uVar1;
      *(ushort *)(*piVar2 + 4) = *(ushort *)(*piVar2 + 4) & uVar1;
      *(ushort *)(*piVar2 + 6) = *(ushort *)(*piVar2 + 6) & uVar1;
      *(ushort *)(*piVar2 + 8) = *(ushort *)(*piVar2 + 8) & uVar1;
      *(ushort *)(*piVar2 + 10) = *(ushort *)(*piVar2 + 10) & uVar1;
      *(ushort *)(*piVar2 + 0xc) = *(ushort *)(*piVar2 + 0xc) & uVar1;
      func_0x0200fcb4();
      return;
    }
    break;
  case 7:
    uVar1 = (ushort)(1 << (param_1 & 0xff));
    *(ushort *)(*DAT_021cf58c + 8) = *(ushort *)(*DAT_021cf58c + 8) & ~uVar1;
    *(ushort *)(*piVar2 + 10) = *(ushort *)(*piVar2 + 10) | uVar1;
    return;
  case 9:
    uVar1 = (ushort)(1 << (param_1 & 0xff));
    *(ushort *)(*DAT_021cf58c + 10) = *(ushort *)(*DAT_021cf58c + 10) & ~uVar1;
    *(ushort *)(*piVar2 + 0xc) = *(ushort *)(*piVar2 + 0xc) | uVar1;
    if (*(short *)(*piVar2 + 2) == *(short *)(*piVar2 + 0xc)) {
      func_0x02009c04();
      return;
    }
    break;
  case 10:
    iVar3 = FUN_021cf360();
    if (iVar3 != 2) {
      FUN_021cf7b8(param_1);
      return;
    }
    *(ushort *)(*DAT_021cf58c + 4) =
         *(ushort *)(*DAT_021cf58c + 4) | (ushort)(1 << (param_1 & 0xff));
    FUN_021cf844(param_1);
    iVar3 = func_0x02007e38(param_1);
    if (iVar3 != 0) {
      func_0x0214d1fc(iVar3,*DAT_021cf58c + 0xe + (param_1 - 1) * 0x1e,0x16);
      return;
    }
    break;
  case 0xc:
    iVar3 = FUN_021cf360();
    if (iVar3 == 4) {
      FUN_021cf36c(5);
    }
    else {
      FUN_021cf36c(0);
    }
    if (*(int *)(*DAT_021cf58c + DAT_021cf590) != 0) {
      *(int *)(*DAT_021cf58c + DAT_021cf590) = 0;
    }
    if (*(int *)(*DAT_021cf58c + DAT_021cf594) != 0) {
      *(int *)(*DAT_021cf58c + DAT_021cf594) = 0;
      return;
    }
    break;
  case 0xd:
    uVar1 = *param_3;
    if (uVar1 < 9) {
      if (((uVar1 < 8) && (uVar1 < 3)) && (uVar1 != 0)) {
        if ((uVar1 != 1) && (uVar1 != 2)) {
          return;
        }
LAB_021cf576:
        FUN_021cf36c(7);
        return;
      }
    }
    else if (uVar1 == 9) goto LAB_021cf576;
    break;
  case 0xe:
    uVar1 = (ushort)(1 << (param_1 & 0xff));
    *(ushort *)(*DAT_021cf58c + 4) = *(ushort *)(*DAT_021cf58c + 4) & ~uVar1;
    *(ushort *)(*piVar2 + 6) = *(ushort *)(*piVar2 + 6) | uVar1;
    iVar3 = FUN_021cf360();
    if (iVar3 == 3) {
      FUN_021cf72c(param_1);
      return;
    }
  }
  return;
}

