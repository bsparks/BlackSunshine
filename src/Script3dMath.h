// Script3dMath.h

v8::Handle<v8::Value> addMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbAddMatrix4(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> addVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbAddVector2(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> addVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbAddVector3(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> addVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbAddVector4(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> buildLookAtLHMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int eye = args[1]->Int32Value();
	int at = args[2]->Int32Value();
	int up = args[3]->Int32Value();

	dbBuildLookAtLHMatrix4(result, eye, at, up);

	return v8::Undefined();
}

v8::Handle<v8::Value> buildLookAtRHMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int eye = args[1]->Int32Value();
	int at = args[2]->Int32Value();
	int up = args[3]->Int32Value();

	dbBuildLookAtRHMatrix4(result, eye, at, up);

	return v8::Undefined();
}

v8::Handle<v8::Value> buildOrthoLHMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float width = args[1]->NumberValue();
	float height = args[2]->NumberValue();
	float fNear = args[3]->NumberValue();
	float fFar = args[4]->NumberValue();

	dbBuildOrthoLHMatrix4(result, width, height, fNear, fFar);

	return v8::Undefined();
}

v8::Handle<v8::Value> buildOrthoRHMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float width = args[1]->NumberValue();
	float height = args[2]->NumberValue();
	float fNear = args[3]->NumberValue();
	float fFar = args[4]->NumberValue();

	dbBuildOrthoRHMatrix4(result, width, height, fNear, fFar);

	return v8::Undefined();
}

v8::Handle<v8::Value> buildFovLHMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float fov = args[1]->NumberValue();
	float aspect = args[2]->NumberValue();
	float fNear = args[3]->NumberValue();
	float fFar = args[4]->NumberValue();

	dbBuildFovLHMatrix4(result, fov, aspect, fNear, fFar);

	return v8::Undefined();
}

v8::Handle<v8::Value> buildFovRHMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float fov = args[1]->NumberValue();
	float aspect = args[2]->NumberValue();
	float fNear = args[3]->NumberValue();
	float fFar = args[4]->NumberValue();

	dbBuildFovRHMatrix4(result, fov, aspect, fNear, fFar);

	return v8::Undefined();
}

v8::Handle<v8::Value> buildPerspectiveLHMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float width = args[1]->NumberValue();
	float height = args[2]->NumberValue();
	float fNear = args[3]->NumberValue();
	float fFar = args[4]->NumberValue();

	dbBuildPerspectiveLHMatrix4(result, width, height, fNear, fFar);

	return v8::Undefined();
}

v8::Handle<v8::Value> buildPerspectiveRHMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float width = args[1]->NumberValue();
	float height = args[2]->NumberValue();
	float fNear = args[3]->NumberValue();
	float fFar = args[4]->NumberValue();

	dbBuildPerspectiveRHMatrix4(result, width, height, fNear, fFar);

	return v8::Undefined();
}

v8::Handle<v8::Value> buildReflectionMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float a = args[1]->NumberValue();
	float b = args[2]->NumberValue();
	float c = args[3]->NumberValue();
	float d = args[4]->NumberValue();

	dbBuildReflectionMatrix4(result, a, b, c, d);

	return v8::Undefined();
}

v8::Handle<v8::Value> buildRotationAxisMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int axis = args[1]->Int32Value();
	float angle = args[2]->NumberValue();

	dbBuildRotationAxisMatrix4(result, axis, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> catmullRomVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();
	int c = args[3]->Int32Value();
	int d = args[4]->Int32Value();
	float s = args[5]->NumberValue();

	dbCatmullRomVector2(result, a, b, c, d, s);

	return v8::Undefined();
}

v8::Handle<v8::Value> catmullRomVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();
	int c = args[3]->Int32Value();
	int d = args[4]->Int32Value();
	float s = args[5]->NumberValue();

	dbCatmullRomVector3(result, a, b, c, d, s);

	return v8::Undefined();
}

v8::Handle<v8::Value> catmullRomVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();
	int c = args[3]->Int32Value();
	int d = args[4]->Int32Value();
	float s = args[5]->NumberValue();

	dbCatmullRomVector4(result, a, b, c, d, s);

	return v8::Undefined();
}

v8::Handle<v8::Value> copyMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int source = args[0]->Int32Value();
	int dest = args[1]->Int32Value();

	dbCopyMatrix4(source, dest);

	return v8::Undefined();
}

v8::Handle<v8::Value> copyVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int source = args[0]->Int32Value();
	int dest = args[1]->Int32Value();

	dbCopyVector2(source, dest);

	return v8::Undefined();
}

v8::Handle<v8::Value> copyVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int source = args[0]->Int32Value();
	int dest = args[1]->Int32Value();

	dbCopyVector3(source, dest);

	return v8::Undefined();
}

v8::Handle<v8::Value> copyVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int source = args[0]->Int32Value();
	int dest = args[1]->Int32Value();

	dbCopyVector4(source, dest);

	return v8::Undefined();
}

v8::Handle<v8::Value> crossProductVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbCrossProductVector3(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();

	return v8::Boolean::New(dbDeleteMatrix4(id));
}

v8::Handle<v8::Value> deleteVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();

	return v8::Boolean::New(dbDeleteVector2(id));
}

v8::Handle<v8::Value> deleteVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();

	return v8::Boolean::New(dbDeleteVector3(id));
}

v8::Handle<v8::Value> deleteVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();

	return v8::Boolean::New(dbDeleteVector4(id));
}

v8::Handle<v8::Value> divideMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	float value = args[1]->NumberValue();

	dbDivideMatrix4(id, value);

	return v8::Undefined();
}

v8::Handle<v8::Value> divideVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	float value = args[1]->NumberValue();

	dbDivideVector2(id, value);

	return v8::Undefined();
}

v8::Handle<v8::Value> divideVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	float value = args[1]->NumberValue();

	dbDivideVector3(id, value);

	return v8::Undefined();
}

v8::Handle<v8::Value> divideVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int id = args[0]->Int32Value();
	float value = args[1]->NumberValue();

	dbDivideVector4(id, value);

	return v8::Undefined();
}

v8::Handle<v8::Value> dotProductVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int a = args[0]->Int32Value();
	int b = args[1]->Int32Value();

	return v8::Number::New(dbDotProductVector2(a, b));
}

v8::Handle<v8::Value> dotProductVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int a = args[0]->Int32Value();
	int b = args[1]->Int32Value();

	return v8::Number::New(dbDotProductVector3(a, b));
}

v8::Handle<v8::Value> bccVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();
	int c = args[3]->Int32Value();
	float f = args[4]->NumberValue();
	float g = args[5]->NumberValue();

	dbBCCVector2(result, a, b, c, f, g);

	return v8::Undefined();
}

v8::Handle<v8::Value> bccVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();
	int c = args[3]->Int32Value();
	float f = args[4]->NumberValue();
	float g = args[5]->NumberValue();

	dbBCCVector3(result, a, b, c, f, g);

	return v8::Undefined();
}

v8::Handle<v8::Value> bccVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();
	int c = args[3]->Int32Value();
	float f = args[4]->NumberValue();
	float g = args[5]->NumberValue();

	dbBCCVector4(result, a, b, c, f, g);

	return v8::Undefined();
}

v8::Handle<v8::Value> ccwVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int a = args[0]->Int32Value();
	int b = args[1]->Int32Value();

	return v8::Number::New(dbCCWVector2(a, b));
}

v8::Handle<v8::Value> squaredLengthVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbSquaredLengthVector2(vec));
}

v8::Handle<v8::Value> squaredLengthVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbSquaredLengthVector3(vec));
}

v8::Handle<v8::Value> squaredLengthVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbSquaredLengthVector4(vec));
}

v8::Handle<v8::Value> lengthVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbLengthVector2(vec));
}

v8::Handle<v8::Value> lengthVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbLengthVector3(vec));
}

v8::Handle<v8::Value> lengthVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbLengthVector4(vec));
}

v8::Handle<v8::Value> projectionMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();

	dbProjectionMatrix4(result);

	return v8::Undefined();
}

v8::Handle<v8::Value> viewMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();

	dbViewMatrix4(result);

	return v8::Undefined();
}

v8::Handle<v8::Value> wVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbWVector4(vec));
}

v8::Handle<v8::Value> worldMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();

	dbWorldMatrix4(result);

	return v8::Undefined();
}

v8::Handle<v8::Value> xVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbXVector2(vec));
}

v8::Handle<v8::Value> xVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbXVector3(vec));
}

v8::Handle<v8::Value> xVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbXVector4(vec));
}

v8::Handle<v8::Value> yVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbYVector2(vec));
}

v8::Handle<v8::Value> yVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbYVector3(vec));
}

v8::Handle<v8::Value> yVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbYVector4(vec));
}

v8::Handle<v8::Value> zVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbZVector3(vec));
}

v8::Handle<v8::Value> zVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Number::New(dbZVector4(vec));
}

v8::Handle<v8::Value> hermiteVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();
	int c = args[3]->Int32Value();
	int d = args[4]->Int32Value();
	float s = args[5]->NumberValue();

	dbHermiteVector2(result, a, b, c, d, s);

	return v8::Undefined();
}

v8::Handle<v8::Value> hermiteVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();
	int c = args[3]->Int32Value();
	int d = args[4]->Int32Value();
	float s = args[5]->NumberValue();

	dbHermiteVector3(result, a, b, c, d, s);

	return v8::Undefined();
}

v8::Handle<v8::Value> hermiteVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();
	int c = args[3]->Int32Value();
	int d = args[4]->Int32Value();
	float s = args[5]->NumberValue();

	dbHermiteVector4(result, a, b, c, d, s);

	return v8::Undefined();
}

v8::Handle<v8::Value> inverseMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();

	return v8::Number::New(dbInverseMatrix4(result, source));
}

v8::Handle<v8::Value> isEqualMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int a = args[0]->Int32Value();
	int b = args[1]->Int32Value();

	return v8::Boolean::New(dbIsEqualMatrix4(a, b));
}

v8::Handle<v8::Value> isEqualVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int a = args[0]->Int32Value();
	int b = args[1]->Int32Value();

	return v8::Boolean::New(dbIsEqualVector2(a, b));
}

v8::Handle<v8::Value> isEqualVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int a = args[0]->Int32Value();
	int b = args[1]->Int32Value();

	return v8::Boolean::New(dbIsEqualVector3(a, b));
}

v8::Handle<v8::Value> isEqualVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int a = args[0]->Int32Value();
	int b = args[1]->Int32Value();

	return v8::Boolean::New(dbIsEqualVector4(a, b));
}

v8::Handle<v8::Value> isIdentityMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int mat = args[0]->Int32Value();

	return v8::Boolean::New(dbIsIdentityMatrix4(mat));
}

v8::Handle<v8::Value> linearInterpolateVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();
	float s = args[3]->NumberValue();

	dbLinearInterpolateVector2(result, a, b, s);

	return v8::Undefined();
}

v8::Handle<v8::Value> linearInterpolateVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();
	float s = args[3]->NumberValue();

	dbLinearInterpolateVector3(result, a, b, s);

	return v8::Undefined();
}

v8::Handle<v8::Value> linearInterpolateVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();
	float s = args[3]->NumberValue();

	dbLinearInterpolateVector4(result, a, b, s);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int mat = args[0]->Int32Value();

	return v8::Boolean::New(dbMakeMatrix4(mat));
}

v8::Handle<v8::Value> makeVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Boolean::New(dbMakeVector2(vec));
}

v8::Handle<v8::Value> makeVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Boolean::New(dbMakeVector3(vec));
}

v8::Handle<v8::Value> makeVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vec = args[0]->Int32Value();

	return v8::Boolean::New(dbMakeVector4(vec));
}

v8::Handle<v8::Value> maximizeVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbMaximizeVector2(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> maximizeVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbMaximizeVector3(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> maximizeVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbMaximizeVector4(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> minimizeVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbMinimizeVector2(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> minimizeVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbMinimizeVector3(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> minimizeVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbMinimizeVector4(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> multiplyMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbMultiplyMatrix4(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> multiplyVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float value = args[1]->NumberValue();

	dbMultiplyVector2(result, value);

	return v8::Undefined();
}

v8::Handle<v8::Value> multiplyVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float value = args[1]->NumberValue();

	dbMultiplyVector3(result, value);

	return v8::Undefined();
}

v8::Handle<v8::Value> multiplyVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float value = args[1]->NumberValue();

	dbMultiplyVector4(result, value);

	return v8::Undefined();
}

v8::Handle<v8::Value> normalizeVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();

	dbNormalizeVector2(result, source);

	return v8::Undefined();
}

v8::Handle<v8::Value> normalizeVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();

	dbNormalizeVector3(result, source);

	return v8::Undefined();
}

v8::Handle<v8::Value> normalizeVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();

	dbNormalizeVector4(result, source);

	return v8::Undefined();
}

v8::Handle<v8::Value> projectVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();
	int projMat = args[2]->Int32Value();
	int viewMat = args[3]->Int32Value();
	int worldMat = args[4]->Int32Value();

	dbProjectVector3(result, source, projMat, viewMat, worldMat);

	return v8::Undefined();
}

v8::Handle<v8::Value> rotateXMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float angle = args[1]->NumberValue();

	dbRotateXMatrix4(result, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> rotateYMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float angle = args[1]->NumberValue();

	dbRotateYMatrix4(result, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> rotateZMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float angle = args[1]->NumberValue();

	dbRotateZMatrix4(result, angle);

	return v8::Undefined();
}

v8::Handle<v8::Value> rotateYPRMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float yaw = args[1]->NumberValue();
	float pitch = args[2]->NumberValue();
	float roll = args[3]->NumberValue();

	dbRotateYPRMatrix4(result, yaw, pitch, roll);

	return v8::Undefined();
}

v8::Handle<v8::Value> scaleMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbScaleMatrix4(result, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> scaleVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();
	float s = args[2]->NumberValue();

	dbScaleVector2(result, source, s);

	return v8::Undefined();
}

v8::Handle<v8::Value> scaleVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();
	float s = args[2]->NumberValue();

	dbScaleVector3(result, source, s);

	return v8::Undefined();
}

v8::Handle<v8::Value> scaleVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();
	float s = args[2]->NumberValue();

	dbScaleVector4(result, source, s);

	return v8::Undefined();
}

v8::Handle<v8::Value> setIdentityMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();

	dbSetIdentityMatrix4(result);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();

	dbSetVector2(result, x, y);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbSetVector3(result, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();
	float w = args[4]->NumberValue();

	dbSetVector4(result, x, y, z, w);

	return v8::Undefined();
}

v8::Handle<v8::Value> subtractMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbSubtractMatrix4(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> subtractVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbSubtractVector2(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> subtractVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbSubtractVector3(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> subtractVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int a = args[1]->Int32Value();
	int b = args[2]->Int32Value();

	dbSubtractVector4(result, a, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> transformVector4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();
	int matrix = args[2]->Int32Value();

	dbTransformVector4(result, source, matrix);

	return v8::Undefined();
}

v8::Handle<v8::Value> transformCoordsVector2(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();
	int matrix = args[2]->Int32Value();

	dbTransformCoordsVector2(result, source, matrix);

	return v8::Undefined();
}

v8::Handle<v8::Value> transformCoordsVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();
	int matrix = args[2]->Int32Value();

	dbTransformCoordsVector3(result, source, matrix);

	return v8::Undefined();
}

v8::Handle<v8::Value> transformNormalsVector3(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();
	int matrix = args[2]->Int32Value();

	dbTransformNormalsVector3(result, source, matrix);

	return v8::Undefined();
}

v8::Handle<v8::Value> translateMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbTranslateMatrix4(result, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> transposeMatrix4(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int result = args[0]->Int32Value();
	int source = args[1]->Int32Value();

	dbTransposeMatrix4(result, source);

	return v8::Undefined();
}

void RegisterScript3dMath(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbAddMatrix4"), v8::FunctionTemplate::New(addMatrix4));
	global->Set(v8::String::New("dbAddVector2"), v8::FunctionTemplate::New(addVector2));
	global->Set(v8::String::New("dbAddVector3"), v8::FunctionTemplate::New(addVector3));
	global->Set(v8::String::New("dbAddVector4"), v8::FunctionTemplate::New(addVector4));
	global->Set(v8::String::New("dbBuildLookAtLHMatrix4"), v8::FunctionTemplate::New(buildLookAtLHMatrix4));
	global->Set(v8::String::New("dbBuildLookAtRHMatrix4"), v8::FunctionTemplate::New(buildLookAtRHMatrix4));
	global->Set(v8::String::New("dbBuildOrthoLHMatrix4"), v8::FunctionTemplate::New(buildOrthoLHMatrix4));
	global->Set(v8::String::New("dbBuildOrthoRHMatrix4"), v8::FunctionTemplate::New(buildOrthoRHMatrix4));
	global->Set(v8::String::New("dbBuildFovLHMatrix4"), v8::FunctionTemplate::New(buildFovLHMatrix4));
	global->Set(v8::String::New("dbBuildFovRHMatrix4"), v8::FunctionTemplate::New(buildFovRHMatrix4));
	global->Set(v8::String::New("dbBuildPerspectiveLHMatrix4"), v8::FunctionTemplate::New(buildPerspectiveLHMatrix4));
	global->Set(v8::String::New("dbBuildPerspectiveRHMatrix4"), v8::FunctionTemplate::New(buildPerspectiveRHMatrix4));
	global->Set(v8::String::New("dbBuildReflectionMatrix4"), v8::FunctionTemplate::New(buildReflectionMatrix4));
	global->Set(v8::String::New("dbBuildRotationAxisMatrix4"), v8::FunctionTemplate::New(buildRotationAxisMatrix4));
	global->Set(v8::String::New("dbCatmullRomVector2"), v8::FunctionTemplate::New(catmullRomVector2));
	global->Set(v8::String::New("dbCatmullRomVector3"), v8::FunctionTemplate::New(catmullRomVector3));
	global->Set(v8::String::New("dbCatmullRomVector4"), v8::FunctionTemplate::New(catmullRomVector4));
	global->Set(v8::String::New("dbCopyMatrix4"), v8::FunctionTemplate::New(copyMatrix4));
	global->Set(v8::String::New("dbCopyVector2"), v8::FunctionTemplate::New(copyVector2));
	global->Set(v8::String::New("dbCopyVector3"), v8::FunctionTemplate::New(copyVector3));
	global->Set(v8::String::New("dbCopyVector4"), v8::FunctionTemplate::New(copyVector4));
	global->Set(v8::String::New("dbCrossProductVector3"), v8::FunctionTemplate::New(crossProductVector3));
	global->Set(v8::String::New("dbDeleteMatrix4"), v8::FunctionTemplate::New(deleteMatrix4));
	global->Set(v8::String::New("dbDeleteVector2"), v8::FunctionTemplate::New(deleteVector2));
	global->Set(v8::String::New("dbDeleteVector3"), v8::FunctionTemplate::New(deleteVector3));
	global->Set(v8::String::New("dbDeleteVector4"), v8::FunctionTemplate::New(deleteVector4));
	global->Set(v8::String::New("dbDivideMatrix4"), v8::FunctionTemplate::New(divideMatrix4));
	global->Set(v8::String::New("dbDivideVector2"), v8::FunctionTemplate::New(divideVector2));
	global->Set(v8::String::New("dbDivideVector3"), v8::FunctionTemplate::New(divideVector3));
	global->Set(v8::String::New("dbDivideVector4"), v8::FunctionTemplate::New(divideVector4));
	global->Set(v8::String::New("dbDotProductVector2"), v8::FunctionTemplate::New(dotProductVector2));
	global->Set(v8::String::New("dbDotProductVector3"), v8::FunctionTemplate::New(dotProductVector3));
	global->Set(v8::String::New("dbBccVector2"), v8::FunctionTemplate::New(bccVector2));
	global->Set(v8::String::New("dbBccVector3"), v8::FunctionTemplate::New(bccVector3));
	global->Set(v8::String::New("dbBccVector4"), v8::FunctionTemplate::New(bccVector4));
	global->Set(v8::String::New("dbCcwVector2"), v8::FunctionTemplate::New(ccwVector2));
	global->Set(v8::String::New("dbSquaredLengthVector2"), v8::FunctionTemplate::New(squaredLengthVector2));
	global->Set(v8::String::New("dbSquaredLengthVector3"), v8::FunctionTemplate::New(squaredLengthVector3));
	global->Set(v8::String::New("dbSquaredLengthVector4"), v8::FunctionTemplate::New(squaredLengthVector4));
	global->Set(v8::String::New("dbLengthVector2"), v8::FunctionTemplate::New(lengthVector2));
	global->Set(v8::String::New("dbLengthVector3"), v8::FunctionTemplate::New(lengthVector3));
	global->Set(v8::String::New("dbLengthVector4"), v8::FunctionTemplate::New(lengthVector4));
	global->Set(v8::String::New("dbProjectionMatrix4"), v8::FunctionTemplate::New(projectionMatrix4));
	global->Set(v8::String::New("dbViewMatrix4"), v8::FunctionTemplate::New(viewMatrix4));
	global->Set(v8::String::New("dbWVector4"), v8::FunctionTemplate::New(wVector4));
	global->Set(v8::String::New("dbWorldMatrix4"), v8::FunctionTemplate::New(worldMatrix4));
	global->Set(v8::String::New("dbXVector2"), v8::FunctionTemplate::New(xVector2));
	global->Set(v8::String::New("dbXVector3"), v8::FunctionTemplate::New(xVector3));
	global->Set(v8::String::New("dbXVector4"), v8::FunctionTemplate::New(xVector4));
	global->Set(v8::String::New("dbYVector2"), v8::FunctionTemplate::New(yVector2));
	global->Set(v8::String::New("dbYVector3"), v8::FunctionTemplate::New(yVector3));
	global->Set(v8::String::New("dbYVector4"), v8::FunctionTemplate::New(yVector4));
	global->Set(v8::String::New("dbZVector3"), v8::FunctionTemplate::New(zVector3));
	global->Set(v8::String::New("dbZVector4"), v8::FunctionTemplate::New(zVector4));
	global->Set(v8::String::New("dbHermiteVector2"), v8::FunctionTemplate::New(hermiteVector2));
	global->Set(v8::String::New("dbHermiteVector3"), v8::FunctionTemplate::New(hermiteVector3));
	global->Set(v8::String::New("dbHermiteVector4"), v8::FunctionTemplate::New(hermiteVector4));
	global->Set(v8::String::New("dbInverseMatrix4"), v8::FunctionTemplate::New(inverseMatrix4));
	global->Set(v8::String::New("dbIsEqualMatrix4"), v8::FunctionTemplate::New(isEqualMatrix4));
	global->Set(v8::String::New("dbIsEqualVector2"), v8::FunctionTemplate::New(isEqualVector2));
	global->Set(v8::String::New("dbIsEqualVector3"), v8::FunctionTemplate::New(isEqualVector3));
	global->Set(v8::String::New("dbIsEqualVector4"), v8::FunctionTemplate::New(isEqualVector4));
	global->Set(v8::String::New("dbIsIdentityMatrix4"), v8::FunctionTemplate::New(isIdentityMatrix4));
	global->Set(v8::String::New("dbLinearInterpolateVector2"), v8::FunctionTemplate::New(linearInterpolateVector2));
	global->Set(v8::String::New("dbLinearInterpolateVector3"), v8::FunctionTemplate::New(linearInterpolateVector3));
	global->Set(v8::String::New("dbLinearInterpolateVector4"), v8::FunctionTemplate::New(linearInterpolateVector4));
	global->Set(v8::String::New("dbMakeMatrix4"), v8::FunctionTemplate::New(makeMatrix4));
	global->Set(v8::String::New("dbMakeVector2"), v8::FunctionTemplate::New(makeVector2));
	global->Set(v8::String::New("dbMakeVector3"), v8::FunctionTemplate::New(makeVector3));
	global->Set(v8::String::New("dbMakeVector4"), v8::FunctionTemplate::New(makeVector4));
	global->Set(v8::String::New("dbMaximizeVector2"), v8::FunctionTemplate::New(maximizeVector2));
	global->Set(v8::String::New("dbMaximizeVector3"), v8::FunctionTemplate::New(maximizeVector3));
	global->Set(v8::String::New("dbMaximizeVector4"), v8::FunctionTemplate::New(maximizeVector4));
	global->Set(v8::String::New("dbMinimizeVector2"), v8::FunctionTemplate::New(minimizeVector2));
	global->Set(v8::String::New("dbMinimizeVector3"), v8::FunctionTemplate::New(minimizeVector3));
	global->Set(v8::String::New("dbMinimizeVector4"), v8::FunctionTemplate::New(minimizeVector4));
	global->Set(v8::String::New("dbMultiplyMatrix4"), v8::FunctionTemplate::New(multiplyMatrix4));
	global->Set(v8::String::New("dbMultiplyVector2"), v8::FunctionTemplate::New(multiplyVector2));
	global->Set(v8::String::New("dbMultiplyVector3"), v8::FunctionTemplate::New(multiplyVector3));
	global->Set(v8::String::New("dbMultiplyVector4"), v8::FunctionTemplate::New(multiplyVector4));
	global->Set(v8::String::New("dbNormalizeVector2"), v8::FunctionTemplate::New(normalizeVector2));
	global->Set(v8::String::New("dbNormalizeVector3"), v8::FunctionTemplate::New(normalizeVector3));
	global->Set(v8::String::New("dbNormalizeVector4"), v8::FunctionTemplate::New(normalizeVector4));
	global->Set(v8::String::New("dbProjectVector3"), v8::FunctionTemplate::New(projectVector3));
	global->Set(v8::String::New("dbRotateXMatrix4"), v8::FunctionTemplate::New(rotateXMatrix4));
	global->Set(v8::String::New("dbRotateYMatrix4"), v8::FunctionTemplate::New(rotateYMatrix4));
	global->Set(v8::String::New("dbRotateYPRMatrix4"), v8::FunctionTemplate::New(rotateYPRMatrix4));
	global->Set(v8::String::New("dbRotateZMatrix4"), v8::FunctionTemplate::New(rotateZMatrix4));
	global->Set(v8::String::New("dbScaleMatrix4"), v8::FunctionTemplate::New(scaleMatrix4));
	global->Set(v8::String::New("dbScaleVector2"), v8::FunctionTemplate::New(scaleVector2));
	global->Set(v8::String::New("dbScaleVector3"), v8::FunctionTemplate::New(scaleVector3));
	global->Set(v8::String::New("dbScaleVector4"), v8::FunctionTemplate::New(scaleVector4));
	global->Set(v8::String::New("dbSetIdentityMatrix4"), v8::FunctionTemplate::New(setIdentityMatrix4));
	global->Set(v8::String::New("dbSetVector2"), v8::FunctionTemplate::New(setVector2));
	global->Set(v8::String::New("dbSetVector3"), v8::FunctionTemplate::New(setVector3));
	global->Set(v8::String::New("dbSetVector4"), v8::FunctionTemplate::New(setVector4));
	global->Set(v8::String::New("dbSubtractMatrix4"), v8::FunctionTemplate::New(subtractMatrix4));
	global->Set(v8::String::New("dbSubtractVector2"), v8::FunctionTemplate::New(subtractVector2));
	global->Set(v8::String::New("dbSubtractVector3"), v8::FunctionTemplate::New(subtractVector3));
	global->Set(v8::String::New("dbSubtractVector4"), v8::FunctionTemplate::New(subtractVector4));
	global->Set(v8::String::New("dbTransformVector4"), v8::FunctionTemplate::New(transformVector4));
	global->Set(v8::String::New("dbTransformCoordsVector2"), v8::FunctionTemplate::New(transformCoordsVector2));
	global->Set(v8::String::New("dbTransformCoordsVector3"), v8::FunctionTemplate::New(transformCoordsVector3));
	global->Set(v8::String::New("dbTransformNormalsVector3"), v8::FunctionTemplate::New(transformNormalsVector3));
	global->Set(v8::String::New("dbTranslateMatrix4"), v8::FunctionTemplate::New(translateMatrix4));
	global->Set(v8::String::New("dbTransposeMatrix4"), v8::FunctionTemplate::New(transposeMatrix4));
}