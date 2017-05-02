#ifndef LUA_BRIDGE_H
#define LUA_BRIDGE_H

extern "C" {
	#include <lua.h>
	#include <lualib.h>
	#include <luaxlib.h>
}


class LuaBridge{
public:
	void registerPlayerManager(lua_State * lua);



};

#endif
