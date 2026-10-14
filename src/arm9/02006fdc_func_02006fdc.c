/* Verified local Thumb bytes. Global caller ABI and full ROM remain unverified. */
unsigned int func_02006fdc(int value) { int i; i=0; do { if ((value >> i)&1) return i; i++; } while (i<16); return -1; }
