/* Decompiled C draft; module arm9_ov000; ROM address 0218ca58. No matching claim. */
#include "types.h"
#include "deps/0218ca58_FUN_0218ca58.h"

int FUN_0218ca58(int *param_1,int param_2,int param_3,uint param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  undefined1 local_320;
  byte bStack_31f;
  uint local_31c;
  undefined1 *local_318;
  undefined1 local_314;
  byte local_313;
  undefined1 auStack_312 [766];
  
  if (*param_1 != 1) {
    func_0x0213442c(DAT_0218cc10,DAT_0218cc14,0,DAT_0218cc18);
  }
  if (param_2 == 0) {
    param_2 = DAT_0218cc1c;
  }
  if (param_3 == 0) {
    param_3 = DAT_0218cc1c;
  }
  uVar1 = func_0x0213a434(param_2);
  if (uVar1 <= DAT_0218cc20) {
    uVar1 = func_0x0213a434(param_3);
    if (DAT_0218cc20 < uVar1) {
      return 6;
    }
    iVar2 = FUN_0218ce14((int)(uintptr_t)(param_1));
    if (iVar2 == 0) {
      *(uint *)((int)param_1 + DAT_0218cc24) = param_4;
      FUN_0218ccbc((int)(uintptr_t)(param_1));
      local_31c = 2;
      local_318 = auStack_312;
      FUN_0218cdc4((int *)(void *)(&local_318),0,&local_31c);
      FUN_0218cdc4((int *)(void *)(&local_318),1,&local_31c);
      FUN_0218cdc4((int *)(void *)(&local_318),3,&local_31c);
      FUN_0218cd94((int *)(void *)(&local_318),*(undefined4 *)((int)param_1 + DAT_0218cc28),&local_31c);
      FUN_0218cdd8((int *)(void *)(&local_318),(int)(uintptr_t)(param_1 + 3),&local_31c);
      FUN_0218cdd8((int *)(void *)(&local_318),(int)(uintptr_t)(param_1 + 0xc),&local_31c);
      FUN_0218cd74((int *)(void *)(&local_318),(undefined4)(uintptr_t)(param_1 + 0x1d),8,&local_31c);
      FUN_0218cdd8((int *)(void *)(&local_318),param_3,&local_31c);
      FUN_0218cdd8((int *)(void *)(&local_318),param_2,&local_31c);
      FUN_0218cd94((int *)(void *)(&local_318),
                   param_4 << 0x18 & DAT_0218cc2c |
                   param_4 << 8 & DAT_0218cc30 | param_4 >> 0x18 | param_4 >> 8 & DAT_0218cc34,
                   &local_31c);
      if ((*(uint *)((int)param_1 + DAT_0218cc24) & 8) != 0) {
        FUN_0218cd94((int *)(void *)(&local_318),*(undefined4 *)((int)param_1 + DAT_0218cc38),&local_31c);
      }
      if ((*(uint *)((int)param_1 + DAT_0218cc24) & 0x80) != 0) {
        FUN_0218cd94((int *)(void *)(&local_318),param_5,&local_31c);
      }
      bStack_31f = (byte)(local_31c & 0xffff) & (byte)(DAT_0218cc34 >> 8);
      local_320 = (undefined1)((local_31c & 0xffff) >> 8);
      local_314 = local_320;
      local_313 = bStack_31f;
      iVar2 = FUN_0218e420(*(undefined4 *)((int)param_1 + DAT_0218cc3c),&local_314,local_31c,0);
      if (iVar2 < 1) {
        FUN_0218c980(param_1);
        return 3;
      }
      *param_1 = 3;
      *(undefined4 *)((int)param_1 + DAT_0218cc40) = 0;
      if (param_1[0x1f] == 0) {
        iVar2 = FUN_021a3690(DAT_0218cc44);
        param_1[0x1f] = iVar2;
        if (param_1[0x1f] == 0) {
          return 5;
        }
        param_1[0x20] = 0;
      }
      iVar2 = 0;
    }
    return iVar2;
  }
  return 6;
}

