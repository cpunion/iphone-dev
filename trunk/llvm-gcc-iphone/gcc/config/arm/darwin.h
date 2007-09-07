/* Target definitions for arm running Darwin.
   APPLE LOCAL mainline 2005-04-11
   Copyright (C) 2001, 2002, 2004, 2005 Free Software Foundation, Inc.
   Contributed by Apple Computer Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* Enable Mach-O bits in generic x86 code.  */
#undef TARGET_MACHO
#define TARGET_MACHO 1

/* APPLE LOCAL begin mainline */
#undef  TARGET_64BIT
#define TARGET_64BIT 0

#undef TARGET_VERSION
#define TARGET_VERSION fprintf (stderr, " (arm Darwin)");
/* APPLE LOCAL end mainline */

/* APPLE LOCAL begin mainline */
#undef PTRDIFF_TYPE
#define PTRDIFF_TYPE (TARGET_64BIT ? "long int" : "int")

#undef MAX_BITS_PER_WORD
#define MAX_BITS_PER_WORD 64

#define TARGET_OS_CPP_BUILTINS()                \
  do                                            \
    {                                           \
      builtin_define ("__arm__");		\
      builtin_define ("__LITTLE_ENDIAN__");     \
      darwin_cpp_builtins (pfile);		\
    }                                           \
  while (0)
/* APPLE LOCAL end mainline */

/* IPHONE BINUTILS LOCAL */
#undef SUBTARGET_ASM_FLOAT_SPEC
#define SUBTARGET_ASM_FLOAT_SPEC \
    "%{!mfpu=*:-mfpu=vfp} %{!mcpu=*:-mcpu=arm1176jzf-s}"

/* We want -fPIC by default, unless we're using -static to compile for
   the kernel or some such.  */

#undef CC1_SPEC
/* APPLE LOCAL mainline */
#define CC1_SPEC "%{!mkernel:%{!static:%{!mdynamic-no-pic:-fPIC}}} \
  "/* APPLE LOCAL mainline 2007-02-20 5005743 */"\
  %{!mmacosx-version-min=*:-mmacosx-version-min=%(darwin_minversion)} \
  "/* APPLE LOCAL ignore -mcpu=G4 -mcpu=G5 */"\
  %<faltivec %<mno-fused-madd %<mlong-branch %<mlongcall %<mcpu=G4 %<mcpu=G5 \
  %{g: %{!fno-eliminate-unused-debug-symbols: -feliminate-unused-debug-symbols }} " \
    SUBTARGET_ASM_FLOAT_SPEC

/* APPLE LOCAL AltiVec */
#define CPP_ALTIVEC_SPEC "%<faltivec"

/* APPLE LOCAL begin mainline */
#undef ASM_SPEC
#define ASM_SPEC "-arch %(darwin_arch) -force_cpusubtype_ALL"

#define DARWIN_ARCH_SPEC "arm"
#define DARWIN_SUBARCH_SPEC "arm"

/* APPLE LOCAL begin mainline 2007-03-13 5005743 5040758 */ \
/* Determine a minimum version based on compiler options.  */
#define DARWIN_MINVERSION_SPEC				\
 "%{!m64|fgnu-runtime:10.4;				\
    ,objective-c|,objc-cpp-output:10.5;			\
    ,objective-c++|,objective-c++-cpp-output:10.5;	\
    :10.4}"

/* APPLE LOCAL end mainline 2007-03-13 5005743 5040758 */ \
#undef SUBTARGET_EXTRA_SPECS
#define SUBTARGET_EXTRA_SPECS					\
  DARWIN_EXTRA_SPECS						\
  { "darwin_arch", DARWIN_ARCH_SPEC },				\
  { "darwin_crt2", "" },					\
  { "darwin_subarch", DARWIN_SUBARCH_SPEC }, \
  { "subtarget_asm_float_spec", SUBTARGET_ASM_FLOAT_SPEC },
/* APPLE LOCAL end mainline */

/* Use the following macro for any Darwin/arm-specific command-line option
   translation.  */
#define SUBTARGET_OPTION_TRANSLATE_TABLE \
  { "", "" }

/* Define the syntax of pseudo-ops, labels and comments.  */

#ifndef REGISTER_PREFIX
#define REGISTER_PREFIX		""
#endif

#ifndef USER_LABEL_PREFIX
#define USER_LABEL_PREFIX 	"_"
#endif

#ifndef LOCAL_LABEL_PREFIX
#define LOCAL_LABEL_PREFIX 	""
#endif

/* The assembler's names for the registers.  */
#ifndef REGISTER_NAMES
#define REGISTER_NAMES				   \
{				                   \
  "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",  \
  "r8", "r9", "sl", "fp", "ip", "sp", "lr", "pc",  \
  "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7",  \
  "cc", "sfp", "afp",		   		   \
  "mv0",   "mv1",   "mv2",   "mv3",		   \
  "mv4",   "mv5",   "mv6",   "mv7",		   \
  "mv8",   "mv9",   "mv10",  "mv11",		   \
  "mv12",  "mv13",  "mv14",  "mv15",		   \
  "wcgr0", "wcgr1", "wcgr2", "wcgr3",		   \
  "wr0",   "wr1",   "wr2",   "wr3",		   \
  "wr4",   "wr5",   "wr6",   "wr7",		   \
  "wr8",   "wr9",   "wr10",  "wr11",		   \
  "wr12",  "wr13",  "wr14",  "wr15",		   \
  "s0",  "s1",  "s2",  "s3",  "s4",  "s5",  "s6",  "s7",  \
  "s8",  "s9",  "s10", "s11", "s12", "s13", "s14", "s15", \
  "s16", "s17", "s18", "s19", "s20", "s21", "s22", "s23", \
  "s24", "s25", "s26", "s27", "s28", "s29", "s30", "s31", \
  "vfpcc"					   \
}
#endif

#ifndef ADDITIONAL_REGISTER_NAMES
#define ADDITIONAL_REGISTER_NAMES		\
{						\
  {"a1", 0},					\
  {"a2", 1},					\
  {"a3", 2},					\
  {"a4", 3},					\
  {"v1", 4},					\
  {"v2", 5},					\
  {"v3", 6},					\
  {"v4", 7},					\
  {"v5", 8},					\
  {"v6", 9},					\
  {"rfp", 9}, /* Gcc used to call it this */	\
  {"sb", 9},					\
  {"v7", 10},					\
  {"r10", 10},	/* sl */			\
  {"r11", 11},	/* fp */			\
  {"r12", 12},	/* ip */			\
  {"r13", 13},	/* sp */			\
  {"r14", 14},	/* lr */			\
  {"r15", 15},	/* pc */			\
  {"mvf0", 27},					\
  {"mvf1", 28},					\
  {"mvf2", 29},					\
  {"mvf3", 30},					\
  {"mvf4", 31},					\
  {"mvf5", 32},					\
  {"mvf6", 33},					\
  {"mvf7", 34},					\
  {"mvf8", 35},					\
  {"mvf9", 36},					\
  {"mvf10", 37},				\
  {"mvf11", 38},				\
  {"mvf12", 39},				\
  {"mvf13", 40},				\
  {"mvf14", 41},				\
  {"mvf15", 42},				\
  {"mvd0", 27},					\
  {"mvd1", 28},					\
  {"mvd2", 29},					\
  {"mvd3", 30},					\
  {"mvd4", 31},					\
  {"mvd5", 32},					\
  {"mvd6", 33},					\
  {"mvd7", 34},					\
  {"mvd8", 35},					\
  {"mvd9", 36},					\
  {"mvd10", 37},				\
  {"mvd11", 38},				\
  {"mvd12", 39},				\
  {"mvd13", 40},				\
  {"mvd14", 41},				\
  {"mvd15", 42},				\
  {"mvfx0", 27},				\
  {"mvfx1", 28},				\
  {"mvfx2", 29},				\
  {"mvfx3", 30},				\
  {"mvfx4", 31},				\
  {"mvfx5", 32},				\
  {"mvfx6", 33},				\
  {"mvfx7", 34},				\
  {"mvfx8", 35},				\
  {"mvfx9", 36},				\
  {"mvfx10", 37},				\
  {"mvfx11", 38},				\
  {"mvfx12", 39},				\
  {"mvfx13", 40},				\
  {"mvfx14", 41},				\
  {"mvfx15", 42},				\
  {"mvdx0", 27},				\
  {"mvdx1", 28},				\
  {"mvdx2", 29},				\
  {"mvdx3", 30},				\
  {"mvdx4", 31},				\
  {"mvdx5", 32},				\
  {"mvdx6", 33},				\
  {"mvdx7", 34},				\
  {"mvdx8", 35},				\
  {"mvdx9", 36},				\
  {"mvdx10", 37},				\
  {"mvdx11", 38},				\
  {"mvdx12", 39},				\
  {"mvdx13", 40},				\
  {"mvdx14", 41},				\
  {"mvdx15", 42},				\
  {"d0", 63},					\
  {"d1", 65},					\
  {"d2", 67},					\
  {"d3", 69},					\
  {"d4", 71},					\
  {"d5", 73},					\
  {"d6", 75},					\
  {"d7", 77},					\
  {"d8", 79},					\
  {"d9", 81},					\
  {"d10", 83},					\
  {"d11", 85},					\
  {"d12", 87},					\
  {"d13", 89},					\
  {"d14", 91},					\
  {"d15", 93},					\
}
#endif




/* String containing the assembler's comment-starter.  */

#define ASM_COMMENT_START "#"

/* APPLE LOCAL begin dynamic-no-pic */
/* Darwin switches.  */
/* Use dynamic-no-pic codegen (no picbase reg; not suitable for shlibs.)  */
#define MASK_MACHO_DYNAMIC_NO_PIC (0x00800000)

#define TARGET_DYNAMIC_NO_PIC	(target_flags & MASK_MACHO_DYNAMIC_NO_PIC)
/* APPLE LOCAL end dynamic-no-pic */
/* APPLE LOCAL begin mainline */
#undef GOT_SYMBOL_NAME
#define GOT_SYMBOL_NAME (machopic_function_base_name ())
/* APPLE LOCAL end mainline */
/* Define the syntax of pseudo-ops, labels and comments.  */

#define LPREFIX "L"

/* These are used by -fbranch-probabilities */
#define HOT_TEXT_SECTION_NAME "__TEXT,__text,regular,pure_instructions"
#define UNLIKELY_EXECUTED_TEXT_SECTION_NAME \
                              "__TEXT,__unlikely,regular,pure_instructions"

#undef ASM_OUTPUT_ALIGN
/* Align output to a power of two.  Note ".align 0" is redundant,
   and also GAS will treat it as ".align 2" which we do not want.  */
#define ASM_OUTPUT_ALIGN(STREAM, POWER)			\
  do							\
    {							\
      if ((POWER) > 0)					\
	fprintf (STREAM, "\t.align\t%d\n", POWER);	\
    }							\
  while (0)
/* APPLE LOCAL begin mainline */
/* Removed ASM_OUTPUT_COMMON and ASM_OUTPUT_LOCAL */
/* APPLE LOCAL end mainline */

/* APPLE LOCAL begin Macintosh alignment 2002-2-19 --ff */
#define MASK_ALIGN_NATURAL	0x40000000
#define TARGET_ALIGN_NATURAL	(target_flags & MASK_ALIGN_NATURAL)
#define rs6000_alignment_flags target_flags
#define MASK_ALIGN_MAC68K	0x20000000
#define TARGET_ALIGN_MAC68K	(target_flags & MASK_ALIGN_MAC68K)

#define ROUND_TYPE_ALIGN(TYPE, COMPUTED, SPECIFIED) \
  (((TREE_CODE (TYPE) == RECORD_TYPE \
     || TREE_CODE (TYPE) == UNION_TYPE \
     || TREE_CODE (TYPE) == QUAL_UNION_TYPE) \
    && TARGET_ALIGN_MAC68K \
    && MAX (COMPUTED, SPECIFIED) == 8) ? 16 \
    : MAX (COMPUTED, SPECIFIED))

#undef SUBTARGET_SWITCHES
#define SUBTARGET_SWITCHES						\
  {"align-mac68k",      MASK_ALIGN_MAC68K,				\
	N_("Align structs and unions according to mac68k rules")},	\
  {"align-power",       - (MASK_ALIGN_MAC68K | MASK_ALIGN_NATURAL),	\
	N_("Align structs and unions according to PowerPC rules")},	\
  {"align-natural",     MASK_ALIGN_NATURAL,				\
	N_("Align structs and unions according to natural rules")},	\
  {"dynamic-no-pic",    MASK_MACHO_DYNAMIC_NO_PIC,			\
	N_("Generate code suitable for executables (NOT shared libs)")},\
  {"no-dynamic-no-pic", -MASK_MACHO_DYNAMIC_NO_PIC,  ""},
/* APPLE LOCAL end Macintosh alignment 2002-2-19 --ff */

/* Darwin profiling -- call mcount.  */
/*
 #undef FUNCTION_PROFILER
 #define FUNCTION_PROFILER(FILE, LABELNO)
*/

/* APPLE LOCAL CW asm blocks */
extern int flag_iasm_blocks;
/* APPLE LOCAL begin fix-and-continue x86 */
#undef SUBTARGET_OVERRIDE_OPTIONS
#define SUBTARGET_OVERRIDE_OPTIONS				\
  do {								\
    /* Handle -mfix-and-continue.  */				\
    if (darwin_fix_and_continue_switch)				\
      {								\
	const char *base = darwin_fix_and_continue_switch;	\
	while (base[-1] != 'm') base--;				\
								\
	if (*darwin_fix_and_continue_switch != '\0')		\
	  error ("invalid option %qs", base);			\
	darwin_fix_and_continue = (base[0] != 'n');		\
      }								\
    /* APPLE LOCAL begin AT&T-style stub 4164563 */		\
    /* Handle -matt-stubs.  */					\
    if (darwin_macho_att_stub_switch)				\
      {								\
	const char *base = darwin_macho_att_stub_switch;	\
	while (base[-1] != 'm') base--;				\
								\
	if (*darwin_macho_att_stub_switch != '\0')		\
	  error ("invalid option %qs", base);			\
	darwin_macho_att_stub = (base[0] != 'n');		\
      }								\
    /* APPLE LOCAL end AT&T-style stub 4164563 */		\
    /* APPLE LOCAL begin CW asm blocks */			\
    if (flag_iasm_blocks)					\
      flag_ms_asms = 1;						\
    /* APPLE LOCAL end CW asm blocks */				\
    if (TARGET_64BIT)						\
      {								\
	if (MACHO_DYNAMIC_NO_PIC_P)				\
	  target_flags &= ~MASK_MACHO_DYNAMIC_NO_PIC;		\
      }								\
  } while (0)

/* APPLE LOCAL begin kexts */
#define C_COMMON_OVERRIDE_OPTIONS do {		\
  SUBTARGET_C_COMMON_OVERRIDE_OPTIONS;		\
  } while (0)
/* APPLE LOCAL end kexts */

/* True, iff we're generating fast turn around debugging code.  When
   true, we arrange for function prologues to start with 6 nops so
   that gdb may insert code to redirect them, and for data to be
   accessed indirectly.  The runtime uses this indirection to forward
   references for data to the original instance of that data.  */

#define TARGET_FIX_AND_CONTINUE 0
/* APPLE LOCAL end fix-and-continue arm */

/* APPLE LOCAL begin mainline */
#undef REGISTER_TARGET_PRAGMAS
#define REGISTER_TARGET_PRAGMAS() DARWIN_REGISTER_TARGET_PRAGMAS()

#undef TARGET_SET_DEFAULT_TYPE_ATTRIBUTES
#define TARGET_SET_DEFAULT_TYPE_ATTRIBUTES darwin_set_default_type_attributes
/* APPLE LOCAL end mainline */

/* IPHONE BINUTILS LOCAL: we need to specify the iPhone's CPU here */
#undef SUBTARGET_CPU_DEFAULT
#define SUBTARGET_CPU_DEFAULT TARGET_CPU_arm1176jzfs

/* iPhone binutils local: don't use built-in setjmp and longjmp, as they're
 * broken under LLVM and they're our method of exception handling. */
#define DONT_USE_BUILTIN_SETJMP
#define JMP_BUF_SIZE    27 
#define OBJC_JBLEN      27

#undef FPUTYPE_DEFAULT
#define FPUTYPE_DEFAULT FPUTYPE_VFP

/* APPLE LOCAL begin LLVM */
#ifdef ENABLE_LLVM

/* Add general target specific stuff */
/* #include "llvm-arm-target.h" */

/* APPLE LOCAL end LLVM */

#endif
