/* Decompiled C draft; module arm9_ov000; ROM address 0219e8fc. No matching claim. */
#include "types.h"
#include "deps/0219e8fc_FUN_0219e8fc.h"

uint FUN_0219e8fc(int param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  if (param_1 == 0) {
    iVar2 = 1;
    iVar4 = *DAT_0219e93c;
    pbVar1 = (byte *)(iVar4 + 0xd);
    if (*pbVar1 != 0) {
      do {
        iVar4 = iVar4 + 1;
        uVar3 = uVar3 | 1 << *(sbyte *)(iVar4 + DAT_0219e944);
        iVar2 = iVar2 + 1;
      } while (iVar2 <= (int)(uint)*pbVar1);
    }
    return uVar3;
  }
  return *(uint *)(*DAT_0219e93c + DAT_0219e940) & 0xfffffffe;
}

