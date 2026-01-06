#pragma once

#include <bonsai/gpu_mapped_buffer.h>
#include <bonsai/framebuffer.h>
#include <bonsai/matrix.h>
#include <bonsai/shader.h>

struct render_to_texture_group
{
  framebuffer                FBO;
  shader                     Shader;
  gpu_mapped_element_buffer  GeoBuffer;
  m4 ViewProjection;
};

