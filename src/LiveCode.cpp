#include "LiveCode.h"

#include "Paths.h"
#include "cinder/Log.h"

using namespace ci;
using namespace std;

using namespace reza::ui;
using namespace reza::glsl;
using namespace reza::paths;

namespace reza {
namespace live {

void glsl(
	const fs::path &vertex,
	const fs::path &fragment,
	const fs::path &geometry,
	gl::GlslProg::Format format,
	std::function<void()> superFn,
	std::function<void( gl::GlslProgRef, vector<string> )> successFn,
	std::function<void( Exception )> errorFn )
{
	if( superFn ) {
		superFn();
	}

	bool compiled = true;
	gl::ShaderPreprocessor pp;
	gl::GlslProgRef result;
	vector<string> sources;

	try {
		pp.addSearchDirectory( getAppSupportWorkingSessionShadersPath( "Common" ) );
		sources.emplace_back( pp.parse( vertex ) );
		sources.emplace_back( pp.parse( fragment ) );
		sources.emplace_back( pp.parse( geometry ) );

		format.vertex( sources[0] ).fragment( sources[1] ).geometry( sources[2] );
		result = gl::GlslProg::create( format );
	}
	catch( Exception &exc ) {
		compiled = false;
		if( errorFn ) {
			errorFn( exc );
		}
	}

	if( compiled ) {
		if( successFn ) {
			successFn( result, sources );
		}
	}
}

void glsl(
	const fs::path &vertex,
	const fs::path &fragment,
	gl::GlslProg::Format format,
	std::function<void()> superFn,
	std::function<void( gl::GlslProgRef, vector<string> )> successFn,
	std::function<void( Exception )> errorFn )
{
	if( superFn ) {
		superFn();
	}

	bool compiled = true;
	gl::ShaderPreprocessor pp;
	gl::GlslProgRef result;
	vector<string> sources;

	try {
		pp.addSearchDirectory( getAppSupportWorkingSessionShadersPath( "Common" ) );
		sources.emplace_back( pp.parse( vertex ) );
		sources.emplace_back( pp.parse( fragment ) );
		format.vertex( sources[0] ).fragment( sources[1] );
		result = gl::GlslProg::create( format );
	}
	catch( Exception &exc ) {
		compiled = false;
		if( errorFn ) {
			errorFn( exc );
		}
	}

	if( compiled ) {
		if( successFn ) {
			successFn( result, sources );
		}
	}
}

void glsl(
	const fs::path &vertex,
	gl::GlslProg::Format format,
	std::function<void()> superFn,
	std::function<void( gl::GlslProgRef, vector<string> )> successFn,
	std::function<void( Exception )> errorFn )
{
	if( superFn ) {
		superFn();
	}

	bool compiled = true;
	gl::ShaderPreprocessor pp;
	gl::GlslProgRef result;
	vector<string> sources;

	try {
		pp.addSearchDirectory( getAppSupportWorkingSessionShadersPath( "Common" ) );
		sources.emplace_back( pp.parse( vertex ) );
		format.vertex( sources[0] );
		result = gl::GlslProg::create( format );
	}
	catch( Exception &exc ) {
		compiled = false;
		if( errorFn ) {
			errorFn( exc );
		}
	}

	if( compiled ) {
		if( successFn ) {
			successFn( result, sources );
		}
	}
}
} // namespace live
} // namespace reza