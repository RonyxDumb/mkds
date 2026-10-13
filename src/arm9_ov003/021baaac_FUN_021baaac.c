/* Decompiled C draft; module arm9_ov003; ROM address 021baaac. No matching claim. */
#include "types.h"
#include "deps/021baaac_FUN_021baaac.h"

undefined4 FUN_021baaac(undefined1 *param_1,undefined1 *param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  uVar2 = func_0x0200fca0();
  *DAT_021baba0 = param_4;
  if (param_1 == (undefined1 *)0x0) {
    func_0x0214d168((uint *)(void *)(DAT_021baba4),0xff,6);
    *DAT_021baba8 = DAT_021babac;
  }
  else {
    iVar4 = 0;
    puVar3 = DAT_021baba4;
    do {
      uVar1 = *param_1;
      param_1 = param_1 + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 6);
    *DAT_021baba8 = DAT_021baba4;
  }
  if (((param_2 == (undefined1 *)0x0) || (param_3 < 1)) || (0x20 < param_3)) {
    func_0x0214d168((uint *)(void *)(DAT_021babb0),0xff,0x20);
    *DAT_021babb4 = DAT_021babb8;
  }
  else {
    iVar4 = 0;
    puVar3 = DAT_021babb0;
    if (0 < param_3) {
      do {
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        *puVar3 = uVar1;
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar4 < param_3);
    }
    if (iVar4 < 0x20) {
      puVar3 = DAT_021babb0 + iVar4;
      do {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x20);
    }
    *DAT_021babb4 = DAT_021babb0;
  }
  if (*DAT_021babbc == 3) {
    iVar4 = func_0x021a61c4(*DAT_021baba8,*DAT_021babb4,*DAT_021baba0);
    if (iVar4 == 3) {
      *DAT_021babbc = 6;
      func_0x0200fcb4(uVar2);
      return 1;
    }
  }
  else {
    iVar4 = FUN_021bac0c();
    if (iVar4 == 1) {
      *DAT_021babbc = 6;
      func_0x0200fcb4(uVar2);
      return 1;
    }
  }
  func_0x0200fcb4(uVar2);
  return 0;
}

