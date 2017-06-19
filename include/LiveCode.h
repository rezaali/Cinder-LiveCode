/*
Copyright(c) 2017 Reza Ali syed.reza.ali@gmail.com www.syedrezaali.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <functional>

#include "cinder/Filesystem.h"
#include "cinder/app/Window.h"
#include "cinder/gl/GlslProg.h"

#include "GlslParams.h"
#include "UI.h"

namespace reza {
namespace live {
void glsl(
	const ci::fs::path &vertex,
	const ci::fs::path &fragment,
	const ci::fs::path &geometry,
	ci::gl::GlslProg::Format format,
	std::function<void()> superFn = nullptr,
	std::function<void( ci::gl::GlslProgRef, const std::vector<std::string> )> successFn = nullptr,
	std::function<void( ci::Exception )> errorFn = nullptr );

void glsl(
	const ci::fs::path &vertex,
	const ci::fs::path &fragment,
	ci::gl::GlslProg::Format format,
	std::function<void()> superFn = nullptr,
	std::function<void( ci::gl::GlslProgRef, const std::vector<std::string> )> successFn = nullptr,
	std::function<void( ci::Exception )> errorFn = nullptr );

void glsl(
	const ci::fs::path &vertex,
	ci::gl::GlslProg::Format format,
	std::function<void()> superFn = nullptr,
	std::function<void( ci::gl::GlslProgRef, const std::vector<std::string> )> successFn = nullptr,
	std::function<void( ci::Exception )> errorFn = nullptr );
} // namespace live
} // namespace reza
