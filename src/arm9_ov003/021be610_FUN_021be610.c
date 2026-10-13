/* Decompiled C draft; module arm9_ov003; ROM address 021be610. No matching claim. */
#include "types.h"
#include "deps/021be610_FUN_021be610.h"

undefined4 FUN_021be610(undefined4 param_1,int param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = func_0x0200fca0();
  *DAT_021be6e4 = param_2;
  puVar1 = DAT_021be6e8;
  uVar5 = param_2 + 99U & 0xfffffffc;
  *DAT_021be6e8 = uVar5;
  uVar4 = uVar5 + 0x2f & 0xffffffe0;
  *DAT_021be6ec = uVar4;
  uVar4 = uVar4 + DAT_021be6f0 & 0xffffffe0;
  *DAT_021be6f4 = uVar4;
  *(uint *)(uVar5 + 4) = uVar4 + 0xc0;
  *(int *)(*puVar1 + 8) = (param_2 + param_3) - *(int *)(*puVar1 + 4);
  *(undefined4 *)(*puVar1 + 0xc) = 0;
  *(undefined4 *)*puVar1 = 3;
  *DAT_021be6f8 = param_1;
  if (*DAT_021be6fc == 0) {
    iVar3 = func_0x021a6470(*DAT_021be6ec,DAT_021be700);
    if (iVar3 != 0) {
      func_0x0200fcb4(uVar2);
      return 0;
    }
    *DAT_021be6fc = 1;
  }
  if (*DAT_021be6fc == 1) {
    iVar3 = func_0x021a629c(*DAT_021be6e8,DAT_021be704);
    if (iVar3 != 3) {
      func_0x0200fcb4(uVar2);
      return 0;
    }
    *DAT_021be6fc = 4;
    func_0x0200fcb4(uVar2);
    return 1;
  }
  func_0x0200fcb4(uVar2);
  return 0;
}

