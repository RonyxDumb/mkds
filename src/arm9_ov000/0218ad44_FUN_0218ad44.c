/* Decompiled C draft; module arm9_ov000; ROM address 0218ad44. No matching claim. */
#include "types.h"
#include "deps/0218ad44_FUN_0218ad44.h"

void FUN_0218ad44(int *param_1,int *param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 uStack_118;
  undefined1 local_117;
  undefined2 local_116;
  int local_114;
  undefined1 local_110 [4];
  undefined1 local_10c;
  undefined1 local_10b;
  undefined1 local_10a;
  undefined1 local_109;
  undefined1 local_108 [248];
  
  FUN_0218aedc(param_1 + 2);
  iVar2 = FUN_0218e8c4();
  param_2[7] = iVar2;
  local_117 = 2;
  if ((*(byte *)(param_2 + 5) & 0x20) == 0) {
    if (*param_1 == 1) {
      local_110[0] = 0xfe;
      local_110[1] = 0xfd;
      iVar2 = 0;
      local_110[2] = 0;
      local_110[3] = (undefined1)param_2[7];
      local_10c = *(undefined1 *)((int)param_2 + 0x1d);
      local_10b = *(undefined1 *)((int)param_2 + 0x1e);
      local_10a = *(undefined1 *)((int)param_2 + 0x1f);
      if ((*(byte *)(param_2 + 5) & 4) == 0) {
        local_109 = 0xff;
        local_108[0] = 0xff;
        local_108[1] = 0xff;
        iVar2 = 10;
      }
      else {
        local_109 = (undefined1)param_1[0x10];
        iVar5 = param_1[0x10];
        if (0 < iVar5) {
          do {
            local_108[iVar2] = *(undefined1 *)((int)param_1 + iVar2 + 0x2c);
            iVar2 = iVar2 + 1;
            iVar5 = param_1[0x10];
          } while (iVar2 < iVar5);
        }
        local_108[iVar5] = 0;
        local_108[param_1[0x10] + 1] = 0;
        iVar2 = param_1[0x10] + 10;
      }
    }
    else if ((*(byte *)(param_2 + 5) & 4) == 0) {
      puVar4 = local_110;
      iVar2 = 8;
      puVar3 = DAT_0218ae58;
      do {
        uVar1 = *puVar3;
        puVar3 = puVar3 + 1;
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      iVar2 = 8;
    }
    else {
      puVar4 = local_110;
      iVar2 = 0xd;
      puVar3 = DAT_0218ae54;
      do {
        uVar1 = *puVar3;
        puVar3 = puVar3 + 1;
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      iVar2 = 0xd;
    }
    local_114 = *param_2;
    if ((local_114 == param_1[10]) && ((*(byte *)((int)param_2 + 0x15) & 2) != 0)) {
      local_114 = param_2[2];
      local_116 = (undefined2)param_2[3];
    }
    else {
      local_116 = (undefined2)param_2[1];
    }
    FUN_0218e3e4(param_1[8],local_110,iVar2,0,&uStack_118,8);
  }
  return;
}

