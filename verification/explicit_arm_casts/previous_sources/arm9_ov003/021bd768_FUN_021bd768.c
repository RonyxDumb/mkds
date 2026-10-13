/* Decompiled C draft; module arm9_ov003; ROM address 021bd768. No matching claim. */
#include "types.h"
#include "deps/021bd768_FUN_021bd768.h"

undefined4 FUN_021bd768(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  byte local_58;
  byte local_57;
  byte local_56;
  byte local_55;
  byte local_54;
  byte local_53;
  byte local_52;
  byte local_51;
  byte local_50;
  byte local_4f;
  byte local_4e;
  byte local_4d;
  undefined1 auStack_4c [32];
  undefined1 auStack_2c [36];
  
  pbVar1 = DAT_021bd874;
  param_1[0xc] = *DAT_021bd874;
  param_1[0xd] = pbVar1[1];
  param_1[0xe] = pbVar1[2];
  param_1[0xf] = pbVar1[3];
  local_57 = DAT_021bd878[1];
  local_56 = DAT_021bd878[2];
  local_55 = DAT_021bd878[3];
  local_54 = DAT_021bd878[4];
  local_53 = DAT_021bd878[5];
  local_58 = *DAT_021bd878 & 0xfd;
  FUN_021bd884(&local_52);
  pbVar1 = DAT_021bd87c;
  *DAT_021bd87c = local_52;
  pbVar1[1] = local_51;
  pbVar1[2] = local_50;
  pbVar1[3] = local_4f;
  pbVar1[4] = local_4e;
  pbVar1[5] = local_4d;
  iVar2 = func_0x02134d30(&local_58,&local_52,6);
  if (iVar2 < 1) {
    *param_1 = local_52;
    param_1[1] = local_51;
    param_1[2] = local_50;
    param_1[3] = local_4f;
    param_1[4] = local_4e;
    param_1[5] = local_4d;
    param_1[6] = local_58;
    param_1[7] = local_57;
    param_1[8] = local_56;
    param_1[9] = local_55;
    param_1[10] = local_54;
    param_1[0xb] = local_53;
  }
  else {
    *param_1 = local_58;
    param_1[1] = local_57;
    param_1[2] = local_56;
    param_1[3] = local_55;
    param_1[4] = local_54;
    param_1[5] = local_53;
    param_1[6] = local_52;
    param_1[7] = local_51;
    param_1[8] = local_50;
    param_1[9] = local_4f;
    param_1[10] = local_4e;
    param_1[0xb] = local_4d;
  }
  if (*DAT_021bd880 != 0) {
    FUN_021bb29c(auStack_4c,&local_52);
    FUN_021bb29c(auStack_2c,&local_58);
  }
  return 1;
}

