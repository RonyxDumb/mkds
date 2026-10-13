/* Decompiled C draft; module arm9_ov000; ROM address 021ac7e8. No matching claim. */
#include "types.h"
#include "deps/021ac7e8_FUN_021ac7e8.h"

void FUN_021ac7e8(undefined2 *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = (*(code *)*DAT_021ac8f4)(param_4 << 3);
  if (iVar1 != 0) {
    iVar2 = iVar1 + param_4 * 2;
    func_0x0214d168(param_1 + 1,0,(param_4 + -1) * 2);
    *param_1 = 1;
    iVar3 = thunk_FUN_021acecc(param_3,param_4);
    uVar4 = param_4 << 4;
    for (uVar5 = (param_4 - iVar3) * 0x10; uVar5 < uVar4; uVar5 = uVar5 + 1) {
      if ((DAT_021ac8f8 >> (uVar5 & 0xf) &
          (uint)*(ushort *)(param_3 + ((param_4 - ((int)uVar5 >> 4)) + -1) * 2)) != 0) {
        func_0x0214d1fc(param_2,param_1,param_4 << 1);
        uVar5 = uVar5 + 1;
        break;
      }
    }
    if (uVar5 < uVar4) {
      do {
        FUN_021acab0(iVar1,param_1,param_4);
        func_0x0214d1fc(iVar1,param_1,param_4 << 1);
        if (param_5 != 0) {
          FUN_021ac900(0,param_1,param_5,param_1,param_4,iVar2);
        }
        if ((DAT_021ac8f8 >> (uVar5 & 0xf) &
            (uint)*(ushort *)(param_3 + ((param_4 - ((int)uVar5 >> 4)) + -1) * 2)) != 0) {
          FUN_021acbf8(iVar1,param_1,param_2,param_4);
          func_0x0214d1fc(iVar1,param_1,param_4 << 1);
          if (param_5 != 0) {
            FUN_021ac900(0,param_1,param_5,param_1,param_4,iVar2);
          }
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar4);
    }
    (*(code *)*DAT_021ac8fc)(iVar1);
  }
  return;
}

