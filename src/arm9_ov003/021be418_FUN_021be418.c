/* Decompiled C draft; module arm9_ov003; ROM address 021be418. No matching claim. */
#include "types.h"
#include "deps/021be418_FUN_021be418.h"

undefined4 FUN_021be418(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_r4;
  
  bVar1 = true;
  *DAT_021be4c0 = param_1;
  FUN_021be568();
  iVar2 = (*(code *)*DAT_021be4c8)(param_1 * 400 + DAT_021be4c4);
  *DAT_021be4cc = iVar2;
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  uVar3 = iVar2 + 0x1fU & 0xffffffe0;
  *DAT_021be4d0 = uVar3;
  *DAT_021be4d8 = uVar3 + param_1 * 0xd0 + DAT_021be4d4 + 0x1f & 0xffffffe0;
  iVar2 = FUN_021be610(DAT_021be4dc);
  if (iVar2 == 0) {
    return 0xfffffffe;
  }
  do {
    func_0x0200dc3c(10);
    iVar2 = FUN_021be528();
    if (iVar2 != 0) {
      do {
        if ((iVar2 != 4) && (iVar2 != 5)) {
          if (iVar2 == 6) {
            bVar1 = false;
            unaff_r4 = 1;
          }
          else {
            bVar1 = false;
            unaff_r4 = 0xfffffffe;
          }
        }
        iVar2 = FUN_021be528();
      } while (iVar2 != 0);
    }
  } while (bVar1);
  return unaff_r4;
}

