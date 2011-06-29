// ScriptEngine.h
// load up all the various script functions

#ifndef SCRIPTENGINE_H
#define SCRIPTENGINE_H

#include <v8.h>

#include <MyGUI.h>
#include <MyGUI_DirectXPlatform.h>

#include <deque>
#include <vector>
#include <string>

// v8 macros
#define SAVE_PTR(index, ptr) args.This()->SetPointerInInternalField(index, (void *)(ptr))
#define LOAD_PTR(index, type) reinterpret_cast<type>(args.This()->GetPointerFromInternalField(index))
#define SAVE_VALUE(index, val) args.This()->SetInternalField(index, val)
#define LOAD_VALUE(index) args.This()->GetInternalField(index)
#define JS_STR(...) v8::String::New(__VA_ARGS__)
#define JS_INT(val) v8::Integer::New(val)
#define JS_FLOAT(val) v8::Number::New(val)
#define JS_BOOL(val) v8::Boolean::New(val)
#define JS_NULL v8::Null()
#define JS_UNDEFINED v8::Undefined()
#define JS_METHOD(name) v8::Handle<v8::Value> name(const v8::Arguments& args)
#define JS_GETTER(name) v8::Handle<v8::Value> name(v8::Local<v8::String> property, const v8::AccessorInfo &info)
#define JS_SETTER(name) void name(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
#define JS_EXCEPTION(reason) v8::ThrowException(JS_STR(reason))
#define JS_RETHROW(tc) v8::Local<v8::Value>::New(tc.Exception());
#define INSTANCEOF(obj, func) func->HasInstance(obj)

#define JS_GLOBAL v8::Context::GetCurrent()->Global()
#define GLOBAL_PROTO v8::Handle<v8::Object>::Cast(JS_GLOBAL->GetPrototype())

#define ASSERT_CONSTRUCTOR if (!args.IsConstructCall()) { return JS_EXCEPTION("Invalid call format. Please use the 'new' operator."); }
#define ASSERT_NOT_CONSTRUCTOR if (args.IsConstructCall()) { return JS_EXCEPTION("Invalid call format. Please do not use the 'new' operator."); }
#define ASSERT_MIN_ARGS(val, msg) if (!args.Length() > val) { return JS_EXCEPTION(msg); }

// global gui object
MyGUI::Gui* g_Gui = nullptr;
MyGUI::DirectXPlatform* g_GuiPlatform = nullptr;

// a couple of utility functions needed

std::deque<const char*> consoleBuffer; // global buffer for the console 

// Extracts a C string from a V8 Utf8Value.
const char* ToCString(const v8::String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}

char* ToCharString(const char* value)
{	
	char* tmp = new char[strlen(value) + 1];
	strcpy(tmp, value);
	return tmp;
	delete[] tmp;
}

// global persistant context
v8::Persistent<v8::Context> gScriptContext;

// global persistant callbacks
v8::Persistent<v8::Function> cbOnBeforeGameLoop;
v8::Persistent<v8::Function> cbOnKeyPress;
v8::Persistent<v8::Function> cbOnRenderFrame;
v8::Persistent<v8::Function> cbOnGameShutdown;

#include "ScriptCore.h"
#include "ScriptTimer.h" // timer functions (setTimeout & setInterval)
#include "ScriptInput.h"
#include "ScriptDisplay.h"
#include "ScriptCamera.h"
#include "ScriptImage.h"
#include "ScriptBasic3D.h"
#include "ScriptBasic2D.h"
#include "ScriptMusic.h"
#include "ScriptSound.h"
#include "ScriptBitmap.h"
#include "ScriptParticles.h"
#include "ScriptTerrain.h"
#include "ScriptLight.h"
#include "ScriptFtp.h"
#include "ScriptWorld.h"
#include "ScriptMatrix.h"
#include "ScriptSprite.h"
#include "ScriptMemblock.h"
#include "ScriptSystem.h"
#include "ScriptMultiplayer.h"
#include "Script3dMath.h"
#include "ScriptText.h"
#include "ScriptGui.h"

// must call this first
void InitScriptEngine(void)
{
	v8::HandleScope handle_scope;
	// Create a template for the global object.
	v8::Handle<v8::ObjectTemplate> global = v8::ObjectTemplate::New();

	// register each library (later use macro for EAC or DAI?)
	RegisterScriptCore(global);
	RegisterScriptDisplay(global);
	RegisterScriptTimer(global);
	RegisterScriptInput(global);
	RegisterScriptCamera(global);
	RegisterScriptImage(global);
	RegisterScriptBasic2D(global);
	RegisterScriptBasic3D(global);
	RegisterScriptMusic(global);
	RegisterScriptSound(global);
	RegisterScriptBitmap(global);
	RegisterScriptParticles(global);
	RegisterScriptTerrain(global);
	RegisterScriptLight(global);
	RegisterScriptWorld(global);
	RegisterScriptMatrix(global);
	RegisterScriptSprite(global);
	RegisterScriptFtp(global);
	RegisterScriptMemblock(global);
	RegisterScriptSystem(global);
	//RegisterScriptMultiplayer(global);
	RegisterScript3dMath(global);
	RegisterScriptText(global);
    RegisterScriptGui(global);

	// create a context with the global object
	v8::Handle<v8::Context> context = v8::Context::New(NULL, global);
	// set the global context as persistant so it exists outside this function
	gScriptContext = v8::Persistent<v8::Context>::New(context);

	// Enter the execution environment.
	v8::Context::Scope context_scope(context);

	// load and execute the starting script
	v8::Handle<v8::String> file_name = v8::String::New("main.js");
    v8::Handle<v8::String> source = ReadFile("main.js");
	ExecuteString(source, file_name, false, true);

	// setup other callbacks
	v8::Handle<v8::String> sOnKeyPress = v8::String::New("onKeyPress");
	v8::Handle<v8::Value> fOnKeyPress = context->Global()->Get(sOnKeyPress);
	// only set it up if defined in script
	if(fOnKeyPress->IsFunction())
	{
		// cast to function
		v8::Handle<v8::Function> fnOnKeyPress = v8::Handle<v8::Function>::Cast(fOnKeyPress);
		cbOnKeyPress = v8::Persistent<v8::Function>::New(fnOnKeyPress);
	}

	v8::Handle<v8::String> sOnRenderFrame = v8::String::New("onRenderFrame");
	v8::Handle<v8::Value> fOnRenderFrame = context->Global()->Get(sOnRenderFrame);
	// only set it up if defined in script
	if(fOnRenderFrame->IsFunction())
	{
		// cast to function
		v8::Handle<v8::Function> fnOnRenderFrame = v8::Handle<v8::Function>::Cast(fOnRenderFrame);
		cbOnRenderFrame = v8::Persistent<v8::Function>::New(fnOnRenderFrame);
	}

	v8::Handle<v8::String> sOnGameShutdown = v8::String::New("onGameShutdown");
	v8::Handle<v8::Value> fOnGameShutdown = context->Global()->Get(sOnGameShutdown);
	// only set it up if defined in script
	if(fOnGameShutdown->IsFunction())
	{
		// cast to function
		v8::Handle<v8::Function> fnOnGameShutdown = v8::Handle<v8::Function>::Cast(fOnGameShutdown);
		cbOnGameShutdown = v8::Persistent<v8::Function>::New(fnOnGameShutdown);
	}

	// last chance to have script do something prior to starting the main game loop
	v8::Handle<v8::String> sOnBeforeGameLoop = v8::String::New("onBeforeGameLoop");
	v8::Handle<v8::Value> fOnBeforeGameLoop = context->Global()->Get(sOnBeforeGameLoop);
	// must be a function, if it's not defined dont do anythign
	if(fOnBeforeGameLoop->IsFunction())
	{
		// It is a function; cast it to a Function
		v8::Handle<v8::Function> fnOnBeforeGameLoop = v8::Handle<v8::Function>::Cast(fOnBeforeGameLoop); 
		cbOnBeforeGameLoop = v8::Persistent<v8::Function>::New(fnOnBeforeGameLoop);
	}
}

#endif