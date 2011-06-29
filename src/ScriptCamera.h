//ScriptCamera.h
// camera commands

v8::Handle<v8::Value> makeCamera(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	dbMakeCamera(camId);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteCamera(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	dbDeleteCamera(camId);

	return v8::Undefined();
}

// todo: make an exception for omitting the id for 0 ?
v8::Handle<v8::Value> moveCamera(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float dist = args[1]->NumberValue();

	dbMoveCamera(camId, dist);

	return v8::Undefined();
}

// todo: allow for vector usage? omit id?
v8::Handle<v8::Value> positionCamera(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbPositionCamera(camId, x, y, z);

	return v8::Undefined();
}

// todo: allow for vector usage? omit id?
v8::Handle<v8::Value> pointCamera(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbPointCamera(camId, x, y, z);

	return v8::Undefined();
}

// todo: allow for vector usage? omit id?
v8::Handle<v8::Value> rotateCamera(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbRotateCamera(camId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> xRotateCamera(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float x = args[1]->NumberValue();

	dbXRotateCamera(camId, x);

	return v8::Undefined();
}

v8::Handle<v8::Value> yRotateCamera(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float y = args[1]->NumberValue();

	dbYRotateCamera(camId, y);

	return v8::Undefined();
}

v8::Handle<v8::Value> zRotateCamera(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float z = args[1]->NumberValue();

	dbZRotateCamera(camId, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> turnCameraLeft(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float angle = args[1]->NumberValue();

	dbTurnCameraLeft(camId, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> turnCameraRight(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float angle = args[1]->NumberValue();

	dbTurnCameraRight(camId, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> pitchCameraUp(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float angle = args[1]->NumberValue();

	dbPitchCameraUp(camId, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> pitchCameraDown(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float angle = args[1]->NumberValue();

	dbPitchCameraDown(camId, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> rollCameraLeft(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float angle = args[1]->NumberValue();

	dbRollCameraLeft(camId, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> rollCameraRight(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float angle = args[1]->NumberValue();

	dbRollCameraRight(camId, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCurrentCamera(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	dbSetCurrentCamera(camId);

	return v8::Undefined();
}

v8::Handle<v8::Value> clearCameraView(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	int color = args[1]->Int32Value();

	dbClearCameraView(camId, color);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCameraFOV(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float angle = args[1]->NumberValue();

	dbSetCameraFOV(camId, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCameraRange(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float fNear = args[1]->NumberValue();
	float fFar = args[2]->NumberValue();

	dbSetCameraRange(camId, fNear, fFar);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCameraView(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float left = args[1]->NumberValue();
	float top = args[2]->NumberValue();
	float right = args[3]->NumberValue();
	float bottom = args[4]->NumberValue();

	dbSetCameraView(camId, left, top, right, bottom);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCameraAspect(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float ratio = args[1]->NumberValue();

	dbSetCameraAspect(camId, ratio);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCameraRotationXYZ(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	dbSetCameraRotationXYZ(camId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCameraRotationZYX(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	dbSetCameraRotationZYX(camId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCameraToFollow(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();
	float angle = args[4]->NumberValue();
	float dist = args[5]->NumberValue();
	float height = args[6]->NumberValue();
	float smooth = args[7]->NumberValue();
	int collision = args[8]->Int32Value();

	dbSetCameraToFollow(camId, x, y, z, angle, dist, height, smooth, collision);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCameraToImage(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	int image = args[1]->Int32Value();
	int width = args[2]->Int32Value();
	int height = args[3]->Int32Value();

	dbSetCameraToImage(camId, image, width, height);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCameraToObjectOrientation(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	int objId = args[1]->Int32Value();

	dbSetCameraToObjectOrientation(camId, objId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVector3ToCameraPosition(const v8::Arguments& args)
{
	int vecId = args[0]->Int32Value();
	int camId = args[1]->Int32Value();

	dbSetVector3ToCameraPosition(vecId, camId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVector3ToCameraRotation(const v8::Arguments& args)
{
	int vecId = args[0]->Int32Value();
	int camId = args[1]->Int32Value();

	dbSetVector3ToCameraRotation(vecId, camId);

	return v8::Undefined();
}

v8::Handle<v8::Value> controlCameraUsingArrowKeys(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float move = args[1]->NumberValue();
	float turn = args[2]->NumberValue();

	dbControlCameraUsingArrowKeys(camId, move, turn);

	return v8::Undefined();
}

v8::Handle<v8::Value> autoCamOn(const v8::Arguments& args)
{
	dbAutoCamOn();

	return v8::Undefined();
}

v8::Handle<v8::Value> autoCamOff(const v8::Arguments& args)
{
	dbAutoCamOff();

	return v8::Undefined();
}

v8::Handle<v8::Value> backdropOn(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	dbBackdropOn(camId);

	return v8::Undefined();
}

v8::Handle<v8::Value> backdropOff(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	dbBackdropOff(camId);

	return v8::Undefined();
}

v8::Handle<v8::Value> colorBackdrop(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	int color = args[1]->Int32Value();

	dbColorBackdrop(camId, color);

	return v8::Undefined();
}

v8::Handle<v8::Value> textureBackdrop(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	int imgId = args[1]->Int32Value();

	dbTextureBackdrop(camId, imgId);

	return v8::Undefined();
}

v8::Handle<v8::Value> scrollBackdrop(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();
	float u = args[1]->NumberValue();
	float v = args[2]->NumberValue();

	dbScrollBackdrop(camId, u, v);

	return v8::Undefined();
}

v8::Handle<v8::Value> getCameraPositionX(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	return v8::Number::New(dbCameraPositionX(camId));
}

v8::Handle<v8::Value> getCameraPositionY(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	return v8::Number::New(dbCameraPositionY(camId));
}

v8::Handle<v8::Value> getCameraPositionZ(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	return v8::Number::New(dbCameraPositionZ(camId));
}

v8::Handle<v8::Value> getCameraAngleX(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	return v8::Number::New(dbCameraAngleX(camId));
}

v8::Handle<v8::Value> getCameraAngleY(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	return v8::Number::New(dbCameraAngleY(camId));
}

v8::Handle<v8::Value> getCameraAngleZ(const v8::Arguments& args)
{
	int camId = args[0]->Int32Value();

	return v8::Number::New(dbCameraAngleZ(camId));
}

void RegisterScriptCamera(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbMakeCamera"), v8::FunctionTemplate::New(makeCamera));
	global->Set(v8::String::New("dbDeleteCamera"), v8::FunctionTemplate::New(deleteCamera));
	global->Set(v8::String::New("dbMoveCamera"), v8::FunctionTemplate::New(moveCamera));
	global->Set(v8::String::New("dbPositionCamera"), v8::FunctionTemplate::New(positionCamera));
	global->Set(v8::String::New("dbPointCamera"), v8::FunctionTemplate::New(pointCamera));
	global->Set(v8::String::New("dbRotateCamera"), v8::FunctionTemplate::New(rotateCamera));
	global->Set(v8::String::New("dbXRotateCamera"), v8::FunctionTemplate::New(xRotateCamera));
	global->Set(v8::String::New("dbYRotateCamera"), v8::FunctionTemplate::New(yRotateCamera));
	global->Set(v8::String::New("dbZRotateCamera"), v8::FunctionTemplate::New(zRotateCamera));
	global->Set(v8::String::New("dbTurnCameraLeft"), v8::FunctionTemplate::New(turnCameraLeft));
	global->Set(v8::String::New("dbTurnCameraRight"), v8::FunctionTemplate::New(turnCameraRight));
	global->Set(v8::String::New("dbPitchCameraUp"), v8::FunctionTemplate::New(pitchCameraUp));
	global->Set(v8::String::New("dbPitchCameraDown"), v8::FunctionTemplate::New(pitchCameraDown));
	global->Set(v8::String::New("dbRollCameraLeft"), v8::FunctionTemplate::New(rollCameraLeft));
	global->Set(v8::String::New("dbRollCameraRight"), v8::FunctionTemplate::New(rollCameraRight));
	global->Set(v8::String::New("dbSetCurrentCamera"), v8::FunctionTemplate::New(setCurrentCamera));
	global->Set(v8::String::New("dbClearCameraView"), v8::FunctionTemplate::New(clearCameraView));
	global->Set(v8::String::New("dbSetCameraFOV"), v8::FunctionTemplate::New(setCameraFOV));
	global->Set(v8::String::New("dbSetCameraRange"), v8::FunctionTemplate::New(setCameraRange));
	global->Set(v8::String::New("dbSetCameraView"), v8::FunctionTemplate::New(setCameraView));
	global->Set(v8::String::New("dbSetCameraAspect"), v8::FunctionTemplate::New(setCameraAspect));
	global->Set(v8::String::New("dbSetCameraRotationXYZ"), v8::FunctionTemplate::New(setCameraRotationXYZ));
	global->Set(v8::String::New("dbSetCameraRotationZYX"), v8::FunctionTemplate::New(setCameraRotationZYX));
	global->Set(v8::String::New("dbSetCameraToFollow"), v8::FunctionTemplate::New(setCameraToFollow));
	global->Set(v8::String::New("dbSetCameraToObjectOrientation"), v8::FunctionTemplate::New(setCameraToObjectOrientation));
	global->Set(v8::String::New("dbSetVector3ToCameraPosition"), v8::FunctionTemplate::New(setVector3ToCameraPosition));
	global->Set(v8::String::New("dbSetVector3ToCameraRotation"), v8::FunctionTemplate::New(setVector3ToCameraRotation));
	global->Set(v8::String::New("dbControlCameraUsingArrowKeys"), v8::FunctionTemplate::New(controlCameraUsingArrowKeys));
	global->Set(v8::String::New("dbAutoCamOn"), v8::FunctionTemplate::New(autoCamOn));
	global->Set(v8::String::New("dbAutoCamOff"), v8::FunctionTemplate::New(autoCamOff));
	global->Set(v8::String::New("dbBackdropOn"), v8::FunctionTemplate::New(backdropOn));
	global->Set(v8::String::New("dbBackdropOff"), v8::FunctionTemplate::New(backdropOff));
	global->Set(v8::String::New("dbColorBackdrop"), v8::FunctionTemplate::New(colorBackdrop));
	global->Set(v8::String::New("dbTextureBackdrop"), v8::FunctionTemplate::New(textureBackdrop));
	global->Set(v8::String::New("dbScrollBackdrop"), v8::FunctionTemplate::New(scrollBackdrop));
	global->Set(v8::String::New("dbCameraPositionX"), v8::FunctionTemplate::New(getCameraPositionX));
	global->Set(v8::String::New("dbCameraPositionY"), v8::FunctionTemplate::New(getCameraPositionY));
	global->Set(v8::String::New("dbCameraPositionZ"), v8::FunctionTemplate::New(getCameraPositionZ));
	global->Set(v8::String::New("dbCameraAngleX"), v8::FunctionTemplate::New(getCameraAngleX));
	global->Set(v8::String::New("dbCameraAngleY"), v8::FunctionTemplate::New(getCameraAngleY));
	global->Set(v8::String::New("dbCameraAngleZ"), v8::FunctionTemplate::New(getCameraAngleZ));
}