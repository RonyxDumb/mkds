/* Decompiled C draft; module arm9; ROM address 0214c028. No matching claim. */
#include "types.h"
#include "deps/0214c028_TEQSub_Fn30Impl.h"

void TEQSub_Fn30Impl(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam0214c088 & 0xfffffffc) >> (uRam0214c088 & 3) * 8 |
          *(uint *)(uRam0214c088 & 0xfffffffc) << (uRam0214c088 & 3) * -8 + 0x20;
  if ((uVar1 != 0xffffffff) && (0x1c < param_3)) {
    MI_DmaCopy16(uVar1,param_1,param_2 + iRam0214c08c);
    return;
  }
  CopyMemory16(param_1,param_2 + iRam0214c08c,param_3);
  return;
}

