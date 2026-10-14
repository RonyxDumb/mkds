/* Decompiled C draft; module arm9; ROM address 0212c018. No matching claim. */
#include "types.h"
#include "deps/0212c018_NNSi_SndPlayerStopSeq.h"

void NNSi_SndPlayerStopSeq(int param_1,int param_2)

{
  if (param_1 == 0) {
    return;
  }
  if (*(char *)(param_1 + 0x2c) != '\0') {
    if (param_2 != 0) {
      func_0212f834(param_1 + 0x1c,0);
      func_0212bcac(param_1,0);
      *(undefined1 *)(param_1 + 0x2c) = 2;
      return;
    }
    func_0212be78();
    return;
  }
  return;
}

