/* Decompiled C draft; module arm9_ov000; ROM address 021969d8. No matching claim. */
#include "types.h"
#include "deps/021969d8_FUN_021969d8.h"

void FUN_021969d8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  code *pcVar3;
  
  if ((-1 < param_1) && (iVar1 = FUN_0218dc44((undefined4 *)(uintptr_t)(*DAT_02196a80)), param_1 < iVar1)) {
    puVar2 = (undefined4 *)FUN_0218dbf8((int *)(uintptr_t)(*DAT_02196a80),param_1);
    pcVar3 = (code *)puVar2[6];
    if (pcVar3 != (code *)0x0) {
      switch(*puVar2) {
      case 0:
        (*pcVar3)(puVar2[1],puVar2[2],param_2,param_4,puVar2[5]);
        break;
      case 1:
        (*pcVar3)(puVar2[1],puVar2[2],puVar2[3],puVar2[4],param_2,param_3,param_4,param_5,puVar2[5])
        ;
        break;
      case 2:
        (*pcVar3)(puVar2[1],puVar2[2],puVar2[3],puVar2[4],param_2,param_3,puVar2[5]);
        break;
      case 3:
        (*pcVar3)(puVar2[1],puVar2[2],param_2,puVar2[5]);
      }
    }
    FUN_0218da5c((int *)(uintptr_t)(*DAT_02196a80),param_1);
  }
  return;
}

