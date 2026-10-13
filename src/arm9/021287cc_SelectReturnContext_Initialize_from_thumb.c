/* Decompiled C draft; module arm9; ROM address 021287cc. No matching claim. */
#include "types.h"
#include "deps/021287cc_SelectReturnContext_Initialize_from_thumb.h"

undefined4 SelectReturnContext_Initialize_from_thumb(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = Mem_AllocateHeap(param_1,uRam02128858);
  *piRam0212885c = iVar2;
  if (*psRam02128860 == 2) {
    *(undefined4 *)(iVar2 + iRam02128864) = 0;
    *puRam02128868 =
         *puRam02128868 & uRam02128870 | ((*puRam02128868 & uRam0212886c) >> 8 & 0xfffffffb) << 8;
  }
  else {
    func_02128778();
    param_2 = LoadSelectReturnGraphics_from_thumb(param_2);
    *(undefined4 *)(*piRam0212885c + iRam02128864) = 1;
  }
  piVar1 = piRam0212885c;
  *(undefined4 *)*piRam0212885c = 1;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + iRam02128874) = 0;
  *(undefined4 *)(*piVar1 + iRam02128878) = 0;
  *(undefined4 *)(*piVar1 + iRam0212887c) = 0xffffffd8;
  *(undefined4 *)(*piVar1 + iRam02128880) = 0xe;
  return param_2;
}

