/* Decompiled C draft; module arm9; ROM address 0211d2f0. No matching claim. */
#include "types.h"
#include "deps/0211d2f0_func_0211d2f0.h"

undefined4 func_0211d2f0(short *param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  short extraout_r1;
  int iVar4;
  int iVar5;
  longlong lVar6;
  
  iVar3 = func_0211d62c();
  if (iVar3 != 0) {
    switch(*(undefined4 *)(*DAT_0211d39c + 0x2c)) {
    case 0:
    case 1:
      sVar1 = func_0211d650();
      func_0211d62c();
      sVar2 = func_020ae3b4();
      *param_1 = sVar1 + sVar2;
      break;
    case 2:
    case 3:
    case 4:
    case 5:
      iVar5 = *DAT_0211d3a0;
      iVar4 = iVar5 + DAT_0211d3a4;
      iVar3 = func_0211d62c();
      lVar6 = Multiply64(*(undefined4 *)(iVar4 + 8),*(undefined4 *)(iVar4 + 0xc),
                         *(undefined4 *)(iVar5 + DAT_0211d3a4),*(undefined4 *)(iVar4 + 4));
      lVar6 = lVar6 + *(longlong *)(iVar4 + 0x10);
      *(int *)(iVar5 + DAT_0211d3a4) = (int)lVar6;
      *(int *)(iVar4 + 4) = (int)((ulonglong)lVar6 >> 0x20);
      if (iVar3 == 0) {
        sVar1 = (short)*(undefined4 *)(iVar4 + 4);
      }
      else {
        Multiply64(*(undefined4 *)(iVar4 + 4),0,iVar3,0);
        sVar1 = extraout_r1;
      }
      sVar2 = func_0211d650();
      *param_1 = sVar2 + sVar1;
    }
    return 1;
  }
  *param_1 = 8;
  return 0;
}

