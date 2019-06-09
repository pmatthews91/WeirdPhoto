#pragma once

#include "IRenderer.h"
#include "RenderType.h"

class ViewFunctionFactory
{
public:
	static IRenderer::ViewImageFunc make_view_func(RenderType renderType);
};