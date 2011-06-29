 // 3D OBJECT COMMANDS ********************************************************************************
//****************************************************************************************************

v8::Handle<v8::Value> loadObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);

	int objId = args[1]->Int32Value();

	dbLoadObject(ToCharString(temp), objId);

	return v8::Undefined();
}

v8::Handle<v8::Value> appendObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);

	int objId = args[1]->Int32Value();
	int frame = args[2]->Int32Value();

	dbAppendObject(ToCharString(temp), objId, frame);

	return v8::Undefined();
}

v8::Handle<v8::Value> cloneObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int source = args[1]->Int32Value();

	dbCloneObject(object, source);

	return v8::Undefined();
}

v8::Handle<v8::Value> instanceObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int source = args[1]->Int32Value();

	dbInstanceObject(object, source);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbDeleteObject(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> showObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbShowObject(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> hideObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbHideObject(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> positionObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	if(args.Length() < 4)
	{
		return v8::ThrowException(v8::String::New("Error: required arguments ID, x, y, z"));
	}

	int objId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	if(!dbObjectExist(objId))
	{
		return v8::ThrowException(v8::String::New("Error: object does not exist!"));
	}

	dbPositionObject(objId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> scaleObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	if(args.Length() < 4)
	{
		return v8::ThrowException(v8::String::New("Error: required arguments ID, x, y, z"));
	}

	int objId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	if(!dbObjectExist(objId))
	{
		return v8::ThrowException(v8::String::New("Error: object does not exist!"));
	}

	dbScaleObject(objId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> rotateObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	if(args.Length() < 4)
	{
		return v8::ThrowException(v8::String::New("Error: required arguments ID, x, y, z"));
	}

	int objId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	if(!dbObjectExist(objId))
	{
		return v8::ThrowException(v8::String::New("Error: object does not exist!"));
	}

	dbRotateObject(objId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> pointObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();
	
	dbPointObject(object, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> moveObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float step = args[1]->NumberValue();
	
	dbMoveObject(object, step);

	return v8::Undefined();
}

v8::Handle<v8::Value> moveObjectDown(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float step = args[1]->NumberValue();
	
	dbMoveObjectDown(object, step);

	return v8::Undefined();
}

v8::Handle<v8::Value> moveObjectLeft(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float step = args[1]->NumberValue();
	
	dbMoveObjectLeft(object, step);

	return v8::Undefined();
}

v8::Handle<v8::Value> moveObjectRight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float step = args[1]->NumberValue();
	
	dbMoveObjectRight(object, step);

	return v8::Undefined();
}

v8::Handle<v8::Value> moveObjectUp(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float step = args[1]->NumberValue();
	
	dbMoveObjectUp(object, step);

	return v8::Undefined();
}

v8::Handle<v8::Value> xRotateObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	
	dbXRotateObject(object, x);

	return v8::Undefined();
}

v8::Handle<v8::Value> yRotateObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float y = args[1]->NumberValue();
	
	dbYRotateObject(object, y);

	return v8::Undefined();
}

v8::Handle<v8::Value> zRotateObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float z = args[1]->NumberValue();
	
	dbZRotateObject(object, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> turnObjectLeft(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float angle = args[1]->NumberValue();
	
	dbTurnObjectLeft(object, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> turnObjectRight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float angle = args[1]->NumberValue();
	
	dbTurnObjectRight(object, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> pitchObjectUp(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float angle = args[1]->NumberValue();
	
	dbPitchObjectUp(object, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> pitchObjectDown(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float angle = args[1]->NumberValue();
	
	dbPitchObjectDown(object, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> rollObjectLeft(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float angle = args[1]->NumberValue();
	
	dbRollObjectLeft(object, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> rollObjectRight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float angle = args[1]->NumberValue();
	
	dbRollObjectRight(object, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> playObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	if(args.Length() == 1)
	{
		dbPlayObject(object);
	}

	if(args.Length() > 2)
	{
		int start = args[1]->Int32Value();
		int end = args[2]->Int32Value();

		dbPlayObject(object, start);
	}

	if(args.Length() > 1)
	{
		int start = args[1]->Int32Value();

		dbPlayObject(object, start);
	}

	return v8::Undefined();
}

v8::Handle<v8::Value> loopObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	if(args.Length() == 1)
	{
		dbLoopObject(object);
	}

	if(args.Length() > 2)
	{
		int start = args[1]->Int32Value();
		int end = args[2]->Int32Value();

		dbLoopObject(object, start);
	}

	if(args.Length() > 1)
	{
		int start = args[1]->Int32Value();

		dbLoopObject(object, start);
	}

	return v8::Undefined();
}

v8::Handle<v8::Value> stopObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbStopObject(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectFrame(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float frame = args[1]->NumberValue();
	int recal = args[2]->Int32Value();
	
	dbSetObjectFrame(object, frame, recal);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectSpeed(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int speed = args[1]->Int32Value();
	
	dbSetObjectSpeed(object, speed);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectInterpolation(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int jump = args[1]->Int32Value();
	
	dbSetObjectInterpolation(object, jump);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int mesh = args[1]->Int32Value();
	int texture = args[2]->Int32Value();
	
	dbMakeObject(object, mesh, texture);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeObjectBox(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float width = args[1]->NumberValue();
	float height = args[2]->NumberValue();
	float depth = args[3]->NumberValue();
	
	dbMakeObjectBox(object, width, height, depth);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeObjectCone(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float size = args[1]->NumberValue();
	
	dbMakeObjectCone(object, size);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeObjectCube(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	if(args.Length() < 2)
	{
		return v8::ThrowException(v8::String::New("Error: required arguments ID, Size"));
	}

	int objId = args[0]->Int32Value();
	float size = args[1]->NumberValue();

	dbMakeObjectCube(objId, size);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeObjectCylinder(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float size = args[1]->NumberValue();
	
	dbMakeObjectCylinder(object, size);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeObjectFromLimb(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int source = args[1]->Int32Value();
	int limb = args[2]->Int32Value();
	
	dbMakeObjectFromLimb(object, source, limb);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeObjectPlain(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float width = args[1]->NumberValue();
	float height = args[2]->NumberValue();
	
	dbMakeObjectPlain(object, width, height);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeObjectSphere(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float radius = args[1]->NumberValue();
	
	if(args.Length() == 2)
	{
		dbMakeObjectSphere(object, radius);
	}

	if(args.Length() > 2)
	{
		int rings = args[2]->Int32Value();
		int segments = args[3]->Int32Value();

		dbMakeObjectSphere(object, radius, rings, segments);
	}

	return v8::Undefined();
}

v8::Handle<v8::Value> makeObjectTriangle(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float x1 = args[1]->NumberValue();
	float y1 = args[2]->NumberValue();
	float z1 = args[3]->NumberValue();
	float x2 = args[4]->NumberValue();
	float y2 = args[5]->NumberValue();
	float z2 = args[6]->NumberValue();
	float x3 = args[7]->NumberValue();
	float y3 = args[8]->NumberValue();
	float z3 = args[9]->NumberValue();
	
	dbMakeObjectTriangle(object, x1, y1, z1, x2, y2, z2, x3, y3, z3);

	return v8::Undefined();
}

v8::Handle<v8::Value> textureObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	if(args.Length() == 2)
	{
		int image = args[1]->Int32Value();

		dbTextureObject(object, image);
	}

	if(args.Length() > 2)
	{
		int stage = args[1]->Int32Value();
		int image = args[2]->Int32Value();

		dbTextureObject(object, stage, image);
	}

	return v8::Undefined();
}

v8::Handle<v8::Value> colorObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	DWORD color = args[1]->Uint32Value();
	
	dbColorObject(object, color);

	return v8::Undefined();
}

v8::Handle<v8::Value> ghostObjectOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int flag = args[1]->Int32Value();
	
	dbGhostObjectOn(object, flag);

	return v8::Undefined();
}

v8::Handle<v8::Value> ghostObjectOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbGhostObjectOff(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> fadeObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int percentage = args[1]->Int32Value();
	
	dbFadeObject(object, percentage);

	return v8::Undefined();
}

v8::Handle<v8::Value> lockObjectOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbLockObjectOn(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> lockObjectOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbLockObjectOff(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectTexture(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	if(args.Length() == 3)
	{
		int mode = args[1]->Int32Value();
		int mipGen = args[2]->Int32Value();

		dbSetObjectTexture(object, mode, mipGen);
	}

	if(args.Length() > 3)
	{
		int stage = args[1]->Int32Value();
		int mode = args[2]->Int32Value();
		int mipGen = args[3]->Int32Value();

		dbSetObjectTexture(object, stage, mode, mipGen);
	}

	return v8::Undefined();
}

v8::Handle<v8::Value> scaleObjectTexture(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	if(args.Length() > 3)
	{
		int stage = args[1]->Int32Value();
		float u = args[2]->NumberValue();
		float v = args[3]->NumberValue();

		dbScaleObjectTexture(object, stage, u, v);
	}

	if(args.Length() == 3)
	{
		float u = args[1]->NumberValue();
		float v = args[2]->NumberValue();

		dbScaleObjectTexture(object, u, v);
	}

	return v8::Undefined();
}

v8::Handle<v8::Value> scrollObjectTexture(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float u = args[1]->NumberValue();
	float v = args[2]->NumberValue();
	
	dbScrollObjectTexture(object, u, v);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectSmoothing(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int percentage = args[1]->Int32Value();
	
	dbSetObjectSmoothing(object, percentage);

	return v8::Undefined();
}

v8::Handle<v8::Value> showObjectBounds(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int boxOnly = args[1]->Int32Value();
	
	dbShowObjectBounds(object, boxOnly);

	return v8::Undefined();
}

v8::Handle<v8::Value> hideObjectBounds(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbHideObjectBounds(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	bool wireframe = args[1]->BooleanValue();
	bool transparency = args[2]->BooleanValue();
	bool cull = args[3]->BooleanValue();

	if(args.Length() == 4)
	{
		dbSetObject(object, wireframe, transparency, cull);
	}

	if(args.Length() == 5)
	{
		int filter = args[4]->Int32Value();

		dbSetObject(object, wireframe, transparency, cull, filter);
	}

	if(args.Length() == 6)
	{
		int filter = args[4]->Int32Value();
		bool light = args[5]->BooleanValue();

		dbSetObject(object, wireframe, transparency, cull, filter, light);
	}

	if(args.Length() == 7)
	{
		int filter = args[4]->Int32Value();
		bool light = args[5]->BooleanValue();
		bool fog = args[6]->BooleanValue();

		dbSetObject(object, wireframe, transparency, cull, filter, light, fog);
	}

	if(args.Length() > 7)
	{
		int filter = args[4]->Int32Value();
		bool light = args[5]->BooleanValue();
		bool fog = args[6]->BooleanValue();
		bool ambient = args[7]->BooleanValue();
	
		dbSetObject(object, wireframe, transparency, cull, filter, light, fog, ambient);
	}

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectWireframe(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	bool flag = args[1]->BooleanValue();
	
	dbSetObjectWireframe(object, flag);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectTransparency(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	bool flag = args[1]->BooleanValue();
	
	dbSetObjectTransparency(object, flag);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectCull(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	bool flag = args[1]->BooleanValue();
	
	dbSetObjectCull(object, flag);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectFilter(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int filter = args[1]->Int32Value();
	
	dbSetObjectFilter(object, filter);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectLight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	bool flag = args[1]->BooleanValue();
	
	dbSetObjectLight(object, flag);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectFog(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	bool flag = args[1]->BooleanValue();
	
	dbSetObjectFog(object, flag);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectAmbient(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	bool flag = args[1]->BooleanValue();
	
	dbSetObjectAmbient(object, flag);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectRotationXYZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbSetObjectRotationXYZ(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectRotationZYX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbSetObjectRotationZYX(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectToCameraOrientation(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbSetObjectToCameraOrientation(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectToObjectOrientation(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int target = args[1]->Int32Value();
	
	dbSetObjectToObjectOrientation(object, target);

	return v8::Undefined();
}

v8::Handle<v8::Value> disableObjectZDepth(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbDisableObjectZDepth(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> enableObjectZDepth(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbEnableObjectZDepth(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> glueObjectToLimb(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int target = args[1]->Int32Value();
	int limb = args[2]->Int32Value();
	int mode = args[3]->Int32Value();
	
	dbGlueObjectToLimb(object, target, limb, mode);

	return v8::Undefined();
}

v8::Handle<v8::Value> unglueObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbUnglueObject(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> fixObjectPivot(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbFixObjectPivot(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectDiffuse(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	DWORD color = args[1]->Uint32Value();
	
	dbSetObjectDiffuse(object, color);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectAmbience(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	DWORD color = args[1]->Int32Value();
	
	dbSetObjectAmbience(object, color);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectSpecular(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	DWORD color = args[1]->Uint32Value();
	
	dbSetObjectSpecular(object, color);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectEmissive(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	DWORD color = args[1]->Uint32Value();
	
	dbSetObjectEmissive(object, color);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectSpecularPower(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float power = args[1]->NumberValue();
	
	dbSetObjectSpecularPower(object, power);

	return v8::Undefined();
}

v8::Handle<v8::Value> setLightMappingOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int image = args[1]->Int32Value();
	
	dbSetLightMappingOn(object, image);

	return v8::Undefined();
}

v8::Handle<v8::Value> setDetailMappingOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int image = args[1]->Int32Value();
	
	dbSetDetailMappingOn(object, image);

	return v8::Undefined();
}

v8::Handle<v8::Value> setBlendMappingOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	if(args.Length() == 3)
	{
		int image = args[1]->Int32Value();
		int mode = args[2]->Int32Value();

		dbSetBlendMappingOn(object, image, mode);
	}

	if(args.Length() > 3)
	{
		int stage = args[1]->Int32Value();
		int image = args[2]->Int32Value();
		int texCoordMode = args[3]->Int32Value();
		int mode = args[4]->Int32Value();
		
		dbSetBlendMappingOn(object, stage, image, texCoordMode, mode);
	}

	return v8::Undefined();
}

v8::Handle<v8::Value> setSphereMappingOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int image = args[1]->Int32Value();
	
	dbSetSphereMappingOn(object, image);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCubeMappingOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int i1 = args[1]->Int32Value();
	int i2 = args[2]->Int32Value();
	int i3 = args[3]->Int32Value();
	int i4 = args[4]->Int32Value();
	int i5 = args[5]->Int32Value();
	int i6 = args[6]->Int32Value();
	
	dbSetCubeMappingOn(object, i1, i2, i3, i4, i5, i6);

	return v8::Undefined();
}

v8::Handle<v8::Value> setBumpMappingOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int bumpMap = args[1]->Int32Value();
	
	dbSetBumpMappingOn(object, bumpMap);

	return v8::Undefined();
}

v8::Handle<v8::Value> setCartoonShadingOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int standardImg = args[1]->Int32Value();
	int edgeImg = args[2]->Int32Value();
	
	dbSetCartoonShadingOn(object, standardImg, edgeImg);

	return v8::Undefined();
}

v8::Handle<v8::Value> setRainbowShadingOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int image = args[1]->Int32Value();
	
	dbSetRainbowShadingOn(object, image);

	return v8::Undefined();
}

v8::Handle<v8::Value> setShadowShadingOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbSetShadowShadingOn(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setReflectionShadingOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbSetReflectionShadingOn(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setAlphaMappingOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float percentage = args[1]->NumberValue();
	
	dbSetAlphaMappingOn(object, percentage);

	return v8::Undefined();
}

v8::Handle<v8::Value> setEffectOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	v8::String::Utf8Value str(args[1]);
	const char* file = ToCString(str);
	int useDefault = args[2]->IntegerValue();
	
	dbSetEffectOn(object, ToCharString(file), useDefault);

	return v8::Undefined();
}

/* LINKER ERROR?
v8::Handle<v8::Value> setShadingOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbSetShadingOff(object);

	return v8::Undefined();
}*/

v8::Handle<v8::Value> loadEffect(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* file = ToCString(str);
	int effect = args[1]->Int32Value();
	int useDefault = args[2]->IntegerValue();
	
	dbLoadEffect(ToCharString(file), effect, useDefault);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteEffect(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int effect = args[0]->Int32Value();
	
	dbDeleteEffect(effect);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectEffect(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int effect = args[1]->Int32Value();
	
	dbSetObjectEffect(object, effect);

	return v8::Undefined();
}

v8::Handle<v8::Value> setLimbEffect(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();
	int effect = args[2]->Int32Value();
	
	dbSetLimbEffect(object, limb, effect);

	return v8::Undefined();
}

v8::Handle<v8::Value> performChecklistForEffectValues(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int effect = args[0]->Int32Value();
	
	dbPerformChecklistForEffectValues(effect);

	return v8::Undefined();
}

v8::Handle<v8::Value> performChecklistForEffectErrors(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int effect = args[0]->Int32Value();
	
	dbPerformChecklistForEffectErrors(effect);

	return v8::Undefined();
}

v8::Handle<v8::Value> setEffectConstantBoolean(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int effect = args[0]->Int32Value();
	v8::String::Utf8Value str(args[1]);
	const char* name = ToCString(str);
	int value = args[3]->Int32Value();
	
	dbSetEffectConstantBoolean(effect, ToCharString(name), value);

	return v8::Undefined();
}

v8::Handle<v8::Value> setEffectConstantInteger(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int effect = args[0]->Int32Value();
	v8::String::Utf8Value str(args[1]);
	const char* name = ToCString(str);
	int value = args[3]->Int32Value();
	
	dbSetEffectConstantInteger(effect, ToCharString(name), value);

	return v8::Undefined();
}

v8::Handle<v8::Value> setEffectConstantFloat(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int effect = args[0]->Int32Value();
	v8::String::Utf8Value str(args[1]);
	const char* name = ToCString(str);
	float value = args[3]->NumberValue();
	
	dbSetEffectConstantFloat(effect, ToCharString(name), value);

	return v8::Undefined();
}

v8::Handle<v8::Value> setEffectConstantVector(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int effect = args[0]->Int32Value();
	v8::String::Utf8Value str(args[1]);
	const char* name = ToCString(str);
	int value = args[3]->Int32Value();
	
	dbSetEffectConstantVector(effect, ToCharString(name), value);

	return v8::Undefined();
}

v8::Handle<v8::Value> setEffectConstantMatrix(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int effect = args[0]->Int32Value();
	v8::String::Utf8Value str(args[1]);
	const char* name = ToCString(str);
	int value = args[3]->Int32Value();
	
	dbSetEffectConstantMatrix(effect, ToCharString(name), value);

	return v8::Undefined();
}

v8::Handle<v8::Value> setEffectTechnique(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int effect = args[0]->Int32Value();
	v8::String::Utf8Value str(args[1]);
	const char* name = ToCString(str);
	
	dbSetEffectTechnique(effect, ToCharString(name));

	return v8::Undefined();
}

v8::Handle<v8::Value> setEffectTranspose(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int effect = args[0]->Int32Value();
	int flag = args[1]->Int32Value();
	
	dbSetEffectTranspose(effect, flag);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeObjectCollisionBox(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float x1 = args[1]->NumberValue();
	float y1 = args[2]->NumberValue();
	float z1 = args[3]->NumberValue();
	float x2 = args[4]->NumberValue();
	float y2 = args[5]->NumberValue();
	float z2 = args[6]->NumberValue();
	int rotatedBoxFlag = args[7]->Int32Value();
	
	dbMakeObjectCollisionBox(object, x1, y1, z1, x2, y2, z2, rotatedBoxFlag);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteObjectCollisionBox(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbDeleteObjectCollisionBox(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectCollisionOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbSetObjectCollisionOn(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectCollisionOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbSetObjectCollisionOff(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectCollisionToBoxes(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbSetObjectCollisionToBoxes(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectCollisionToPolygons(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbSetObjectCollisionToPolygons(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectCollisionToSpheres(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	
	dbSetObjectCollisionToSpheres(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> setGlobalCollisionOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	dbSetGlobalCollisionOn();

	return v8::Undefined();
}

v8::Handle<v8::Value> setGlobalCollisionOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	dbSetGlobalCollisionOff();

	return v8::Undefined();
}

v8::Handle<v8::Value> setObjectRadius(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float radius = args[1]->NumberValue();
	
	dbSetObjectRadius(object, radius);

	return v8::Undefined();
}

v8::Handle<v8::Value> automaticObjectCollision(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float radius = args[1]->NumberValue();
	int response = args[2]->Int32Value();
	
	dbAutomaticObjectCollision(object, radius, response);

	return v8::Undefined();
}

v8::Handle<v8::Value> automaticCameraCollision(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int camera = args[0]->Int32Value();
	float radius = args[1]->NumberValue();
	int response = args[2]->Int32Value();
	
	dbAutomaticCameraCollision(camera, radius, response);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeStaticCollisionBox(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	float x1 = args[0]->NumberValue();
	float y1 = args[1]->NumberValue();
	float z1 = args[2]->NumberValue();
	float x2 = args[3]->NumberValue();
	float y2 = args[4]->NumberValue();
	float z2 = args[5]->NumberValue();
	
	dbMakeStaticCollisionBox(x1, y1, z1, x2, y2, z2);

	return v8::Undefined();
}

v8::Handle<v8::Value> performChecklistForObjectLimbs(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	dbPerformChecklistForObjectLimbs(object);

	return v8::Undefined();
}

v8::Handle<v8::Value> offsetLimb(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();
	float x = args[2]->NumberValue();
	float y = args[3]->NumberValue();
	float z = args[4]->NumberValue();
	int bound = args[5]->Int32Value();

	dbOffsetLimb(object, limb, x, y, z, bound);

	return v8::Undefined();
}

v8::Handle<v8::Value> scaleLimb(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();
	float x = args[2]->NumberValue();
	float y = args[3]->NumberValue();
	float z = args[4]->NumberValue();
	int bound = args[5]->Int32Value();

	dbScaleLimb(object, limb, x, y, z, bound);

	return v8::Undefined();
}

v8::Handle<v8::Value> rotateLimb(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();
	float x = args[2]->NumberValue();
	float y = args[3]->NumberValue();
	float z = args[4]->NumberValue();
	int bound = args[5]->Int32Value();

	dbRotateLimb(object, limb, x, y, z, bound);

	return v8::Undefined();
}

v8::Handle<v8::Value> showLimb(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	dbShowLimb(object, limb);

	return v8::Undefined();
}

v8::Handle<v8::Value> hideLimb(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	dbHideLimb(object, limb);

	return v8::Undefined();
}

v8::Handle<v8::Value> textureLimb(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	if(args.Length() == 4)
	{
		int stage = args[2]->Int32Value();
		int image = args[3]->Int32Value();

		dbTextureLimb(object, limb, stage, image);
	}

	if(args.Length() == 3)
	{
		int image = args[2]->Int32Value();
		
		dbTextureLimb(object, limb, image);
	}

	return v8::Undefined();
}

v8::Handle<v8::Value> colorLimb(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();
	DWORD color = args[2]->Uint32Value();

	dbColorLimb(object, limb, color);

	return v8::Undefined();
}

v8::Handle<v8::Value> scaleLimbTexture(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();
	float u = args[2]->NumberValue();
	float v = args[3]->NumberValue();

	dbScaleLimbTexture(object, limb, u, v);

	return v8::Undefined();
}

v8::Handle<v8::Value> scrollLimbTexture(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();
	float u = args[2]->NumberValue();
	float v = args[3]->NumberValue();

	dbScrollLimbTexture(object, limb, u, v);

	return v8::Undefined();
}

v8::Handle<v8::Value> addLimb(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();
	int mesh = args[2]->Int32Value();

	dbAddLimb(object, limb, mesh);

	return v8::Undefined();
}

v8::Handle<v8::Value> linkLimb(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int parent = args[1]->Int32Value();
	int limb = args[2]->Int32Value();

	dbLinkLimb(object, parent, limb);

	return v8::Undefined();
}

v8::Handle<v8::Value> removeLimb(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	dbRemoveLimb(object, limb);

	return v8::Undefined();
}

v8::Handle<v8::Value> setLimbSmoothing(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();
	float amount = args[2]->NumberValue();

	dbSetLimbSmoothing(object, limb, amount);

	return v8::Undefined();
}

v8::Handle<v8::Value> loadMesh(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* file = ToCString(str);
	int mesh = args[1]->Int32Value();

	dbLoadMesh(ToCharString(file), mesh);

	return v8::Undefined();
}

v8::Handle<v8::Value> saveMesh(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* file = ToCString(str);
	int mesh = args[1]->Int32Value();

	dbSaveMesh(ToCharString(file), mesh);

	return v8::Undefined();
}

v8::Handle<v8::Value> changeMesh(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();
	int mesh = args[2]->Int32Value();

	dbChangeMesh(object, limb, mesh);

	return v8::Undefined();
}


v8::Handle<v8::Value> deleteMesh(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int mesh = args[0]->Int32Value();

	dbDeleteMesh(mesh);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeMeshFromObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int mesh = args[0]->Int32Value();
	int object = args[1]->Int32Value();

	dbMakeMeshFromObject(mesh, object);

	return v8::Undefined();
}

v8::Handle<v8::Value> createVertexShaderFromFile(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	v8::String::Utf8Value str(args[1]);
	const char* file = ToCString(str);

	dbCreateVertexShaderFromFile(id, ToCharString(file));

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteVertexShader(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int shader = args[0]->Int32Value();

	dbDeleteVertexShader(shader);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVertexShaderOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	int shader = args[1]->Int32Value();

	dbSetVertexShaderOn(id, shader);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVertexShaderOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();

	dbSetVertexShaderOff(id);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVertexShaderVector(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	DWORD dwRegister = args[1]->Uint32Value();
	int vector = args[2]->Int32Value();
	DWORD dwConstantCount = args[3]->Uint32Value();

	dbSetVertexShaderVector(id, dwRegister, vector, dwConstantCount);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVertexShaderMatrix(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	DWORD dwRegister = args[1]->Uint32Value();
	int vector = args[2]->Int32Value();
	DWORD dwConstantCount = args[3]->Uint32Value();

	dbSetVertexShaderMatrix(id, dwRegister, vector, dwConstantCount);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVertexShaderStream(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	int pos = args[1]->Int32Value();
	int data = args[2]->Int32Value();
	int dataType = args[3]->Int32Value();

	dbSetVertexShaderStream(id, pos, data, dataType);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVertexShaderStreamCount(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	int count = args[1]->Int32Value();

	dbSetVertexShaderStreamCount(id, count);

	return v8::Undefined();
}

v8::Handle<v8::Value> convertObjectFVF(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	DWORD fvf = args[1]->Uint32Value();

	dbConvertObjectFVF(id, fvf);

	return v8::Undefined();
}

v8::Handle<v8::Value> createPixelShaderFromFile(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	v8::String::Utf8Value str(args[1]);
	const char* file = ToCString(str);

	dbCreatePixelShaderFromFile(id, ToCharString(file));

	return v8::Undefined();
}

v8::Handle<v8::Value> deletePixelShader(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int shader = args[0]->Int32Value();

	dbDeletePixelShader(shader);

	return v8::Undefined();
}

v8::Handle<v8::Value> setPixelShaderOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	int shader = args[1]->Int32Value();

	dbSetPixelShaderOn(id, shader);

	return v8::Undefined();
}

v8::Handle<v8::Value> setPixelShaderOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();

	dbSetPixelShaderOff(id);

	return v8::Undefined();
}

v8::Handle<v8::Value> setPixelShaderTexture(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int shader = args[0]->Int32Value();
	int slot = args[1]->Int32Value();
	int texture = args[2]->Int32Value();

	dbSetPixelShaderTexture(shader, slot, texture);

	return v8::Undefined();
}

v8::Handle<v8::Value> flushVideoMemory(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbFlushVideoMemory();

	return v8::Undefined();
}

v8::Handle<v8::Value> objectExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Boolean::New(dbObjectExist(object));
}

v8::Handle<v8::Value> objectVisible(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Boolean::New(dbObjectVisible(object));
}

v8::Handle<v8::Value> objectPlaying(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Boolean::New(dbObjectPlaying(object));
}

v8::Handle<v8::Value> objectLooping(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Boolean::New(dbObjectLooping(object));
}

v8::Handle<v8::Value> objectPositionX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectPositionX(object));
}

v8::Handle<v8::Value> objectPositionY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectPositionY(object));
}

v8::Handle<v8::Value> objectPositionZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectPositionZ(object));
}

v8::Handle<v8::Value> objectSize(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectSize(object));
}

v8::Handle<v8::Value> objectSizeX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectSizeX(object));
}

v8::Handle<v8::Value> objectSizeY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectSizeY(object));
}

v8::Handle<v8::Value> objectSizeZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectSizeZ(object));
}

v8::Handle<v8::Value> objectAngleX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectAngleX(object));
}

v8::Handle<v8::Value> objectAngleY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectAngleY(object));
}

v8::Handle<v8::Value> objectAngleZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectAngleZ(object));
}

v8::Handle<v8::Value> objectFrame(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectFrame(object));
}

v8::Handle<v8::Value> objectSpeed(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectSpeed(object));
}

v8::Handle<v8::Value> objectInterpolation(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectInterpolation(object));
}

v8::Handle<v8::Value> totalObjectFrames(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Int32::New(dbTotalObjectFrames(object));
}

v8::Handle<v8::Value> objectHit(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int objectA = args[0]->Int32Value();
	int objectB = args[1]->Int32Value();

	return v8::Int32::New(dbObjectHit(objectA, objectB));
}

v8::Handle<v8::Value> objectCollision(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int objectA = args[0]->Int32Value();
	int objectB = args[1]->Int32Value();

	return v8::Int32::New(dbObjectCollision(objectA, objectB));
}

v8::Handle<v8::Value> objectCollisionX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetObjectCollisionX());
}

v8::Handle<v8::Value> objectCollisionY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetObjectCollisionY());
}

v8::Handle<v8::Value> objectCollisionZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetObjectCollisionZ());
}

v8::Handle<v8::Value> objectCollisionRadius(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectCollisionRadius(object));
}

v8::Handle<v8::Value> objectCollisionCenterX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectCollisionCenterX(object));
}

v8::Handle<v8::Value> objectCollisionCenterY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectCollisionCenterY(object));
}

v8::Handle<v8::Value> objectCollisionCenterZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Number::New(dbObjectCollisionCenterZ(object));
}

v8::Handle<v8::Value> intersectObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();
	float newX = args[4]->NumberValue();
	float newY = args[5]->NumberValue();
	float newZ = args[6]->NumberValue();

	return v8::Number::New(dbIntersectObject(object, x, y, z, newX, newY, newZ));
}

v8::Handle<v8::Value> limbExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Boolean::New(dbLimbExist(object, limb));
}

v8::Handle<v8::Value> limbName(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::String::New(dbLimbName(object, limb));
}

v8::Handle<v8::Value> limbVisible(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Boolean::New(dbLimbVisible(object, limb));
}

v8::Handle<v8::Value> limbOffsetX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbOffsetX(object, limb));
}

v8::Handle<v8::Value> limbOffsetY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbOffsetY(object, limb));
}

v8::Handle<v8::Value> limbOffsetZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbOffsetZ(object, limb));
}

v8::Handle<v8::Value> limbScaleX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbScaleX(object, limb));
}

v8::Handle<v8::Value> limbScaleY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbScaleY(object, limb));
}

v8::Handle<v8::Value> limbScaleZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbScaleZ(object, limb));
}

v8::Handle<v8::Value> limbAngleX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbAngleX(object, limb));
}

v8::Handle<v8::Value> limbAngleY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbAngleY(object, limb));
}

v8::Handle<v8::Value> limbAngleZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbAngleZ(object, limb));
}

v8::Handle<v8::Value> limbTexture(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Int32::New(dbLimbTexture(object, limb));
}

v8::Handle<v8::Value> limbTextureName(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::String::New(dbLimbTextureName(object, limb));
}

v8::Handle<v8::Value> limbDirectionX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbDirectionX(object, limb));
}

v8::Handle<v8::Value> limbDirectionY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbDirectionY(object, limb));
}

v8::Handle<v8::Value> limbDirectionZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbDirectionZ(object, limb));
}

v8::Handle<v8::Value> limbPositionX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbPositionX(object, limb));
}

v8::Handle<v8::Value> limbPositionY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbPositionY(object, limb));
}

v8::Handle<v8::Value> limbPositionZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Number::New(dbLimbPositionZ(object, limb));
}

v8::Handle<v8::Value> checkLimbLink(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();
	int limb = args[1]->Int32Value();

	return v8::Int32::New(dbCheckLimbLink(object, limb));
}

v8::Handle<v8::Value> staticLineOfSight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	float sx = args[0]->NumberValue();
	float sy = args[1]->NumberValue();
	float sz = args[2]->NumberValue();
	float dx = args[3]->NumberValue();
	float dy = args[4]->NumberValue();
	float dz = args[5]->NumberValue();
	float width = args[6]->NumberValue();
	float accuracy = args[7]->NumberValue();

	return v8::Int32::New(dbStaticLineOfSight(sx, sy, sz, dx, dy, dz, width, accuracy));
}

v8::Handle<v8::Value> staticLineOfSightX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbStaticLineOfSightX());
}

v8::Handle<v8::Value> staticLineOfSightY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbStaticLineOfSightY());
}

v8::Handle<v8::Value> staticLineOfSightZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbStaticLineOfSightZ());
}

v8::Handle<v8::Value> getStaticCollisionHit(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	float oldx1 = args[0]->NumberValue();
	float oldy1 = args[1]->NumberValue();
	float oldz1 = args[2]->NumberValue();
	float oldx2 = args[3]->NumberValue();
	float oldy2 = args[4]->NumberValue();
	float oldz2 = args[5]->NumberValue();
	float nx1 = args[6]->NumberValue();
	float ny1 = args[7]->NumberValue();
	float nz1 = args[8]->NumberValue();
	float nx2 = args[9]->NumberValue();
	float ny2 = args[10]->NumberValue();
	float nz2 = args[11]->NumberValue();

	return v8::Int32::New(dbGetStaticCollisionHit(oldx1, oldy1, oldz1, oldx2, oldy2, oldz2, nx1, ny1, nz1, nx2, ny2, nz2));
}

v8::Handle<v8::Value> getStaticCollisionX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetStaticCollisionX());
}

v8::Handle<v8::Value> getStaticCollisionY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetStaticCollisionY());
}

v8::Handle<v8::Value> getStaticCollisionZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetStaticCollisionZ());
}

v8::Handle<v8::Value> objectInScreen(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Boolean::New(dbObjectInScreen(object));
}

v8::Handle<v8::Value> objectScreenX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Int32::New(dbObjectScreenX(object));
}

v8::Handle<v8::Value> objectScreenY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int object = args[0]->Int32Value();

	return v8::Int32::New(dbObjectScreenY(object));
}

v8::Handle<v8::Value> pickObject(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int x = args[0]->Int32Value();
	int y = args[1]->Int32Value();
	int start = args[2]->Int32Value();
	int end = args[3]->Int32Value();

	return v8::Int32::New(dbPickObject(x, y, start, end));
}

v8::Handle<v8::Value> pickScreen(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int x = args[0]->Int32Value();
	int y = args[1]->Int32Value();
	float distance = args[2]->NumberValue();

	dbPickScreen(x, y, distance);

	return v8::Undefined();
}

v8::Handle<v8::Value> getPickDistance(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetPickDistance());
}

v8::Handle<v8::Value> getPickVectorX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetPickVectorX());
}

v8::Handle<v8::Value> getPickVectorY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetPickVectorY());
}

v8::Handle<v8::Value> getPickVectorZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetPickVectorZ());
}

v8::Handle<v8::Value> alphaBlendingAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbAlphaBlendingAvailable());
}

v8::Handle<v8::Value> alphaAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbAlphaAvailable());
}

v8::Handle<v8::Value> alphaComparisionAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbAlphaComparisionAvailable());
}

v8::Handle<v8::Value> anisotropicFilteringAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbAnisotropicFilteringAvailable());
}

v8::Handle<v8::Value> antiAliasAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbAntiAliasAvailable());
}

v8::Handle<v8::Value> blitSysOntoLocalAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbBlitSysOntoLocalAvailable());
}

v8::Handle<v8::Value> calibrateGammaAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbCalibrateGammaAvailable());
}

v8::Handle<v8::Value> clipAndScalePointsAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbClipAndScalePointsAvailable());
}

v8::Handle<v8::Value> clipTLVertsAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbClipTLVertsAvailable());
}

v8::Handle<v8::Value> colorPerspectiveAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbColorPerspectiveAvailable());
}

v8::Handle<v8::Value> colorWriteEnableAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbColorWriteEnableAvailable());
}

v8::Handle<v8::Value> cubeMapAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbCubeMapAvailable());
}

v8::Handle<v8::Value> cullCCWAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbCullCCWAvailable());
}

v8::Handle<v8::Value> cullCWAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbCullCWAvailable());
}

v8::Handle<v8::Value> getDeviceType(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbGetDeviceType());
}

v8::Handle<v8::Value> ditherAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbDitherAvailable());
}

v8::Handle<v8::Value> filteringAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbFilteringAvailable());
}

v8::Handle<v8::Value> fogRangeAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbFogRangeAvailable());
}

v8::Handle<v8::Value> fogTableAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbFogTableAvailable());
}

v8::Handle<v8::Value> fogVertexAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbFogVertexAvailable());
}

v8::Handle<v8::Value> fogAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbFogAvailable());
}

v8::Handle<v8::Value> fullScreenGammaAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbFullScreenGammaAvailable());
}

v8::Handle<v8::Value> getMaximumLights(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbGetMaximumLights());
}

v8::Handle<v8::Value> getMaximumPixelShaderValue(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetMaximumPixelShaderValue());
}

v8::Handle<v8::Value> getMaximumTextureHeight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbGetMaximumTextureHeight());
}

v8::Handle<v8::Value> getMaximumTextureWidth(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbGetMaximumTextureWidth());
}

v8::Handle<v8::Value> getMaximumVertexShaderConstants(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbGetMaximumVertexShaderConstants());
}

v8::Handle<v8::Value> getMaximumVolumeExtent(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbGetMaximumVolumeExtent());
}

v8::Handle<v8::Value> mipCubeMapAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbMipCubeMapAvailable());
}

v8::Handle<v8::Value> mipMapAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbMipMapAvailable());
}

v8::Handle<v8::Value> mipMapLODBiasAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbMipMapLODBiasAvailable());
}

v8::Handle<v8::Value> mipMapVolumeAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbMipMapVolumeAvailable());
}

v8::Handle<v8::Value> nonPowTexturesAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbNonPowTexturesAvailable());
}

v8::Handle<v8::Value> perspectiveTexturesAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbPerspectiveTexturesAvailable());
}

v8::Handle<v8::Value> getMaximumPixelShaderVersion(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetMaximumPixelShaderVersion());
}

v8::Handle<v8::Value> projectedTexturesAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbProjectedTexturesAvailable());
}

v8::Handle<v8::Value> renderAfterFlipAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbRenderAfterFlipAvailable());
}

v8::Handle<v8::Value> renderWindowedAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbRenderWindowedAvailable());
}

v8::Handle<v8::Value> separateTextureMemoriesAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbSeparateTextureMemoriesAvailable());
}

v8::Handle<v8::Value> onlySquareTexturesAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbOnlySquareTexturesAvailable());
}

v8::Handle<v8::Value> getTNLAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbGetTNLAvailable());
}

v8::Handle<v8::Value> tlVertexSystemMemoryAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbTLVertexSystemMemoryAvailable());
}

v8::Handle<v8::Value> tlVertexVideoMemoryAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbTLVertexVideoMemoryAvailable());
}

v8::Handle<v8::Value> nonLocalVideoMemoryAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbNonLocalVideoMemoryAvailable());
}

v8::Handle<v8::Value> textureSystemMemoryAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbTextureSystemMemoryAvailable());
}

v8::Handle<v8::Value> textureVideoMemoryAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbTextureVideoMemoryAvailable());
}

v8::Handle<v8::Value> getMaximumVertexShaderVersion(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbGetMaximumVertexShaderVersion());
}

v8::Handle<v8::Value> volumeMapAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbVolumeMapAvailable());
}

v8::Handle<v8::Value> wBufferAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbWBufferAvailable());
}

v8::Handle<v8::Value> wFogAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbWFogAvailable());
}

v8::Handle<v8::Value> zBufferAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbZBufferAvailable());
}

v8::Handle<v8::Value> zFogAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbZFogAvailable());
}

v8::Handle<v8::Value> meshExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int mesh = args[0]->Int32Value();

	return v8::Boolean::New(dbMeshExist(mesh));
}

v8::Handle<v8::Value> effectExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int effect = args[0]->Int32Value();

	return v8::Boolean::New(dbEffectExist(effect));
}

v8::Handle<v8::Value> vertexShaderExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int shader = args[0]->Int32Value();

	return v8::Boolean::New(dbVertexShaderExist(shader));
}

v8::Handle<v8::Value> pixelShaderExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int shader = args[0]->Int32Value();

	return v8::Boolean::New(dbPixelShaderExist(shader));
}

v8::Handle<v8::Value> statistic(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int code = args[0]->Int32Value();

	return v8::Boolean::New(dbStatistic(code));
}

void RegisterScriptBasic3D(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbLoadObject"), v8::FunctionTemplate::New(loadObject));
	global->Set(v8::String::New("dbAppendObject"), v8::FunctionTemplate::New(appendObject));
	global->Set(v8::String::New("dbCloneObject"), v8::FunctionTemplate::New(cloneObject));
	global->Set(v8::String::New("dbInstanceObject"), v8::FunctionTemplate::New(instanceObject));
	global->Set(v8::String::New("dbDeleteObject"), v8::FunctionTemplate::New(deleteObject));

	global->Set(v8::String::New("dbShowObject"), v8::FunctionTemplate::New(showObject));
	global->Set(v8::String::New("dbHideObject"), v8::FunctionTemplate::New(hideObject));
	global->Set(v8::String::New("dbPositionObject"), v8::FunctionTemplate::New(positionObject));
	global->Set(v8::String::New("dbScaleObject"), v8::FunctionTemplate::New(scaleObject));
	global->Set(v8::String::New("dbRotateObject"), v8::FunctionTemplate::New(rotateObject));
	global->Set(v8::String::New("dbMoveObject"), v8::FunctionTemplate::New(moveObject));
	global->Set(v8::String::New("dbPointObject"), v8::FunctionTemplate::New(pointObject));
	global->Set(v8::String::New("dbMoveObjectDown"), v8::FunctionTemplate::New(moveObjectDown));
	global->Set(v8::String::New("dbMoveObjectLeft"), v8::FunctionTemplate::New(moveObjectLeft));
	global->Set(v8::String::New("dbMoveObjectRight"), v8::FunctionTemplate::New(moveObjectRight));
	global->Set(v8::String::New("dbMoveObjectUp"), v8::FunctionTemplate::New(moveObjectUp));
	global->Set(v8::String::New("dbXRotateObject"), v8::FunctionTemplate::New(xRotateObject));
	global->Set(v8::String::New("dbYRotateObject"), v8::FunctionTemplate::New(yRotateObject));
	global->Set(v8::String::New("dbZRotateObject"), v8::FunctionTemplate::New(zRotateObject));
	global->Set(v8::String::New("dbTurnObjectLeft"), v8::FunctionTemplate::New(turnObjectLeft));
	global->Set(v8::String::New("dbTurnObjectRight"), v8::FunctionTemplate::New(turnObjectRight));
	global->Set(v8::String::New("dbPitchObjectUp"), v8::FunctionTemplate::New(pitchObjectUp));
	global->Set(v8::String::New("dbPitchObjectDown"), v8::FunctionTemplate::New(pitchObjectDown));
	global->Set(v8::String::New("dbRollObjectLeft"), v8::FunctionTemplate::New(rollObjectLeft));
	global->Set(v8::String::New("dbRollObjectRight"), v8::FunctionTemplate::New(rollObjectRight));

	global->Set(v8::String::New("dbPlayObject"), v8::FunctionTemplate::New(playObject));
	global->Set(v8::String::New("dbLoopObject"), v8::FunctionTemplate::New(loopObject));
	global->Set(v8::String::New("dbStopObject"), v8::FunctionTemplate::New(stopObject));
	global->Set(v8::String::New("dbSetObjectFrame"), v8::FunctionTemplate::New(setObjectFrame));
	global->Set(v8::String::New("dbSetObjectSpeed"), v8::FunctionTemplate::New(setObjectSpeed));
	global->Set(v8::String::New("dbSetObjectInterpolation"), v8::FunctionTemplate::New(setObjectInterpolation));
	
	// CONSTRUCTION COMMANDS
	global->Set(v8::String::New("dbMakeObject"), v8::FunctionTemplate::New(makeObject));
	global->Set(v8::String::New("dbMakeObjectBox"), v8::FunctionTemplate::New(makeObjectBox));
	global->Set(v8::String::New("dbMakeObjectCone"), v8::FunctionTemplate::New(makeObjectCone));
	global->Set(v8::String::New("dbMakeObjectCube"), v8::FunctionTemplate::New(makeObjectCube));
	global->Set(v8::String::New("dbMakeObjectFromLimb"), v8::FunctionTemplate::New(makeObjectFromLimb));
	global->Set(v8::String::New("dbMakeObjectPlain"), v8::FunctionTemplate::New(makeObjectPlain));
	global->Set(v8::String::New("dbMakeObjectSphere"), v8::FunctionTemplate::New(makeObjectSphere));
	global->Set(v8::String::New("dbMakeObjectTriangle"), v8::FunctionTemplate::New(makeObjectTriangle));

	// APPEARANCE COMMANDS
	global->Set(v8::String::New("dbTextureObject"), v8::FunctionTemplate::New(textureObject));
	global->Set(v8::String::New("dbColorObject"), v8::FunctionTemplate::New(colorObject));
	global->Set(v8::String::New("dbGhostObjectOn"), v8::FunctionTemplate::New(ghostObjectOn));
	global->Set(v8::String::New("dbGhostObjectOff"), v8::FunctionTemplate::New(ghostObjectOff));
	global->Set(v8::String::New("dbFadeObject"), v8::FunctionTemplate::New(fadeObject));
	global->Set(v8::String::New("dbLockObjectOn"), v8::FunctionTemplate::New(lockObjectOn));
	global->Set(v8::String::New("dbLockObjectOff"), v8::FunctionTemplate::New(lockObjectOff));
	global->Set(v8::String::New("dbSetObjectTexture"), v8::FunctionTemplate::New(setObjectTexture));
	global->Set(v8::String::New("dbScaleObjectTexture"), v8::FunctionTemplate::New(scaleObjectTexture));
	global->Set(v8::String::New("dbScrollObjectTexture"), v8::FunctionTemplate::New(scrollObjectTexture));
	global->Set(v8::String::New("dbSetObjectSmoothing"), v8::FunctionTemplate::New(setObjectSmoothing));
	global->Set(v8::String::New("dbShowObjectBounds"), v8::FunctionTemplate::New(showObjectBounds));
	global->Set(v8::String::New("dbHideObjectBounds"), v8::FunctionTemplate::New(hideObjectBounds));

	global->Set(v8::String::New("dbSetObject"), v8::FunctionTemplate::New(setObject));
	global->Set(v8::String::New("dbSetObjectWireframe"), v8::FunctionTemplate::New(setObjectWireframe));
	global->Set(v8::String::New("dbSetObjectTransparency"), v8::FunctionTemplate::New(setObjectTransparency));
	global->Set(v8::String::New("dbSetObjectCull"), v8::FunctionTemplate::New(setObjectCull));
	global->Set(v8::String::New("dbSetObjectFilter"), v8::FunctionTemplate::New(setObjectFilter));
	global->Set(v8::String::New("dbSetObjectLight"), v8::FunctionTemplate::New(setObjectLight));
	global->Set(v8::String::New("dbSetObjectFog"), v8::FunctionTemplate::New(setObjectFog));
	global->Set(v8::String::New("dbSetObjectAmbient"), v8::FunctionTemplate::New(setObjectAmbient));
	global->Set(v8::String::New("dbSetObjectRotationXYZ"), v8::FunctionTemplate::New(setObjectRotationXYZ));
	global->Set(v8::String::New("dbSetObjectRotationZYX"), v8::FunctionTemplate::New(setObjectRotationZYX));
	global->Set(v8::String::New("dbSetObjectToCameraOrientation"), v8::FunctionTemplate::New(setObjectToCameraOrientation));
	global->Set(v8::String::New("dbSetObjectToObjectOrientation"), v8::FunctionTemplate::New(setObjectToObjectOrientation));
	global->Set(v8::String::New("dbDisableObjectZDepth"), v8::FunctionTemplate::New(disableObjectZDepth));
	global->Set(v8::String::New("dbEnableObjectZDepth"), v8::FunctionTemplate::New(enableObjectZDepth));
	global->Set(v8::String::New("dbGlueObjectToLimb"), v8::FunctionTemplate::New(glueObjectToLimb));
	global->Set(v8::String::New("dbUnglueObject"), v8::FunctionTemplate::New(unglueObject));
	global->Set(v8::String::New("dbFixObjectPivot"), v8::FunctionTemplate::New(fixObjectPivot));
	global->Set(v8::String::New("dbSetObjectDiffuse"), v8::FunctionTemplate::New(setObjectDiffuse));
	global->Set(v8::String::New("dbSetObjectAmbience"), v8::FunctionTemplate::New(setObjectAmbience));
	global->Set(v8::String::New("dbSetObjectSpecular"), v8::FunctionTemplate::New(setObjectSpecular));
	global->Set(v8::String::New("dbSetObjectEmissive"), v8::FunctionTemplate::New(setObjectEmissive));
	global->Set(v8::String::New("dbSetObjectSpecularPower"), v8::FunctionTemplate::New(setObjectSpecularPower));

	global->Set(v8::String::New("dbSetLightMappingOn"), v8::FunctionTemplate::New(setLightMappingOn));
	global->Set(v8::String::New("dbSetDetailMappingOn"), v8::FunctionTemplate::New(setDetailMappingOn));
	global->Set(v8::String::New("dbSetBlendMappingOn"), v8::FunctionTemplate::New(setBlendMappingOn));
	global->Set(v8::String::New("dbSetSphereMappingOn"), v8::FunctionTemplate::New(setSphereMappingOn));
	global->Set(v8::String::New("dbSetCubeMappingOn"), v8::FunctionTemplate::New(setCubeMappingOn));
	global->Set(v8::String::New("dbSetBumpMappingOn"), v8::FunctionTemplate::New(setBumpMappingOn));
	global->Set(v8::String::New("dbSetCartoonShadingOn"), v8::FunctionTemplate::New(setCartoonShadingOn));
	global->Set(v8::String::New("dbSetRainbowShadingOn"), v8::FunctionTemplate::New(setRainbowShadingOn));
	global->Set(v8::String::New("dbSetShadowShadingOn"), v8::FunctionTemplate::New(setShadowShadingOn));
	global->Set(v8::String::New("dbSetReflectionShadingOn"), v8::FunctionTemplate::New(setReflectionShadingOn));
	global->Set(v8::String::New("dbSetAlphaMappingOn"), v8::FunctionTemplate::New(setAlphaMappingOn));
	global->Set(v8::String::New("dbSetEffectOn"), v8::FunctionTemplate::New(setEffectOn));
	//global->Set(v8::String::New("dbSetShadingOff"), v8::FunctionTemplate::New(setShadingOff));

	global->Set(v8::String::New("dbLoadEffect"), v8::FunctionTemplate::New(loadEffect));
	global->Set(v8::String::New("dbDeleteEffect"), v8::FunctionTemplate::New(deleteEffect));
	global->Set(v8::String::New("dbSetObjectEffect"), v8::FunctionTemplate::New(setObjectEffect));
	global->Set(v8::String::New("dbSetLimbEffect"), v8::FunctionTemplate::New(setLimbEffect));
	global->Set(v8::String::New("dbPerformChecklistForEffectValues"), v8::FunctionTemplate::New(performChecklistForEffectValues));
	global->Set(v8::String::New("dbPerformChecklistForEffectErrors"), v8::FunctionTemplate::New(performChecklistForEffectErrors));
	global->Set(v8::String::New("dbSetEffectConstantBoolean"), v8::FunctionTemplate::New(setEffectConstantBoolean));
	global->Set(v8::String::New("dbSetEffectConstantInteger"), v8::FunctionTemplate::New(setEffectConstantInteger));
	global->Set(v8::String::New("dbSetEffectConstantFloat"), v8::FunctionTemplate::New(setEffectConstantFloat));
	global->Set(v8::String::New("dbSetEffectConstantVector"), v8::FunctionTemplate::New(setEffectConstantVector));
	global->Set(v8::String::New("dbSetEffectConstantMatrix"), v8::FunctionTemplate::New(setEffectConstantMatrix));
	global->Set(v8::String::New("dbSetEffectTechnique"), v8::FunctionTemplate::New(setEffectTechnique));
	global->Set(v8::String::New("dbSetEffectTranspose"), v8::FunctionTemplate::New(setEffectTranspose));

	// COLLISION COMMANDS
	global->Set(v8::String::New("dbMakeObjectCollisionBox"), v8::FunctionTemplate::New(makeObjectCollisionBox));
	global->Set(v8::String::New("dbDeleteObjectCollisionBox"), v8::FunctionTemplate::New(deleteObjectCollisionBox));
	global->Set(v8::String::New("dbSetObjectCollisionOn"), v8::FunctionTemplate::New(setObjectCollisionOn));
	global->Set(v8::String::New("dbSetObjectCollisionOff"), v8::FunctionTemplate::New(setObjectCollisionOff));
	global->Set(v8::String::New("dbSetObjectCollisionToBoxes"), v8::FunctionTemplate::New(setObjectCollisionToBoxes));
	global->Set(v8::String::New("dbSetObjectCollisionToPolygons"), v8::FunctionTemplate::New(setObjectCollisionToPolygons));
	global->Set(v8::String::New("dbSetObjectCollisionToSpheres"), v8::FunctionTemplate::New(setObjectCollisionToSpheres));
	global->Set(v8::String::New("dbSetGlobalCollisionOn"), v8::FunctionTemplate::New(setGlobalCollisionOn));
	global->Set(v8::String::New("dbSetGlobalCollisionOff"), v8::FunctionTemplate::New(setGlobalCollisionOff));
	global->Set(v8::String::New("dbSetObjectRadius"), v8::FunctionTemplate::New(setObjectRadius));
	global->Set(v8::String::New("dbAutomaticObjectCollision"), v8::FunctionTemplate::New(automaticObjectCollision));
	global->Set(v8::String::New("dbAutomaticCameraCollision"), v8::FunctionTemplate::New(automaticCameraCollision));
	global->Set(v8::String::New("dbMakeStaticCollisionBox"), v8::FunctionTemplate::New(makeStaticCollisionBox));

	// LIMB COMMANDS
	global->Set(v8::String::New("dbPerformChecklistForObjectLimbs"), v8::FunctionTemplate::New(performChecklistForObjectLimbs));
	global->Set(v8::String::New("dbOffsetLimb"), v8::FunctionTemplate::New(offsetLimb));
	global->Set(v8::String::New("dbScaleLimb"), v8::FunctionTemplate::New(scaleLimb));
	global->Set(v8::String::New("dbRotateLimb"), v8::FunctionTemplate::New(rotateLimb));
	global->Set(v8::String::New("dbShowLimb"), v8::FunctionTemplate::New(showLimb));
	global->Set(v8::String::New("dbHideLimb"), v8::FunctionTemplate::New(hideLimb));
	global->Set(v8::String::New("dbTextureLimb"), v8::FunctionTemplate::New(textureLimb));
	global->Set(v8::String::New("dbColorLimb"), v8::FunctionTemplate::New(colorLimb));
	global->Set(v8::String::New("dbScaleLimbTexture"), v8::FunctionTemplate::New(scaleLimbTexture));
	global->Set(v8::String::New("dbScrollLimbTexture"), v8::FunctionTemplate::New(scrollLimbTexture));
	global->Set(v8::String::New("dbAddLimb"), v8::FunctionTemplate::New(addLimb));
	global->Set(v8::String::New("dbLinkLimb"), v8::FunctionTemplate::New(linkLimb));
	global->Set(v8::String::New("dbRemoveLimb"), v8::FunctionTemplate::New(removeLimb));
	global->Set(v8::String::New("dbSetLimbSmoothing"), v8::FunctionTemplate::New(setLimbSmoothing));

	// MESH COMMANDS
	global->Set(v8::String::New("dbLoadMesh"), v8::FunctionTemplate::New(loadMesh));
	global->Set(v8::String::New("dbSaveMesh"), v8::FunctionTemplate::New(saveMesh));
	global->Set(v8::String::New("dbDeleteMesh"), v8::FunctionTemplate::New(deleteMesh));
	global->Set(v8::String::New("dbChangeMesh"), v8::FunctionTemplate::New(changeMesh));
	global->Set(v8::String::New("dbMakeMeshFromObject"), v8::FunctionTemplate::New(makeMeshFromObject));

	// SHADER COMMANDS
	global->Set(v8::String::New("dbCreateVertexShaderFromFile"), v8::FunctionTemplate::New(createVertexShaderFromFile));
	global->Set(v8::String::New("dbDeleteVertexShader"), v8::FunctionTemplate::New(deleteVertexShader));
	global->Set(v8::String::New("dbSetVertexShaderOn"), v8::FunctionTemplate::New(setVertexShaderOn));
	global->Set(v8::String::New("dbSetVertexShaderOff"), v8::FunctionTemplate::New(setVertexShaderOff));
	global->Set(v8::String::New("dbSetVertexShaderVector"), v8::FunctionTemplate::New(setVertexShaderVector));
	global->Set(v8::String::New("dbSetVertexShaderMatrix"), v8::FunctionTemplate::New(setVertexShaderMatrix));
	global->Set(v8::String::New("dbSetVertexShaderStream"), v8::FunctionTemplate::New(setVertexShaderStream));
	global->Set(v8::String::New("dbSetVertexShaderStreamCount"), v8::FunctionTemplate::New(setVertexShaderStreamCount));
	global->Set(v8::String::New("dbConvertObjectFVF"), v8::FunctionTemplate::New(convertObjectFVF));

	global->Set(v8::String::New("dbCreatePixelShaderFromFile"), v8::FunctionTemplate::New(createPixelShaderFromFile));
	global->Set(v8::String::New("dbDeletePixelShader"), v8::FunctionTemplate::New(deletePixelShader));
	global->Set(v8::String::New("dbSetPixelShaderOn"), v8::FunctionTemplate::New(setPixelShaderOn));
	global->Set(v8::String::New("dbSetPixelShaderOff"), v8::FunctionTemplate::New(setPixelShaderOff));
	global->Set(v8::String::New("dbSetPixelShaderTexture"), v8::FunctionTemplate::New(setPixelShaderTexture));

	global->Set(v8::String::New("dbFlushVideoMemory"), v8::FunctionTemplate::New(flushVideoMemory));

	// OBJECT EXPRESSIONS
	global->Set(v8::String::New("dbObjectExist"), v8::FunctionTemplate::New(objectExist));
	global->Set(v8::String::New("dbObjectVisible"), v8::FunctionTemplate::New(objectVisible));
	global->Set(v8::String::New("dbObjectPlaying"), v8::FunctionTemplate::New(objectPlaying));
	global->Set(v8::String::New("dbObjectLooping"), v8::FunctionTemplate::New(objectLooping));
	global->Set(v8::String::New("dbObjectPositionX"), v8::FunctionTemplate::New(objectPositionX));
	global->Set(v8::String::New("dbObjectPositionY"), v8::FunctionTemplate::New(objectPositionY));
	global->Set(v8::String::New("dbObjectPositionZ"), v8::FunctionTemplate::New(objectPositionZ));
	global->Set(v8::String::New("dbObjectSize"), v8::FunctionTemplate::New(objectSize));
	global->Set(v8::String::New("dbObjectSizeX"), v8::FunctionTemplate::New(objectSizeX));
	global->Set(v8::String::New("dbObjectSizeY"), v8::FunctionTemplate::New(objectSizeY));
	global->Set(v8::String::New("dbObjectSizeZ"), v8::FunctionTemplate::New(objectSizeZ));
	global->Set(v8::String::New("dbObjectAngleX"), v8::FunctionTemplate::New(objectAngleX));
	global->Set(v8::String::New("dbObjectAngleY"), v8::FunctionTemplate::New(objectAngleY));
	global->Set(v8::String::New("dbObjectAngleZ"), v8::FunctionTemplate::New(objectAngleZ));
	global->Set(v8::String::New("dbObjectFrame"), v8::FunctionTemplate::New(objectFrame));
	global->Set(v8::String::New("dbObjectSpeed"), v8::FunctionTemplate::New(objectSpeed));
	global->Set(v8::String::New("dbObjectInterpolation"), v8::FunctionTemplate::New(objectInterpolation));
	global->Set(v8::String::New("dbTotalObjectFrames"), v8::FunctionTemplate::New(totalObjectFrames));

	// COLLISION EXPRESSIONS
	global->Set(v8::String::New("dbObjectHit"), v8::FunctionTemplate::New(objectHit));
	global->Set(v8::String::New("dbObjectCollision"), v8::FunctionTemplate::New(objectCollision));
	global->Set(v8::String::New("dbObjectCollisionX"), v8::FunctionTemplate::New(objectCollisionX));
	global->Set(v8::String::New("dbObjectCollisionY"), v8::FunctionTemplate::New(objectCollisionY));
	global->Set(v8::String::New("dbObjectCollisionZ"), v8::FunctionTemplate::New(objectCollisionZ));
	global->Set(v8::String::New("dbObjectCollisionRadius"), v8::FunctionTemplate::New(objectCollisionRadius));
	global->Set(v8::String::New("dbObjectCollisionCenterX"), v8::FunctionTemplate::New(objectCollisionCenterX));
	global->Set(v8::String::New("dbObjectCollisionCenterY"), v8::FunctionTemplate::New(objectCollisionCenterY));
	global->Set(v8::String::New("dbObjectCollisionCenterZ"), v8::FunctionTemplate::New(objectCollisionCenterZ));
	global->Set(v8::String::New("dbIntersectObject"), v8::FunctionTemplate::New(intersectObject));

	// LIMB EXPRESSIONS
	global->Set(v8::String::New("dbLimbExist"), v8::FunctionTemplate::New(limbExist));
	global->Set(v8::String::New("dbLimbName"), v8::FunctionTemplate::New(limbName));
	global->Set(v8::String::New("dbLimbVisible"), v8::FunctionTemplate::New(limbVisible));
	global->Set(v8::String::New("dbLimbOffsetX"), v8::FunctionTemplate::New(limbOffsetX));
	global->Set(v8::String::New("dbLimbOffsetY"), v8::FunctionTemplate::New(limbOffsetY));
	global->Set(v8::String::New("dbLimbOffsetZ"), v8::FunctionTemplate::New(limbOffsetZ));
	global->Set(v8::String::New("dbLimbScaleX"), v8::FunctionTemplate::New(limbScaleX));
	global->Set(v8::String::New("dbLimbScaleY"), v8::FunctionTemplate::New(limbScaleY));
	global->Set(v8::String::New("dbLimbScaleZ"), v8::FunctionTemplate::New(limbScaleZ));
	global->Set(v8::String::New("dbLimbAngleX"), v8::FunctionTemplate::New(limbAngleX));
	global->Set(v8::String::New("dbLimbAngleY"), v8::FunctionTemplate::New(limbAngleY));
	global->Set(v8::String::New("dbLimbAngleZ"), v8::FunctionTemplate::New(limbAngleZ));
	global->Set(v8::String::New("dbLimbTexture"), v8::FunctionTemplate::New(limbTexture));
	global->Set(v8::String::New("dbLimbTextureName"), v8::FunctionTemplate::New(limbTextureName));
	global->Set(v8::String::New("dbLimbDirectionX"), v8::FunctionTemplate::New(limbDirectionX));
	global->Set(v8::String::New("dbLimbDirectionY"), v8::FunctionTemplate::New(limbDirectionY));
	global->Set(v8::String::New("dbLimbDirectionZ"), v8::FunctionTemplate::New(limbDirectionZ));
	global->Set(v8::String::New("dbLimbPositionX"), v8::FunctionTemplate::New(limbPositionX));
	global->Set(v8::String::New("dbLimbPositionY"), v8::FunctionTemplate::New(limbPositionY));
	global->Set(v8::String::New("dbLimbPositionZ"), v8::FunctionTemplate::New(limbPositionZ));
	global->Set(v8::String::New("dbCheckLimbLink"), v8::FunctionTemplate::New(checkLimbLink));

	// STATIC COLLISION EXPRESSIONS
	global->Set(v8::String::New("dbStaticLineOfSight"), v8::FunctionTemplate::New(staticLineOfSight));
	global->Set(v8::String::New("dbStaticLineOfSightX"), v8::FunctionTemplate::New(staticLineOfSightX));
	global->Set(v8::String::New("dbStaticLineOfSightY"), v8::FunctionTemplate::New(staticLineOfSightY));
	global->Set(v8::String::New("dbStaticLineOfSightZ"), v8::FunctionTemplate::New(staticLineOfSightZ));
	global->Set(v8::String::New("dbGetStaticCollisionHit"), v8::FunctionTemplate::New(getStaticCollisionHit));
	global->Set(v8::String::New("dbGetStaticCollisionX"), v8::FunctionTemplate::New(getStaticCollisionX));
	global->Set(v8::String::New("dbGetStaticCollisionY"), v8::FunctionTemplate::New(getStaticCollisionY));
	global->Set(v8::String::New("dbGetStaticCollisionZ"), v8::FunctionTemplate::New(getStaticCollisionZ));

	// SCREEN OBJECT EXPRESSIONS
	global->Set(v8::String::New("dbObjectInScreen"), v8::FunctionTemplate::New(objectInScreen));
	global->Set(v8::String::New("dbObjectScreenX"), v8::FunctionTemplate::New(objectScreenX));
	global->Set(v8::String::New("dbObjectScreenY"), v8::FunctionTemplate::New(objectScreenY));
	global->Set(v8::String::New("dbPickObject"), v8::FunctionTemplate::New(pickObject));
	global->Set(v8::String::New("dbPickScreen"), v8::FunctionTemplate::New(pickScreen));
	global->Set(v8::String::New("dbGetPickDistance"), v8::FunctionTemplate::New(getPickDistance));
	global->Set(v8::String::New("dbGetPickVectorX"), v8::FunctionTemplate::New(getPickVectorX));
	global->Set(v8::String::New("dbGetPickVectorY"), v8::FunctionTemplate::New(getPickVectorY));
	global->Set(v8::String::New("dbGetPickVectorZ"), v8::FunctionTemplate::New(getPickVectorZ));

	// AVAILABILITY EXPRESSIONS
	global->Set(v8::String::New("dbAlphaBlendingAvailable"), v8::FunctionTemplate::New(alphaBlendingAvailable));
	global->Set(v8::String::New("dbAlphaAvailable"), v8::FunctionTemplate::New(alphaAvailable));
	global->Set(v8::String::New("dbAlphaComparisionAvailable"), v8::FunctionTemplate::New(alphaComparisionAvailable));
	global->Set(v8::String::New("dbAnisotropicFilteringAvailable"), v8::FunctionTemplate::New(anisotropicFilteringAvailable));
	global->Set(v8::String::New("dbAntiAliasAvailable"), v8::FunctionTemplate::New(antiAliasAvailable));
	global->Set(v8::String::New("dbBlitSysOntoLocalAvailable"), v8::FunctionTemplate::New(blitSysOntoLocalAvailable));
	global->Set(v8::String::New("dbCalibrateGammaAvailable"), v8::FunctionTemplate::New(calibrateGammaAvailable));
	global->Set(v8::String::New("dbClipAndScalePointsAvailable"), v8::FunctionTemplate::New(clipAndScalePointsAvailable));
	global->Set(v8::String::New("dbClipTLVertsAvailable"), v8::FunctionTemplate::New(clipTLVertsAvailable));
	global->Set(v8::String::New("dbColorPerspectiveAvailable"), v8::FunctionTemplate::New(colorPerspectiveAvailable));
	global->Set(v8::String::New("dbColorWriteEnableAvailable"), v8::FunctionTemplate::New(colorWriteEnableAvailable));
	global->Set(v8::String::New("dbCubeMapAvailable"), v8::FunctionTemplate::New(cubeMapAvailable));
	global->Set(v8::String::New("dbCullCCWAvailable"), v8::FunctionTemplate::New(cullCCWAvailable));
	global->Set(v8::String::New("dbCullCWAvailable"), v8::FunctionTemplate::New(cullCWAvailable));
	global->Set(v8::String::New("dbGetDeviceType"), v8::FunctionTemplate::New(getDeviceType));
	global->Set(v8::String::New("dbDitherAvailable"), v8::FunctionTemplate::New(ditherAvailable));
	global->Set(v8::String::New("dbFilteringAvailable"), v8::FunctionTemplate::New(filteringAvailable));
	global->Set(v8::String::New("dbFogRangeAvailable"), v8::FunctionTemplate::New(fogRangeAvailable));
	global->Set(v8::String::New("dbFogTableAvailable"), v8::FunctionTemplate::New(fogTableAvailable));
	global->Set(v8::String::New("dbFogVertexAvailable"), v8::FunctionTemplate::New(fogVertexAvailable));
	global->Set(v8::String::New("dbFogAvailable"), v8::FunctionTemplate::New(fogAvailable));
	global->Set(v8::String::New("dbFullScreenGammaAvailable"), v8::FunctionTemplate::New(fullScreenGammaAvailable));
	global->Set(v8::String::New("dbGetMaximumLights"), v8::FunctionTemplate::New(getMaximumLights));
	global->Set(v8::String::New("dbGetMaximumPixelShaderValue"), v8::FunctionTemplate::New(getMaximumPixelShaderValue));
	global->Set(v8::String::New("dbGetMaximumTextureHeight"), v8::FunctionTemplate::New(getMaximumTextureHeight));
	global->Set(v8::String::New("dbGetMaximumTextureWidth"), v8::FunctionTemplate::New(getMaximumTextureWidth));
	global->Set(v8::String::New("dbGetMaximumVertexShaderConstants"), v8::FunctionTemplate::New(getMaximumVertexShaderConstants));
	global->Set(v8::String::New("dbGetMaximumVolumeExtent"), v8::FunctionTemplate::New(getMaximumVolumeExtent));
	global->Set(v8::String::New("dbMipCubeMapAvailable"), v8::FunctionTemplate::New(mipCubeMapAvailable));
	global->Set(v8::String::New("dbMipMapAvailable"), v8::FunctionTemplate::New(mipMapAvailable));
	global->Set(v8::String::New("dbMipMapLODBiasAvailable"), v8::FunctionTemplate::New(mipMapLODBiasAvailable));
	global->Set(v8::String::New("dbMipMapVolumeAvailable"), v8::FunctionTemplate::New(mipMapVolumeAvailable));
	global->Set(v8::String::New("dbNonPowTexturesAvailable"), v8::FunctionTemplate::New(nonPowTexturesAvailable));
	global->Set(v8::String::New("dbPerspectiveTexturesAvailable"), v8::FunctionTemplate::New(perspectiveTexturesAvailable));
	global->Set(v8::String::New("dbGetMaximumPixelShaderVersion"), v8::FunctionTemplate::New(getMaximumPixelShaderVersion));
	global->Set(v8::String::New("dbRenderAfterFlipAvailable"), v8::FunctionTemplate::New(renderAfterFlipAvailable));
	global->Set(v8::String::New("dbRenderWindowedAvailable"), v8::FunctionTemplate::New(renderWindowedAvailable));
	global->Set(v8::String::New("dbSeparateTextureMemoriesAvailable"), v8::FunctionTemplate::New(separateTextureMemoriesAvailable));
	global->Set(v8::String::New("dbOnlySquareTexturesAvailable"), v8::FunctionTemplate::New(onlySquareTexturesAvailable));
	global->Set(v8::String::New("dbGetTNLAvailable"), v8::FunctionTemplate::New(getTNLAvailable));
	global->Set(v8::String::New("dbTlVertexSystemMemoryAvailable"), v8::FunctionTemplate::New(tlVertexSystemMemoryAvailable));
	global->Set(v8::String::New("dbTlVertexVideoMemoryAvailable"), v8::FunctionTemplate::New(tlVertexVideoMemoryAvailable));
	global->Set(v8::String::New("dbNonLocalVideoMemoryAvailable"), v8::FunctionTemplate::New(nonLocalVideoMemoryAvailable));
	global->Set(v8::String::New("dbTextureSystemMemoryAvailable"), v8::FunctionTemplate::New(textureSystemMemoryAvailable));
	global->Set(v8::String::New("dbGetMaximumVertexShaderVersion"), v8::FunctionTemplate::New(getMaximumVertexShaderVersion));
	global->Set(v8::String::New("dbVolumeMapAvailable"), v8::FunctionTemplate::New(volumeMapAvailable));
	global->Set(v8::String::New("dbWBufferAvailable"), v8::FunctionTemplate::New(wBufferAvailable));
	global->Set(v8::String::New("dbWFogAvailable"), v8::FunctionTemplate::New(wFogAvailable));
	global->Set(v8::String::New("dbZBufferAvailable"), v8::FunctionTemplate::New(zBufferAvailable));
	global->Set(v8::String::New("dbZFogAvailable"), v8::FunctionTemplate::New(zFogAvailable));
	global->Set(v8::String::New("dbMeshExist"), v8::FunctionTemplate::New(meshExist));
	global->Set(v8::String::New("dbEffectExist"), v8::FunctionTemplate::New(effectExist));
	global->Set(v8::String::New("dbVertexShaderExist"), v8::FunctionTemplate::New(vertexShaderExist));
	global->Set(v8::String::New("dbPixelShaderExist"), v8::FunctionTemplate::New(pixelShaderExist));
	global->Set(v8::String::New("dbStatistic"), v8::FunctionTemplate::New(statistic));

}