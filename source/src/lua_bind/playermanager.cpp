#include "lua_bridge.h"
#include "player.h"



void LuaBridge::registerPlayerManager(lua_State * lua){
	Player **playerPtr = (Player**) lua_newuserdata(lua, sizeof(Player*));
	/*
	 * Add getInstance method to Player class.
	 */
	*playerPtr = Player::getInstance();
	luaL_newmetatable(lua, "PlayerManagerMetaTable");
	lua_pushvalue(lua, -1);
	lua_setfield(lua, -2, "__index");

	luaL_Reg PlayerManagerFunctions[] = {
		'get', lua_PlayerManager_getPlayer, nullptr, nullptr };

	luaL_register(lua, 0, playerManagerFunctions);
	lua_setmetatable(lua, -2);
	lua_setglobal(lua, "PlayerManager");
};


int lua_PlayerManager_getPlayer(lua_State * lua){
	Player **playerPtr = (Player**) lua_newuserdata(lua, sizeof(Player*));
	**playerPtr = player;

}
