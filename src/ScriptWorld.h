// ScriptWorld.h

v8::Handle<v8::Value> loadBSP(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str1(args[0]);
	const char* pk3File = ToCString(str1);

	v8::String::Utf8Value str2(args[1]);
	const char* bspFile = ToCString(str2);

	dbLoadBSP(ToCharString(pk3File), ToCharString(bspFile));

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteBSP(const v8::Arguments& args)
{
	dbDeleteBSP();

	return v8::Undefined();
}

v8::Handle<v8::Value> setBSPCamera(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int cam = args[0]->Int32Value();

	dbSetBSPCamera(cam);

	return v8::Undefined();
}

v8::Handle<v8::Value> setBSPCameraCollision(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int colIdx = args[0]->Int32Value();
	int entityId = args[1]->Int32Value();
	float radius = args[2]->NumberValue();
	int response = args[3]->Int32Value();

	dbSetBSPCameraCollision(colIdx, entityId, radius, response);

	return v8::Undefined();
}

v8::Handle<v8::Value> setBSPObjectCollision(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int colIdx = args[0]->Int32Value();
	int entityId = args[1]->Int32Value();
	float radius = args[2]->NumberValue();
	int response = args[3]->Int32Value();

	dbSetBSPObjectCollision(colIdx, entityId, radius, response);

	return v8::Undefined();
}

v8::Handle<v8::Value> setBSPCollisionThreshold(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int colIdx = args[0]->Int32Value();
	float sensitivity = args[1]->NumberValue();

	dbSetBSPCollisionThreshold(colIdx, sensitivity);

	return v8::Undefined();
}

v8::Handle<v8::Value> setBSPCollisionOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();

	dbSetBSPCollisionOff(id);

	return v8::Undefined();
}

v8::Handle<v8::Value> setBSPCameraCollisionRadius(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int colIdx = args[0]->Int32Value();
	int camId = args[1]->Int32Value();
	float x = args[2]->NumberValue();
	float y = args[3]->NumberValue();
	float z = args[4]->NumberValue();

	dbSetBSPCameraCollisionRadius(colIdx, camId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> setBSPObjectCollisionRadius(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int colIdx = args[0]->Int32Value();
	int objId = args[1]->Int32Value();
	float x = args[2]->NumberValue();
	float y = args[3]->NumberValue();
	float z = args[4]->NumberValue();

	dbSetBSPObjectCollisionRadius(colIdx, objId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> setBSPCollisionHeightAdjustment(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int colIdx = args[0]->Int32Value();
	float height = args[1]->NumberValue();

	dbSetBSPCollisionHeightAdjustment(colIdx, height);

	return v8::Undefined();
}

v8::Handle<v8::Value> setBSPMultiTexturingOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbSetBSPMultiTexturingOn();

	return v8::Undefined();
}

v8::Handle<v8::Value> setBSPMultiTexturingOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbSetBSPMultiTexturingOff();

	return v8::Undefined();
}

v8::Handle<v8::Value> processBSPCollision(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int colIdx = args[0]->Int32Value();

	dbProcessBSPCollision(colIdx);

	return v8::Undefined();
}

v8::Handle<v8::Value> bspCollisionHit(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int colIdx = args[0]->Int32Value();

	return v8::Int32::New(dbBSPCollisionHit(colIdx));
}

v8::Handle<v8::Value> bspCollisionX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int colIdx = args[0]->Int32Value();

	return v8::Number::New(dbBSPCollisionX(colIdx));
}

v8::Handle<v8::Value> bspCollisionY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int colIdx = args[0]->Int32Value();

	return v8::Number::New(dbBSPCollisionY(colIdx));
}

v8::Handle<v8::Value> bspCollisionZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int colIdx = args[0]->Int32Value();

	return v8::Number::New(dbBSPCollisionZ(colIdx));
}

void RegisterScriptWorld(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbLoadBSP"), v8::FunctionTemplate::New(loadBSP));
	global->Set(v8::String::New("dbDeleteBSP"), v8::FunctionTemplate::New(deleteBSP));
	global->Set(v8::String::New("dbSetBSPCamera"), v8::FunctionTemplate::New(setBSPCamera));
	global->Set(v8::String::New("dbSetBSPObjectCollision"), v8::FunctionTemplate::New(setBSPObjectCollision));
	global->Set(v8::String::New("dbSetBSPCameraCollision"), v8::FunctionTemplate::New(setBSPCameraCollision));
	global->Set(v8::String::New("dbSetBSPCollisionThreshold"), v8::FunctionTemplate::New(setBSPCollisionThreshold));
	global->Set(v8::String::New("dbSetBSPCollisionOff"), v8::FunctionTemplate::New(setBSPCollisionOff));
	global->Set(v8::String::New("dbSetBSPCameraCollisionRadius"), v8::FunctionTemplate::New(setBSPCameraCollisionRadius));
	global->Set(v8::String::New("dbSetBSPObjectCollisionRadius"), v8::FunctionTemplate::New(setBSPObjectCollisionRadius));
	global->Set(v8::String::New("dbSetBSPCollisionHeightAdjustment"), v8::FunctionTemplate::New(setBSPCollisionHeightAdjustment));
	global->Set(v8::String::New("dbSetBSPMultiTexturingOn"), v8::FunctionTemplate::New(setBSPMultiTexturingOn));
	global->Set(v8::String::New("dbSetBSPMultiTexturingOff"), v8::FunctionTemplate::New(setBSPMultiTexturingOff));
	global->Set(v8::String::New("dbProcessBSPCollision"), v8::FunctionTemplate::New(processBSPCollision));
	
	global->Set(v8::String::New("dbBspCollisionHit"), v8::FunctionTemplate::New(bspCollisionHit));
	global->Set(v8::String::New("dbBspCollisionX"), v8::FunctionTemplate::New(bspCollisionX));
	global->Set(v8::String::New("dbBspCollisionY"), v8::FunctionTemplate::New(bspCollisionY));
	global->Set(v8::String::New("dbBspCollisionZ"), v8::FunctionTemplate::New(bspCollisionZ));
}