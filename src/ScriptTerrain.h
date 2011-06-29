// ScriptTerrain.h

v8::Handle<v8::Value> loadTerrain(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);
	
	int terrainId = args[1]->Int32Value();

	dbLoadTerrain(ToCharString(temp), terrainId);

	return v8::Undefined();
}

v8::Handle<v8::Value> saveTerrain(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);
	
	int terrainId = args[1]->Int32Value();

	dbSaveTerrain(ToCharString(temp), terrainId);

	return v8::Undefined();
}

v8::Handle<v8::Value> buildTerrain(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int terrainId = args[0]->Int32Value();

	dbBuildTerrain(terrainId);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeObjectTerrain(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int terrainId = args[0]->Int32Value();

	dbMakeObjectTerrain(terrainId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setTerrainScale(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int terrainId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbSetTerrainScale(terrainId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> setTerrainSplit(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int terrainId = args[0]->Int32Value();
	int split = args[1]->Int32Value();

	dbSetTerrainSplit(terrainId, split);

	return v8::Undefined();
}

v8::Handle<v8::Value> setTerrainTiling(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int terrainId = args[0]->Int32Value();
	int tile = args[1]->Int32Value();

	dbSetTerrainTiling(terrainId, tile);

	return v8::Undefined();
}

v8::Handle<v8::Value> setTerrainHeightmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int terrainId = args[0]->Int32Value();

	v8::String::Utf8Value str(args[1]);
	const char* temp = ToCString(str);

	dbSetTerrainHeightmap(terrainId, ToCharString(temp));

	return v8::Undefined();
}

v8::Handle<v8::Value> setTerrainTexture(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int terrainId = args[0]->Int32Value();
	int base = args[1]->Int32Value();
	int detail = args[2]->Int32Value();

	dbSetTerrainTexture(terrainId, base, detail);

	return v8::Undefined();
}

v8::Handle<v8::Value> setTerrainLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int terrainId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();
	float red = args[4]->NumberValue();
	float green = args[5]->NumberValue();
	float blue = args[6]->NumberValue();
	float scale = args[7]->NumberValue();

	dbSetTerrainLight(terrainId, x, y, z, red, green, blue, scale);

	return v8::Undefined();
}

v8::Handle<v8::Value> getTerrainGroundHeight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int terrainId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float z = args[2]->NumberValue();

	return v8::Number::New(dbGetTerrainGroundHeight(terrainId, x, z));
}

v8::Handle<v8::Value> getTerrainXSize(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int terrainId = args[0]->Int32Value();

	return v8::Number::New(dbGetTerrainXSize(terrainId));
}

v8::Handle<v8::Value> getTerrainZSize(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int terrainId = args[0]->Int32Value();

	return v8::Number::New(dbGetTerrainZSize(terrainId));
}

v8::Handle<v8::Value> setupTerrain(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	dbSetupTerrain();

	return v8::Undefined();
}

v8::Handle<v8::Value> updateTerrain(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	dbUpdateTerrain();

	return v8::Undefined();
}

void RegisterScriptTerrain(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbLoadTerrain"), v8::FunctionTemplate::New(loadTerrain));
	global->Set(v8::String::New("dbSaveTerrain"), v8::FunctionTemplate::New(saveTerrain));
	global->Set(v8::String::New("dbBuildTerrain"), v8::FunctionTemplate::New(buildTerrain));
	global->Set(v8::String::New("dbMakeObjectTerrain"), v8::FunctionTemplate::New(makeObjectTerrain));

	global->Set(v8::String::New("dbSetTerrainScale"), v8::FunctionTemplate::New(setTerrainScale));
	global->Set(v8::String::New("dbSetTerrainSplit"), v8::FunctionTemplate::New(setTerrainSplit));
	global->Set(v8::String::New("dbSetTerrainTiling"), v8::FunctionTemplate::New(setTerrainTiling));
	global->Set(v8::String::New("dbSetTerrainHeightmap"), v8::FunctionTemplate::New(setTerrainHeightmap));
	global->Set(v8::String::New("dbSetTerrainTexture"), v8::FunctionTemplate::New(setTerrainTexture));
	global->Set(v8::String::New("dbSetTerrainLight"), v8::FunctionTemplate::New(setTerrainLight));

	global->Set(v8::String::New("dbGetTerrainGroundHeight"), v8::FunctionTemplate::New(getTerrainGroundHeight));
	global->Set(v8::String::New("dbGetTerrainXSize"), v8::FunctionTemplate::New(getTerrainXSize));
	global->Set(v8::String::New("dbGetTerrainZSize"), v8::FunctionTemplate::New(getTerrainZSize));

	global->Set(v8::String::New("dbSetupTerrain"), v8::FunctionTemplate::New(setupTerrain));
	global->Set(v8::String::New("dbUpdateTerrain"), v8::FunctionTemplate::New(updateTerrain));
}