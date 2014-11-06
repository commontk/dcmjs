
var ENVIRONMENT_IS_WEB = typeof window === 'object';

var Module = Module || {};

// See https://github.com/kripken/emscripten/wiki/Interacting-with-code
if (ENVIRONMENT_IS_WEB)
  {
  Module['noInitialRun'] = 1;
  Module['noExitRuntime'] = 1;
  }
