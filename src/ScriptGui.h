// ScriptGui.h

// main GUI
JS_METHOD(gui_showPointer_) {
	v8::HandleScope handle_scope;

    if(g_Gui)
	    g_Gui->showPointer();

	return v8::Undefined();
}

JS_METHOD(gui_hidePointer_) {
	v8::HandleScope handle_scope;

    if(g_Gui)
	    g_Gui->hidePointer();

	return v8::Undefined();
}

JS_METHOD(gui_load_) {
    v8::String::Utf8Value filename(args[0]);

    return JS_BOOL(g_Gui->load(*filename));
}

// common to all widgets
JS_GETTER(widget_getTop_) {
    v8::Local<v8::Object> self = info.Holder();
    MyGUI::WidgetPtr ptr = reinterpret_cast<MyGUI::WidgetPtr>(self->GetPointerFromInternalField(0));

    int value = ptr->getTop();

    return JS_INT(value);
}
  
JS_SETTER(widget_setTop_) {
    v8::Local<v8::Object> self = info.Holder();
    MyGUI::WidgetPtr ptr = reinterpret_cast<MyGUI::WidgetPtr>(self->GetPointerFromInternalField(0));

    ptr->setPosition(ptr->getLeft(), value->Int32Value());
}

JS_GETTER(widget_getLeft_) {
    v8::Local<v8::Object> self = info.Holder();
    MyGUI::WidgetPtr ptr = reinterpret_cast<MyGUI::WidgetPtr>(self->GetPointerFromInternalField(0));

    int value = ptr->getLeft();

    return JS_INT(value);
}
  
JS_SETTER(widget_setLeft_) {
    v8::Local<v8::Object> self = info.Holder();
    MyGUI::WidgetPtr ptr = reinterpret_cast<MyGUI::WidgetPtr>(self->GetPointerFromInternalField(0));

    ptr->setPosition(value->Int32Value(), ptr->getTop());
}

JS_GETTER(widget_getWidth_) {
    v8::Local<v8::Object> self = info.Holder();
    MyGUI::WidgetPtr ptr = reinterpret_cast<MyGUI::WidgetPtr>(self->GetPointerFromInternalField(0));

    int value = ptr->getWidth();

    return JS_INT(value);
}
  
JS_SETTER(widget_setWidth_) {
    v8::Local<v8::Object> self = info.Holder();
    MyGUI::WidgetPtr ptr = reinterpret_cast<MyGUI::WidgetPtr>(self->GetPointerFromInternalField(0));

    ptr->setSize(value->Int32Value(), ptr->getHeight());
}

JS_GETTER(widget_getHeight_) {
    v8::Local<v8::Object> self = info.Holder();
    MyGUI::WidgetPtr ptr = reinterpret_cast<MyGUI::WidgetPtr>(self->GetPointerFromInternalField(0));

    int value = ptr->getHeight();

    return JS_INT(value);
}
  
JS_SETTER(widget_setHeight_) {
    v8::Local<v8::Object> self = info.Holder();
    MyGUI::WidgetPtr ptr = reinterpret_cast<MyGUI::WidgetPtr>(self->GetPointerFromInternalField(0));

    ptr->setSize(ptr->getWidth(), value->Int32Value());
}

JS_METHOD(widget_setCaption_) {
    MyGUI::WidgetPtr ptr = LOAD_PTR(0, MyGUI::WidgetPtr);

    ASSERT_MIN_ARGS(1, "Syntax: widget.setCaption(name)")
    
    v8::String::Utf8Value caption(args[0]);
     
    ptr->setCaption(*caption);

    return args.This();
}

JS_METHOD(widget_setPosition_) {
    MyGUI::WidgetPtr ptr = LOAD_PTR(0, MyGUI::WidgetPtr);

    int x = args[0]->Int32Value();
    int y = args[1]->Int32Value();

    ptr->setPosition(x, y);

    return args.This();
}

JS_METHOD(widget_setSize_) {
    MyGUI::WidgetPtr ptr = LOAD_PTR(0, MyGUI::WidgetPtr);

    int w = args[0]->Int32Value();
    int h = args[1]->Int32Value();

    ptr->setSize(w, h);

    return args.This();
}

JS_METHOD(widget_setVisible_) {
    MyGUI::WidgetPtr ptr = LOAD_PTR(0, MyGUI::WidgetPtr);

    bool vis = args[0]->BooleanValue();

    ptr->setVisible(vis);

    return args.This();
}

JS_METHOD(widget_setAlpha_) {
    MyGUI::WidgetPtr ptr = LOAD_PTR(0, MyGUI::WidgetPtr);

    double val = args[0]->NumberValue();

    ptr->setAlpha(static_cast<float>(val));

    return args.This();
}

JS_METHOD(widget_addChild_) {
    MyGUI::WidgetPtr ptr = LOAD_PTR(0, MyGUI::WidgetPtr);

    // get ptr to another object for child
    v8::Handle<v8::Object> child = args[0]->ToObject();
    MyGUI::WidgetPtr ptr2 = reinterpret_cast<MyGUI::WidgetPtr>
        (child->GetPointerFromInternalField(0));

    ptr2->attachToWidget(ptr);

    return args.This();
}

JS_GETTER(widget_getName_) {
    v8::Local<v8::Object> self = info.Holder();
    MyGUI::WidgetPtr ptr = reinterpret_cast<MyGUI::WidgetPtr>(self->GetPointerFromInternalField(0));

    return JS_STR(ptr->getName().c_str());
}

// EVENTS
// most events should share the same signature, which will call fireEvent on the 
// main Gui script object
void edit_onEnterPressed(MyGUI::Edit* sender)
{
    v8::HandleScope scope;

    v8::Handle<v8::Value> gui = JS_GLOBAL->Get(JS_STR("Gui"));
    v8::Handle<v8::Object> guiObj = v8::Handle<v8::Object>::Cast(gui);
    v8::Handle<v8::Value> eventFunc = guiObj->Get(JS_STR("fireEvent"));
    v8::Handle<v8::Function> fireEvent = v8::Handle<v8::Function>::Cast(eventFunc);

    v8::Local<v8::Value> argv[2];
    argv[0] = JS_STR("enterpressed"); // event name
    argv[1] = JS_STR(sender->getName().c_str()); // source

    fireEvent->Call(guiObj, 2, argv);
}

void notifyWindowButtonPressed(MyGUI::Window* sender, const std::string& button)
{
    // pass it on to script
    v8::HandleScope scope;

    v8::Handle<v8::Value> gui = JS_GLOBAL->Get(JS_STR("Gui"));
    v8::Handle<v8::Object> guiObj = v8::Handle<v8::Object>::Cast(gui);
    v8::Handle<v8::Value> eventFunc = guiObj->Get(JS_STR("fireEvent"));
    v8::Handle<v8::Function> fireEvent = v8::Handle<v8::Function>::Cast(eventFunc);

    v8::Local<v8::Value> argv[3];
    argv[0] = JS_STR("windowbuttonpressed"); // event name
    argv[1] = JS_STR(sender->getName().c_str()); // source
    argv[2] = JS_STR(button.c_str()); // which button

    fireEvent->Call(guiObj, 3, argv);
}

void notifyWindowMouseDrag(MyGUI::Window* sender, int mouseLeft, int mouseTop)
{
    // pass it on to script
    v8::HandleScope scope;

    v8::Handle<v8::Value> gui = JS_GLOBAL->Get(JS_STR("Gui"));
    v8::Handle<v8::Object> guiObj = v8::Handle<v8::Object>::Cast(gui);
    v8::Handle<v8::Value> eventFunc = guiObj->Get(JS_STR("fireEvent"));
    v8::Handle<v8::Function> fireEvent = v8::Handle<v8::Function>::Cast(eventFunc);

    v8::Local<v8::Value> argv[4];
    argv[0] = JS_STR("windowbuttonpressed"); // event name
    argv[1] = JS_STR(sender->getName().c_str()); // source
    argv[2] = JS_INT(mouseLeft);
    argv[3] = JS_INT(mouseTop);

    fireEvent->Call(guiObj, 4, argv);
}

// BUTTON WIDGET CONSTRUCTOR
JS_METHOD(button_) {
    ASSERT_CONSTRUCTOR;
    
    MyGUI::ButtonPtr ptr;

    // name / id (should be unique)
    v8::String::Utf8Value name(args[0]);

    ptr = g_Gui->createWidget<MyGUI::Button>
        ("Button", 0, 0, 50, 25, MyGUI::Align::Default,
        "Main", *name);

    SAVE_PTR(0, ptr);

    return args.This();
}

// WINDOW WIDGET CONSTRUCTOR
JS_METHOD(window_) {
    ASSERT_CONSTRUCTOR;
    
    MyGUI::WindowPtr ptr;

    // name / id (should be unique)
    v8::String::Utf8Value name(args[0]);

    ptr = g_Gui->createWidget<MyGUI::Window>
        ("WindowCSX", 0, 0, 50, 25, MyGUI::Align::Default,
        "Main", *name);

    // setup event callbacks
    ptr->eventWindowButtonPressed = MyGUI::newDelegate(notifyWindowButtonPressed);
    reinterpret_cast<MyGUI::WidgetPtr>(ptr)->eventMouseDrag = MyGUI::newDelegate(notifyWindowMouseDrag);

    SAVE_PTR(0, ptr);

    return args.This();
}

// EDIT WIDGET
JS_METHOD(edit_) {
    ASSERT_CONSTRUCTOR;
    
    MyGUI::EditPtr ptr;

    // name / id (should be unique)
    v8::String::Utf8Value name(args[0]);

    ptr = g_Gui->createWidget<MyGUI::Edit>
        ("EditStretch", MyGUI::IntCoord(0, 0, 10, 10), 
        MyGUI::Align::Default, "Overlapped", *name);

    ptr->eventEditSelectAccept = MyGUI::newDelegate(edit_onEnterPressed);

    SAVE_PTR(0, ptr);

    return args.This();
}

void RegisterScriptGui(v8::Handle<v8::ObjectTemplate> &global)
{
    v8::HandleScope handle_scope;

	// create a sub object of the global object (global.Gui)
    v8::Handle<v8::ObjectTemplate> gui = v8::ObjectTemplate::New();
    // make it readonly so that user can't overwrite the function on accident
    global->Set(JS_STR("Gui"), gui, v8::ReadOnly);

    // setup fireEvent function so it exists (no default definition)
    gui->Set(JS_STR("fireEvent"), v8::FunctionTemplate::New());

    gui->Set(JS_STR("load"), v8::FunctionTemplate::New(gui_load_));
    gui->Set(JS_STR("showPointer"), v8::FunctionTemplate::New(gui_showPointer_));
    gui->Set(JS_STR("hidePointer"), v8::FunctionTemplate::New(gui_hidePointer_));

    // Button ****************************************************************************
    v8::Handle<v8::FunctionTemplate> buttonFT = v8::FunctionTemplate::New(button_);
    buttonFT->SetClassName(JS_STR("Button"));
    
    // constants (Button.*)

    // static methods (Button.*())

    v8::Handle<v8::ObjectTemplate> buttonOT = buttonFT->InstanceTemplate();
    buttonOT->SetInternalFieldCount(1);

    buttonOT->SetAccessor(JS_STR("name"), widget_getName_);

    buttonOT->SetAccessor(JS_STR("top"), widget_getTop_, widget_setTop_);
    buttonOT->SetAccessor(JS_STR("left"), widget_getLeft_, widget_setLeft_);

    buttonOT->SetAccessor(JS_STR("width"), widget_getWidth_, widget_setWidth_);
    buttonOT->SetAccessor(JS_STR("height"), widget_getHeight_, widget_setHeight_);
    
    v8::Handle<v8::ObjectTemplate> buttonPT = buttonFT->PrototypeTemplate();

    // prototype methods (new Button().*)
    buttonPT->Set(JS_STR("setCaption"),     v8::FunctionTemplate::New(widget_setCaption_));
    buttonPT->Set(JS_STR("setPosition"),    v8::FunctionTemplate::New(widget_setPosition_));
    buttonPT->Set(JS_STR("setSize"),        v8::FunctionTemplate::New(widget_setSize_));
    buttonPT->Set(JS_STR("setVisible"),     v8::FunctionTemplate::New(widget_setVisible_));
    buttonPT->Set(JS_STR("setAlpha"),       v8::FunctionTemplate::New(widget_setAlpha_));

    // add button class to gui object
    gui->Set(JS_STR("Button"), buttonFT);

    // Window ***************************************************************************
    v8::Handle<v8::FunctionTemplate> windowFT = v8::FunctionTemplate::New(window_);
    windowFT->SetClassName(JS_STR("Window"));

    // constants (Button.*)

    // static methods (Button.*())

    v8::Handle<v8::ObjectTemplate> windowOT = windowFT->InstanceTemplate();
    windowOT->SetInternalFieldCount(1);

    // properties
    windowOT->SetAccessor(JS_STR("name"), widget_getName_);

    windowOT->SetAccessor(JS_STR("top"), widget_getTop_, widget_setTop_);
    windowOT->SetAccessor(JS_STR("left"), widget_getLeft_, widget_setLeft_);

    windowOT->SetAccessor(JS_STR("width"), widget_getWidth_, widget_setWidth_);
    windowOT->SetAccessor(JS_STR("height"), widget_getHeight_, widget_setHeight_);

    v8::Handle<v8::ObjectTemplate> windowPT = windowFT->PrototypeTemplate();

    // prototype methods (new Button().*)
    windowPT->Set(JS_STR("addChild"),       v8::FunctionTemplate::New(widget_addChild_));
    windowPT->Set(JS_STR("setCaption"),     v8::FunctionTemplate::New(widget_setCaption_));
    windowPT->Set(JS_STR("setPosition"),    v8::FunctionTemplate::New(widget_setPosition_));
    windowPT->Set(JS_STR("setSize"),        v8::FunctionTemplate::New(widget_setSize_));
    windowPT->Set(JS_STR("setVisible"),     v8::FunctionTemplate::New(widget_setVisible_));
    windowPT->Set(JS_STR("setAlpha"),       v8::FunctionTemplate::New(widget_setAlpha_));

    // add button class to gui object
    gui->Set(JS_STR("Window"), windowFT);

    // Edit ***************************************************************************
    v8::Handle<v8::FunctionTemplate> editFT = v8::FunctionTemplate::New(edit_);
    editFT->SetClassName(JS_STR("Edit"));

    // constants (Button.*)

    // static methods (Button.*())

    v8::Handle<v8::ObjectTemplate> editOT = editFT->InstanceTemplate();
    editOT->SetInternalFieldCount(1);

    editOT->SetAccessor(JS_STR("name"), widget_getName_);

    editOT->SetAccessor(JS_STR("top"), widget_getTop_, widget_setTop_);
    editOT->SetAccessor(JS_STR("left"), widget_getLeft_, widget_setLeft_);

    editOT->SetAccessor(JS_STR("width"), widget_getWidth_, widget_setWidth_);
    editOT->SetAccessor(JS_STR("height"), widget_getHeight_, widget_setHeight_);

    v8::Handle<v8::ObjectTemplate> editPT = editFT->PrototypeTemplate();

    // prototype methods (new Button().*)
    editPT->Set(JS_STR("setCaption"),     v8::FunctionTemplate::New(widget_setCaption_));
    editPT->Set(JS_STR("setPosition"),    v8::FunctionTemplate::New(widget_setPosition_));
    editPT->Set(JS_STR("setSize"),        v8::FunctionTemplate::New(widget_setSize_));
    editPT->Set(JS_STR("setVisible"),     v8::FunctionTemplate::New(widget_setVisible_));
    editPT->Set(JS_STR("setAlpha"),       v8::FunctionTemplate::New(widget_setAlpha_));

    // add button class to gui object
    gui->Set(JS_STR("Edit"), editFT);
}