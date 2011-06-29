// ScriptSound.h

v8::Handle<v8::Value> loadSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);

	int soundId = args[1]->Int32Value();

	dbLoadSound(ToCharString(temp), soundId);

	return v8::Undefined();
}

v8::Handle<v8::Value> load3DSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);

	int soundId = args[1]->Int32Value();

	dbLoad3DSound(ToCharString(temp), soundId);

	return v8::Undefined();
}

v8::Handle<v8::Value> saveSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);

	int soundId = args[1]->Int32Value();

	dbSaveSound(ToCharString(temp), soundId);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();

	dbDeleteSound(soundId);

	return v8::Undefined();
}

v8::Handle<v8::Value> cloneSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	int destId = args[0]->Int32Value();
	int sourceId = args[1]->Int32Value();

	dbCloneSound(destId, sourceId);

	return v8::Undefined();
}

v8::Handle<v8::Value> playSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();

	dbPlaySound(soundId);

	return v8::Undefined();
}

v8::Handle<v8::Value> loopSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();

	dbLoopSound(soundId);

	return v8::Undefined();
}

v8::Handle<v8::Value> stopSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();

	dbStopSound(soundId);

	return v8::Undefined();
}

v8::Handle<v8::Value> pauseSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();

	dbPauseSound(soundId);

	return v8::Undefined();
}

v8::Handle<v8::Value> resumeSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();

	dbResumeSound(soundId);

	return v8::Undefined();
}

v8::Handle<v8::Value> positionSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();
	float x = args[1]->NumberValue();
	float y = args[2]->NumberValue();
	float z = args[3]->NumberValue();

	dbPositionSound(soundId, x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> recordSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();

	dbRecordSound(soundId);

	return v8::Undefined();
}

v8::Handle<v8::Value> stopRecordingSound(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	dbStopRecordingSound();

	return v8::Undefined();
}

v8::Handle<v8::Value> setSoundPan(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();
	int pan = args[1]->Int32Value();

	dbSetSoundPan(soundId, pan);

	return v8::Undefined();
}

v8::Handle<v8::Value> setSoundSpeed(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();
	int speed = args[1]->Int32Value();

	dbSetSoundSpeed(soundId, speed);

	return v8::Undefined();
}

v8::Handle<v8::Value> setSoundVolume(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();
	int volume = args[1]->Int32Value();

	dbSetSoundVolume(soundId, volume);

	return v8::Undefined();
}

v8::Handle<v8::Value> positionListener(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	float x = args[0]->NumberValue();
	float y = args[1]->NumberValue();
	float z = args[2]->NumberValue();

	dbPositionListener(x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> rotateListener(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	float x = args[0]->NumberValue();
	float y = args[1]->NumberValue();
	float z = args[2]->NumberValue();

	dbRotateListener(x, y, z);

	return v8::Undefined();
}

v8::Handle<v8::Value> scaleListener(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	float scale = args[0]->NumberValue();

	dbScaleListener(scale);

	return v8::Undefined();
}

v8::Handle<v8::Value> soundExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int soundId = args[0]->Int32Value();

	return v8::Boolean::New(dbSoundExist(soundId));
}

v8::Handle<v8::Value> soundType(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int soundId = args[0]->Int32Value();

	return v8::Int32::New(dbSoundType(soundId));
}

v8::Handle<v8::Value> soundPlaying(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int soundId = args[0]->Int32Value();

	return v8::Boolean::New(dbSoundPlaying(soundId));
}

v8::Handle<v8::Value> soundLooping(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int soundId = args[0]->Int32Value();

	return v8::Boolean::New(dbSoundLooping(soundId));
}

v8::Handle<v8::Value> soundPaused(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int soundId = args[0]->Int32Value();

	return v8::Boolean::New(dbSoundPaused(soundId));
}

v8::Handle<v8::Value> soundPositionX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int soundId = args[0]->Int32Value();

	return v8::Number::New(dbSoundPositionX(soundId));
}

v8::Handle<v8::Value> soundPositionY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int soundId = args[0]->Int32Value();

	return v8::Number::New(dbSoundPositionY(soundId));
}

v8::Handle<v8::Value> soundPositionZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int soundId = args[0]->Int32Value();

	return v8::Number::New(dbSoundPositionZ(soundId));
}

v8::Handle<v8::Value> soundPan(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int soundId = args[0]->Int32Value();

	return v8::Int32::New(dbSoundPan(soundId));
}

v8::Handle<v8::Value> soundSpeed(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int soundId = args[0]->Int32Value();

	return v8::Int32::New(dbSoundSpeed(soundId));
}

v8::Handle<v8::Value> soundVolume(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int soundId = args[0]->Int32Value();

	return v8::Int32::New(dbSoundVolume(soundId));
}

v8::Handle<v8::Value> listenerPositionX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbListenerPositionX());
}

v8::Handle<v8::Value> listenerPositionY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbListenerPositionY());
}

v8::Handle<v8::Value> listenerPositionZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbListenerPositionZ());
}

v8::Handle<v8::Value> listenerAngleX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbListenerAngleX());
}

v8::Handle<v8::Value> listenerAngleY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbListenerAngleY());
}

v8::Handle<v8::Value> listenerAngleZ(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbListenerAngleZ());
}

void RegisterScriptSound(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbLoadSound"), v8::FunctionTemplate::New(loadSound));
	global->Set(v8::String::New("dbLoad3DSound"), v8::FunctionTemplate::New(load3DSound));
	global->Set(v8::String::New("dbSaveSound"), v8::FunctionTemplate::New(saveSound));
	global->Set(v8::String::New("dbDeleteSound"), v8::FunctionTemplate::New(deleteSound));
	global->Set(v8::String::New("dbCloneSound"), v8::FunctionTemplate::New(cloneSound));
	global->Set(v8::String::New("dbPlaySound"), v8::FunctionTemplate::New(playSound));
	global->Set(v8::String::New("dbLoopSound"), v8::FunctionTemplate::New(loopSound));
	global->Set(v8::String::New("dbStopSound"), v8::FunctionTemplate::New(stopSound));
	global->Set(v8::String::New("dbPauseSound"), v8::FunctionTemplate::New(pauseSound));
	global->Set(v8::String::New("dbResumeSound"), v8::FunctionTemplate::New(resumeSound));
	global->Set(v8::String::New("dbPositionSound"), v8::FunctionTemplate::New(positionSound));
	global->Set(v8::String::New("dbRecordSound"), v8::FunctionTemplate::New(recordSound));
	global->Set(v8::String::New("dbStopRecordingSound"), v8::FunctionTemplate::New(stopRecordingSound));
	global->Set(v8::String::New("dbSetSoundPan"), v8::FunctionTemplate::New(setSoundPan));
	global->Set(v8::String::New("dbSetSoundSpeed"), v8::FunctionTemplate::New(setSoundSpeed));
	global->Set(v8::String::New("dbSetSoundVolume"), v8::FunctionTemplate::New(setSoundVolume));
	global->Set(v8::String::New("dbPositionListener"), v8::FunctionTemplate::New(positionListener));
	global->Set(v8::String::New("dbRotateListener"), v8::FunctionTemplate::New(rotateListener));
	global->Set(v8::String::New("dbScaleListener"), v8::FunctionTemplate::New(scaleListener));

	global->Set(v8::String::New("dbSoundExist"), v8::FunctionTemplate::New(soundExist));
	global->Set(v8::String::New("dbSoundType"), v8::FunctionTemplate::New(soundType));
	global->Set(v8::String::New("dbSoundPlaying"), v8::FunctionTemplate::New(soundPlaying));
	global->Set(v8::String::New("dbSoundLooping"), v8::FunctionTemplate::New(soundLooping));
	global->Set(v8::String::New("dbSoundPaused"), v8::FunctionTemplate::New(soundPaused));
	global->Set(v8::String::New("dbSoundPositionX"), v8::FunctionTemplate::New(soundPositionX));
	global->Set(v8::String::New("dbSoundPositionY"), v8::FunctionTemplate::New(soundPositionY));
	global->Set(v8::String::New("dbSoundPositionZ"), v8::FunctionTemplate::New(soundPositionZ));
	global->Set(v8::String::New("dbSoundPan"), v8::FunctionTemplate::New(soundPan));
	global->Set(v8::String::New("dbSoundSpeed"), v8::FunctionTemplate::New(soundSpeed));
	global->Set(v8::String::New("dbSoundVolume"), v8::FunctionTemplate::New(soundVolume));

	global->Set(v8::String::New("dbListenerPositionX"), v8::FunctionTemplate::New(listenerPositionX));
	global->Set(v8::String::New("dbListenerPositionY"), v8::FunctionTemplate::New(listenerPositionY));
	global->Set(v8::String::New("dbListenerPositionZ"), v8::FunctionTemplate::New(listenerPositionZ));
	global->Set(v8::String::New("dbListenerAngleX"), v8::FunctionTemplate::New(listenerAngleX));
	global->Set(v8::String::New("dbListenerAngleY"), v8::FunctionTemplate::New(listenerAngleY));
	global->Set(v8::String::New("dbListenerAngleZ"), v8::FunctionTemplate::New(listenerAngleZ));
}