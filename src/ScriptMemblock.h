// ScriptMemblock.h

v8::Handle<v8::Value> makeMemblock(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int size = args[1]->Int32Value();

	dbMakeMemblock(memId, size);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeMemblockFromBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int bmp = args[1]->Int32Value();

	dbMakeMemblockFromBitmap(memId, bmp);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeMemblockFromImage(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int imageId = args[1]->Int32Value();

	dbMakeMemblockFromImage(memId, imageId);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeMemblockFromSound(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int soundId = args[1]->Int32Value();

	dbMakeMemblockFromSound(memId, soundId);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeMemblockFromMesh(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int meshId = args[1]->Int32Value();

	dbMakeMemblockFromMesh(memId, meshId);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteMemblock(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();

	dbDeleteMemblock(memId);

	return v8::Undefined();
}

v8::Handle<v8::Value> copyMemblock(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int from = args[0]->Int32Value();
	int to = args[1]->Int32Value();
	int posF = args[2]->Int32Value();
	int posT = args[3]->Int32Value();
	int size = args[4]->Int32Value();

	dbCopyMemblock(from, to, posF, posT, size);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeBitmapFromMemblock(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();
	int memId = args[1]->Int32Value();

	dbMakeBitmapFromMemblock(bitmapId, memId);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeImageFromMemblock(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int imageId = args[0]->Int32Value();
	int memId = args[1]->Int32Value();

	dbMakeImageFromMemblock(imageId, memId);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeSoundFromMemblock(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();
	int memId = args[1]->Int32Value();

	dbMakeSoundFromMemblock(soundId, memId);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeMeshFromMemblock(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int meshId = args[0]->Int32Value();
	int memId = args[1]->Int32Value();

	dbMakeMeshFromMemblock(meshId, memId);

	return v8::Undefined();
}

v8::Handle<v8::Value> changeMeshFromMemblock(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int meshId = args[0]->Int32Value();
	int memId = args[1]->Int32Value();

	dbChangeMeshFromMemblock(meshId, memId);

	return v8::Undefined();
}

v8::Handle<v8::Value> writeMemblockByte(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int pos = args[1]->Int32Value();
	int data = args[2]->Int32Value();

	dbWriteMemblockByte(memId, pos, data);

	return v8::Undefined();
}

v8::Handle<v8::Value> writeMemblockWord(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int pos = args[1]->Int32Value();
	WORD data = args[2]->Int32Value();

	dbWriteMemblockWord(memId, pos, data);

	return v8::Undefined();
}

v8::Handle<v8::Value> writeMemblockDword(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int pos = args[1]->Int32Value();
	DWORD data = args[2]->Int32Value();

	dbWriteMemblockDWORD(memId, pos, data);

	return v8::Undefined();
}

v8::Handle<v8::Value> writeMemblockFloat(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int pos = args[1]->Int32Value();
	float data = args[2]->NumberValue();

	dbWriteMemblockFloat(memId, pos, data);

	return v8::Undefined();
}

v8::Handle<v8::Value> memblockExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	
	return v8::Boolean::New(dbMemblockExist(memId));
}

v8::Handle<v8::Value> getMemblockPtr(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	
	return v8::Uint32::New(dbGetMemblockPtr(memId));
}

v8::Handle<v8::Value> getMemblockSize(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	
	return v8::Int32::New(dbGetMemblockSize(memId));
}

v8::Handle<v8::Value> memblockByte(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int pos = args[1]->Int32Value();
	
	return v8::Integer::New(dbMemblockByte(memId, pos));
}

v8::Handle<v8::Value> memblockWord(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int pos = args[1]->Int32Value();
	
	return v8::Integer::New(dbMemblockWord(memId, pos));
}

v8::Handle<v8::Value> memblockDword(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int pos = args[1]->Int32Value();
	
	return v8::Uint32::New(dbMemblockDword(memId, pos));
}

v8::Handle<v8::Value> memblockFloat(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memId = args[0]->Int32Value();
	int pos = args[1]->Int32Value();
	
	return v8::Number::New(dbMemblockFloat(memId, pos));
}

void RegisterScriptMemblock(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbMakeMemblock"), v8::FunctionTemplate::New(makeMemblock));
	global->Set(v8::String::New("dbMakeMemblockFromBitmap"), v8::FunctionTemplate::New(makeMemblockFromBitmap));
	global->Set(v8::String::New("dbMakeMemblockFromImage"), v8::FunctionTemplate::New(makeMemblockFromImage));
	global->Set(v8::String::New("dbMakeMemblockFromSound"), v8::FunctionTemplate::New(makeMemblockFromSound));
	global->Set(v8::String::New("dbMakeMemblockFromMesh"), v8::FunctionTemplate::New(makeMemblockFromMesh));
	global->Set(v8::String::New("dbDeleteMemblock"), v8::FunctionTemplate::New(deleteMemblock));
	global->Set(v8::String::New("dbCopyMemblock"), v8::FunctionTemplate::New(copyMemblock));
	global->Set(v8::String::New("dbMakeBitmapFromMemblock"), v8::FunctionTemplate::New(makeBitmapFromMemblock));
	global->Set(v8::String::New("dbMakeImageFromMemblock"), v8::FunctionTemplate::New(makeImageFromMemblock));
	global->Set(v8::String::New("dbMakeSoundFromMemblock"), v8::FunctionTemplate::New(makeSoundFromMemblock));
	global->Set(v8::String::New("dbMakeMeshFromMemblock"), v8::FunctionTemplate::New(makeMeshFromMemblock));
	global->Set(v8::String::New("dbChangeMeshFromMemblock"), v8::FunctionTemplate::New(changeMeshFromMemblock));
	global->Set(v8::String::New("dbWriteMemblockByte"), v8::FunctionTemplate::New(writeMemblockByte));
	global->Set(v8::String::New("dbWriteMemblockWord"), v8::FunctionTemplate::New(writeMemblockWord));
	global->Set(v8::String::New("dbWriteMemblockDword"), v8::FunctionTemplate::New(writeMemblockDword));
	global->Set(v8::String::New("dbWriteMemblockFloat"), v8::FunctionTemplate::New(writeMemblockFloat));

	global->Set(v8::String::New("dbMemblockExist"), v8::FunctionTemplate::New(memblockExist));
	global->Set(v8::String::New("dbGetMemblockPtr"), v8::FunctionTemplate::New(getMemblockPtr));
	global->Set(v8::String::New("dbGetMemblockSize"), v8::FunctionTemplate::New(getMemblockSize));
	global->Set(v8::String::New("dbMemblockByte"), v8::FunctionTemplate::New(memblockByte));
	global->Set(v8::String::New("dbMemblockWord"), v8::FunctionTemplate::New(memblockWord));
	global->Set(v8::String::New("dbMemblockDword"), v8::FunctionTemplate::New(memblockDword));
	global->Set(v8::String::New("dbMemblockFloat"), v8::FunctionTemplate::New(memblockFloat));
}