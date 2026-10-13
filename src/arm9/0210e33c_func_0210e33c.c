/* Decompiled C draft; module arm9; ROM address 0210e33c. No matching claim. */
#include "types.h"
#include "deps/0210e33c_func_0210e33c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 func_0210e33c(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 != 0xff) &&
     (iVar1 = CheckMaybeLoadSseqOk
                        (param_2,*(uint *)(uRam0210e3e8 & 0xfffffffc) >> (uRam0210e3e8 & 3) * 8 |
                                 *(uint *)(uRam0210e3e8 & 0xfffffffc) <<
                                 (uRam0210e3e8 & 3) * -8 + 0x20), iVar1 == 0)) {
    return 0;
  }
  if ((param_3 != 0xff) &&
     (iVar1 = Sound_LoadSbnk(param_3,*(uint *)(uRam0210e3e8 & 0xfffffffc) >> (uRam0210e3e8 & 3) * 8
                                     | *(uint *)(uRam0210e3e8 & 0xfffffffc) <<
                                       (uRam0210e3e8 & 3) * -8 + 0x20), iVar1 == 0)) {
    return 0;
  }
  if ((param_4 != 0xff) &&
     (iVar1 = Sound_LoadSbnk(param_4,*(uint *)(uRam0210e3e8 & 0xfffffffc) >> (uRam0210e3e8 & 3) * 8
                                     | *(uint *)(uRam0210e3e8 & 0xfffffffc) <<
                                       (uRam0210e3e8 & 3) * -8 + 0x20), iVar1 == 0)) {
    return 0;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  return 1;
}

