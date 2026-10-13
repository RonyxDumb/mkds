/* Decompiled C draft; module arm9_ov000; ROM address 02189030. No matching claim. */
#include "types.h"
#include "deps/02189030_FUN_02189030.h"

undefined4 FUN_02189030(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  undefined8 uVar8;
  
  iVar3 = FUN_021a5bfc();
  iVar7 = param_1 + DAT_02189110;
  bVar1 = *(byte *)(param_1 + data_ov000_02189114);
  if (iVar3 == 3) {
    uVar4 = FUN_02188ec0(param_1);
    pbVar6 = (byte *)(param_1 + DAT_02189118);
    *pbVar6 = *pbVar6 + 1;
    if (3 < *pbVar6) {
      *pbVar6 = 0;
      *(undefined1 *)(param_1 + (uint)*(byte *)(param_1 + data_ov000_02189114) * 4 + DAT_0218911c) =
           1;
      return 9;
    }
    if (*pbVar6 != 1) {
      cVar2 = *(char *)(param_1 + DAT_02189120);
      if (cVar2 == '\x01') {
        *(byte *)(param_1 + DAT_02189124) = *(byte *)(param_1 + DAT_02189124) & 0xf3;
      }
      else {
        if (cVar2 == '\x02') {
          *pbVar6 = 0;
          *(undefined1 *)
           (param_1 + (uint)*(byte *)(param_1 + data_ov000_02189114) * 4 + DAT_0218911c) = 3;
          return 9;
        }
        if (cVar2 == '\x03') {
          *pbVar6 = 0;
          *(undefined1 *)
           (param_1 + (uint)*(byte *)(param_1 + data_ov000_02189114) * 4 + DAT_0218911c) = 4;
          return 9;
        }
      }
    }
    uVar5 = FUN_02188ea0(param_1);
    FUN_021a5e84(iVar7 + (uint)bVar1 * 0xc0,param_1 + data_ov000_02189128,uVar4 | uVar5);
  }
  else if (iVar3 == 9) {
    *(undefined1 *)(param_1 + DAT_02189118) = 0;
    uVar8 = func_0x0200f5ac();
    *(int *)(param_1 + DAT_0218912c) = (int)uVar8;
    *(int *)(param_1 + DAT_02189130) = (int)((ulonglong)uVar8 >> 0x20);
    return 10;
  }
  return 8;
}

