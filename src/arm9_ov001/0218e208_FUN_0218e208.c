/* Decompiled C draft; module arm9_ov001; ROM address 0218e208. No matching claim. */
#include "types.h"
#include "deps/0218e208_FUN_0218e208.h"

void FUN_0218e208(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    iVar4 = 0;
    for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(param_1 + 1); iVar3 = iVar3 + 1) {
      iVar2 = *(int *)(*param_1 + iVar4);
      if (iVar2 == 0) break;
      iVar1 = func_0x02062ec4();
      if (iVar1 == 0) {
        FUN_0218e520(iVar2);
      }
      else {
        FUN_0218e4ac(iVar2);
      }
      if (*(int *)(*DAT_0218e280 + 8) == 4) {
        iVar2 = *(int *)(iVar2 + 0xa0);
        func_ov001_02181844(*(uint *)(iVar2 + DAT_0218e284) & 0xffff,
                            *(uint *)(iVar2 + DAT_0218e288) & 0xffff,
                            *(uint *)(iVar2 + DAT_0218e28c) & 0xffff,
                            *(uint *)(iVar2 + DAT_0218e290) & 0xffff);
      }
      iVar4 = iVar4 + 4;
    }
  }
  func_0x020a2314(DAT_0218e294);
  return;
}

