/* Decompiled C draft; module arm9; ROM address 0212ba74. No matching claim. */
#include "types.h"
#include "deps/0212ba74_NNS_SndMain.h"

void NNS_SndMain(void)

{
  int iVar1;
  
  do {
    iVar1 = Sound_CommandReceiveAndReply(0);
  } while (iVar1 != 0);
  NNSi_SndPlayerMain();
  NNSi_SndCaptureMain();
  NNSi_SndArcStrmMain();
  Sound_FlushCommand(0);
  return;
}

