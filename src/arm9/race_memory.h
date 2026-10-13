/* Read primitives: naturally aligned DS RAM loads. Test harness may override. */
#pragma once
#include <stdint.h>
#ifndef MKDS_READ8
#define MKDS_READ8(a) (*(const uint8_t *)(uintptr_t)(a))
#endif
#ifndef MKDS_READ16
#define MKDS_READ16(a) (*(const uint16_t *)(uintptr_t)(a))
#endif
#ifndef MKDS_READ32
#define MKDS_READ32(a) (*(const uint32_t *)(uintptr_t)(a))
#endif
