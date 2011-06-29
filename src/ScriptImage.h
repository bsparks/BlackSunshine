// ScriptImage.h

v8::Handle<v8::Value> loadImage(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);

	int imgId = args[1]->Int32Value();

	dbLoadImage(ToCharString(temp), imgId);

	return v8::Undefined();
}

v8::Handle<v8::Value> saveImage(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);

	int imgId = args[1]->Int32Value();

	dbSaveImage(ToCharString(temp), imgId);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteImage(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int imgId = args[0]->Int32Value();

	dbDeleteImage(imgId);

	return v8::Undefined();
}

v8::Handle<v8::Value> getImage(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int imgId = args[0]->Int32Value();
	int left = args[1]->Int32Value();
	int top = args[2]->Int32Value();
	int right = args[3]->Int32Value();
	int bottom = args[4]->Int32Value();
	int flag = args[5]->Int32Value();

	dbGetImage(imgId, left, top, right, bottom, flag);

	return v8::Undefined();
}

v8::Handle<v8::Value> pasteImage(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int imgId = args[0]->Int32Value();
	int x = args[1]->Int32Value();
	int y = args[2]->Int32Value();
	int transparency = args[3]->Int32Value();

	dbPasteImage(imgId, x, y, transparency);

	return v8::Undefined();
}

v8::Handle<v8::Value> setImageColorKey(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int red = args[0]->Int32Value();
	int green = args[1]->Int32Value();
	int blue = args[2]->Int32Value();

	dbSetImageColorKey(red, green, blue);

	return v8::Undefined();
}

v8::Handle<v8::Value> imageExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int imgId = args[0]->Int32Value();

	return v8::Boolean::New(dbImageExist(imgId));
}

void RegisterScriptImage(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbLoadImage"), v8::FunctionTemplate::New(loadImage));
	global->Set(v8::String::New("dbSaveImage"), v8::FunctionTemplate::New(saveImage));
	global->Set(v8::String::New("dbDeleteImage"), v8::FunctionTemplate::New(deleteImage));
	global->Set(v8::String::New("dbGetImage"), v8::FunctionTemplate::New(getImage));
	global->Set(v8::String::New("dbPasteImage"), v8::FunctionTemplate::New(pasteImage));
	global->Set(v8::String::New("dbSetImageColorKey"), v8::FunctionTemplate::New(setImageColorKey));
	global->Set(v8::String::New("dbImageExist"), v8::FunctionTemplate::New(imageExist));
}