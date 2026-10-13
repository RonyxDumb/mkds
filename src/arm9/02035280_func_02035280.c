/* Decompiled C draft; module arm9; ROM address 02035280. No matching claim. */
#include "types.h"
#include "deps/02035280_func_02035280.h"

void func_02035280(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = false;
  iVar3 = *piRam020352f4;
  iVar4 = *(int *)(iVar3 + 0x80) + 1;
  if (3 < iVar4) {
    if (param_1 == 0) {
      return;
    }
    iVar4 = 0;
  }
  if (iVar4 != *(int *)(iVar3 + 0x80)) {
    do {
      iVar2 = iVar3 + iVar4 * 0x3c;
      if ((*(int *)(iVar2 + 0xc4) == 1) && (*(int *)(iVar2 + 200) == 1)) {
        bVar1 = true;
        *(int *)(iVar3 + 0x80) = iVar4;
        break;
      }
      iVar4 = iVar4 + 1;
      if (3 < iVar4) {
        if (param_1 == 0) {
          return;
        }
        iVar4 = 0;
      }
    } while (iVar4 != *(int *)(iVar3 + 0x80));
  }
  if (bVar1) {
    NNSi_MaybeSndPlayerStartSeq(uRam020352f8,0,0);
  }
  return;
}

