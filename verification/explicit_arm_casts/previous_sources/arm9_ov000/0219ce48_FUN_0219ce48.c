/* Decompiled C draft; module arm9_ov000; ROM address 0219ce48. No matching claim. */
#include "types.h"
#include "deps/0219ce48_FUN_0219ce48.h"

void FUN_0219ce48(undefined4 param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_1c [2];
  
  if ((*param_2 == 0) && (param_2[1] != 0)) {
    iVar3 = param_3 * 0xc;
    iVar2 = func_0x02152a1c(*(int *)(*DAT_0219cfb4 + 0x18) + iVar3);
    if (iVar2 != 0) {
      if (*(int *)*DAT_0219cfb4 != 1) {
        return;
      }
      *(undefined1 *)(*DAT_0219cfb4 + 0x1d) = 1;
      iVar5 = 0;
      iVar2 = param_2[1];
      if (0 < iVar2) {
        iVar4 = 0;
        do {
          iVar2 = FUN_0219d210(*(undefined4 *)(*DAT_0219cfb4 + 0x18),param_3,
                               *(undefined4 *)(param_2[3] + iVar4));
          piVar1 = DAT_0219cfb4;
          if (iVar2 != 0) {
            *(char *)(*DAT_0219cfb4 + 0x1c) = *(char *)(*DAT_0219cfb4 + 0x1c) + '\x01';
            *(undefined1 *)(*piVar1 + 0x1e) = 1;
            param_2[2] = DAT_0219cfb8;
            return;
          }
          iVar4 = iVar4 + 0xac;
          iVar5 = iVar5 + 1;
          iVar2 = param_2[1];
        } while (iVar5 < iVar2);
      }
      iVar5 = 0;
      if (0 < iVar2) {
        iVar2 = 0;
        do {
          FUN_0218ebe8(param_1,*(undefined4 *)(param_2[3] + iVar2),local_1c);
          FUN_0219d034();
          if (local_1c[0] != -1) {
            func_0x02152468(*(int *)(*DAT_0219cfb4 + 0x18) + iVar3,*(undefined4 *)param_2[3]);
            func_0x021529bc(*(int *)(*DAT_0219cfb4 + 0x18) + iVar3);
            FUN_0219d504(param_3);
            piVar1 = DAT_0219cfb4;
            *(char *)(*DAT_0219cfb4 + 0x1c) = *(char *)(*DAT_0219cfb4 + 0x1c) + '\x01';
            *(undefined1 *)(*piVar1 + 0x1e) = 1;
            param_2[2] = DAT_0219cfb8;
            return;
          }
          FUN_0219d128(*(undefined4 *)(param_2[3] + iVar2));
          iVar2 = iVar2 + 0xac;
          iVar5 = iVar5 + 1;
        } while (iVar5 < param_2[1]);
      }
      piVar1 = DAT_0219cfb4;
      if (param_2[2] == DAT_0219cfbc) {
        return;
      }
      *(char *)(*DAT_0219cfb4 + 0x1c) = *(char *)(*DAT_0219cfb4 + 0x1c) + '\x01';
      *(undefined1 *)(*piVar1 + 0x1e) = 1;
      return;
    }
  }
  if (*param_2 == 0) {
    if ((*(int *)*DAT_0219cfb4 == 1) ||
       (iVar3 = func_0x02152a1c(((int *)*DAT_0219cfb4)[6] + param_3 * 0xc), iVar3 == 0)) {
      piVar1 = DAT_0219cfb4;
      *(char *)(*DAT_0219cfb4 + 0x1c) = *(char *)(*DAT_0219cfb4 + 0x1c) + '\x01';
      *(undefined1 *)(*piVar1 + 0x1e) = 1;
    }
    return;
  }
  FUN_0219d034();
  return;
}

