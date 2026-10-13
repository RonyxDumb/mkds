/* Decompiled C draft; module arm9_ov000; ROM address 0218ccbc. No matching claim. */
#include "types.h"
#include "deps/0218ccbc_FUN_0218ccbc.h"

void FUN_0218ccbc(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  char extraout_r1;
  char extraout_r1_00;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = func_0x021384dc();
  func_0x02133068(uVar1,0x5d);
  *(char *)(param_1 + 0x74) = extraout_r1 + '!';
  uVar6 = 0;
  uVar5 = 1;
  do {
    uVar2 = (uint)*(char *)(param_1 + uVar5 + 0x73);
    uVar3 = (uint)*(char *)(param_1 + 0x74);
    uVar6 = uVar3 & 1 ^ uVar6 ^ (uVar5 ^ uVar2) & 1 ^ (uint)((int)uVar3 < 0x4f) ^
            (uint)((int)uVar2 < (int)uVar3);
    iVar4 = param_1 + uVar5;
    uVar1 = func_0x021384dc();
    func_0x02133068(uVar1,0x5d);
    *(char *)(iVar4 + 0x74) = extraout_r1_00 + '!';
    if (((uVar6 != 0) && ((*(byte *)(iVar4 + 0x74) & 1) == 0)) ||
       ((uVar6 == 0 && ((*(byte *)(iVar4 + 0x74) & 1) == 1)))) {
      *(char *)(iVar4 + 0x74) = *(char *)(iVar4 + 0x74) + '\x01';
    }
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 8);
  return;
}

