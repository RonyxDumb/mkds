#include "00/code_0219a014.h"

int gti2SNDiff(int serialNumber1, int serialNumber2) {
    return (serialNumber1 - serialNumber2) * 0x10000 >> 0x10;
}
