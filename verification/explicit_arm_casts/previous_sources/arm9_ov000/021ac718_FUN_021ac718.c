/* Decompiled C draft; module arm9_ov000; ROM address 021ac718. No matching claim. */
#include "types.h"
#include "deps/021ac718_FUN_021ac718.h"

void FUN_021ac718(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = param_4 * 2;
  iVar1 = param_5 + iVar6;
  iVar2 = iVar1 + iVar6;
  iVar3 = iVar2 + iVar6;
  iVar4 = iVar3 + iVar6;
  iVar7 = iVar4 + iVar6;
  func_0x0214d1fc(param_2,param_5,iVar6);
  func_0x0214d1fc(param_3,iVar2,iVar6);
  *(undefined2 *)(iVar2 + iVar6) = 1;
  iVar5 = FUN_021ace90(param_5,param_4);
  while (0 < iVar5) {
    FUN_021ac900(iVar1,iVar2,param_5,iVar7,param_4,iVar7 + iVar6);
    func_0x0214d1fc(param_5,iVar2,iVar6);
    func_0x0214d1fc(iVar7,param_5,iVar6);
    FUN_021acbf8(iVar7,iVar1,iVar3,param_4);
    FUN_021acd24(iVar7,iVar4,iVar7,param_4);
    func_0x0214d1fc(iVar3,iVar4,iVar6);
    func_0x0214d1fc(iVar7,iVar3,iVar6);
    iVar5 = FUN_021ace90(param_5,param_4);
  }
  FUN_021ace14(iVar4,iVar4,param_3,param_4);
  FUN_021ac900(0,iVar4,param_3,param_1,param_4,iVar7 + iVar6);
  return;
}

