/* Decompiled C draft; module arm9; ROM address 02005a30. No matching claim. */
#include "types.h"
#include "deps/02005a30_func_02005a30.h"

void func_02005a30(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  switch(*param_1) {
  default:
    return;
  case 2:
    uVar1 = func_020070d8();
    uVar2 = func_020070e4();
    func_02006858(param_2,(short)param_1[2],(char)param_1[3],uVar1,uVar2);
    return;
  case 4:
  case 6:
    uVar5 = 0;
    iVar6 = (int)param_1 + DAT_02005b14;
    break;
  case 10:
    func_0200654c(param_2,(short)param_1[2],(char)param_1[3],param_1 + 5,
                  *(undefined1 *)((int)param_1 + 0x1d));
    return;
  }
  do {
    uVar4 = 1 << (uVar5 & 0xff);
    if (((uint)*(ushort *)(param_1 + 2) & uVar4 & 0xffff) != 0) {
      iVar3 = func_020062f4(iVar6);
      if (iVar3 == -1) {
        iVar3 = func_020065f8(param_2,uVar4 & 0xffff,(char)param_1[3],param_1[5]);
      }
      else if (*param_1 == 4) {
        iVar3 = func_02006794(param_2,(short)param_1[2],(char)param_1[3],param_1[5],iVar3);
      }
      else {
        iVar3 = func_020066c0(param_2,(short)param_1[2],(char)param_1[3],param_1[5],iVar3);
      }
      if (iVar3 != 0) {
        return;
      }
    }
    iVar6 = iVar6 + 0x68;
    uVar5 = uVar5 + 1;
    if (0xf < (int)uVar5) {
      return;
    }
  } while( true );
}

