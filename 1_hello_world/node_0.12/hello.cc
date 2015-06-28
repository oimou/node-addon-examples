#include <nan.h>

using namespace v8;

NAN_METHOD(Method) {
    NanScope();
    NanReturnValue(NanNew<String>("world"));
}

void Init(Handle<Object> exports) {
    exports->Set(
        NanNew<String>("hello"),
        NanNew<FunctionTemplate>(Method)->GetFunction()
    );
}

NODE_MODULE(hello, Init)
