
/*
 *  RISC-V "ZCE" extension proposal intrinsics and emulation
 *
 *  Copyright (C) 2021  Liao Shihua <shihua@iscas.ac.cn>
 *
 *  Permission to use, copy, modify, and/or distribute this software for any
 *  purpose with or without fee is hereby granted, provided that the above
 *  copyright notice and this permission notice appear in all copies.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 *  ----------------------------------------------------------------------
 *
 *  Define RVINTRIN_EMULATE to enable emulation mode.
 *
 *  This header defines C inline functions with "mockup intrinsics" for
 *  RISC-V "B" extension proposal instructions.
 *
 *  _rv_*(...)
 *    RV32/64 intrinsics that operate on the "long" data type
 *
 *  _rv32_*(...)
 *    RV32/64 intrinsics that operate on the "int32_t" data type
 *
 *  _rv64_*(...)
 *    RV64-only intrinsics that operate on the "int64_t" data type
 *
 */

#ifndef ZCE_INTRIN_H
#define ZCE_INTRIN_H

#include <limits.h>
#include <stdint.h>

#if !defined(__riscv_xlen) && !defined(RVINTRIN_EMULATE)
#warning "Target is not RISC-V. Enabling <zceintrin.h> emulation mode."
#define RVINTRIN_EMULATE 1
#endif

#ifndef RVINTRIN_EMULATE

#if __riscv_xlen == 32
#define RVINTRIN_RV32
#endif

#if __riscv_xlen == 64
#define RVINTRIN_RV64
#endif

#ifdef RVINTRIN_RV32
static inline int32_t _rv32_sext_b(int32_t rs1) { int32_t rd; __asm__ ("sext.b  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }
static inline int32_t _rv32_sext_h(int32_t rs1) { int32_t rd; __asm__ ("sext.h  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }
static inline int32_t _rv32_zext_b(int32_t rs1) { int32_t rd; __asm__ ("zext.b  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }
static inline int32_t _rv32_zext_h(int32_t rs1) { int32_t rd; __asm__ ("zext.h  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }
#endif

#ifdef RVINTRIN_RV64
static inline int32_t _rv32_sext_b(int32_t rs1) { int32_t rd; __asm__ ("sext.b  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }
static inline int32_t _rv32_sext_h(int32_t rs1) { int32_t rd; __asm__ ("sext.h  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }
static inline int32_t _rv32_zext_b(int32_t rs1) { int32_t rd; __asm__ ("zext.b  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }
static inline int32_t _rv32_zext_h(int32_t rs1) { int32_t rd; __asm__ ("zext.h  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }

static inline int64_t _rv64_sext_b(int64_t rs1) { int64_t rd; __asm__ ("sext.b  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }
static inline int64_t _rv64_sext_h(int64_t rs1) { int64_t rd; __asm__ ("sext.h  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }
static inline int64_t _rv64_zext_b(int64_t rs1) { int64_t rd; __asm__ ("zext.b  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }
static inline int64_t _rv64_zext_h(int64_t rs1) { int64_t rd; __asm__ ("zext.h  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }

static inline int64_t _rv64_sext_w(int64_t rs1) { int64_t rd; __asm__ ("sext.w  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }
static inline int64_t _rv64_zext_w(int64_t rs1) { int64_t rd; __asm__ ("zext.w  %0, %1" : "=r"(rd) : "r"(rs1)); return rd; }
#endif

static inline int32_t _rv32_sext_b(int32_t rs1) { return rs1 << (32-8) >> (32-8); }
static inline int64_t _rv64_sext_b(int64_t rs1) { return rs1 << (64-8) >> (64-8); }

static inline int32_t _rv32_sext_h(int32_t rs1) { return rs1 << (32-16) >> (32-16); }
static inline int64_t _rv64_sext_h(int64_t rs1) { return rs1 << (64-16) >> (64-16); }

static inline int32_t _rv32_zext_b(int32_t rs1) { return (uint32_t)rs1 << (32-8) >> (32-8); }
static inline int64_t _rv64_zext_b(int64_t rs1) { return (uint64_t)rs1 << (64-8) >> (64-8); }

static inline int32_t _rv32_zext_h(int32_t rs1) { return (uint32_t)rs1 << (32-16) >> (32-16); }
static inline int64_t _rv64_zext_h(int64_t rs1) { return (uint64_t)rs1 << (64-16) >> (64-16); }

static inline int64_t _rv64_sext_w(int64_t rs1) { return rs1 << (64-32) >> (64-32);}
static inline int64_t _rv64_zext_w(int64_t rs1) { return (uint64_t)rs1 << (64-32) >> (64-32);}
#endif //ZCEINTRIN_EMULATE

#ifdef RVINTRIN_RV32
static inline long _rv_sext_b (long rs1) { return _rv32_sext_b(rs1); }
static inline long _rv_sext_h (long rs1) { return _rv32_sext_h(rs1); }

static inline long _rv_zext_b (long rs1) { return _rv32_sext_b(rs1); }
static inline long _rv_zext_h (long rs1) { return _rv32_sext_h(rs1); }

#endif

#ifdef RVINTRIN_RV64
static inline long _rv_sext_b (long rs1) { return _rv64_sext_b(rs1); }
static inline long _rv_sext_h (long rs1) { return _rv64_sext_h(rs1); }
static inline long _rv_sext_w (long rs1) { return _rv64_sext_w(rs1); }

static inline long _rv_zext_b (long rs1) { return _rv64_sext_b(rs1); }
static inline long _rv_zext_h (long rs1) { return _rv64_sext_h(rs1); }
static inline long _rv_zext_w (long rs1) { return _rv64_zext_w(rs1); }
#endif

#endif // !ZCE_INTRIN_H