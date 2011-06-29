//ScriptInput.h

// get the current mouse x coord
v8::Handle<v8::Value> getMouseX(const v8::Arguments& args)
{
	return v8::Int32::New(dbMouseX());
}

// global object will have MouseX and MouseY as a properties constantly available...
v8::Handle<v8::Value> MouseXGetter(v8::Local<v8::String> property, const v8::AccessorInfo& info) 
{
	return v8::Integer::New(dbMouseX());
}

void MouseXSetter(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) 
{
	// just change the x value, y is another setter...
	dbPositionMouse(value->Int32Value(), dbMouseY());
}

v8::Handle<v8::Value> MouseYGetter(v8::Local<v8::String> property, const v8::AccessorInfo& info) 
{
	return v8::Integer::New(dbMouseY());
}

void MouseYSetter(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) 
{
	// just change the x value, y is another setter...
	dbPositionMouse(dbMouseX(), value->Int32Value());
}



// get the current mouse y coord
v8::Handle<v8::Value> getMouseY(const v8::Arguments& args)
{
	return v8::Int32::New(dbMouseY());
}

v8::Handle<v8::Value> getMouseZ(const v8::Arguments& args)
{
	return v8::Int32::New(dbMouseZ());
}

v8::Handle<v8::Value> getMouseMoveX(const v8::Arguments& args)
{
	return v8::Int32::New(dbMouseMoveX());
}

// get the current mouse y coord
v8::Handle<v8::Value> getMouseMoveY(const v8::Arguments& args)
{
	return v8::Int32::New(dbMouseMoveY());
}

// scroll wheel
v8::Handle<v8::Value> getMouseMoveZ(const v8::Arguments& args)
{
	return v8::Int32::New(dbMouseMoveZ());
}

// which button clicked
v8::Handle<v8::Value> getMouseClick(const v8::Arguments& args)
{
	return v8::Int32::New(dbMouseClick());
}

// show the mouse cursor
v8::Handle<v8::Value> showMouse(const v8::Arguments& args)
{
	dbShowMouse();

	return v8::Undefined();
}

// hide the mouse cursor
v8::Handle<v8::Value> hideMouse(const v8::Arguments& args)
{
	dbHideMouse();

	return v8::Undefined();
}

/**dbChangeMouse 
This command will change the cursor that belongs to the mouse pointer. 
A value of zero uses the applications arrow cursor and a value of one will use the hourglass cursor. 
Values 2 to 31 are custom cursors that can be specified in the project media section and selected with this command. 
**/
v8::Handle<v8::Value> changeMouse(const v8::Arguments& args)
{
	dbChangeMouse(args[0]->Int32Value());

	return v8::Undefined();
}

v8::Handle<v8::Value> positionMouse(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int x = args[0]->Int32Value();
	int y = args[1]->Int32Value();

	dbPositionMouse(x, y);

	return v8::Undefined();
}


v8::Handle<v8::Value> upKey(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbUpKey());
}

v8::Handle<v8::Value> downKey(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbDownKey());
}

v8::Handle<v8::Value> rightKey(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbRightKey());
}

v8::Handle<v8::Value> leftKey(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbLeftKey());
}

v8::Handle<v8::Value> controlKey(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbControlKey());
}

v8::Handle<v8::Value> shiftKey(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbShiftKey());
}

v8::Handle<v8::Value> spaceKey(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbSpaceKey());
}

v8::Handle<v8::Value> escapeKey(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbEscapeKey());
}

v8::Handle<v8::Value> returnKey(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Boolean::New(dbReturnKey());
}

v8::Handle<v8::Value> keyState(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int key = args[0]->Int32Value();

	return v8::Int32::New(dbKeyState(key));
}

v8::Handle<v8::Value> scanCode(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	return v8::Int32::New(dbScanCode());
}

void RegisterScriptInput(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbMouseX"), v8::FunctionTemplate::New(getMouseX));
	global->Set(v8::String::New("dbMouseY"), v8::FunctionTemplate::New(getMouseY));
	global->Set(v8::String::New("dbMouseZ"), v8::FunctionTemplate::New(getMouseZ));
	global->Set(v8::String::New("dbMouseMoveX"), v8::FunctionTemplate::New(getMouseMoveX));
	global->Set(v8::String::New("dbMouseMoveY"), v8::FunctionTemplate::New(getMouseMoveY));
	global->Set(v8::String::New("dbMouseMoveZ"), v8::FunctionTemplate::New(getMouseMoveZ));
	global->Set(v8::String::New("dbMouseClick"), v8::FunctionTemplate::New(getMouseClick));
	global->Set(v8::String::New("dbHideMouse"), v8::FunctionTemplate::New(hideMouse));
	global->Set(v8::String::New("dbShowMouse"), v8::FunctionTemplate::New(showMouse));
	global->Set(v8::String::New("dbChangeMouse"), v8::FunctionTemplate::New(changeMouse));
	global->Set(v8::String::New("dbPositionMouse"), v8::FunctionTemplate::New(positionMouse));

	global->Set(v8::String::New("dbUpKey"), v8::FunctionTemplate::New(upKey));
	global->Set(v8::String::New("dbDownKey"), v8::FunctionTemplate::New(downKey));
	global->Set(v8::String::New("dbLeftKey"), v8::FunctionTemplate::New(leftKey));
	global->Set(v8::String::New("dbRightKey"), v8::FunctionTemplate::New(rightKey));
	global->Set(v8::String::New("dbControlKey"), v8::FunctionTemplate::New(controlKey));
	global->Set(v8::String::New("dbShiftKey"), v8::FunctionTemplate::New(shiftKey));
	global->Set(v8::String::New("dbSpaceKey"), v8::FunctionTemplate::New(spaceKey));
	global->Set(v8::String::New("dbEscapeKey"), v8::FunctionTemplate::New(escapeKey));
	global->Set(v8::String::New("dbReturnKey"), v8::FunctionTemplate::New(returnKey));
	global->Set(v8::String::New("dbKeyState"), v8::FunctionTemplate::New(keyState));
	global->Set(v8::String::New("dbScanCode"), v8::FunctionTemplate::New(scanCode));

	// special properties of the global object (testing...)
	global->SetAccessor(v8::String::New("mouseX"), MouseXGetter, MouseXSetter);
	global->SetAccessor(v8::String::New("mouseY"), MouseYGetter, MouseYSetter);
}