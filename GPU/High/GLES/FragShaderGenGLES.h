// Copyright (c) 2012- PPSSPP Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0 or later versions.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official git repository and contact information can be found at
// https://github.com/hrydgard/ppsspp and http://www.ppsspp.org/.

#pragma once

#include "Globals.h"

namespace HighGpu {

struct ShaderID;
struct BlendState;
struct FragmentState;
struct DepthStencilState;
struct RasterState;
struct FramebufState;
struct TexScaleState;

void ComputeFragmentShaderID(ShaderID *id_out, u32 enabled, u32 vertType,
		const FramebufState *fb, const RasterState *raster, const FragmentState *frag,
		const TexScaleState *ts, const BlendState *blend, const DepthStencilState *ds,
		bool allowShaderBlend, bool flipTexture, bool vertexFullAlpha, bool textureFullAlpha);
void GenerateFragmentShader(ShaderID id, char *buffer);

enum StencilValueType {
	STENCIL_VALUE_UNIFORM,
	STENCIL_VALUE_ZERO,
	STENCIL_VALUE_ONE,
	STENCIL_VALUE_KEEP,
	STENCIL_VALUE_INVERT,
	STENCIL_VALUE_INCR_4,
	STENCIL_VALUE_INCR_8,
	STENCIL_VALUE_DECR_4,
	STENCIL_VALUE_DECR_8,
};

enum ReplaceAlphaType {
	REPLACE_ALPHA_NO = 0,
	REPLACE_ALPHA_YES = 1,
	REPLACE_ALPHA_DUALSOURCE = 2,
};

enum ReplaceBlendType {
	REPLACE_BLEND_NO,
	REPLACE_BLEND_STANDARD,
	REPLACE_BLEND_PRE_SRC,
	REPLACE_BLEND_PRE_SRC_2X_ALPHA,
	REPLACE_BLEND_2X_ALPHA,
	REPLACE_BLEND_2X_SRC,
	REPLACE_BLEND_COPY_FBO,
};

bool IsAlphaTestAgainstZero(const BlendState *blendState);
bool IsAlphaTestTriviallyTrue(u32 enabled, const BlendState *blendState, const FragmentState *fragState, const DepthStencilState *depthState);
bool IsColorTestAgainstZero(const BlendState *blendState);
bool IsColorTestTriviallyTrue(const BlendState *blendState);

StencilValueType ReplaceAlphaWithStencilType();
ReplaceAlphaType ReplaceAlphaWithStencil(ReplaceBlendType replaceBlend);
ReplaceBlendType ReplaceBlendWithShader(bool allowShaderBlend);

}  // HighGpu
