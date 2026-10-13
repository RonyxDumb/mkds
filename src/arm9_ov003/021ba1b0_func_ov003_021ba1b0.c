/* Decompiled C draft; module arm9_ov003; ROM address 021ba1b0. No matching claim. */
#include "types.h"
#include "deps/021ba1b0_func_ov003_021ba1b0.h"

int func_ov003_021ba1b0(undefined4 *param_1,undefined4 param_2)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  uint unaff_r6;
  uint uVar5;
  int local_54;
  int local_50;
  undefined4 local_48;
  undefined1 auStack_44 [48];
  
  bVar1 = true;
  bVar2 = false;
  local_54 = -1;
  uVar5 = DAT_021ba36c;
  if ((param_1[9] != 0) && (uVar5 = unaff_r6, param_1[9] == 1)) {
    uVar5 = DAT_021ba370;
  }
  func_0x0214d168((uint *)(void *)(DAT_021ba374),0,0x60);
  iVar4 = param_1[10];
  if (iVar4 == 5) {
    *DAT_021ba374 = 1;
  }
  else if (iVar4 == 0xd) {
    *DAT_021ba374 = 2;
  }
  else {
    if (iVar4 != 0x10) {
      return -1;
    }
    *DAT_021ba374 = 3;
  }
  DAT_021ba374[1] = 0;
  func_0x0214d1fc((ushort *)(void *)(param_1 + 0xb),(uint *)(uintptr_t)(DAT_021ba378),param_1[10]);
  func_0x021a6894();
  iVar4 = FUN_021baaac(0,(undefined1 *)(void *)(param_1 + 1),*param_1,DAT_021ba37c);
  if (iVar4 != 0) {
    local_50 = 0;
    func_0x0200fb08((unsigned int)(uintptr_t)(auStack_44));
    func_0x0200f950((undefined4 *)(void *)(auStack_44),DAT_021ba380,0,DAT_021ba384,0x12);
    uVar3 = DAT_021ba38c;
    uVar5 = uVar5 | DAT_021ba388;
    do {
      func_0x0200ea3c(DAT_021ba390,&local_48,1);
      switch(local_48) {
      default:
        bVar1 = false;
        break;
      case 4:
      case 8:
      case 0x13:
        break;
      case 5:
        if (!bVar2) {
          func_0x0200f8b8((undefined4 *)(void *)(auStack_44));
          iVar4 = FUN_021babc0(uVar3,1);
          if (iVar4 == 1) {
            FUN_021ba744(param_1,uVar3);
            iVar4 = FUN_021ba910(uVar3,(int)(uintptr_t)(DAT_021ba374),uVar5);
            if (iVar4 == 0) {
              bVar1 = false;
            }
            else {
              bVar2 = true;
            }
          }
          else {
            bVar1 = false;
          }
        }
        break;
      case 10:
        FUN_021ba744(param_1,uVar3);
        iVar4 = FUN_021ba910(uVar3,(int)(uintptr_t)(DAT_021ba374),uVar5);
        if (iVar4 == 0) {
          bVar1 = false;
        }
        break;
      case 0xc:
        local_54 = 0;
        bVar1 = false;
        break;
      case 0xd:
        local_50 = local_50 + 1;
        if (local_50 < 3) {
          iVar4 = FUN_021ba910(uVar3,(int)(uintptr_t)(DAT_021ba374),uVar5);
          if (iVar4 == 0) {
            bVar1 = false;
          }
        }
        else {
          bVar1 = false;
        }
        break;
      case 0x12:
        if (!bVar2) {
          bVar1 = false;
        }
      }
    } while (bVar1);
    func_0x0200f8b8((undefined4 *)(void *)(auStack_44));
    uVar3 = DAT_021ba390;
    do {
      iVar4 = func_0x0200ea3c(uVar3,&local_48,0);
    } while (iVar4 == 1);
  }
  FUN_021ba734(param_2,DAT_021ba38c,local_54 == 0);
  return local_54;
}

