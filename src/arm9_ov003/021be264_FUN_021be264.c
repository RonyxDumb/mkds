/* Decompiled C draft; module arm9_ov003; ROM address 021be264. No matching claim. */
#include "types.h"
#include "deps/021be264_FUN_021be264.h"

int FUN_021be264(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_44;
  undefined1 auStack_40 [44];
  
  bVar1 = true;
  iVar4 = -2;
  iVar5 = *DAT_021be390 + *DAT_021be394 * 0xc0;
  if (iVar5 == 0) {
    return 0;
  }
  iVar2 = FUN_021be708(iVar5,0,DAT_021be398);
  if (iVar2 == 0) {
    return -2;
  }
  func_0x0200fb08((unsigned int)(uintptr_t)(auStack_40));
  func_0x0200f950((undefined4 *)(void *)(auStack_40),DAT_021be39c,0,DAT_021be3a0,0x12);
  local_44 = -8;
  while( true ) {
    uVar3 = FUN_021bb354();
    if (*DAT_021be3a4 <= uVar3) {
      iVar4 = -3;
      goto LAB_021be358;
    }
    if (*DAT_021be3a8 != 0) break;
    func_0x0200dc3c(10);
    iVar2 = FUN_021be528();
    while (iVar2 != 0) {
      if (iVar2 < 0xd) {
        if (iVar2 < 0xc) {
          if (((5 < iVar2) || (iVar2 < 4)) || ((iVar2 != 4 && (iVar2 != 5)))) goto LAB_021be34a;
        }
        else {
          bVar1 = false;
          iVar4 = 1;
        }
      }
      else if ((iVar2 < 0x14) && (0xc < iVar2)) {
        if (iVar2 == 0xd) {
          if (*DAT_021be3a8 == 0) {
            iVar2 = FUN_021be708(iVar5,0,DAT_021be398);
            if (iVar2 == 0) {
              return iVar4;
            }
          }
          else {
            bVar1 = false;
            iVar4 = local_44;
          }
        }
        else if ((iVar2 != 0x12) && (iVar2 != 0x13)) goto LAB_021be34a;
      }
      else {
LAB_021be34a:
        bVar1 = false;
      }
      iVar2 = FUN_021be528();
    }
    if (!bVar1) {
LAB_021be358:
      func_0x0200f8b8((undefined4 *)(void *)(auStack_40));
      do {
        iVar5 = FUN_021be528();
      } while (iVar5 != 0);
      if (0 < iVar4) {
        *DAT_021be3ac = 1;
        iVar5 = func_0x021a8c94(DAT_021be3b0);
        if (iVar5 < 0) {
          iVar4 = -2;
        }
        else {
          *DAT_021be3b4 = 1;
        }
      }
      return iVar4;
    }
  }
  iVar4 = -8;
  goto LAB_021be358;
}

