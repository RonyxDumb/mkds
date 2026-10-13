/* Decompiled C draft; module arm9; ROM address 0212e708. No matching claim. */
#include "types.h"
#include "deps/0212e708_NNSi_SndArcLoadSeq.h"

int NNSi_SndArcLoadSeq(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                      int *param_5)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = NNS_SndArcGetSeqInfo();
  if (uVar1 == 0) {
    return 2;
  }
  iVar2 = Sound_GetSbnkPointer(*(undefined2 *)(uVar1 + 4),param_2,param_3,param_4);
  if (iVar2 == 0) {
    if ((param_2 & 1) == 0) {
      iVar2 = Sound_MaybeGetRawFilePointer
                        (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                         *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20);
    }
    else {
      iVar2 = Sound_PrepareSseqData
                        (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                         *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20,param_3,param_4);
      if (iVar2 == 0) {
        return 6;
      }
    }
    if (param_5 != (int *)0x0) {
      *param_5 = iVar2;
    }
    return 0;
  }
  return iVar2;
}

