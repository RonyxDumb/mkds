/* Decompiled C draft; module arm9_ov000; ROM address 0219d2e8. No matching claim. */
#include "types.h"
#include "deps/0219d2e8_FUN_0219d2e8.h"

void FUN_0219d2e8(int param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_248;
  int local_244;
  undefined1 auStack_240 [24];
  int local_228 [133];
  
  if (*(char *)(*DAT_0219d470 + 0x1e) == '\0') {
    FUN_0218ed44((int *)(uintptr_t)(*(undefined4 *)(*DAT_0219d470 + 4)),&local_248);
    FUN_0219d034();
    local_244 = 0;
    if (0 < local_248) {
      do {
        FUN_0218ec44((int *)(uintptr_t)(*(undefined4 *)(*DAT_0219d470 + 4)),local_244,local_228);
        FUN_0219d034();
        iVar5 = 0;
        if (0 < param_2) {
          do {
            iVar3 = FUN_0219d630(iVar5);
            if (local_228[0] == iVar3) {
              iVar3 = func_0x02152a24(param_1 + iVar5 * 0xc);
              if (iVar3 == 0) {
                iVar3 = param_1 + iVar5 * 0xc;
                func_0x02152468(iVar3,local_228[0]);
                func_0x021529bc(iVar3);
                *(undefined1 *)(*DAT_0219d470 + 0x1d) = 1;
              }
              break;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < param_2);
        }
        if (iVar5 == param_2) {
          FUN_0218eb44(*(undefined4 *)(*DAT_0219d470 + 4),local_228[0]);
          FUN_0219d034();
          local_248 = local_248 + -1;
          local_244 = local_244 + -1;
        }
        local_244 = local_244 + 1;
      } while (local_244 < local_248);
    }
    *(undefined1 *)(*DAT_0219d470 + 0x1e) = 1;
  }
  piVar2 = DAT_0219d470;
  bVar1 = *(byte *)(*DAT_0219d470 + 0x1c);
  do {
    if (param_2 <= (int)(uint)bVar1) {
      return;
    }
    iVar5 = FUN_0219d630();
    if (iVar5 == 0) {
      uVar4 = FUN_0219c9c4();
      iVar5 = func_0x02152520(uVar4,param_1 + (uint)*(byte *)(*piVar2 + 0x1c) * 0xc);
      if (iVar5 == -1) {
        uVar4 = FUN_0219c9c4();
        func_0x02152458(uVar4,param_1 + (uint)*(byte *)(*DAT_0219d470 + 0x1c) * 0xc,auStack_240);
        FUN_0218f0a8(*(undefined4 *)(*DAT_0219d470 + 4),0,0,0,0,auStack_240,0,0,DAT_0219d474,
                     *(undefined1 *)(*DAT_0219d470 + 0x1c));
        *(undefined1 *)(*DAT_0219d470 + 0x1e) = 2;
        return;
      }
    }
    else {
      iVar3 = FUN_0219d210(param_1,*(undefined1 *)(*piVar2 + 0x1c),iVar5);
      if ((iVar3 == 0) &&
         (iVar3 = func_0x02152a24(param_1 + (uint)*(byte *)(*piVar2 + 0x1c) * 0xc), iVar3 == 0)) {
        FUN_0218ebe8((int *)(uintptr_t)(*(undefined4 *)(*piVar2 + 4)),iVar5,&local_244);
        FUN_0219d034();
        if (local_244 == -1) {
          FUN_0219d128(iVar5);
        }
      }
    }
    *(char *)(*piVar2 + 0x1c) = *(char *)(*piVar2 + 0x1c) + '\x01';
    bVar1 = *(byte *)(*piVar2 + 0x1c);
  } while( true );
}

