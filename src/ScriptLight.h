// ScriptLight.h

v8::Handle<v8::Value> makeLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	dbMakeLight(lightId);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	dbDeleteLight(lightId);

	return v8::Undefined();
}

v8::Handle<v8::Value> showLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	dbShowLight(lightId);

	return v8::Undefined();
}

v8::Handle<v8::Value> hideLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	dbHideLight(lightId);

	return v8::Undefined();
}

v8::Handle<v8::Value> colorLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();
	DWORD color = args[1]->Int32Value();

	dbColorLight(lightId, color);

	return v8::Undefined();
}

v8::Handle<v8::Value> positionLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbPositionLight(lightId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> rotateLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbRotateLight(lightId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> pointLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbPointLight(lightId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> setDirectionalLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbSetDirectionalLight(lightId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> setPointLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbSetPointLight(lightId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> setSpotLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();
	float inner = args[1]->NumberValue();
	float outer = args[2]->NumberValue();

	dbSetSpotLight(lightId, inner, outer);

	return v8::Undefined();
}

v8::Handle<v8::Value> setLightRange(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();
	float dist = args[1]->NumberValue();

	dbSetLightRange(lightId, dist);

	return v8::Undefined();
}

v8::Handle<v8::Value> setLightToObjectPosition(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();
	int objId = args[1]->Int32Value();

	dbSetLightToObjectPosition(lightId, objId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setLightToObjectOrientation(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();
	int objId = args[1]->Int32Value();

	dbSetLightToObjectOrientation(lightId, objId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVector3ToLightPosition(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vecId = args[0]->Int32Value();
	int lightId = args[1]->Int32Value();

	dbSetVector3ToLightPosition(vecId, lightId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVector3ToLightRotation(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vecId = args[0]->Int32Value();
	int lightId = args[1]->Int32Value();

	dbSetVector3ToLightRotation(vecId, lightId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setNormalizationOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbSetNormalizationOn();

	return v8::Undefined();
}

v8::Handle<v8::Value> setNormalizationOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbSetNormalizationOff();

	return v8::Undefined();
}

v8::Handle<v8::Value> fogOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbFogOn();

	return v8::Undefined();
}

v8::Handle<v8::Value> fogOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbFogOff();

	return v8::Undefined();
}

v8::Handle<v8::Value> fogColor(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	DWORD color = args[0]->Int32Value();

	dbFogColor(color);

	return v8::Undefined();
}

v8::Handle<v8::Value> fogDistance(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	if(args.Length() > 1)
	{
		int start = args[0]->Int32Value();
		int finish = args[1]->Int32Value();

		dbFogDistance(start, finish);
	} else {
		int dist = args[0]->Int32Value();

		dbFogDistance(dist);
	}

	return v8::Undefined();
}

v8::Handle<v8::Value> setAmbientLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int percent = args[0]->Int32Value();

	dbSetAmbientLight(percent);

	return v8::Undefined();
}

v8::Handle<v8::Value> colorAmbientLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	DWORD color = args[0]->Int32Value();

	dbColorAmbientLight(color);

	return v8::Undefined();
}

v8::Handle<v8::Value> lightExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	return v8::Boolean::New(dbLightExist(lightId));
}

v8::Handle<v8::Value> lightType(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	return v8::Int32::New(dbLightType(lightId));
}

v8::Handle<v8::Value> lightVisible(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	return v8::Boolean::New(dbLightVisible(lightId));
}

v8::Handle<v8::Value> lightRange(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	return v8::Number::New(dbLightRange(lightId));
}

v8::Handle<v8::Value> lightPositionX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	return v8::Number::New(dbLightPositionX(lightId));
}

v8::Handle<v8::Value> lightPositionY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	return v8::Number::New(dbLightPositionY(lightId));
}

v8::Handle<v8::Value> lightPositionZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	return v8::Number::New(dbLightPositionZ(lightId));
}

v8::Handle<v8::Value> lightDirectionX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	return v8::Number::New(dbLightDirectionX(lightId));
}

v8::Handle<v8::Value> lightDirectionY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	return v8::Number::New(dbLightDirectionY(lightId));
}

v8::Handle<v8::Value> lightDirectionZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int lightId = args[0]->Int32Value();

	return v8::Number::New(dbLightDirectionZ(lightId));
}

void RegisterScriptLight(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbMakeLight"), v8::FunctionTemplate::New(makeLight));
	global->Set(v8::String::New("dbDeleteLight"), v8::FunctionTemplate::New(deleteLight));
	global->Set(v8::String::New("dbShowLight"), v8::FunctionTemplate::New(showLight));
	global->Set(v8::String::New("dbHideLight"), v8::FunctionTemplate::New(hideLight));
	global->Set(v8::String::New("dbColorLight"), v8::FunctionTemplate::New(colorLight));
	global->Set(v8::String::New("dbPositionLight"), v8::FunctionTemplate::New(positionLight));
	global->Set(v8::String::New("dbRotateLight"), v8::FunctionTemplate::New(rotateLight));
	global->Set(v8::String::New("dbPointLight"), v8::FunctionTemplate::New(pointLight));

	global->Set(v8::String::New("dbSetDirectionalLight"), v8::FunctionTemplate::New(setDirectionalLight));
	global->Set(v8::String::New("dbSetPointLight"), v8::FunctionTemplate::New(setPointLight));
	global->Set(v8::String::New("dbSetSpotLight"), v8::FunctionTemplate::New(setSpotLight));
	global->Set(v8::String::New("dbSetLightRange"), v8::FunctionTemplate::New(setLightRange));
	global->Set(v8::String::New("dbSetLightToObjectPosition"), v8::FunctionTemplate::New(setLightToObjectPosition));
	global->Set(v8::String::New("dbSetLightToObjectOrientation"), v8::FunctionTemplate::New(setLightToObjectOrientation));
	global->Set(v8::String::New("dbSetVector3ToLightPosition"), v8::FunctionTemplate::New(setVector3ToLightPosition));
	global->Set(v8::String::New("dbSetVector3ToLightRotation"), v8::FunctionTemplate::New(setVector3ToLightRotation));
	global->Set(v8::String::New("dbSetNormalizationOn"), v8::FunctionTemplate::New(setNormalizationOn));
	global->Set(v8::String::New("dbSetNormalizationOff"), v8::FunctionTemplate::New(setNormalizationOff));

	global->Set(v8::String::New("dbFogOn"), v8::FunctionTemplate::New(fogOn));
	global->Set(v8::String::New("dbFogOff"), v8::FunctionTemplate::New(fogOff));
	global->Set(v8::String::New("dbFogColor"), v8::FunctionTemplate::New(fogColor));
	global->Set(v8::String::New("dbFogDistance"), v8::FunctionTemplate::New(fogDistance));
	global->Set(v8::String::New("dbSetAmbientLight"), v8::FunctionTemplate::New(setAmbientLight));
	global->Set(v8::String::New("dbColorAmbientLight"), v8::FunctionTemplate::New(colorAmbientLight));

	global->Set(v8::String::New("dbLightExist"), v8::FunctionTemplate::New(lightExist));
	global->Set(v8::String::New("dbLightType"), v8::FunctionTemplate::New(lightType));
	global->Set(v8::String::New("dbLightVisible"), v8::FunctionTemplate::New(lightVisible));
	global->Set(v8::String::New("dbLightRange"), v8::FunctionTemplate::New(lightRange));
	global->Set(v8::String::New("dbLightPositionX"), v8::FunctionTemplate::New(lightPositionX));
	global->Set(v8::String::New("dbLightPositionY"), v8::FunctionTemplate::New(lightPositionY));
	global->Set(v8::String::New("dbLightPositionZ"), v8::FunctionTemplate::New(lightPositionZ));
	global->Set(v8::String::New("dbLightDirectionX"), v8::FunctionTemplate::New(lightDirectionX));
	global->Set(v8::String::New("dbLightDirectionY"), v8::FunctionTemplate::New(lightDirectionY));
	global->Set(v8::String::New("dbLightDirectionZ"), v8::FunctionTemplate::New(lightDirectionZ));
}