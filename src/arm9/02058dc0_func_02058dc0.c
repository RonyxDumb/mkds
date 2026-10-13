/* Decompiled C draft; module arm9; ROM address 02058dc0. No matching claim. */
#include "types.h"
#include "deps/02058dc0_func_02058dc0.h"

undefined4 func_02058dc0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  piVar3 = (int *)*DAT_02058edc;
  puVar2 = (undefined4 *)((int)piVar3 + DAT_02058ee0);
  switch(*puVar2) {
  case 0:
    if ((*(ushort *)((int)piVar3 + DAT_02058ee4) & 1) != 0) {
      if (piVar3 == (int *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *piVar3;
      }
      if (iVar1 == 1) {
        *(undefined4 *)((int)piVar3 + DAT_02058ee0) = 6;
      }
      else if (iVar1 == 2) {
        *(undefined4 *)((int)piVar3 + DAT_02058ee0) = 2;
      }
    }
    break;
  case 1:
    if ((*(byte *)((int)piVar3 + DAT_02058ee8) & 2) != 0) {
      uVar4 = 1;
    }
    break;
  case 2:
    if (*DAT_02058ef0 == 2) {
      WorkerInsertTask();
      *(undefined4 *)(*DAT_02058ef4 + 0xf8) = 1;
    }
    *(undefined4 *)(*DAT_02058edc + DAT_02058ee0) = 3;
    func_020505a8(3,1);
    break;
  case 3:
    if (*(int *)(*DAT_02058ef4 + 0xf8) == 0) {
      if (*(char *)((int)piVar3 + DAT_02058ef8) == '\0') {
        *puVar2 = 5;
      }
      else {
        func_02050e60(7);
      }
    }
    break;
  case 5:
    iVar1 = func_020505a8(4,1);
    if (iVar1 != 0) {
      *(undefined4 *)(*DAT_02058edc + DAT_02058ee0) = 1;
    }
    break;
  case 6:
    if (*(byte *)((int)piVar3 + 0x87) ==
        (*(byte *)((int)piVar3 + 0x87) & *(byte *)((int)piVar3 + DAT_02058eec))) {
      *puVar2 = 7;
    }
    break;
  case 7:
    func_020505a8(5,0xff);
    piVar3 = DAT_02058edc;
    *(byte *)(*DAT_02058edc + DAT_02058ee8) = *(byte *)(*DAT_02058edc + DAT_02058ee8) | 2;
    *(undefined1 *)(*piVar3 + DAT_02058eec) = 0;
    *(undefined4 *)(*piVar3 + DAT_02058ee0) = 1;
  }
  return uVar4;
}

