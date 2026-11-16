#pragma once

#include "types.h"

void CPSi_rc4_crypt(u8 *context, u8 *data, s32 length);
void CPSi_rc4_init(u8 *context, const u8 *key, s32 keyLength);
void CPSi_char_from_big(u8 *bytes, const u16 *digits, s32 byteCount, s32 digitCount);
void CPSi_big_from_char(u16 *digits, const u8 *bytes, s32 byteCount, s32 digitCount);
void CPSi_big_montpower(u16 *result, u16 *base, u16 *exponent, s32 digitCount, u16 *modulus);
void CPSi_big_montmult(u16 *accumulator, u16 *savedCopy, u16 *multiplier, s32 digitCount, s32 modulusDigits,
                       u16 *modulus, u16 *modulusPrime, u16 *reduceFactor, u16 *reduceProduct);
void CPSi_big_modinv(u16 *inverse, u16 *value, u16 *modulus, s32 digitCount, u16 *work);
void CPSi_big_power(u16 *result, u16 *base, u16 *exponent, s32 digitCount, u16 *modulus);
void CPSi_big_div(u16 *quotient, u16 *dividend, u16 *divisor, u16 *remainder, s32 digitCount, u16 *work);
void CPSi_big_sqr(u16 *result, const u16 *value, s32 digitCount);
void CPSi_big_mult_small(u16 *result, const u16 *value, u16 factor, s32 digitCount);
