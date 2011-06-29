// ScriptMusic.h

v8::Handle<v8::Value> loadMusic(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);
	
	int musicId = args[1]->Int32Value();

	dbLoadMusic(ToCharString(temp), musicId);

	return v8::Undefined();
}

v8::Handle<v8::Value> loadCDMusic(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int track = args[0]->Int32Value();
	int musicId = args[1]->Int32Value();

	dbLoadCDMusic(track, musicId);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteMusic(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();

	dbDeleteMusic(musicId);

	return v8::Undefined();
}

v8::Handle<v8::Value> playMusic(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();

	dbPlayMusic(musicId);

	return v8::Undefined();
}

v8::Handle<v8::Value> loopMusic(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();

	dbLoopMusic(musicId);

	return v8::Undefined();
}

v8::Handle<v8::Value> stopMusic(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();

	dbStopMusic(musicId);

	return v8::Undefined();
}

v8::Handle<v8::Value> pauseMusic(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();

	dbPauseMusic(musicId);

	return v8::Undefined();
}

v8::Handle<v8::Value> resumeMusic(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();

	dbResumeMusic(musicId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setMusicSpeed(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();
	int speed = args[1]->Int32Value();

	dbSetMusicSpeed(musicId, speed);

	return v8::Undefined();
}

v8::Handle<v8::Value> setMusicVolume(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();
	int volume = args[1]->Int32Value();

	dbSetMusicVolume(musicId, volume);

	return v8::Undefined();
}

v8::Handle<v8::Value> musicExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();

	return v8::Boolean::New(dbMusicExist(musicId));
}

v8::Handle<v8::Value> musicPlaying(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();

	return v8::Boolean::New(dbMusicPlaying(musicId));
}

v8::Handle<v8::Value> musicLooping(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();

	return v8::Boolean::New(dbMusicLooping(musicId));
}

v8::Handle<v8::Value> musicPaused(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();

	return v8::Boolean::New(dbMusicPaused(musicId));
}

v8::Handle<v8::Value> musicSpeed(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();

	return v8::Int32::New(dbMusicSpeed(musicId));
}

v8::Handle<v8::Value> musicVolume(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;
	
	int musicId = args[0]->Int32Value();

	return v8::Int32::New(dbMusicVolume(musicId));
}

v8::Handle<v8::Value> getNumberOfCDTracks(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbGetNumberOfCDTracks());
}

void RegisterScriptMusic(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbLoadMusic"), v8::FunctionTemplate::New(loadMusic));
	global->Set(v8::String::New("dbLoadCDMusic"), v8::FunctionTemplate::New(loadCDMusic));
	global->Set(v8::String::New("dbDeleteMusic"), v8::FunctionTemplate::New(deleteMusic));
	global->Set(v8::String::New("dbPlayMusic"), v8::FunctionTemplate::New(playMusic));
	global->Set(v8::String::New("dbLoopMusic"), v8::FunctionTemplate::New(loopMusic));
	global->Set(v8::String::New("dbStopMusic"), v8::FunctionTemplate::New(stopMusic));
	global->Set(v8::String::New("dbPauseMusic"), v8::FunctionTemplate::New(pauseMusic));
	global->Set(v8::String::New("dbResumeMusic"), v8::FunctionTemplate::New(resumeMusic));
	global->Set(v8::String::New("dbSetMusicSpeed"), v8::FunctionTemplate::New(setMusicSpeed));
	global->Set(v8::String::New("dbSetMusicVolume"), v8::FunctionTemplate::New(setMusicVolume));
	global->Set(v8::String::New("dbMusicExist"), v8::FunctionTemplate::New(musicExist));
	global->Set(v8::String::New("dbMusicPlaying"), v8::FunctionTemplate::New(musicPlaying));
	global->Set(v8::String::New("dbMusicLooping"), v8::FunctionTemplate::New(musicLooping));
	global->Set(v8::String::New("dbMusicPaused"), v8::FunctionTemplate::New(musicPaused));
	global->Set(v8::String::New("dbMusicSpeed"), v8::FunctionTemplate::New(musicSpeed));
	global->Set(v8::String::New("dbMusicVolume"), v8::FunctionTemplate::New(musicVolume));
	global->Set(v8::String::New("dbGetNumberOfCDTracks"), v8::FunctionTemplate::New(getNumberOfCDTracks));
}