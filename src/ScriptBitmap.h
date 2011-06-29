// ScriptBitmap.h

v8::Handle<v8::Value> loadBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);
	
	int bitmapId = args[1]->Int32Value();

	dbLoadBitmap(ToCharString(temp), bitmapId);

	return v8::Undefined();
}

v8::Handle<v8::Value> createBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();
	int width = args[1]->Int32Value();
	int height = args[2]->Int32Value();

	dbCreateBitmap(bitmapId, width, height);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();

	dbDeleteBitmap(bitmapId);

	return v8::Undefined();
}

v8::Handle<v8::Value> copyBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int from = args[0]->Int32Value();
	int to = args[1]->Int32Value();

	dbCopyBitmap(from, to);

	return v8::Undefined();
}

v8::Handle<v8::Value> flipBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();

	dbFlipBitmap(bitmapId);

	return v8::Undefined();
}

v8::Handle<v8::Value> mirrorBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();

	dbMirrorBitmap(bitmapId);

	return v8::Undefined();
}

v8::Handle<v8::Value> fadeBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();
	int fade = args[1]->Int32Value();

	dbFadeBitmap(bitmapId, fade);

	return v8::Undefined();
}

v8::Handle<v8::Value> blurBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();
	int blur = args[1]->Int32Value();

	dbBlurBitmap(bitmapId, blur);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCurrentBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();

	dbSetCurrentBitmap(bitmapId);

	return v8::Undefined();
}

v8::Handle<v8::Value> currentBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbCurrentBitmap());
}

v8::Handle<v8::Value> bitmapExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();

	return v8::Int32::New(dbBitmapExist());
}

v8::Handle<v8::Value> bitmapWidth(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();

	return v8::Int32::New(dbBitmapWidth());
}

v8::Handle<v8::Value> bitmapHeight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();

	return v8::Int32::New(dbBitmapHeight());
}

v8::Handle<v8::Value> bitmapDepth(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();

	return v8::Int32::New(dbBitmapDepth());
}

v8::Handle<v8::Value> bitmapMirrored(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();

	return v8::Int32::New(dbBitmapMirrored());
}

v8::Handle<v8::Value> bitmapFlipped(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();

	return v8::Int32::New(dbBitmapFlipped());
}

void RegisterScriptBitmap(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbLoadBitmap"), v8::FunctionTemplate::New(loadBitmap));
	global->Set(v8::String::New("dbCreateBitmap"), v8::FunctionTemplate::New(createBitmap));
	global->Set(v8::String::New("dbDeleteBitmap"), v8::FunctionTemplate::New(deleteBitmap));
	global->Set(v8::String::New("dbCopyBitmap"), v8::FunctionTemplate::New(copyBitmap));
	global->Set(v8::String::New("dbFlipBitmap"), v8::FunctionTemplate::New(flipBitmap));
	global->Set(v8::String::New("dbMirrorBitmap"), v8::FunctionTemplate::New(mirrorBitmap));
	global->Set(v8::String::New("dbFadeBitmap"), v8::FunctionTemplate::New(fadeBitmap));
	global->Set(v8::String::New("dbBlurBitmap"), v8::FunctionTemplate::New(blurBitmap));
	global->Set(v8::String::New("dbSetCurrentBitmap"), v8::FunctionTemplate::New(setCurrentBitmap));
	global->Set(v8::String::New("dbCurrentBitmap"), v8::FunctionTemplate::New(currentBitmap));
	global->Set(v8::String::New("dbBitmapExist"), v8::FunctionTemplate::New(bitmapExist));
	global->Set(v8::String::New("dbBitmapWidth"), v8::FunctionTemplate::New(bitmapWidth));
	global->Set(v8::String::New("dbBitmapHeight"), v8::FunctionTemplate::New(bitmapHeight));
	global->Set(v8::String::New("dbBitmapDepth"), v8::FunctionTemplate::New(bitmapDepth));
	global->Set(v8::String::New("dbBitmapMirrored"), v8::FunctionTemplate::New(bitmapMirrored));
	global->Set(v8::String::New("dbBitmapFlipped"), v8::FunctionTemplate::New(bitmapFlipped));
}