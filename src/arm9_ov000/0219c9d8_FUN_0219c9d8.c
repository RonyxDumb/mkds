/* Decompiled C draft; module arm9_ov000; ROM address 0219c9d8. No matching claim. */
#include "types.h"
#include "deps/0219c9d8_FUN_0219c9d8.h"

uint FUN_0219c9d8(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  uVar1 = *DAT_0219ca74;
  if ((*DAT_0219ca74 != 0) && (uVar1 = FUN_0219c39c(), uVar1 == 0)) {
    uVar2 = ((int *)*DAT_0219ca74)[1];
    uVar1 = uVar2;
    if (uVar2 < 6) {
      uVar1 = (int)&switchD_0219ca02::switchdataD_0219ca04 +
              (int)(short)(&switchD_0219ca02::switchdataD_0219ca04)[uVar2];
      switch(uVar2) {
      case 0:
      case 5:
        break;
      case 1:
        uVar1 = FUN_0219c524();
        return uVar1;
      default:
        piVar3 = *(int **)*DAT_0219ca74;
        if ((piVar3 != (int *)0x0) && (*piVar3 != 0)) {
          FUN_0218f268();
        }
        uVar1 = *(uint *)(*DAT_0219ca74 + 0x34);
        if (uVar1 != 0) {
          lVar5 = func_0x0200f5ac();
          lVar5 = lVar5 - *(longlong *)(*DAT_0219ca74 + 0x38);
          uVar1 = (uint)lVar5;
          uVar6 = func_0x02132e40(uVar1 * 0x40,
                                  (int)((ulonglong)lVar5 >> 0x20) * 0x40 | uVar1 >> 0x1a,
                                  DAT_0219ca78,0);
          iVar4 = (int)((ulonglong)uVar6 >> 0x20);
          uVar2 = (uint)uVar6;
          uVar1 = DAT_0219ca7c - uVar2;
          if ((uint)(uVar2 <= DAT_0219ca7c) <= (uint)-iVar4) {
            FUN_0219c990(6,DAT_0219ca80,DAT_0219ca7c,-(uint)(uVar2 > DAT_0219ca7c) - iVar4);
            uVar1 = *DAT_0219ca74;
            *(undefined4 *)(uVar1 + 0x34) = 0;
          }
        }
      }
    }
  }
  return uVar1;
}

