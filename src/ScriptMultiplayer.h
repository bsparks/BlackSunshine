// ScriptMultiplayer.h

v8::Handle<v8::Value> defaultNetGame(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* gameName = ToCString(str);

	v8::String::Utf8Value str1(args[1]);
	const char* playerName = ToCString(str1);

	int playerMax = args[2]->Int32Value();
	int flagNum = args[3]->Int32Value();

	return v8::Int32::New(dbDefaultNetGame(ToCharString(gameName), 
		ToCharString(playerName), playerMax, flagNum));
}

v8::Handle<v8::Value> createNetGame(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* gameName = ToCString(str);

	v8::String::Utf8Value str1(args[1]);
	const char* playerName = ToCString(str1);

	int playerMax = args[2]->Int32Value();
	int flagNum = args[3]->Int32Value();

	dbCreateNetGame(ToCharString(gameName), 
		ToCharString(playerName), playerMax, flagNum);

	return v8::Undefined();
}

v8::Handle<v8::Value> joinNetGame(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int session = args[0]->Int32Value();

	v8::String::Utf8Value str1(args[1]);
	const char* playerName = ToCString(str1);

	dbJoinNetGame(session, ToCharString(playerName));

	return v8::Undefined();
}

v8::Handle<v8::Value> freeNetGame(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbFreeNetGame();

	return v8::Undefined();
}

v8::Handle<v8::Value> createNetPlayer(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str1(args[0]);
	const char* playerName = ToCString(str1);

	dbCreateNetPlayer(ToCharString(playerName));

	return v8::Undefined();
}

v8::Handle<v8::Value> freeNetPlayer(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int playerNum = args[0]->Int32Value();

	dbFreeNetPlayer(playerNum);

	return v8::Undefined();
}

v8::Handle<v8::Value> setNetConnection(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int index = args[0]->Int32Value();

	v8::String::Utf8Value str(args[1]);
	const char* ip = ToCString(str);

	dbSetNetConnection(index, ToCharString(ip));

	return v8::Undefined();
}

v8::Handle<v8::Value> performChecklistForNetConnections(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbPerformChecklistForNetConnections();

	return v8::Undefined();
}

v8::Handle<v8::Value> performChecklistForNetSessions(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbPerformChecklistForNetSessions();

	return v8::Undefined();
}

v8::Handle<v8::Value> performChecklistForNetPlayers(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbPerformChecklistForNetPlayers();

	return v8::Undefined();
}

v8::Handle<v8::Value> sendNetMessageInteger(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int playerNum = args[0]->Int32Value();
	int data = args[1]->Int32Value();

	dbSendNetMessageInteger(playerNum, data);

	return v8::Undefined();
}

v8::Handle<v8::Value> sendNetMessageFloat(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int playerNum = args[0]->Int32Value();
	float data = args[1]->NumberValue();

	dbSendNetMessageFloat(playerNum, data);

	return v8::Undefined();
}

v8::Handle<v8::Value> sendNetMessageString(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int playerNum = args[0]->Int32Value();
	v8::String::Utf8Value str(args[1]);
	const char* data = ToCString(str);

	dbSendNetMessageString(playerNum, ToCharString(data));

	return v8::Undefined();
}

v8::Handle<v8::Value> sendNetMessageMemblock(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int playerNum = args[0]->Int32Value();
	int memblockId = args[1]->Int32Value();
	int guarantee = args[2]->Int32Value();

	dbSendNetMessageMemblock(playerNum, memblockId, guarantee);

	return v8::Undefined();
}

v8::Handle<v8::Value> sendNetMessageBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int playerNum = args[0]->Int32Value();
	int bitmapId = args[1]->Int32Value();
	int guarantee = args[2]->Int32Value();

	dbSendNetMessageBitmap(playerNum, bitmapId, guarantee);

	return v8::Undefined();
}

v8::Handle<v8::Value> sendNetMessageImage(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int playerNum = args[0]->Int32Value();
	int imageId = args[1]->Int32Value();
	int guarantee = args[2]->Int32Value();

	dbSendNetMessageImage(playerNum, imageId, guarantee);

	return v8::Undefined();
}

v8::Handle<v8::Value> sendNetMessageSound(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int playerNum = args[0]->Int32Value();
	int soundId = args[1]->Int32Value();
	int guarantee = args[2]->Int32Value();

	dbSendNetMessageSound(playerNum, soundId, guarantee);

	return v8::Undefined();
}

v8::Handle<v8::Value> sendNetMessageMesh(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int playerNum = args[0]->Int32Value();
	int meshId = args[1]->Int32Value();
	int guarantee = args[2]->Int32Value();

	dbSendNetMessageMesh(playerNum, meshId, guarantee);

	return v8::Undefined();
}

v8::Handle<v8::Value> getNetMessage(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbGetNetMessage();

	return v8::Undefined();
}

v8::Handle<v8::Value> netMessageInteger(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbNetMessageInteger());
}

v8::Handle<v8::Value> netMessageFloat(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Number::New(dbNetMessageFloat());
}

v8::Handle<v8::Value> netMessageString(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::String::New(dbNetMessageString());
}

v8::Handle<v8::Value> netMessageMemblock(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int memblockId = args[0]->Int32Value();

	dbNetMessageMemblock(memblockId);

	return v8::Undefined();
}

v8::Handle<v8::Value> netMessageImage(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int imageId = args[0]->Int32Value();

	dbNetMessageImage(imageId);

	return v8::Undefined();
}

v8::Handle<v8::Value> netMessageBitmap(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int bitmapId = args[0]->Int32Value();

	dbNetMessageBitmap(bitmapId);

	return v8::Undefined();
}

v8::Handle<v8::Value> netMessageSound(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int soundId = args[0]->Int32Value();

	dbNetMessageSound(soundId);

	return v8::Undefined();
}

v8::Handle<v8::Value> netMessageMesh(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int meshId = args[0]->Int32Value();

	dbNetMessageMesh(meshId);

	return v8::Undefined();
}

v8::Handle<v8::Value> netGameExists(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbNetGameExists());
}

v8::Handle<v8::Value> netMessageExists(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbNetMessageExists());
}

v8::Handle<v8::Value> netMessagePlayerFrom(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Integer::New(dbNetMessagePlayerFrom());
}

v8::Handle<v8::Value> netMessagePlayerTo(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Integer::New(dbNetMessagePlayerTo());
}

v8::Handle<v8::Value> netMessageType(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Integer::New(dbNetMessageType());
}

v8::Handle<v8::Value> netGameLost(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbNetGameLost());
}

v8::Handle<v8::Value> netGameNowHosting(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbNetGameNowHosting());
}

v8::Handle<v8::Value> netBufferSize(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Integer::New(dbNetBufferSize());
}

v8::Handle<v8::Value> netPlayerDestroyed(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Integer::New(dbNetPlayerDestroyed());
}

v8::Handle<v8::Value> netPlayerCreated(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Integer::New(dbNetPlayerCreated());
}

void RegisterScriptMultiplayer(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbDefaultNetGame"), v8::FunctionTemplate::New(defaultNetGame));
	global->Set(v8::String::New("dbCreateNetGame"), v8::FunctionTemplate::New(createNetGame));
	global->Set(v8::String::New("dbJoinNetGame"), v8::FunctionTemplate::New(joinNetGame));
	global->Set(v8::String::New("dbFreeNetGame"), v8::FunctionTemplate::New(freeNetGame));
	global->Set(v8::String::New("dbCreateNetPlayer"), v8::FunctionTemplate::New(createNetPlayer));
	global->Set(v8::String::New("dbFreeNetPlayer"), v8::FunctionTemplate::New(freeNetPlayer));
	global->Set(v8::String::New("dbSetNetConnection"), v8::FunctionTemplate::New(setNetConnection));

	global->Set(v8::String::New("dbPerformChecklistForNetConnections"), v8::FunctionTemplate::New(performChecklistForNetConnections));
	global->Set(v8::String::New("dbPerformChecklistForNetSessions"), v8::FunctionTemplate::New(performChecklistForNetSessions));
	global->Set(v8::String::New("dbPerformChecklistForNetPlayers"), v8::FunctionTemplate::New(performChecklistForNetPlayers));

	global->Set(v8::String::New("dbSendNetMessageInteger"), v8::FunctionTemplate::New(sendNetMessageInteger));
	global->Set(v8::String::New("dbSendNetMessageFloat"), v8::FunctionTemplate::New(sendNetMessageFloat));
	global->Set(v8::String::New("dbSendNetMessageString"), v8::FunctionTemplate::New(sendNetMessageString));
	global->Set(v8::String::New("dbSendNetMessageMemblock"), v8::FunctionTemplate::New(sendNetMessageMemblock));
	global->Set(v8::String::New("dbSendNetMessageBitmap"), v8::FunctionTemplate::New(sendNetMessageBitmap));
	global->Set(v8::String::New("dbSendNetMessageImage"), v8::FunctionTemplate::New(sendNetMessageImage));
	global->Set(v8::String::New("dbSendNetMessageSound"), v8::FunctionTemplate::New(sendNetMessageSound));
	global->Set(v8::String::New("dbSendNetMessageMesh"), v8::FunctionTemplate::New(sendNetMessageMesh));
	global->Set(v8::String::New("dbGetNetMessage"), v8::FunctionTemplate::New(getNetMessage));
	global->Set(v8::String::New("dbNetMessageInteger"), v8::FunctionTemplate::New(netMessageInteger));
	global->Set(v8::String::New("dbNetMessageFloat"), v8::FunctionTemplate::New(netMessageFloat));
	global->Set(v8::String::New("dbNetMessageString"), v8::FunctionTemplate::New(netMessageString));
	global->Set(v8::String::New("dbNetMessageMemblock"), v8::FunctionTemplate::New(netMessageMemblock));
	global->Set(v8::String::New("dbNetMessageBitmap"), v8::FunctionTemplate::New(netMessageBitmap));
	global->Set(v8::String::New("dbNetMessageImage"), v8::FunctionTemplate::New(netMessageImage));
	global->Set(v8::String::New("dbNetMessageSound"), v8::FunctionTemplate::New(netMessageSound));
	global->Set(v8::String::New("dbNetMessageMesh"), v8::FunctionTemplate::New(netMessageMesh));

	global->Set(v8::String::New("dbNetGameExists"), v8::FunctionTemplate::New(netGameExists));
	global->Set(v8::String::New("dbNetMessageExists"), v8::FunctionTemplate::New(netMessageExists));
	global->Set(v8::String::New("dbNetMessagePlayerFrom"), v8::FunctionTemplate::New(netMessagePlayerFrom));
	global->Set(v8::String::New("dbNetMessagePlayerTo"), v8::FunctionTemplate::New(netMessagePlayerTo));
	global->Set(v8::String::New("dbNetMessageType"), v8::FunctionTemplate::New(netMessageType));
	global->Set(v8::String::New("dbNetGameLost"), v8::FunctionTemplate::New(netGameLost));
	global->Set(v8::String::New("dbNetGameNowHosting"), v8::FunctionTemplate::New(netGameNowHosting));
	global->Set(v8::String::New("dbNetBufferSize"), v8::FunctionTemplate::New(netBufferSize));
	global->Set(v8::String::New("dbNetPlayerDestroyed"), v8::FunctionTemplate::New(netPlayerDestroyed));
	global->Set(v8::String::New("dbNetPlayerCreated"), v8::FunctionTemplate::New(netPlayerCreated));
}