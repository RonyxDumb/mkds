/* Decompiled C draft; module arm9_ov000; ROM address 021ad898. No matching claim. */
#include "types.h"
#include "deps/021ad898_FUN_021ad898.h"

void FUN_021ad898(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  int local_68;
  int local_34;
  int local_28;
  uint local_1c [2];
  
  *DAT_021adac4 = 0;
  func_0x0214d168((uint *)(uintptr_t)(DAT_021adac8),0,100);
  uVar2 = DAT_021adacc;
  iVar3 = DAT_021adac8;
  *(undefined4 *)(DAT_021adac8 + 0x3c) = DAT_021adacc;
  *(undefined4 *)(iVar3 + 0x40) = DAT_021adad0;
  *(undefined4 *)(iVar3 + 0x48) = uVar2;
  *(undefined4 *)(iVar3 + 0x4c) = DAT_021adad4;
  FUN_021ae304();
  local_68 = 0;
  bVar1 = true;
  local_1c[0] = 1;
  *DAT_021adad8 = 1;
  local_34 = 0;
  local_28 = 0;
  while (func_0x0200dc3c(DAT_021adadc), *DAT_021adac4 == 0) {
    uVar8 = func_0x0200f5ac();
    uVar6 = (uint)uVar8 >> 0x10 | (int)((ulonglong)uVar8 >> 0x20) << 0x10;
    iVar3 = (*(code *)*DAT_021adae0)();
    if (iVar3 == 0) {
      FUN_021b04f8(1);
      local_68 = 0;
      local_1c[0] = 1;
    }
    else {
      local_1c[0] = local_1c[0] - 1;
      if (local_1c[0] == 0) {
        if ((*DAT_021adae4 & 1) == 0) {
          switch(local_68) {
          case 0:
            if (bVar1) {
              *DAT_021adad8 = 2;
              bVar1 = false;
            }
            iVar3 = FUN_021ad36c();
            if ((iVar3 == 0) || (iVar3 = FUN_021ad2b8(local_1c,0), iVar3 == 0)) {
              FUN_021adb00();
              local_68 = 3;
            }
            else {
              local_68 = 1;
            }
            break;
          case 1:
            iVar3 = FUN_021ad2b8(local_1c,1);
            if ((iVar3 == 0) && (local_1c[0] < 0x3c)) {
              local_68 = 2;
            }
            break;
          case 2:
            iVar3 = FUN_021ad2b8(local_1c,2);
            if (iVar3 == 0) {
              if (local_1c[0] < 0x3c) {
                FUN_021b04f8(3);
                local_68 = 0;
                local_1c[0] = 1;
              }
            }
            else {
              local_68 = 1;
            }
          }
        }
        else if (local_68 == 0) {
          FUN_021adb00();
          local_68 = 1;
        }
      }
    }
    piVar4 = DAT_021adae8;
    iVar3 = local_34;
    do {
      if ((*piVar4 != 0) &&
         (DAT_021adaec < (int)((uVar6 - *(ushort *)((int)piVar4 + 10)) * 0x10000) >> 0x10)) {
        *piVar4 = 0;
      }
      piVar4 = piVar4 + 3;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    iVar5 = DAT_021adaf4;
    for (iVar3 = *(int *)(DAT_021adaf0 + 8); iVar7 = local_28, DAT_021adaf4 = iVar5, iVar3 != 0;
        iVar3 = *(int *)(iVar3 + 0x68)) {
      piVar4 = *(int **)(iVar3 + 0xa4);
      if ((piVar4 != (int *)0x0) && (*piVar4 != 0)) {
        if (((char)piVar4[2] == '\x03') && (0x27 < (int)(uVar6 - piVar4[4]))) {
          *(undefined1 *)(piVar4 + 2) = 1;
          *(undefined2 *)(piVar4 + 6) = *(undefined2 *)((int)piVar4 + 0x1a);
          piVar4[7] = piVar4[8];
        }
        else if ((((char)piVar4[2] == '\x02') && (0x27 < (int)(uVar6 - piVar4[4]))) &&
                (piVar4[1] == 1)) {
          *(undefined1 *)(piVar4 + 2) = 0;
          piVar4[1] = 0;
          func_0x0200df68(*piVar4);
        }
      }
      iVar5 = DAT_021adaf4;
    }
    do {
      if ((*(short *)(iVar5 + 4) != 0) && (0xef < (int)(uVar6 - *(int *)(iVar5 + 0x2c)))) {
        (*(code *)*DAT_021adaf8)(*(undefined4 *)(iVar5 + 0x34));
        *(undefined2 *)(iVar5 + 4) = 0;
      }
      iVar5 = iVar5 + 0x38;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 8);
    FUN_021a91cc(uVar6);
    if ((code *)*DAT_021adafc != (code *)0x0) {
      (*(code *)*DAT_021adafc)();
    }
  }
  if (((*DAT_021adae4 & 1) == 0) && (local_68 != 3)) {
    FUN_021ad264();
  }
  FUN_021ae2f4();
  return;
}

