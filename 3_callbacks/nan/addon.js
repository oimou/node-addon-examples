var addon = require('bindings')('addon');

addon(function(msg){
  return function (msg) {
      console.log(msg); // 'hello world'
  };
});
