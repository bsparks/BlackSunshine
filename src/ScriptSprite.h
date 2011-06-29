// ScriptSprite.h

v8::Handle<v8::Value> sprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int x = args[1]->Int32Value();
	int y = args[2]->Int32Value();
	int imageId = args[3]->Int32Value();

	dbSprite(spriteId, x, y, imageId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int backSave = args[1]->Int32Value();
	int transparent = args[2]->Int32Value();

	dbSetSprite(spriteId, backSave, transparent);

	return v8::Undefined();
}

v8::Handle<v8::Value> deleteSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();

	dbDeleteSprite(spriteId);

	return v8::Undefined();
}

v8::Handle<v8::Value> cloneSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int destId = args[1]->Int32Value();

	dbCloneSprite(spriteId, destId);

	return v8::Undefined();
}

v8::Handle<v8::Value> showSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();

	dbShowSprite(spriteId);

	return v8::Undefined();
}

v8::Handle<v8::Value> hideSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();

	dbHideSprite(spriteId);

	return v8::Undefined();
}

v8::Handle<v8::Value> hideAllSprites(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbHideAllSprites();

	return v8::Undefined();
}

v8::Handle<v8::Value> showAllSprites(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	dbShowAllSprites();

	return v8::Undefined();
}

v8::Handle<v8::Value> moveSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	float velocity = args[1]->NumberValue();

	dbMoveSprite(spriteId, velocity);

	return v8::Undefined();
}

v8::Handle<v8::Value> offsetSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int x = args[1]->Int32Value();
	int y = args[2]->Int32Value();

	dbOffsetSprite(spriteId, x, y);

	return v8::Undefined();
}

v8::Handle<v8::Value> scaleSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	float scale = args[1]->NumberValue();

	dbScaleSprite(spriteId, scale);

	return v8::Undefined();
}

v8::Handle<v8::Value> sizeSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int x = args[1]->Int32Value();
	int y = args[2]->Int32Value();

	dbSizeSprite(spriteId, x, y);

	return v8::Undefined();
}

v8::Handle<v8::Value> stretchSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int x = args[1]->Int32Value();
	int y = args[2]->Int32Value();

	dbStretchSprite(spriteId, x, y);

	return v8::Undefined();
}

v8::Handle<v8::Value> rotateSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	float rotate = args[1]->NumberValue();

	dbRotateSprite(spriteId, rotate);

	return v8::Undefined();
}

v8::Handle<v8::Value> flipSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();

	dbFlipSprite(spriteId);

	return v8::Undefined();
}

v8::Handle<v8::Value> mirrorSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();

	dbMirrorSprite(spriteId);

	return v8::Undefined();
}

v8::Handle<v8::Value> pasteSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int x = args[1]->Int32Value();
	int y = args[2]->Int32Value();

	dbPasteSprite(spriteId, x, y);

	return v8::Undefined();
}

v8::Handle<v8::Value> createAnimatedSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	v8::String::Utf8Value str(args[1]);
	const char* img = ToCString(str);

	int width = args[2]->Int32Value();
	int height = args[3]->Int32Value();
	int imageId = args[4]->Int32Value();

	dbCreateAnimatedSprite(spriteId, ToCharString(img), width, height, imageId);

	return v8::Undefined();
}

v8::Handle<v8::Value> playSprite(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int start = args[1]->Int32Value();
	int end = args[2]->Int32Value();
	int delay = args[3]->Int32Value();

	dbPlaySprite(spriteId, start, end, delay);

	return v8::Undefined();
}

v8::Handle<v8::Value> setSpriteFrame(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int frame = args[1]->Int32Value();

	dbSetSpriteFrame(spriteId, frame);

	return v8::Undefined();
}

v8::Handle<v8::Value> setSpritePriority(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int priority = args[1]->Int32Value();

	dbSetSpritePriority(spriteId, priority);

	return v8::Undefined();
}

v8::Handle<v8::Value> setSpriteImage(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int imageId = args[1]->Int32Value();

	dbSetSpriteImage(spriteId, imageId);

	return v8::Undefined();
}

v8::Handle<v8::Value> setSpriteAlpha(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int value = args[1]->Int32Value();

	dbSetSpriteAlpha(spriteId, value);

	return v8::Undefined();
}

v8::Handle<v8::Value> setSpriteDiffuse(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int r = args[1]->Int32Value();
	int g = args[2]->Int32Value();
	int b = args[3]->Int32Value();

	dbSetSpriteDiffuse(spriteId, r, g, b);

	return v8::Undefined();
}

v8::Handle<v8::Value> setSpriteTextureCoord(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int vertex = args[1]->Int32Value();
	int u = args[2]->Int32Value();
	int v = args[3]->Int32Value();

	dbSetSpriteTextureCoord(spriteId, vertex, u, v);

	return v8::Undefined();
}

v8::Handle<v8::Value> spriteExist(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Boolean::New(dbSpriteExist(spriteId));
}

v8::Handle<v8::Value> spriteX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteX(spriteId));
}

v8::Handle<v8::Value> spriteY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteY(spriteId));
}

v8::Handle<v8::Value> spriteOffsetX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteOffsetX(spriteId));
}

v8::Handle<v8::Value> spriteOffsetY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteOffsetY(spriteId));
}

v8::Handle<v8::Value> spriteScaleX(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteScaleX(spriteId));
}

v8::Handle<v8::Value> spriteScaleY(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteScaleY(spriteId));
}

v8::Handle<v8::Value> spriteWidth(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteWidth(spriteId));
}

v8::Handle<v8::Value> spriteHeight(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteHeight(spriteId));
}

v8::Handle<v8::Value> spriteImage(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteImage(spriteId));
}

v8::Handle<v8::Value> spriteMirrored(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Boolean::New(dbSpriteMirrored(spriteId));
}

v8::Handle<v8::Value> spriteFlipped(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Boolean::New(dbSpriteFlipped(spriteId));
}

v8::Handle<v8::Value> spriteHit(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int target = args[1]->Int32Value();
	
	return v8::Int32::New(dbSpriteHit(spriteId, target));
}

v8::Handle<v8::Value> spriteCollision(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	int target = args[1]->Int32Value();
	
	return v8::Int32::New(dbSpriteCollision(spriteId, target));
}

v8::Handle<v8::Value> spriteAngle(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Number::New(dbSpriteAngle(spriteId));
}

v8::Handle<v8::Value> spriteFrame(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteFrame(spriteId));
}

v8::Handle<v8::Value> spriteAlpha(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteAlpha(spriteId));
}

v8::Handle<v8::Value> spriteRed(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteRed(spriteId));
}

v8::Handle<v8::Value> spriteGreen(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteGreen(spriteId));
}

v8::Handle<v8::Value> spriteBlue(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Int32::New(dbSpriteBlue(spriteId));
}

v8::Handle<v8::Value> spriteVisible(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int spriteId = args[0]->Int32Value();
	
	return v8::Boolean::New(dbSpriteVisible(spriteId));
}

void RegisterScriptSprite(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("dbSprite"), v8::FunctionTemplate::New(sprite));
	global->Set(v8::String::New("dbSetSprite"), v8::FunctionTemplate::New(setSprite));
	global->Set(v8::String::New("dbDeleteSprite"), v8::FunctionTemplate::New(deleteSprite));
	global->Set(v8::String::New("dbCloneSprite"), v8::FunctionTemplate::New(cloneSprite));
	global->Set(v8::String::New("dbShowSprite"), v8::FunctionTemplate::New(showSprite));
	global->Set(v8::String::New("dbHideSprite"), v8::FunctionTemplate::New(hideSprite));
	global->Set(v8::String::New("dbHideAllSprites"), v8::FunctionTemplate::New(hideAllSprites));
	global->Set(v8::String::New("dbShowAllSprites"), v8::FunctionTemplate::New(showAllSprites));
	global->Set(v8::String::New("dbMoveSprite"), v8::FunctionTemplate::New(moveSprite));
	global->Set(v8::String::New("dbOffsetSprite"), v8::FunctionTemplate::New(offsetSprite));
	global->Set(v8::String::New("dbScaleSprite"), v8::FunctionTemplate::New(scaleSprite));
	global->Set(v8::String::New("dbSizeSprite"), v8::FunctionTemplate::New(sizeSprite));
	global->Set(v8::String::New("dbStretchSprite"), v8::FunctionTemplate::New(stretchSprite));
	global->Set(v8::String::New("dbRotateSprite"), v8::FunctionTemplate::New(rotateSprite));
	global->Set(v8::String::New("dbFlipSprite"), v8::FunctionTemplate::New(flipSprite));
	global->Set(v8::String::New("dbMirrorSprite"), v8::FunctionTemplate::New(mirrorSprite));
	global->Set(v8::String::New("dbPasteSprite"), v8::FunctionTemplate::New(pasteSprite));
	global->Set(v8::String::New("dbCreateAnimatedSprite"), v8::FunctionTemplate::New(createAnimatedSprite));
	global->Set(v8::String::New("dbPlaySprite"), v8::FunctionTemplate::New(playSprite));
	global->Set(v8::String::New("dbSetSpriteFrame"), v8::FunctionTemplate::New(setSpriteFrame));
	global->Set(v8::String::New("dbSetSpritePriority"), v8::FunctionTemplate::New(setSpritePriority));
	global->Set(v8::String::New("dbSetSpriteImage"), v8::FunctionTemplate::New(setSpriteImage));
	global->Set(v8::String::New("dbSetSpriteAlpha"), v8::FunctionTemplate::New(setSpriteAlpha));
	global->Set(v8::String::New("dbSetSpriteDiffuse"), v8::FunctionTemplate::New(setSpriteDiffuse));
	global->Set(v8::String::New("dbSetSpriteTextureCoord"), v8::FunctionTemplate::New(setSpriteTextureCoord));

	global->Set(v8::String::New("dbSpriteExist"), v8::FunctionTemplate::New(spriteExist));
	global->Set(v8::String::New("dbSpriteX"), v8::FunctionTemplate::New(spriteX));
	global->Set(v8::String::New("dbSpriteY"), v8::FunctionTemplate::New(spriteY));
	global->Set(v8::String::New("dbSpriteOffsetX"), v8::FunctionTemplate::New(spriteOffsetX));
	global->Set(v8::String::New("dbSpriteOffsetY"), v8::FunctionTemplate::New(spriteOffsetY));
	global->Set(v8::String::New("dbSpriteScaleX"), v8::FunctionTemplate::New(spriteScaleX));
	global->Set(v8::String::New("dbSpriteScaleY"), v8::FunctionTemplate::New(spriteScaleY));
	global->Set(v8::String::New("dbSpriteWidth"), v8::FunctionTemplate::New(spriteWidth));
	global->Set(v8::String::New("dbSpriteHeight"), v8::FunctionTemplate::New(spriteHeight));
	global->Set(v8::String::New("dbSpriteImage"), v8::FunctionTemplate::New(spriteImage));
	global->Set(v8::String::New("dbSpriteMirrored"), v8::FunctionTemplate::New(spriteMirrored));
	global->Set(v8::String::New("dbSpriteFlipped"), v8::FunctionTemplate::New(spriteFlipped));
	global->Set(v8::String::New("dbSpriteHit"), v8::FunctionTemplate::New(spriteHit));
	global->Set(v8::String::New("dbSpriteCollision"), v8::FunctionTemplate::New(spriteCollision));
	global->Set(v8::String::New("dbSpriteAngle"), v8::FunctionTemplate::New(spriteAngle));
	global->Set(v8::String::New("dbSpriteFrame"), v8::FunctionTemplate::New(spriteFrame));
	global->Set(v8::String::New("dbSpriteAlpha"), v8::FunctionTemplate::New(spriteAlpha));
	global->Set(v8::String::New("dbSpriteRed"), v8::FunctionTemplate::New(spriteRed));
	global->Set(v8::String::New("dbSpriteGreen"), v8::FunctionTemplate::New(spriteGreen));
	global->Set(v8::String::New("dbSpriteBlue"), v8::FunctionTemplate::New(spriteBlue));
	global->Set(v8::String::New("dbSpriteVisible"), v8::FunctionTemplate::New(spriteVisible));
}