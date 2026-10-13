/* Decompiled C draft; module arm9_ov003; ROM address 021cf260. No matching claim. */
#include "types.h"
#include "deps/021cf260_FUN_021cf260.h"

int FUN_021cf260(uint param_1)

{
  if (((uint)*(ushort *)(*DAT_021cf280 + 2) & 1 << (param_1 & 0xff)) != 0) {
    return *DAT_021cf280 + 0xe + (param_1 - 1) * 0x1e;
  }
  return 0;
}

