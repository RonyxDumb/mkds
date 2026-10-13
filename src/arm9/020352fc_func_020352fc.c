/* Decompiled C draft; module arm9; ROM address 020352fc. No matching claim. */
#include "types.h"
#include "deps/020352fc_func_020352fc.h"

void func_020352fc(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = false;
  iVar3 = *piRam02035370;
  iVar4 = *(int *)(iVar3 + 0x80) + -1;
  if (iVar4 < 0) {
    if (param_1 == 0) {
      return;
    }
    iVar4 = 3;
  }
  if (iVar4 != *(int *)(iVar3 + 0x80)) {
    do {
      iVar2 = iVar3 + iVar4 * 0x3c;
      if ((*(int *)(iVar2 + 0xc4) == 1) && (*(int *)(iVar2 + 200) == 1)) {
        bVar1 = true;
        *(int *)(iVar3 + 0x80) = iVar4;
        break;
      }
      iVar4 = iVar4 + -1;
      if (iVar4 < 0) {
        if (param_1 == 0) {
          return;
        }
        iVar4 = 3;
      }
    } while (iVar4 != *(int *)(iVar3 + 0x80));
  }
  if (bVar1) {
    NNSi_MaybeSndPlayerStartSeq(uRam02035374,0,0);
  }
  return;
}

