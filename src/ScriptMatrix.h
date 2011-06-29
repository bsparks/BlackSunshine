// ScriptMatrix.h

v8::Handle<v8::Value> makeMatrix(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	float width = args[1]->NumberValue();
	float depth = args[2]->NumberValue();
	int x = args[3]->Int32Value();
	int z = args[4]->Int32Value();

	dbMakeMatrix(matrixId, width, depth, x, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteMatrix(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	dbDeleteMatrix(matrixId);

	return v8::Undefined();
}

v8::Handle<v8::Value> prepareMatrixTexture(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	int imageId = args[1]->Int32Value();
	int across = args[2]->Int32Value();
	int down = args[3]->Int32Value();

	dbPrepareMatrixTexture(matrixId, imageId, across, down);

	return v8::Undefined();
}

v8::Handle<v8::Value> positionMatrix(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbPositionMatrix(matrixId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> fillMatrix(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	float height = args[1]->NumberValue();
	int tile = args[2]->Int32Value();

	dbFillMatrix(matrixId, height, tile);

	return v8::Undefined();
}

v8::Handle<v8::Value> randomizeMatrix(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	int height = args[1]->Int32Value();

	dbRandomizeMatrix(matrixId, height);

	return v8::Undefined();
}

v8::Handle<v8::Value> ghostMatrixOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	dbGhostMatrixOn(matrixId);

	return v8::Undefined();
}

v8::Handle<v8::Value> ghostMatrixOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	dbGhostMatrixOff(matrixId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setMatrixWireframeOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	dbSetMatrixWireframeOn(matrixId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setMatrixWireframeOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	dbSetMatrixWireframeOff(matrixId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVector3ToMatrixPosition(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vecId = args[0]->Int32Value();
	int matrixId = args[1]->Int32Value();

	dbSetVector3ToMatrixPosition(vecId, matrixId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setMatrixTexture(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	int mode = args[1]->Int32Value();
	int mip = args[2]->Int32Value();

	dbSetMatrixTexture(matrixId, mode, mip);

	return v8::Undefined();
}

v8::Handle<v8::Value> setMatrix(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	int wireframe = args[1]->Int32Value();
	int transparency = args[2]->Int32Value();
	int cull = args[3]->Int32Value();
	int filter = args[4]->Int32Value();
	int light = args[5]->Int32Value();
	int fog = args[6]->Int32Value();
	int ambient = args[7]->Int32Value();

	dbSetMatrix(matrixId, wireframe, transparency, cull, filter, light, fog, ambient);

	return v8::Undefined();
}

v8::Handle<v8::Value> setMatrixTrim(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();

	dbSetMatrixTrim(matrixId, x, y);

	return v8::Undefined();
}

v8::Handle<v8::Value> setMatrixPriority(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	int priority = args[1]->Int32Value();

	dbSetMatrixPriority(matrixId, priority);

	return v8::Undefined();
}

v8::Handle<v8::Value> shiftMatrixDown(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	dbShiftMatrixDown(matrixId);

	return v8::Undefined();
}

v8::Handle<v8::Value> shiftMatrixLeft(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	dbShiftMatrixLeft(matrixId);

	return v8::Undefined();
}

v8::Handle<v8::Value> shiftMatrixRight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	dbShiftMatrixRight(matrixId);

	return v8::Undefined();
}

v8::Handle<v8::Value> shiftMatrixUp(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	dbShiftMatrixUp(matrixId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setMatrixHeight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	int x = args[1]->Int32Value();
	int z = args[2]->Int32Value();
	float height = args[3]->NumberValue();

	dbSetMatrixHeight(matrixId, x, z, height);

	return v8::Undefined();
}

v8::Handle<v8::Value> setMatrixNormal(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	int x = args[1]->Int32Value();
	int z = args[2]->Int32Value();
	float fx = args[3]->NumberValue();
	float fy = args[4]->NumberValue();
	float fz = args[5]->NumberValue();

	dbSetMatrixNormal(matrixId, x, z, fx, fy, fz);

	return v8::Undefined();
}

v8::Handle<v8::Value> setMatrixTile(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	int x = args[1]->Int32Value();
	int z = args[2]->Int32Value();
	int tile = args[3]->Int32Value();

	dbSetMatrixTile(matrixId, x, z, tile);

	return v8::Undefined();
}

v8::Handle<v8::Value> updateMatrix(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	dbUpdateMatrix(matrixId);

	return v8::Undefined();
}

v8::Handle<v8::Value> matrixExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	return v8::Boolean::New(dbMatrixExist(matrixId));
}

v8::Handle<v8::Value> matrixPositionX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	return v8::Number::New(dbMatrixPositionX(matrixId));
}

v8::Handle<v8::Value> matrixPositionY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	return v8::Number::New(dbMatrixPositionY(matrixId));
}

v8::Handle<v8::Value> matrixPositionZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	return v8::Number::New(dbMatrixPositionZ(matrixId));
}

v8::Handle<v8::Value> matrixTileCount(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	return v8::Int32::New(dbMatrixTileCount(matrixId));
}

v8::Handle<v8::Value> matrixTilesExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	return v8::Boolean::New(dbMatrixTilesExist(matrixId));
}

v8::Handle<v8::Value> matrixWireframeState(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();

	return v8::Int32::New(dbMatrixWireframeState(matrixId));
}

v8::Handle<v8::Value> getGroundHeight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float z = args[2]->NumberValue();

	return v8::Number::New(dbGetGroundHeight(matrixId, x, z));
}

v8::Handle<v8::Value> getMatrixHeight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int matrixId = args[0]->Int32Value();
	int x = args[1]->Int32Value();
	int z = args[2]->Int32Value();

	return v8::Number::New(dbGetMatrixHeight(matrixId, x, z));
}

void RegisterScriptMatrix(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbMakeMatrix"), v8::FunctionTemplate::New(makeMatrix));
	global->Set(v8::String::New("dbDeleteMatrix"), v8::FunctionTemplate::New(deleteMatrix));
	global->Set(v8::String::New("dbPrepareMatrixTexture"), v8::FunctionTemplate::New(prepareMatrixTexture));
	global->Set(v8::String::New("dbPositionMatrix"), v8::FunctionTemplate::New(positionMatrix));
	global->Set(v8::String::New("dbFillMatrix"), v8::FunctionTemplate::New(fillMatrix));
	global->Set(v8::String::New("dbRandomizeMatrix"), v8::FunctionTemplate::New(randomizeMatrix));
	global->Set(v8::String::New("dbGhostMatrixOn"), v8::FunctionTemplate::New(ghostMatrixOn));
	global->Set(v8::String::New("dbGhostMatrixOff"), v8::FunctionTemplate::New(ghostMatrixOff));
	global->Set(v8::String::New("dbSetMatrixWireframeOn"), v8::FunctionTemplate::New(setMatrixWireframeOn));
	global->Set(v8::String::New("dbSetMatrixWireframeOff"), v8::FunctionTemplate::New(setMatrixWireframeOff));
	global->Set(v8::String::New("dbSetVector3ToMatrixPosition"), v8::FunctionTemplate::New(setVector3ToMatrixPosition));
	global->Set(v8::String::New("dbSetMatrixTexture"), v8::FunctionTemplate::New(setMatrixTexture));
	global->Set(v8::String::New("dbSetMatrix"), v8::FunctionTemplate::New(setMatrix));
	global->Set(v8::String::New("dbSetMatrixTrim"), v8::FunctionTemplate::New(setMatrixTrim));
	global->Set(v8::String::New("dbSetMatrixPriority"), v8::FunctionTemplate::New(setMatrixPriority));
	global->Set(v8::String::New("dbShiftMatrixDown"), v8::FunctionTemplate::New(shiftMatrixDown));
	global->Set(v8::String::New("dbShiftMatrixLeft"), v8::FunctionTemplate::New(shiftMatrixLeft));
	global->Set(v8::String::New("dbShiftMatrixRight"), v8::FunctionTemplate::New(shiftMatrixRight));
	global->Set(v8::String::New("dbShiftMatrixUp"), v8::FunctionTemplate::New(shiftMatrixUp));

	global->Set(v8::String::New("dbSetMatrixHeight"), v8::FunctionTemplate::New(setMatrixHeight));
	global->Set(v8::String::New("dbSetMatrixNormal"), v8::FunctionTemplate::New(setMatrixNormal));
	global->Set(v8::String::New("dbSetMatrixTile"), v8::FunctionTemplate::New(setMatrixTile));
	global->Set(v8::String::New("dbUpdateMatrix"), v8::FunctionTemplate::New(updateMatrix));

	global->Set(v8::String::New("dbMatrixExist"), v8::FunctionTemplate::New(matrixExist));
	global->Set(v8::String::New("dbMatrixPositionX"), v8::FunctionTemplate::New(matrixPositionX));
	global->Set(v8::String::New("dbMatrixPositionY"), v8::FunctionTemplate::New(matrixPositionY));
	global->Set(v8::String::New("dbMatrixPositionZ"), v8::FunctionTemplate::New(matrixPositionZ));
	global->Set(v8::String::New("dbMatrixTileCount"), v8::FunctionTemplate::New(matrixTileCount));
	global->Set(v8::String::New("dbMatrixTilesExist"), v8::FunctionTemplate::New(matrixTilesExist));
	global->Set(v8::String::New("dbMatrixWireframeState"), v8::FunctionTemplate::New(matrixWireframeState));
	global->Set(v8::String::New("dbGetGroundHeight"), v8::FunctionTemplate::New(getGroundHeight));
	global->Set(v8::String::New("dbGetMatrixHeight"), v8::FunctionTemplate::New(getMatrixHeight));
}