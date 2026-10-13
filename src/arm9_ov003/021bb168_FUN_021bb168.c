/* Decompiled C draft; module arm9_ov003; ROM address 021bb168. No matching claim. */
#include "types.h"
#include "deps/021bb168_FUN_021bb168.h"

int FUN_021bb168(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,uint param_6)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((0 < *DAT_021bb25c) && (*DAT_021bb25c < 6)) {
    return -10;
  }
  *DAT_021bb260 = param_2;
  *DAT_021bb25c = 7;
  *DAT_021bb264 = param_3;
  *DAT_021bb268 = param_4;
  *DAT_021bb26c = param_5;
  *DAT_021bb270 = param_6;
  iVar2 = FUN_021be418(param_2);
  *DAT_021bb274 = 1;
  if (iVar2 < 0) {
    *DAT_021bb278 = iVar2;
    return iVar2;
  }
  iVar2 = (*(code *)*DAT_021bb268)(*DAT_021bb270);
  *DAT_021bb27c = iVar2;
  if (iVar2 == 0) {
    *DAT_021bb278 = -1;
    return -1;
  }
  iVar2 = func_0x0200db4c();
  if (iVar2 != 1) {
    *DAT_021bb278 = -9;
    return -9;
  }
  iVar3 = 7;
  func_0x0200e28c(DAT_021bb280,DAT_021bb284,0,*DAT_021bb27c + (*DAT_021bb270 & 0xfffffff8),
                  *DAT_021bb270,param_1);
  *DAT_021bb25c = 1;
  iVar2 = FUN_021bb354();
  *DAT_021bb28c = iVar2 + DAT_021bb288;
  *DAT_021bb290 = 0;
  puVar1 = DAT_021bb294;
  do {
    puVar4 = puVar1;
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[7] = 0;
    iVar3 = iVar3 + -1;
    puVar1 = puVar4 + 8;
  } while (iVar3 != 0);
  puVar4[8] = 0;
  puVar4[9] = 0;
  FUN_021bb03c();
  func_0x0200df68(DAT_021bb280);
  *DAT_021bb298 = 1;
  return 1;
}

