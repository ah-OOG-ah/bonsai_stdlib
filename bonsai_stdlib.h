#pragma once

/* #define BONSAI_NO_AVX */

#define MAIN_THREAD_ThreadLocal_ThreadIndex (0)
#define RENDER_THREAD_ThreadLocal_ThreadIndex (1)

#include <bonsai/poof_on.h>

// NOTE(Jesse): This is strictly present to hack around some deficiencies in
// poof.  It should be removed in the future.
//#include <bonsai/poof_crutches.h>

#include <bonsai/primitives.h>




#include <x86intrin.h>
#include <immintrin.h>
#include <smmintrin.h>
/* #include <ymmintrin.h> */

//#include <bonsai_stdlib/src/simd_sse.h>

#ifndef BONSAI_NO_AVX
//#include <bonsai_stdlib/src/simd_avx2.h>
//#include <bonsai_stdlib/src/avx2_v3.h>
#endif

//#include <bonsai_stdlib/src/console_macros.h>
//#include <bonsai_stdlib/src/globals.h>
//#include <bonsai_stdlib/src/platform.h>
//#include <bonsai_stdlib/src/bit_tricks.h>
//#include <bonsai_stdlib/src/atomic.h>
//#include <bonsai_stdlib/src/thread.h>

//#include <bonsai_stdlib/src/costable.h>
//#include <bonsai_stdlib/src/arccostable.h>

//#include <bonsai_stdlib/src/maff.h>
//#include <bonsai_stdlib/src/memory_arena.h>
//#include <bonsai_stdlib/src/primitive_containers.h>
//#include <bonsai_stdlib/src/file.h>
//#include <bonsai_stdlib/src/filesystem.h>
//#include <bonsai_stdlib/src/vector.h>
//#include <bonsai_stdlib/src/matrix.h>
//#include <bonsai_stdlib/src/colors.h>

//#include <bonsai_stdlib/src/gl.h>
//#include <bonsai_stdlib/src/ui/gl.h>

//#include <bonsai_stdlib/src/texture.h>
//#include <bonsai_stdlib/src/shader.h>
//#include <bonsai_stdlib/src/random.h>
//#include <bonsai_stdlib/src/noise.h>
#ifndef BONSAI_NO_AVX
//#include <bonsai_stdlib/src/perlin.h>
#endif
//#include <bonsai_stdlib/src/simplex.h>
//#include <bonsai_stdlib/src/input.h>
//#include <bonsai_stdlib/src/mutex.h>
//#include <bonsai_stdlib/src/work_queue.h>

//#include <bonsai_stdlib/src/mesh.h>
//#include <bonsai_stdlib/src/gpu_mapped_buffer.h>
//#include <bonsai_stdlib/src/framebuffer.h>
//#include <bonsai_stdlib/src/render.h>

//#include <bonsai_stdlib/src/platform_struct.h>
//#include <bonsai_stdlib/src/heap_allocator.h>
//#include <bonsai_stdlib/src/stream.h>
//#include <bonsai_stdlib/src/counted_string.h>
//#include <bonsai_stdlib/src/sort.h>
//#include <bonsai_stdlib/src/console_io.h>
//#include <bonsai_stdlib/src/line.h>
//#include <bonsai_stdlib/src/quaternion.h>
//#include <bonsai_stdlib/src/string_builder.h>
//#include <bonsai_stdlib/src/ansi_stream.h>
//#include <bonsai_stdlib/src/binary_parser.h>
//#include <bonsai_stdlib/src/rect.h>
//#include <bonsai_stdlib/src/xml.h>
//#include <bonsai_stdlib/src/ui/interactable.h>
//#include <bonsai_stdlib/src/ui/ui.h>

//#include <bonsai_stdlib/src/c_token.h>
//#include <bonsai_stdlib/src/c_parser.h>

//#include <bonsai_stdlib/src/debug_ui.h>



#include <bonsai_debug/debug.h>
#include <bonsai_debug/src/api.h>

#define UNPACK_STDLIB(Stdlib) \
  os *Os         = &(Stdlib)->Os; \
  platform *Plat = &(Stdlib)->Plat;






