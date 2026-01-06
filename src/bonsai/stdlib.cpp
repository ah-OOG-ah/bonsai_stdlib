#include "stdlib.h"

#include <bonsai/ansi_stream.h>
#include <bonsai/file.h>
#include <bonsai/gl.h>
#include <bonsai/platform.h>
#include <bonsai/platform_struct.h>
#include <bonsai/shader.h>
#include <bonsai/texture.h>
#include <bonsai/thread.h>

struct bonsai_stdlib
poof(@do_editor_ui)
{
    os  Os;
    platform  Plat;
    application_api  AppApi;
    opengl  GL;

    // NOTE(Jesse): If we've setup a thread pool we allocate ThreadStates (and
    // set ThreadLocal_ThreadIndex for each thread), but if we just want a
    // single-threaded program (or want to access a thread_local_state before
    // we've initialized stdlib) we don't have to bother with that.. there's just
    // a sentinal here.
    thread_local_state *ThreadStates;

    thread_local_state  DefaultThreadState;

    hot_reloadable_file ShaderHeaderFile;
    ansi_stream ShaderHeaderCode;

    //
    // Debug
    //

    // TODO(Jesse): Move into debug_state?
    texture_block_array AllTextures;
    shader_ptr_block_array AllShaders;

#if BONSAI_DEBUG_SYSTEM_API
    debug_state DebugState;
#else
    // NOTE(Jesse): This is a crutch for the UI .. barf ..
    void *DebugState;
#endif
};

global_variable bonsai_stdlib *Global_Stdlib;

link_internal opengl *
GetGL()
{
    return &Global_Stdlib->GL;
}

link_internal bonsai_stdlib *
GetStdlib()
{
    return Global_Stdlib;
}

link_internal void setGlobalStdlib(bonsai_stdlib* stdlib) {
    Global_Stdlib = stdlib;
}

link_internal thread_local_state* getThreadStates() {
    return Global_Stdlib->ThreadStates;
}

link_internal thread_local_state* getDefaultThreadState() {
    return &Global_Stdlib->DefaultThreadState;
}

link_internal debug_state *
GetDebugState()
{
    debug_state *Result = 0;
#if BONSAI_DEBUG_SYSTEM_API
    bonsai_stdlib *Stdlib = GetStdlib();
    if (Stdlib && Stdlib->DebugState.Initialized)
    {
        Result = &Stdlib->DebugState;
    }
#endif
    return Result;
}