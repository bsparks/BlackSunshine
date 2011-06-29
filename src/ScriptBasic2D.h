//**************************** 2D **********************************

v8::Handle<v8::Value> ink(const v8::Arguments& args)
{
	DWORD fgColor = args[0]->Uint32Value();
	DWORD bgColor = args[1]->Uint32Value();

	dbInk(fgColor, bgColor);

	return v8::Undefined();
}

v8::Handle<v8::Value> cls(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbCLS();

	return v8::Undefined();
}

v8::Handle<v8::Value> dot(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int x = args[0]->Int32Value();
	int y = args[1]->Int32Value();

	dbDot(x, y);

	return v8::Undefined();
}

v8::Handle<v8::Value> drawLine(const v8::Arguments& args)
{
	if(args.Length() < 4)
		return v8::String::New("Syntax: drawLine(x1, y1, x2, y2)");

	int x1 = args[0]->Int32Value();
	int y1 = args[1]->Int32Value();
	int x2 = args[2]->Int32Value();
	int y2 = args[3]->Int32Value();

	dbLine(x1, y1, x2, y2);

	return v8::Undefined();
}

v8::Handle<v8::Value> drawBox(const v8::Arguments& args)
{
	if(args.Length() < 4)
		return v8::String::New("Syntax: drawBox(left, top, right, bottom)");

	int left = args[0]->Int32Value();
	int top = args[1]->Int32Value();
	int right = args[2]->Int32Value();
	int bottom = args[3]->Int32Value();

	dbBox(left, top, right, bottom);

	return v8::Undefined();
}

v8::Handle<v8::Value> drawCircle(const v8::Arguments& args)
{
	if(args.Length() < 3)
		return v8::String::New("Syntax: drawCircle(x, y, r)");

	int x = args[0]->Int32Value();
	int y = args[1]->Int32Value();
	int r = args[2]->Int32Value();

	dbCircle(x, y, r);

	return v8::Undefined();
}

v8::Handle<v8::Value> drawEllipse(const v8::Arguments& args)
{
	if(args.Length() < 4)
		return v8::String::New("Syntax: drawEllipse(x, y, rx, ry)");

	int x = args[0]->Int32Value();
	int y = args[1]->Int32Value();
	int rx = args[2]->Int32Value();
	int ry = args[3]->Int32Value();

	dbEllipse(x, y, rx, ry);

	return v8::Undefined();
}

v8::Handle<v8::Value> lockPixels(const v8::Arguments& args)
{
	dbLockPixels();

	return v8::Undefined();
}

v8::Handle<v8::Value> unlockPixels(const v8::Arguments& args)
{
	dbUnlockPixels();

	return v8::Undefined();
}

v8::Handle<v8::Value> rgb(const v8::Arguments& args)
{
	int r = args[0]->Int32Value();
	int g = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	return v8::Uint32::New(dbRGB(r,g,b));
}

v8::Handle<v8::Value> rgbR(const v8::Arguments& args)
{
	DWORD color = args[0]->Uint32Value();

	return v8::Uint32::New(dbRGBR(color));
}

v8::Handle<v8::Value> rgbG(const v8::Arguments& args)
{
	DWORD color = args[0]->Uint32Value();

	return v8::Uint32::New(dbRGBG(color));
}

v8::Handle<v8::Value> rgbB(const v8::Arguments& args)
{
	DWORD color = args[0]->Uint32Value();

	return v8::Uint32::New(dbRGBB(color));
}

v8::Handle<v8::Value> point(const v8::Arguments& args)
{
	int x = args[0]->Int32Value();
	int y = args[1]->Int32Value();

	return v8::Uint32::New(dbPoint(x, y));
}

void RegisterScriptBasic2D(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbInk"), v8::FunctionTemplate::New(ink));
	global->Set(v8::String::New("dbCLS"), v8::FunctionTemplate::New(cls));
	global->Set(v8::String::New("dbDot"), v8::FunctionTemplate::New(dot));
	global->Set(v8::String::New("dbLine"), v8::FunctionTemplate::New(drawLine));
	global->Set(v8::String::New("dbBox"), v8::FunctionTemplate::New(drawBox));
	global->Set(v8::String::New("dbCircle"), v8::FunctionTemplate::New(drawCircle));
	global->Set(v8::String::New("dbEllipse"), v8::FunctionTemplate::New(drawEllipse));

	global->Set(v8::String::New("dbRGB"), v8::FunctionTemplate::New(rgb));
	global->Set(v8::String::New("dbRGBR"), v8::FunctionTemplate::New(rgbR));
	global->Set(v8::String::New("dbRGBG"), v8::FunctionTemplate::New(rgbG));
	global->Set(v8::String::New("dbRGBB"), v8::FunctionTemplate::New(rgbB));
	global->Set(v8::String::New("dbPoint"), v8::FunctionTemplate::New(point));
	
	
}
