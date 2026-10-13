/* Decompiled C draft; module arm9; ROM address 0205ec14. No matching claim. */
#include "types.h"
#include "deps/0205ec14_func_0205ec14.h"

void func_0205ec14(char *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *(uint *)(uRam0205ec9c & 0xfffffffc) >> (uRam0205ec9c & 3) * 8 |
          *(uint *)(uRam0205ec9c & 0xfffffffc) << (uRam0205ec9c & 3) * -8 + 0x20;
  uVar5 = (int)((longlong)iRam0205eca0 * (longlong)param_2 >> 0x21) - (param_2 >> 0x1f);
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar3 = uVar5 & 0xff;
  iVar2 = func_0205743c(uVar3,(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x2e,2);
  if (iVar2 == 0) {
    *param_1 = -1;
    return;
  }
  if (uVar3 != (int)*param_1) {
    ReadSaveDataSection_NKFE_from_thumb(param_1 + 4,uVar3);
    *param_1 = (char)uVar5;
    return;
  }
  return;
}

