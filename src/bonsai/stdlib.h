#pragma once

#include <bonsai/primitives.h>

struct bonsai_stdlib;
link_internal bonsai_stdlib * GetStdlib();
link_internal void setGlobalStdlib(bonsai_stdlib* stdlib);

struct thread_local_state; // from thread.h
link_internal thread_local_state* getThreadStates();
link_internal thread_local_state* getDefaultThreadState();

struct debug_state;
link_internal debug_state * GetDebugState();