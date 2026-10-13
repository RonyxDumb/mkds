/* Decompiled C draft; module arm9; ROM address 021156d4. No matching claim. */
#include "types.h"
#include "deps/021156d4_func_021156d4.h"

void func_021156d4(void)

{
  func_021113fc((int)*(short *)(*piRam02115718 + 0x76));
  func_021113f0((int)*(short *)(*piRam02115718 + 0x74));
  *piRam02115718 = 0;
  *puRam0211571c =
       *puRam0211571c & uRam02115724 | ((*puRam0211571c & uRam02115720) >> 8 & 0xfffffff6) << 8;
  return;
}

