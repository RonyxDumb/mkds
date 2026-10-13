/* Decompiled C draft; module arm9; ROM address 0210cfbc. No matching claim. */
#include "types.h"
#include "deps/0210cfbc_StructMQRacerEntry_SomeFn_47.h"

void StructMQRacerEntry_SomeFn_47(int param_1,uint param_2,int param_3)

{
  if (param_3 == 1) {
    param_2 = (uint)*(ushort *)(param_1 + 0x34) | 1 << (param_2 & 0xff);
  }
  if (param_3 == 1) {
    *(short *)(param_1 + 0x34) = (short)param_2;
  }
  else {
    *(ushort *)(param_1 + 0x34) = *(ushort *)(param_1 + 0x34) & ~(ushort)(1 << (param_2 & 0xff));
  }
  return;
}

