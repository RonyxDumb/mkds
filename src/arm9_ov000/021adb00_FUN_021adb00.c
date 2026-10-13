/* Decompiled C draft; module arm9_ov000; ROM address 021adb00. No matching claim. */
#include "types.h"
#include "deps/021adb00_FUN_021adb00.h"

void FUN_021adb00(void)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  (*(code *)*DAT_021adb70)();
  if (*DAT_021adb74 != 0) {
    FUN_021afc5c();
    func_0x0200dc3c(100);
    FUN_021afc5c(*DAT_021adb74);
    uVar4 = func_0x0200f5ac();
    puVar2 = DAT_021adb7c;
    pcVar1 = DAT_021adb78;
    while (iVar3 = (*(code *)*puVar2)(), iVar3 != 0) {
      uVar5 = func_0x0200f5ac();
      if (0x16 < (int)(((uint)uVar5 >> 0x10 | (int)((ulonglong)uVar5 >> 0x20) << 0x10) -
                      ((uint)uVar4 >> 0x10 | (int)((ulonglong)uVar4 >> 0x20) << 0x10))) {
        return;
      }
      if (*pcVar1 != '\0') {
        FUN_021b04f8(4);
        return;
      }
      func_0x0200dc3c(100);
    }
  }
  return;
}

