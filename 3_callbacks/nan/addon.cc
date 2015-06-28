#include <nan.h>

using namespace v8;

NAN_METHOD(RunCallback) {
  NanScope();

  Local<Function> generateCallback = args[0].As<Function>();
  const unsigned argc = 1;
  Local<Value> argv[argc] = { NanNew("hello world") };
  Local<Value> emptyArgv[] = {};
  Local<Value> ambiguousCB = generateCallback->Call(
    NanGetCurrentContext()->Global(),
    0,
    emptyArgv
  );
  Local<Function> cb = Function::Cast(ambiguousCB);
  NanMakeCallback(NanGetCurrentContext()->Global(), cb, argc, argv);

  NanReturnUndefined();
}

void Init(Handle<Object> exports, Handle<Object> module) {
  NODE_SET_METHOD(module, "exports", RunCallback);
}

NODE_MODULE(addon, Init)
