// ScriptSystem.h

/*
v8::Handle<v8::Value> loadDLL(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	DWORD dllFilePtr = args[0]->Uint32Value();
	int dllId = args[1]->Int32Value();

	dbLoadDLL(dllFilePtr, dllId);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteDLL(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int dllId = args[0]->Int32Value();

	dbDeleteDLL(dllId);

	return v8::Undefined();
}

v8::Handle<v8::Value> callDLL(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int dllId = args[0]->Int32Value();
	DWORD funcPtr = args[1]->Uint32Value();

	dbCallDLL(dllId, funcPtr);

	return v8::Undefined();
}

v8::Handle<v8::Value> dllExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int dllId = args[0]->Int32Value();

	return v8::Boolean::New(dbDLLExist(dllId));
}

v8::Handle<v8::Value> dllCallExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int dllId = args[0]->Int32Value();
	DWORD funcPtr = args[1]->Uint32Value();

	return v8::Boolean::New(dbDLLCallExist(dllId, funcPtr));
}
*/

v8::Handle<v8::Value> emptyChecklist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbEmptyChecklist();

	return v8::Undefined();
}

v8::Handle<v8::Value> checklistQuantity(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Integer::New(dbChecklistQuantity());
}

v8::Handle<v8::Value> checklistString(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int index = args[0]->Int32Value();

	return v8::String::New(dbChecklistString(index));
}

v8::Handle<v8::Value> checklistValueA(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int index = args[0]->Int32Value();

	return v8::Integer::New(dbChecklistValueA(index));
}

v8::Handle<v8::Value> checklistValueB(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int index = args[0]->Int32Value();

	return v8::Integer::New(dbChecklistValueB(index));
}

v8::Handle<v8::Value> checklistValueC(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int index = args[0]->Int32Value();

	return v8::Integer::New(dbChecklistValueC(index));
}

v8::Handle<v8::Value> checklistValueD(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int index = args[0]->Int32Value();

	return v8::Integer::New(dbChecklistValueD(index));
}

v8::Handle<v8::Value> disableEscapeKey(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbDisableEscapeKey();

	return v8::Undefined();
}

v8::Handle<v8::Value> enableEscapeKey(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbEnableEscapeKey();

	return v8::Undefined();
}

v8::Handle<v8::Value> disableSystemKeys(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbDisableSystemKeys();

	return v8::Undefined();
}

v8::Handle<v8::Value> enableSystemKeys(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbEnableSystemKeys();

	return v8::Undefined();
}

v8::Handle<v8::Value> exitPrompt(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value str(args[0]);
	const char* msg = ToCString(str);

	v8::String::Utf8Value str1(args[1]);
	const char* caption = ToCString(str1);

	dbExitPrompt(ToCharString(msg), ToCharString(caption));

	return v8::Undefined();
}

v8::Handle<v8::Value> systemTMemAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbSystemTmemAvailable());
}

v8::Handle<v8::Value> systemDMemAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbSystemDmemAvailable());
}

v8::Handle<v8::Value> systemSMemAvailable(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbSystemSmemAvailable());
}

void RegisterScriptSystem(v8::Handle<v8::ObjectTemplate> &global)
{
	/* DLL stuff not working? maybe c++ doesn't need/use it??
	global->Set(v8::String::New("dbLoadDLL"), v8::FunctionTemplate::New(loadDLL));
	global->Set(v8::String::New("dbDeleteDLL"), v8::FunctionTemplate::New(deleteDLL));
	global->Set(v8::String::New("dbCallDLL"), v8::FunctionTemplate::New(callDLL));
	global->Set(v8::String::New("dbDllExist"), v8::FunctionTemplate::New(dllExist));
	global->Set(v8::String::New("dbDllCallExist"), v8::FunctionTemplate::New(dllCallExist));
	*/

	global->Set(v8::String::New("dbEmptyChecklist"), v8::FunctionTemplate::New(emptyChecklist));
	global->Set(v8::String::New("dbChecklistQuantity"), v8::FunctionTemplate::New(checklistQuantity));
	global->Set(v8::String::New("dbChecklistString"), v8::FunctionTemplate::New(checklistString));
	global->Set(v8::String::New("dbChecklistValueA"), v8::FunctionTemplate::New(checklistValueA));
	global->Set(v8::String::New("dbChecklistValueB"), v8::FunctionTemplate::New(checklistValueB));
	global->Set(v8::String::New("dbChecklistValueC"), v8::FunctionTemplate::New(checklistValueC));
	global->Set(v8::String::New("dbChecklistValueD"), v8::FunctionTemplate::New(checklistValueD));

	global->Set(v8::String::New("dbDisableEscapeKey"), v8::FunctionTemplate::New(disableEscapeKey));
	global->Set(v8::String::New("dbEnableEscapeKey"), v8::FunctionTemplate::New(enableEscapeKey));
	global->Set(v8::String::New("dbDisableSystemKeys"), v8::FunctionTemplate::New(disableSystemKeys));
	global->Set(v8::String::New("dbEnableSystemKeys"), v8::FunctionTemplate::New(enableSystemKeys));
	global->Set(v8::String::New("dbExitPrompt"), v8::FunctionTemplate::New(exitPrompt));
	global->Set(v8::String::New("dbSystemTMemAvailable"), v8::FunctionTemplate::New(systemTMemAvailable));
	global->Set(v8::String::New("dbSystemDMemAvailable"), v8::FunctionTemplate::New(systemDMemAvailable));
	global->Set(v8::String::New("dbSystemSMemAvailable"), v8::FunctionTemplate::New(systemSMemAvailable));
}