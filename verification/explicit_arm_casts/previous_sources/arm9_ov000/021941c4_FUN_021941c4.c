/* Decompiled C draft; module arm9_ov000; ROM address 021941c4. No matching claim. */
#include "types.h"
#include "deps/021941c4_FUN_021941c4.h"

int FUN_021941c4(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  
  iVar3 = *param_1;
  if ((param_2[0xc] != 0) &&
     ((iVar1 = FUN_021906e4(param_1,param_2[2],param_2 + 10,&local_2c,1,DAT_02194358), local_2c != 0
      || (iVar1 != 0)))) {
    *param_2 = 0x6a;
    return 0;
  }
  if (param_2[0xc] == 0) {
    iVar1 = FUN_02194370(param_1,param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*param_2 == 0x6a) {
      return 0;
    }
  }
  iVar1 = FUN_021907e8(param_1,param_2[2],param_2 + 6,&local_30,&local_2c,DAT_02194358);
  if (iVar1 != 0) {
    *param_2 = 0x6a;
    return 0;
  }
  if (0 < local_30) {
    iVar1 = FUN_0218e320(0);
    param_2[4] = iVar1 + DAT_0219435c;
  }
  do {
    iVar1 = FUN_02190618(param_1,param_2 + 6,&local_20,&local_1c,&local_18);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (local_20 != 0) {
      if (local_1c < 0x67) {
        if (local_1c < 0x66) {
          if (local_1c == 1) {
            local_28 = *(int *)(iVar3 + DAT_02194360);
            local_24 = *(undefined4 *)(iVar3 + DAT_02194364);
            if (local_28 != 0) {
              piVar2 = (int *)FUN_021a3690(0xc);
              if (piVar2 == (int *)0x0) {
                FUN_02196590(param_1,DAT_02194368);
                return 1;
              }
              *piVar2 = param_2[3];
              iVar1 = FUN_0218e880(local_20);
              piVar2[2] = iVar1;
              iVar1 = FUN_0218e320(0);
              piVar2[1] = iVar1;
              iVar1 = FUN_02190ed4(param_1,local_28,local_24,piVar2,0,2);
              if (iVar1 != 0) {
                return iVar1;
              }
            }
          }
        }
        else {
          FUN_0218fb3c(param_1,param_2[3],0x67,DAT_0219436c);
        }
      }
      else {
        switch(local_1c) {
        case 200:
        case 0xc9:
        case 0xca:
        case 0xcb:
        case 0xcc:
        case 0xcd:
        case 0xce:
        case 0xcf:
        case 0xd0:
          FUN_02196434(param_1,param_2,local_1c,param_2[6],local_20,local_18);
        }
      }
      FUN_021905d4(param_1,param_2 + 6);
    }
    if (local_20 == 0) {
      if (local_2c != 0) {
        *param_2 = 0x6a;
      }
      return 0;
    }
  } while( true );
}

