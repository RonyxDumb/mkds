/* Decompiled C draft; module arm9; ROM address 02152b08. No matching claim. */
#include "types.h"
#include "deps/02152b08_MaybeInitializeDwc_from_thumb.h"

undefined4 MaybeInitializeDwc_from_thumb(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  Os_ReferSymbol(uRam02152b58);
  iVar1 = StructDC_SomeFn_2_from_thumb(param_1);
  iVar2 = func_02151da8();
  bVar3 = iVar2 != 0;
  if (bVar3) {
    StructDC_SomeFn_4_from_thumb(param_1);
  }
  if (iVar1 < 0) {
    if (bVar3) {
      return 2;
    }
    return 3;
  }
  if (bVar3) {
    return 1;
  }
  return 0;
}

