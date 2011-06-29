// ScriptText.h
// note: not wrapping all db functions, javascript can handle string manipulation on its own

v8::Handle<v8::Value> performChecklistForFonts(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	dbPerformChecklistForFonts();

	return v8::Undefined();
}

v8::Handle<v8::Value> text(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int x = args[0]->Int32Value();
	int y = args[1]->Int32Value();
	v8::String::Utf8Value str(args[2]);
	const char* sText = ToCString(str);
	
	dbText(x, y, ToCharString(sText));

	return v8::Undefined();
}

v8::Handle<v8::Value> centerText(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int x = args[0]->Int32Value();
	int y = args[1]->Int32Value();
	v8::String::Utf8Value str(args[2]);
	const char* sText = ToCString(str);
	
	dbCenterText(x, y, ToCharString(sText));

	return v8::Undefined();
}

v8::Handle<v8::Value> setTextFont(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* sFont = ToCString(str);
	
	dbSetTextFont(ToCharString(sFont));

	return v8::Undefined();
}

v8::Handle<v8::Value> setTextSize(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int size = args[0]->Int32Value();
	
	dbSetTextSize(size);

	return v8::Undefined();
}

v8::Handle<v8::Value> setTextToNormal(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	dbSetTextToNormal();

	return v8::Undefined();
}

v8::Handle<v8::Value> setTextToItalic(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	dbSetTextToItalic();

	return v8::Undefined();
}

v8::Handle<v8::Value> setTextToBold(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	dbSetTextToBold();

	return v8::Undefined();
}

v8::Handle<v8::Value> setTextToBoldItalic(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	dbSetTextToBoldItalic();

	return v8::Undefined();
}

v8::Handle<v8::Value> setTextToOpaque(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	dbSetTextToOpaque();

	return v8::Undefined();
}

v8::Handle<v8::Value> setTextToTransparent(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	dbSetTextToTransparent();

	return v8::Undefined();
}

v8::Handle<v8::Value> textBackgroundType(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbTextBackgroundType());
}

v8::Handle<v8::Value> textFont(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::String::New(dbTextFont());
}

v8::Handle<v8::Value> textSize(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbTextSize());
}

v8::Handle<v8::Value> textStyle(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbTextStyle());
}

v8::Handle<v8::Value> textWidth(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* sText = ToCString(str);

	return v8::Int32::New(dbTextWidth(ToCharString(sText)));
}

v8::Handle<v8::Value> textHeight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* sText = ToCString(str);

	return v8::Int32::New(dbTextHeight(ToCharString(sText)));
}

v8::Handle<v8::Value> text3D(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* sText = ToCString(str);

	dbText3D(ToCharString(sText));

	return v8::Undefined();
}

v8::Handle<v8::Value> setTextColor(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int alpha = args[0]->Int32Value();
	int red = args[1]->Int32Value();
	int green = args[2]->Int32Value();
	int blue = args[3]->Int32Value();

	dbSetTextColor(alpha, red, green, blue);

	return v8::Undefined();
}


void RegisterScriptText(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbPerformChecklistForFonts"), v8::FunctionTemplate::New(performChecklistForFonts));
	global->Set(v8::String::New("dbText"), v8::FunctionTemplate::New(text));
	global->Set(v8::String::New("dbCenterText"), v8::FunctionTemplate::New(centerText));
	global->Set(v8::String::New("dbSetTextFont"), v8::FunctionTemplate::New(setTextFont));
	global->Set(v8::String::New("dbSetTextSize"), v8::FunctionTemplate::New(setTextSize));
	global->Set(v8::String::New("dbSetTextToNormal"), v8::FunctionTemplate::New(setTextToNormal));
	global->Set(v8::String::New("dbSetTextToItalic"), v8::FunctionTemplate::New(setTextToItalic));
	global->Set(v8::String::New("dbSetTextToBold"), v8::FunctionTemplate::New(setTextToBold));
	global->Set(v8::String::New("dbSetTextToBoldItalic"), v8::FunctionTemplate::New(setTextToBoldItalic));
	global->Set(v8::String::New("dbSetTextToOpaque"), v8::FunctionTemplate::New(setTextToOpaque));
	global->Set(v8::String::New("dbSetTextToTransparent"), v8::FunctionTemplate::New(setTextToTransparent));
	global->Set(v8::String::New("dbSetTextColor"), v8::FunctionTemplate::New(setTextColor));

	global->Set(v8::String::New("dbTextBackgroundType"), v8::FunctionTemplate::New(textBackgroundType));
	global->Set(v8::String::New("dbTextFont"), v8::FunctionTemplate::New(textFont));
	global->Set(v8::String::New("dbTextSize"), v8::FunctionTemplate::New(textSize));
	global->Set(v8::String::New("dbTextStyle"), v8::FunctionTemplate::New(textStyle));
	global->Set(v8::String::New("dbTextWidth"), v8::FunctionTemplate::New(textWidth));
	global->Set(v8::String::New("dbTextHeight"), v8::FunctionTemplate::New(textHeight));
}