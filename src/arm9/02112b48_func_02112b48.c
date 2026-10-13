/* Decompiled C draft; module arm9; ROM address 02112b48. No matching claim. */
#include "types.h"
#include "deps/02112b48_func_02112b48.h"

void func_02112b48(void)

{
  if (*(int *)(*piRam02112ba4 + 0x90) == 4) {
    func_021113fc((int)*(short *)(*piRam02112ba4 + 0x6a));
    func_021113f0((int)*(short *)(*piRam02112ba4 + 0x68));
  }
  else {
    func_021113fc(0);
    func_021113f0(0);
    *puRam02112ba8 =
         *puRam02112ba8 & uRam02112bb0 | ((*puRam02112ba8 & uRam02112bac) >> 8 & 0xffffffec) << 8;
  }
  *piRam02112ba4 = 0;
  return;
}

