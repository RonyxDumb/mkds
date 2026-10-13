/* Decompiled C draft; module arm9; ROM address 02010d98. No matching claim. */
#include "types.h"
#include "deps/02010d98_Anim_GetNeededBlockSize.h"

uint Anim_GetNeededBlockSize(char *param_1,int param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (cVar1 != 'J') {
    if (cVar1 == 'M') {
      return (uint)*(byte *)(param_2 + 0x18) * 2 + 0x1c & 0xfffffffc;
    }
    if (cVar1 != 'V') {
      return 0;
    }
  }
  return (uint)*(byte *)(param_2 + 0x17) * 2 + 0x1c & 0xfffffffc;
}

