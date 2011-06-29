// ScriptParticles.h

v8::Handle<v8::Value> makeParticles(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	int imageId = args[1]->Int32Value();
	int maxParticles = args[2]->Int32Value();
	float radius = args[3]->NumberValue();

	dbMakeParticles(particleId, imageId, maxParticles, radius);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeSnowParticles(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	int imageId = args[1]->Int32Value();
	int maxParticles = args[2]->Int32Value();
	float x = args[3]->NumberValue();
	float y = args[4]->NumberValue();
	float z = args[5]->NumberValue();
	float width = args[6]->NumberValue();
	float height = args[7]->NumberValue();
	float depth = args[8]->NumberValue();

	dbMakeSnowParticles(particleId, imageId, maxParticles, x, y, z, width, height, depth);

	return v8::Undefined();
}

v8::Handle<v8::Value> makeFireParticles(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	int imageId = args[1]->Int32Value();
	int maxParticles = args[2]->Int32Value();
	float x = args[3]->NumberValue();
	float y = args[4]->NumberValue();
	float z = args[5]->NumberValue();
	float width = args[6]->NumberValue();
	float height = args[7]->NumberValue();
	float depth = args[8]->NumberValue();

	dbMakeFireParticles(particleId, imageId, maxParticles, x, y, z, width, height, depth);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteParticles(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();

	dbDeleteParticles(particleId);

	return v8::Undefined();
}

v8::Handle<v8::Value> showParticles(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();

	dbShowParticles(particleId);

	return v8::Undefined();
}

v8::Handle<v8::Value> hideParticles(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();

	dbHideParticles(particleId);

	return v8::Undefined();
}

v8::Handle<v8::Value> positionParticles(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbPositionParticles(particleId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> positionParticleEmissions(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbPositionParticleEmissions(particleId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> rotateParticles(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbRotateParticles(particleId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVector3ToParticlesPosition(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vectorId = args[0]->Int32Value();
	int particleId = args[1]->Int32Value();
	
	dbSetVector3ToParticlesPosition(vectorId, particleId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setVector3ToParticlesRotation(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int vectorId = args[0]->Int32Value();
	int particleId = args[1]->Int32Value();
	
	dbSetVector3ToParticlesRotation(vectorId, particleId);

	return v8::Undefined();
}

v8::Handle<v8::Value> colorParticles(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	int red = args[1]->Int32Value();
	int green = args[2]->Int32Value();
	int blue = args[3]->Int32Value();
	
	dbColorParticles(particleId, red, green, blue);

	return v8::Undefined();
}

v8::Handle<v8::Value> setParticleEmissions(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	int frequency = args[1]->Int32Value();
	
	dbSetParticleEmissions(particleId, frequency);

	return v8::Undefined();
}

v8::Handle<v8::Value> setParticleVelocity(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	float velocity = args[1]->NumberValue();
	
	dbSetParticleVelocity(particleId, velocity);

	return v8::Undefined();
}

v8::Handle<v8::Value> setParticleGravity(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	float gravity = args[1]->NumberValue();
	
	dbSetParticleGravity(particleId, gravity);

	return v8::Undefined();
}

v8::Handle<v8::Value> setParticleSpeed(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	float time = args[1]->NumberValue();
	
	dbSetParticleSpeed(particleId, time);

	return v8::Undefined();
}

v8::Handle<v8::Value> setParticleChaos(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	float chaos = args[1]->NumberValue();
	
	dbSetParticleChaos(particleId, chaos);

	return v8::Undefined();
}

v8::Handle<v8::Value> setParticleFloor(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	int flag = args[1]->Int32Value();
	
	dbSetParticleFloor(particleId, flag);

	return v8::Undefined();
}

v8::Handle<v8::Value> setParticleLife(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	int life = args[1]->Int32Value();
	
	dbSetParticleLife(particleId, life);

	return v8::Undefined();
}

v8::Handle<v8::Value> ghostParticlesOn(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	int mode = args[1]->Int32Value();
	
	dbGhostParticlesOn(particleId, mode);

	return v8::Undefined();
}

v8::Handle<v8::Value> ghostParticlesOff(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	
	dbGhostParticlesOff(particleId);

	return v8::Undefined();
}

v8::Handle<v8::Value> particlesExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	
	return v8::Int32::New(dbParticlesExist(particleId));
}

v8::Handle<v8::Value> particlesPositionX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	
	return v8::Number::New(dbParticlesPositionX(particleId));
}

v8::Handle<v8::Value> particlesPositionY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	
	return v8::Number::New(dbParticlesPositionY(particleId));
}

v8::Handle<v8::Value> particlesPositionZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int particleId = args[0]->Int32Value();
	
	return v8::Number::New(dbParticlesPositionZ(particleId));
}

void RegisterScriptParticles(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbMakeParticles"), v8::FunctionTemplate::New(makeParticles));
	global->Set(v8::String::New("dbMakeSnowParticles"), v8::FunctionTemplate::New(makeSnowParticles));
	global->Set(v8::String::New("dbMakeFireParticles"), v8::FunctionTemplate::New(makeFireParticles));
	global->Set(v8::String::New("dbDeleteParticles"), v8::FunctionTemplate::New(deleteParticles));
	global->Set(v8::String::New("dbShowParticles"), v8::FunctionTemplate::New(showParticles));
	global->Set(v8::String::New("dbHideParticles"), v8::FunctionTemplate::New(hideParticles));
	global->Set(v8::String::New("dbPositionParticles"), v8::FunctionTemplate::New(positionParticles));
	global->Set(v8::String::New("dbPositionParticleEmissions"), v8::FunctionTemplate::New(positionParticleEmissions));
	global->Set(v8::String::New("dbRotateParticles"), v8::FunctionTemplate::New(rotateParticles));
	global->Set(v8::String::New("dbSetVector3ToParticlesPosition"), v8::FunctionTemplate::New(setVector3ToParticlesPosition));
	global->Set(v8::String::New("dbSetVector3ToParticlesRotation"), v8::FunctionTemplate::New(setVector3ToParticlesRotation));
	global->Set(v8::String::New("dbColorParticles"), v8::FunctionTemplate::New(colorParticles));
	global->Set(v8::String::New("dbSetParticleEmissions"), v8::FunctionTemplate::New(setParticleEmissions));
	global->Set(v8::String::New("dbSetParticleVelocity"), v8::FunctionTemplate::New(setParticleVelocity));
	global->Set(v8::String::New("dbSetParticleGravity"), v8::FunctionTemplate::New(setParticleGravity));
	global->Set(v8::String::New("dbSetParticleSpeed"), v8::FunctionTemplate::New(setParticleSpeed));
	global->Set(v8::String::New("dbSetParticleChaos"), v8::FunctionTemplate::New(setParticleChaos));
	global->Set(v8::String::New("dbSetParticleFloor"), v8::FunctionTemplate::New(setParticleFloor));
	global->Set(v8::String::New("dbSetParticleLife"), v8::FunctionTemplate::New(setParticleLife));
	global->Set(v8::String::New("dbGhostParticlesOn"), v8::FunctionTemplate::New(ghostParticlesOn));
	global->Set(v8::String::New("dbGhostParticlesOff"), v8::FunctionTemplate::New(ghostParticlesOff));
	global->Set(v8::String::New("dbParticlesExist"), v8::FunctionTemplate::New(particlesExist));
	global->Set(v8::String::New("dbParticlesPositionX"), v8::FunctionTemplate::New(particlesPositionX));
	global->Set(v8::String::New("dbParticlesPositionY"), v8::FunctionTemplate::New(particlesPositionY));
	global->Set(v8::String::New("dbParticlesPositionZ"), v8::FunctionTemplate::New(particlesPositionZ));
}