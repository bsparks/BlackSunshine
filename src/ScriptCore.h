// ScriptCore.h

// native script functions not tied to Dark Basic

// The callback that is invoked by v8 whenever the JavaScript 'print'
// function is called.  Prints its arguments on stdout separated by
// spaces and ending with a newline.
v8::Handle<v8::Value> Print(const v8::Arguments& args) {
	v8::HandleScope handle_scope;
	v8::String::Utf8Value str(args[0]);
	const char* temp = ToCString(str);

	consoleBuffer.push_front(ToCharString(temp));

	return v8::Undefined();
}

void ReportException(v8::TryCatch* try_catch) {
  v8::HandleScope handle_scope;
  v8::String::Utf8Value exception(try_catch->Exception());
  const char* exception_string = ToCString(exception);
  v8::Handle<v8::Message> message = try_catch->Message();
  if (message.IsEmpty()) {
    // V8 didn't provide any extra information about this error; just
    // print the exception.
    consoleBuffer.push_front(ToCharString(exception_string));
  } else {
    // Print (filename):(line number): (message).
    v8::String::Utf8Value filename(message->GetScriptResourceName());
    const char* filename_string = ToCString(filename);
    int linenum = message->GetLineNumber();
	//char* buffer = NULL;
    //sprintf(buffer, "%s:%i: %s\n", filename_string, linenum, exception_string);
	//consoleBuffer.push_front(buffer);
	consoleBuffer.push_front(ToCharString(filename_string));
	consoleBuffer.push_front(ToCharString(exception_string));
    // Print line of source code.
    v8::String::Utf8Value sourceline(message->GetSourceLine());
    const char* sourceline_string = ToCString(sourceline);
    consoleBuffer.push_front(ToCharString(sourceline_string));
  }
}

// Executes a string within the current v8 context.
bool ExecuteString(v8::Handle<v8::String> source,
                   v8::Handle<v8::Value> name,
                   bool print_result,
                   bool report_exceptions) {
  v8::HandleScope handle_scope;
  v8::TryCatch try_catch;
  v8::Handle<v8::Script> script = v8::Script::Compile(source, name);
  if (script.IsEmpty()) {
    // Print errors that happened during compilation.
    if (report_exceptions)
      ReportException(&try_catch);
    return false;
  } else {
    v8::Handle<v8::Value> result = script->Run();
    if (result.IsEmpty()) {
      // Print errors that happened during execution.
      if (report_exceptions)
        ReportException(&try_catch);
      return false;
    } else {
      if (print_result && !result->IsUndefined()) {
        // If all went well and the result wasn't undefined then print
        // the returned value.
        v8::String::Utf8Value str(result);
        const char* cstr = ToCString(str);
		consoleBuffer.push_front(ToCharString(cstr));
        //printf("%s\n", cstr);
      }
      return true;
    }
  }
}

// Reads a file into a v8 string.
v8::Handle<v8::String> ReadFile(const char* name) {
  FILE* file = fopen(name, "rb");
  if (file == NULL) return v8::Handle<v8::String>();

  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind(file);

  char* chars = new char[size + 1];
  chars[size] = '\0';
  for (int i = 0; i < size;) {
    int read = fread(&chars[i], 1, size - i, file);
    i += read;
  }
  fclose(file);
  v8::Handle<v8::String> result = v8::String::New(chars, size);
  delete[] chars;
  return result;
}

// The callback that is invoked by v8 whenever the JavaScript 'load'
// function is called.  Loads, compiles and executes its argument
// JavaScript file.
v8::Handle<v8::Value> Load(const v8::Arguments& args) {
  for (int i = 0; i < args.Length(); i++) {
    v8::HandleScope handle_scope;
    v8::String::Utf8Value file(args[i]);
    if (*file == NULL) {
      return v8::ThrowException(v8::String::New("Error loading file"));
    }
    v8::Handle<v8::String> source = ReadFile(*file);
    if (source.IsEmpty()) {
      return v8::ThrowException(v8::String::New("Error loading file"));
    }
    if (!ExecuteString(source, v8::String::New(*file), false, false)) {
      return v8::ThrowException(v8::String::New("Error executing file"));
    }
  }
  return v8::Undefined();
}

// Reads a file from a remote http source into a v8 string.
v8::Handle<v8::String> ReadRemoteFile(const char* host, const char* path) {
/*
	std::string h(host);
    std::string p(path);

	SocketClient s(h, 80);
    s.SendLine("GET " + p + " HTTP/1.1");
	s.SendLine("Host: " + h);
    s.SendLine("Connection: close");
    s.SendLine("");

    std::string r;
    bool endHeader = false;

	while (1) {

		std::string l = s.ReceiveLine();
		if (l.empty()) break;
            
		// single carriage return *should* mean header is complete
        // todo: read the header and use it?
        if(l == "\r\n")
	        endHeader = true;

        // only after the header is complete do we want to start recording the script
        if(endHeader)
	        r += l;
	}

	v8::Handle<v8::String> result = v8::String::New(r.c_str(), r.length());

	return result;
    */
    return v8::String::New("Not Implemented");
}

// load and execute remote http file
v8::Handle<v8::Value> LoadRemote(const v8::Arguments& args) {
	v8::HandleScope handle_scope;

	v8::String::Utf8Value host(args[0]);
    v8::String::Utf8Value path(args[1]);

	v8::Handle<v8::String> source = ReadRemoteFile(*host, *path);

    if (source.IsEmpty()) {
		return v8::ThrowException(v8::String::New("Error loading file"));
    }

    if (!ExecuteString(source, v8::String::New(*path), true, true)) {
	    return v8::ThrowException(v8::String::New("Error executing file"));
    }

	return v8::Undefined();
}



// The callback that is invoked by v8 whenever the JavaScript 'quit'
// function is called.  Quits.
v8::Handle<v8::Value> Quit(const v8::Arguments& args) {
  // If not arguments are given args[0] will yield undefined which
  // converts to the integer value 0.
  int exit_code = args[0]->Int32Value();
  exit(exit_code);
  return v8::Undefined();
}

v8::Handle<v8::Value> Version(const v8::Arguments& args) {
  return v8::String::New(v8::V8::GetVersion());
}

// DB CORE

v8::Handle<v8::Value> syncOn(const v8::Arguments& args)
{
	dbSyncOn();

	return v8::Undefined();
}

v8::Handle<v8::Value> syncOff(const v8::Arguments& args)
{
	dbSyncOff();

	return v8::Undefined();
}

v8::Handle<v8::Value> sync(const v8::Arguments& args)
{
	dbSync();

	return v8::Undefined();
}

v8::Handle<v8::Value> syncRate(const v8::Arguments& args)
{
	int rate = args[0]->Int32Value();

	dbSyncRate(rate);

	return v8::Undefined();
}

v8::Handle<v8::Value> fastSync(const v8::Arguments& args)
{
	dbFastSync();

	return v8::Undefined();
}

v8::Handle<v8::Value> randomize(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int seed = args[0]->Int32Value();

	dbRandomize(seed);

	return v8::Undefined();
}

v8::Handle<v8::Value> rnd(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int range = args[0]->Int32Value();

	return v8::Int32::New(dbRND(range));
}

v8::Handle<v8::Value> timer(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbTimer());
}

void RegisterScriptCore(v8::Handle<v8::ObjectTemplate> &global)
{
	// basic V8 CORE
	global->Set(v8::String::New("echo"), v8::FunctionTemplate::New(Print));
	global->Set(v8::String::New("load"), v8::FunctionTemplate::New(Load));
	global->Set(v8::String::New("loadRemote"), v8::FunctionTemplate::New(LoadRemote));
	global->Set(v8::String::New("quit"), v8::FunctionTemplate::New(Quit));
	global->Set(v8::String::New("exit"), v8::FunctionTemplate::New(Quit));
	global->Set(v8::String::New("version"), v8::FunctionTemplate::New(Version));

	// DB CORE
	global->Set(v8::String::New("dbSyncOn"), v8::FunctionTemplate::New(syncOn));
	global->Set(v8::String::New("dbSyncOff"), v8::FunctionTemplate::New(syncOff));
	global->Set(v8::String::New("dbSync"), v8::FunctionTemplate::New(sync));
	global->Set(v8::String::New("dbSyncRate"), v8::FunctionTemplate::New(syncRate));

	global->Set(v8::String::New("dbRandomize"), v8::FunctionTemplate::New(randomize));
	global->Set(v8::String::New("dbRnd"), v8::FunctionTemplate::New(rnd));

	global->Set(v8::String::New("dbTimer"), v8::FunctionTemplate::New(timer));
}