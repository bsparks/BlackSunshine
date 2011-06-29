// ScriptDisplay.h

v8::Handle<v8::Value> performChecklistForGraphicsCards(const v8::Arguments& args)
{
	dbPerformChecklistForGraphicsCards();

	return v8::Undefined();
}

v8::Handle<v8::Value> performChecklistForDisplayModes(const v8::Arguments& args)
{
	dbPerformChecklistForDisplayModes();

	return v8::Undefined();
}

v8::Handle<v8::Value> screenWidth(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbScreenWidth());
}

v8::Handle<v8::Value> screenHeight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbScreenHeight());
}

v8::Handle<v8::Value> screenDepth(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbScreenDepth());
}

// modified this a little
v8::Handle<v8::Value> setDisplayMode(const v8::Arguments& args)
{
	if(args.Length() < 4)
		return v8::String::New("Syntax: setDisplayMode(width, height, depth, fullscreen)");

	int sWidth  = args[0]->Int32Value();
	int sHeight = args[1]->Int32Value();
	int sDepth  = args[2]->Int32Value();
	bool fullscreen = args[3]->BooleanValue();

	if(fullscreen)
	{
		dbSetWindowOff();
	}
	else
	{
		dbSetWindowOn();
	}

	dbSetDisplayMode(sWidth, sHeight, sDepth);

	return v8::Undefined();
}

v8::Handle<v8::Value> setGraphicsCard(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);

	dbSetGraphicsCard(ToCharString(temp));

	return v8::Undefined();
}

v8::Handle<v8::Value> setGamma(const v8::Arguments& args)
{
	int red = args[0]->IntegerValue();
	int green = args[1]->IntegerValue();
	int blue = args[2]->IntegerValue();

	dbSetGamma(red, green, blue);

	return v8::Undefined();
}

v8::Handle<v8::Value> setWindowTitle(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);

	dbSetWindowTitle(ToCharString(temp));

	return v8::Undefined();
}

v8::Handle<v8::Value> setWindowPosition(const v8::Arguments& args)
{
	int x = args[0]->IntegerValue();
	int y = args[1]->IntegerValue();

	dbSetWindowPosition(x, y);

	return v8::Undefined();
}

void RegisterScriptDisplay(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbPerformChecklistForGraphicsCards"), v8::FunctionTemplate::New(performChecklistForGraphicsCards));
	global->Set(v8::String::New("dbPerformChecklistForDisplayModes"), v8::FunctionTemplate::New(performChecklistForDisplayModes));

	global->Set(v8::String::New("dbScreenWidth"), v8::FunctionTemplate::New(screenWidth));
	global->Set(v8::String::New("dbScreenHeight"), v8::FunctionTemplate::New(screenHeight));
	global->Set(v8::String::New("dbScreenDepth"), v8::FunctionTemplate::New(screenDepth));

	global->Set(v8::String::New("dbSetDisplayMode"), v8::FunctionTemplate::New(setDisplayMode));
	global->Set(v8::String::New("dbSetGraphicsCard"), v8::FunctionTemplate::New(setGraphicsCard));
	global->Set(v8::String::New("dbSetGamma"), v8::FunctionTemplate::New(setGamma));
	global->Set(v8::String::New("dbSetWindowTitle"), v8::FunctionTemplate::New(setWindowTitle));	
	global->Set(v8::String::New("dbSetWindowPosition"), v8::FunctionTemplate::New(setWindowPosition));
}