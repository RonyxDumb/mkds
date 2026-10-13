/* Decompiled C draft; module arm9_ov003; ROM address 021be860. No matching claim. */
#include "types.h"
#include "deps/021be860_FUN_021be860.h"

undefined4 FUN_021be860(undefined1 *param_1,undefined1 *param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  uVar2 = func_0x0200fca0();
  *DAT_021be94c = param_4;
  puVar3 = DAT_021be950;
  *DAT_021be954 = DAT_021be950;
  if (param_1 == (undefined1 *)0x0) {
    func_0x0214d168(puVar3,0xff,6);
    *DAT_021be954 = DAT_021be958;
  }
  else {
    iVar4 = 0;
    do {
      uVar1 = *param_1;
      param_1 = param_1 + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 6);
  }
  puVar3 = DAT_021be95c;
  *DAT_021be960 = DAT_021be95c;
  if (((param_2 == (undefined1 *)0x0) || (param_3 < 1)) || (0x1f < param_3)) {
    func_0x0214d168(DAT_021be95c,0xff,0x20);
    *DAT_021be960 = DAT_021be964;
  }
  else {
    iVar4 = 0;
    if (0 < param_3) {
      do {
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        *puVar3 = uVar1;
        puVar3 = puVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_3);
    }
    if (iVar4 < 0x20) {
      puVar3 = DAT_021be95c + iVar4;
      do {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x20);
    }
  }
  if (*DAT_021be968 == 3) {
    iVar4 = func_0x021a61c4(DAT_021be950,*DAT_021be960,*DAT_021be94c);
    if (iVar4 == 3) {
      *DAT_021be968 = 6;
      func_0x0200fcb4(uVar2);
      return 1;
    }
  }
  else {
    iVar4 = FUN_021be9b8();
    if (iVar4 == 1) {
      *DAT_021be968 = 6;
      func_0x0200fcb4(uVar2);
      return 1;
    }
  }
  func_0x0200fcb4(uVar2);
  return 0;
}

