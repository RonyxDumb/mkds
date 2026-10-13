/* Decompiled C draft; module arm9; ROM address 0203b3d8. No matching claim. */
#include "types.h"
#include "deps/0203b3d8_StructCP_IsBBetterThanA.h"

bool StructCP_IsBBetterThanA(ushort *param_1,ushort *param_2)

{
  byte bVar1;
  
  bVar1 = (byte)param_2[0xe];
  if (bVar1 == 3) {
    return false;
  }
  if ((char)param_1[0xc] == '\0') {
    return true;
  }
  if (bVar1 < (byte)param_1[0xe]) {
    return true;
  }
  if ((byte)param_1[0xe] < bVar1) {
    return false;
  }
  if ((byte)param_1[0xf] < (byte)param_2[0xf]) {
    return true;
  }
  if ((byte)param_2[0xf] < (byte)param_1[0xf]) {
    return false;
  }
  if (*(byte *)((int)param_1 + 0x1d) < *(byte *)((int)param_2 + 0x1d)) {
    return true;
  }
  if (*(byte *)((int)param_1 + 0x1d) <= *(byte *)((int)param_2 + 0x1d)) {
    return (int)((uint)*param_2 +
                (uint)*(byte *)((int)param_2 + 3) * 1000 + (uint)(byte)param_2[1] * iRam0203b4c4) <
           (int)((uint)*param_1 +
                (uint)*(byte *)((int)param_1 + 3) * 1000 + (uint)(byte)param_1[1] * iRam0203b4c4);
  }
  return false;
}

