// ScriptFtp.h

v8::Handle<v8::Value> ftpConnect(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	v8::String::Utf8Value url(args[0]);
	const char* tUrl = ToCString(url);

	v8::String::Utf8Value user(args[1]);
	const char* tUser = ToCString(user);

	v8::String::Utf8Value pass(args[2]);
	const char* tPass = ToCString(pass);

	dbFTPConnect(ToCharString(tUrl), ToCharString(tUser), ToCharString(tPass));

	return v8::Undefined();
}

v8::Handle<v8::Value> ftpDisconnect(const v8::Arguments& args)
{
	dbFTPDisconnect();

	return v8::Undefined();
}

v8::Handle<v8::Value> ftpTerminate(const v8::Arguments& args)
{
	dbFTPTerminate();

	return v8::Undefined();
}

v8::Handle<v8::Value> ftpSetDir(const v8::Arguments& args)
{
	v8::String::Utf8Value dir(args[0]);
	const char* tDir = ToCString(dir);

	dbFTPSetDir(ToCharString(tDir));

	return v8::Undefined();
}

v8::Handle<v8::Value> ftpGetFile(const v8::Arguments& args)
{
	v8::String::Utf8Value file(args[0]);
	const char* tFile = ToCString(file);

	v8::String::Utf8Value local(args[1]);
	const char* tLocal = ToCString(local);

	int bytes = args[2]->Int32Value();

	dbFTPGetFile(ToCharString(tFile), ToCharString(tLocal), bytes);

	return v8::Undefined();
}

v8::Handle<v8::Value> ftpPutFile(const v8::Arguments& args)
{
	v8::String::Utf8Value file(args[0]);
	const char* tFile = ToCString(file);

	dbFTPPutFile(ToCharString(tFile));

	return v8::Undefined();
}

v8::Handle<v8::Value> ftpDeleteFile(const v8::Arguments& args)
{
	v8::String::Utf8Value file(args[0]);
	const char* tFile = ToCString(file);

	dbFTPDeleteFile(ToCharString(tFile));

	return v8::Undefined();
}

v8::Handle<v8::Value> ftpProceed(const v8::Arguments& args)
{
	dbFTPProceed();

	return v8::Undefined();
}

v8::Handle<v8::Value> ftpFindFirst(const v8::Arguments& args)
{
	dbFTPFindFirst();

	return v8::Undefined();
}

v8::Handle<v8::Value> ftpFindNext(const v8::Arguments& args)
{
	dbFTPFindNext();

	return v8::Undefined();
}

v8::Handle<v8::Value> getFtpStatus(const v8::Arguments& args)
{
	return v8::Int32::New(dbGetFTPStatus());
}

v8::Handle<v8::Value> getFtpDir(const v8::Arguments& args)
{
	return v8::String::New(dbGetFTPDir());
}

v8::Handle<v8::Value> getFtpProgress(const v8::Arguments& args)
{
	return v8::Int32::New(dbGetFTPProgress());
}

v8::Handle<v8::Value> getFtpFailure(const v8::Arguments& args)
{
	return v8::Int32::New(dbGetFTPFailure());
}

v8::Handle<v8::Value> getFtpError(const v8::Arguments& args)
{
	return v8::String::New(dbGetFTPError());
}

v8::Handle<v8::Value> getFtpFileType(const v8::Arguments& args)
{
	return v8::Int32::New(dbGetFTPFileType());
}

v8::Handle<v8::Value> getFtpFileName(const v8::Arguments& args)
{
	return v8::String::New(dbGetFTPFileName());
}

v8::Handle<v8::Value> getFtpFileSize(const v8::Arguments& args)
{
	return v8::Int32::New(dbGetFTPFileSize());
}

void RegisterScriptFtp(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbFtpConnect"), v8::FunctionTemplate::New(ftpConnect));
	global->Set(v8::String::New("dbFtpDisconnect"), v8::FunctionTemplate::New(ftpDisconnect));
	global->Set(v8::String::New("dbFtpTerminate"), v8::FunctionTemplate::New(ftpTerminate));
	global->Set(v8::String::New("dbFtpSetDir"), v8::FunctionTemplate::New(ftpSetDir));
	global->Set(v8::String::New("dbFtpGetFile"), v8::FunctionTemplate::New(ftpGetFile));
	global->Set(v8::String::New("dbFtpPutFile"), v8::FunctionTemplate::New(ftpPutFile));
	global->Set(v8::String::New("dbFtpDeleteFile"), v8::FunctionTemplate::New(ftpDeleteFile));
	global->Set(v8::String::New("dbFtpProceed"), v8::FunctionTemplate::New(ftpProceed));
	global->Set(v8::String::New("dbFtpFindFirst"), v8::FunctionTemplate::New(ftpFindFirst));
	global->Set(v8::String::New("dbFtpFindNext"), v8::FunctionTemplate::New(ftpFindNext));
	global->Set(v8::String::New("dbGetFtpStatus"), v8::FunctionTemplate::New(getFtpStatus));
	global->Set(v8::String::New("dbGetFtpDir"), v8::FunctionTemplate::New(getFtpDir));
	global->Set(v8::String::New("dbGetFtpProgress"), v8::FunctionTemplate::New(getFtpProgress));
	global->Set(v8::String::New("dbGetFtpFailure"), v8::FunctionTemplate::New(getFtpFailure));
	global->Set(v8::String::New("dbGetFtpError"), v8::FunctionTemplate::New(getFtpError));
	global->Set(v8::String::New("dbGetFtpFileType"), v8::FunctionTemplate::New(getFtpFileType));
	global->Set(v8::String::New("dbGetFtpFileName"), v8::FunctionTemplate::New(getFtpFileName));
	global->Set(v8::String::New("dbGetFtpFileSize"), v8::FunctionTemplate::New(getFtpFileSize));
}