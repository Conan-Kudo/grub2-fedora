/* compiler-rt.h - prototypes for compiler helpers. */
/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2002,2003,2005,2006,2007,2008,2009,2010-2014  Free Software Foundation, Inc.
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GRUB_COMPILER_RT_HEADER
#define GRUB_COMPILER_RT_HEADER	1

#include <stdarg.h>
#include <grub/types.h>
#include <grub/symbol.h>

#if defined (__arm__)

grub_uint32_t
EXPORT_FUNC (__udivsi3) (grub_uint32_t a, grub_uint32_t b);

grub_uint32_t
EXPORT_FUNC (__umodsi3) (grub_uint32_t a, grub_uint32_t b);

#endif

#if defined (__sparc__) || defined (__powerpc__)
unsigned
EXPORT_FUNC (__ctzdi2) (grub_uint64_t x);
#define NEED_CTZDI2 1
#endif

#if defined (__mips__) || defined (__arm__)
unsigned
EXPORT_FUNC (__ctzsi2) (grub_uint32_t x);
#define NEED_CTZSI2 1
#endif

#ifdef __arm__
grub_uint32_t
EXPORT_FUNC (__aeabi_uidiv) (grub_uint32_t a, grub_uint32_t b);
grub_uint32_t
EXPORT_FUNC (__aeabi_uidivmod) (grub_uint32_t a, grub_uint32_t b);

/* Needed for allowing modules to be compiled as thumb.  */
grub_uint64_t
EXPORT_FUNC (__muldi3) (grub_uint64_t a, grub_uint64_t b);
grub_uint64_t
EXPORT_FUNC (__aeabi_lmul) (grub_uint64_t a, grub_uint64_t b);

#endif

#if defined (__ia64__)

grub_uint64_t
EXPORT_FUNC (__udivdi3) (grub_uint64_t a, grub_uint64_t b);

grub_uint64_t
EXPORT_FUNC (__umoddi3) (grub_uint64_t a, grub_uint64_t b);

#endif


#if defined (__powerpc__)

void EXPORT_FUNC (_restgpr_14_x) (void);
void EXPORT_FUNC (_restgpr_15_x) (void);
void EXPORT_FUNC (_restgpr_16_x) (void);
void EXPORT_FUNC (_restgpr_17_x) (void);
void EXPORT_FUNC (_restgpr_18_x) (void);
void EXPORT_FUNC (_restgpr_19_x) (void);
void EXPORT_FUNC (_restgpr_20_x) (void);
void EXPORT_FUNC (_restgpr_21_x) (void);
void EXPORT_FUNC (_restgpr_22_x) (void);
void EXPORT_FUNC (_restgpr_23_x) (void);
void EXPORT_FUNC (_restgpr_24_x) (void);
void EXPORT_FUNC (_restgpr_25_x) (void);
void EXPORT_FUNC (_restgpr_26_x) (void);
void EXPORT_FUNC (_restgpr_27_x) (void);
void EXPORT_FUNC (_restgpr_28_x) (void);
void EXPORT_FUNC (_restgpr_29_x) (void);
void EXPORT_FUNC (_restgpr_30_x) (void);
void EXPORT_FUNC (_restgpr_31_x) (void);
void EXPORT_FUNC (_savegpr_14) (void);
void EXPORT_FUNC (_savegpr_15) (void);
void EXPORT_FUNC (_savegpr_16) (void);
void EXPORT_FUNC (_savegpr_17) (void);
void EXPORT_FUNC (_savegpr_18) (void);
void EXPORT_FUNC (_savegpr_19) (void);
void EXPORT_FUNC (_savegpr_20) (void);
void EXPORT_FUNC (_savegpr_21) (void);
void EXPORT_FUNC (_savegpr_22) (void);
void EXPORT_FUNC (_savegpr_23) (void);
void EXPORT_FUNC (_savegpr_24) (void);
void EXPORT_FUNC (_savegpr_25) (void);
void EXPORT_FUNC (_savegpr_26) (void);
void EXPORT_FUNC (_savegpr_27) (void);
void EXPORT_FUNC (_savegpr_28) (void);
void EXPORT_FUNC (_savegpr_29) (void);
void EXPORT_FUNC (_savegpr_30) (void);
void EXPORT_FUNC (_savegpr_31) (void);

#endif

#if defined (__powerpc__) || defined(__mips__)

int
EXPORT_FUNC(__ucmpdi2) (grub_uint64_t a, grub_uint64_t b);

#endif

#if defined (__powerpc__)
grub_uint64_t
__ashldi3 (grub_uint64_t u, int b);
#endif

#if defined (__powerpc__) || defined(__mips__) || defined(__sparc__)
grub_uint32_t
EXPORT_FUNC(__bswapsi2) (grub_uint32_t u);

grub_uint64_t
EXPORT_FUNC(__bswapdi2) (grub_uint64_t u);
#endif

#if defined (__APPLE__) && defined(__i386__)
#define GRUB_BUILTIN_ATTR  __attribute__ ((regparm(0)))
#else
#define GRUB_BUILTIN_ATTR
#endif

/* Prototypes for aliases.  */
int GRUB_BUILTIN_ATTR EXPORT_FUNC(memcmp) (const void *s1, const void *s2, grub_size_t n);
void *GRUB_BUILTIN_ATTR EXPORT_FUNC(memmove) (void *dest, const void *src, grub_size_t n);
void *GRUB_BUILTIN_ATTR EXPORT_FUNC(memcpy) (void *dest, const void *src, grub_size_t n);
void *GRUB_BUILTIN_ATTR EXPORT_FUNC(memset) (void *s, int c, grub_size_t n);

#ifdef __APPLE__
void GRUB_BUILTIN_ATTR EXPORT_FUNC (__bzero) (void *s, grub_size_t n);
#endif

#if defined (__MINGW32__) || defined (__CYGWIN__)
void EXPORT_FUNC (__register_frame_info) (void);
void EXPORT_FUNC (__deregister_frame_info) (void);
void EXPORT_FUNC (___chkstk_ms) (void);
#endif

#endif

